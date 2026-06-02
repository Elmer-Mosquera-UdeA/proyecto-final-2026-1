#include "gestorbasedatos.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

bool GestorBaseDatos::conectarBD() {
    // Si ya existe la conexión, no hacemos nada duplicate
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        return true;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    QString rutaCarpeta = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(rutaCarpeta);
    QString rutaDb = rutaCarpeta + "/cronos_data.sqlite";
    db.setDatabaseName(rutaDb);

    if (!db.open()) {
        qDebug() << "Error crítico: No se pudo conectar a la BD:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;");

    qDebug() << "Conexión a SQLite exitosa en:" << rutaDb;
    return inicializarTablas();
}

bool GestorBaseDatos::inicializarTablas() {
    QSqlQuery query;

    QString sqlJugador = R"(
        CREATE TABLE IF NOT EXISTS Jugador (
            id_jugador TEXT PRIMARY KEY,
            pin_secreto TEXT NOT NULL,
            vidas INTEGER DEFAULT 5 CHECK(vidas >= 0),
            puntuacion_total INTEGER DEFAULT 0
        );
    )";

    // 2. Tabla de Progreso (Modo Uno)
    QString sqlProgresoModUno = R"(
        CREATE TABLE IF NOT EXISTS ProgresoModUno (
            id_jugador TEXT,
            id_nivel INTEGER NOT NULL CHECK(id_nivel BETWEEN 1 AND 4),
            golpes_realizados INTEGER DEFAULT 0,
            mejor_tiempo_segundos INTEGER,
            PRIMARY KEY (id_jugador, id_nivel),
            FOREIGN KEY (id_jugador) REFERENCES Jugador(id_jugador)
                ON DELETE CASCADE
                ON UPDATE CASCADE
        );
    )";


    // TODO - MODO 2

    // sqlProgresoModUno -> ProgresoModUno

    if (!query.exec(sqlJugador)) {
        qDebug() << "Error creando tabla Jugador:" << query.lastError().text();
        return false;
    }

    if (!query.exec(sqlProgresoModUno)) {
        qDebug() << "Error creando tabla ProgresoModUno:" << query.lastError().text();
        return false;
    }
    return true;
}

bool GestorBaseDatos::registrarJugador(const QString& idJugador, const QString& pin) {
    QSqlQuery query;

    if (idJugador.isEmpty() || pin.isEmpty()){
        qDebug() << "No se pueden dejar los campos en blanco";
        return false;
    }

    query.prepare("INSERT INTO Jugador (id_jugador, pin_secreto) VALUES (:id, :pin)");
    query.bindValue(":id", idJugador);
    query.bindValue(":pin", pin);

    if (query.exec()) {
        qDebug() << "¡Éxito! Jugador registrado:" << idJugador;
        return true;
    }
    qDebug() << "Fallo al registrar:" << query.lastError().text();
    return false;
}

bool GestorBaseDatos::validarAcceso(const QString& idJugador, const QString& pin) {
    QSqlQuery query;
    query.prepare("SELECT id_jugador FROM Jugador WHERE id_jugador = :id AND pin_secreto = :pin");
    query.bindValue(":id", idJugador);
    query.bindValue(":pin", pin);

    if (query.exec() && query.next()) {
        m_jugadorActivo = idJugador;
        qDebug() << "Acceso concedido:" << idJugador;
        return true;
    }
    qDebug() << "Acceso denegado o error.";
    return false;
}

bool GestorBaseDatos::exitAuth()
{
    m_jugadorActivo = "";
    qDebug() << "¡Secion cerrada!";
    return true;
}

QString GestorBaseDatos::obtenerJugadorActivo()  {
    return m_jugadorActivo;
}

bool GestorBaseDatos::retomarJuego(const QString &idJugador, const QString &modoJuego)
{
    QSqlQuery query;

    if (modoJuego == "ModoUno") {
        // Buscamos el nivel máximo alcanzado o guardado por el jugador
        query.prepare("SELECT MAX(id_nivel) FROM ProgresoModUno WHERE id_jugador = :id");
        query.bindValue(":id", idJugador);

        if (query.exec() && query.next()) {
            // Si el resultado es nulo, significa que nunca ha jugado el Modo Uno
            if (query.value(0).isNull()) {
                qDebug() << "El jugador no tiene progreso en Modo Uno. Empezará desde el nivel 1.";
                return false;
            }

            int ultimoNivel = query.value(0).toInt();
            qDebug() << "Retomando Modo Uno para" << idJugador << "en el nivel:" << ultimoNivel;
            return true;
        }
        return true;
    }
    else if (modoJuego == "ModoDos") {
        // TODO: Implementar cuando ya esten la tabla del Modo Dos
        qDebug() << "Modo Dos no implementado todavía.";
        return false;
    }

    return false;
}
