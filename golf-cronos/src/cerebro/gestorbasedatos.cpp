#include "gestorbasedatos.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>

// --- CONSTRUCTOR ---
GestorBaseDatos::GestorBaseDatos() {
    // 1. Instanciar el driver nativo de SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");

    // 2. Definir la ruta del archivo local
    QString rutaDb = QDir::currentPath() + "/cronos_data.sqlite";
    db.setDatabaseName(rutaDb);

    // 3. Abrir la conexión
    if (!db.open()) {
        qDebug() << "Error crítico: No se pudo conectar a la BD:" << db.lastError().text();
    } else {
        qDebug() << "Conexión a SQLite exitosa.";
        inicializarTablas(); // Nos aseguramos de que las tablas existan
    }
}

// --- DESTRUCTOR ---
GestorBaseDatos::~GestorBaseDatos() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Conexión a SQLite cerrada de forma segura.";
    }
}

// --- INICIALIZAR TABLAS ---
bool GestorBaseDatos::inicializarTablas() {
    QSqlQuery query;
    // Tabla Jugador con los valores por defecto que definimos para Crono Golf
    QString sqlJugador = R"(
        CREATE TABLE IF NOT EXISTS Jugador (
            id_jugador TEXT PRIMARY KEY,
            pin_secreto TEXT NOT NULL,
            vidas INTEGER DEFAULT 5,
            nivel_actual INTEGER DEFAULT 0,
            puntuacion_total INTEGER DEFAULT 0
        )
    )";

    if (!query.exec(sqlJugador)) {
        qDebug() << "Error creando tabla Jugador:" << query.lastError().text();
        return false;
    }
    return true;
}

// --- MÉTODO: REGISTRAR JUGADOR ---
bool GestorBaseDatos::registrarJugador(const QString& idJugador, const QString& pin) {
    QSqlQuery query;

    // Preparamos la consulta SQL para evitar inyecciones y errores de sintaxis
    query.prepare("INSERT INTO Jugador (id_jugador, pin_secreto) VALUES (:id, :pin)");

    // Enlazamos las variables de C++ a los marcadores de la consulta SQL
    query.bindValue(":id", idJugador);
    query.bindValue(":pin", pin);

    // Ejecutamos la inserción
    if (query.exec()) {
        qDebug() << "¡Éxito! Jugador registrado en Cronos:" << idJugador;
        return true;
    } else {
        // Si falla (por ejemplo, si el id_jugador ya existe debido a la PRIMARY KEY)
        qDebug() << "Fallo al registrar (¿El identificador ya existe?):" << query.lastError().text();
        return false;
    }
}

// --- MÉTODO: VALIDAR ACCESO ---
bool GestorBaseDatos::validarAcceso(const QString& idJugador, const QString& pin) {
    QSqlQuery query;

    // Buscamos si existe una fila que coincida exactamente con el ID y el PIN
    query.prepare("SELECT id_jugador FROM Jugador WHERE id_jugador = :id AND pin_secreto = :pin");
    query.bindValue(":id", idJugador);
    query.bindValue(":pin", pin);

    if (query.exec()) {
        // query.next() avanza al primer resultado. Si hay al menos uno, devuelve true.
        if (query.next()) {
            qDebug() << "Acceso concedido. Bienvenido de nuevo:" << idJugador;
            return true;
        } else {
            qDebug() << "Acceso denegado: Identificador o PIN incorrectos.";
            return false;
        }
    } else {
        qDebug() << "Error ejecutando la validación:" << query.lastError().text();
        return false;
    }
}