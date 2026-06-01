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

    qDebug() << "Conexión a SQLite exitosa en:" << rutaDb;
    return inicializarTablas();
}

bool GestorBaseDatos::inicializarTablas() {
    QSqlQuery query;
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

bool GestorBaseDatos::registrarJugador(const QString& idJugador, const QString& pin) {
    QSqlQuery query;
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
        qDebug() << "Acceso concedido:" << idJugador;
        return true;
    }
    qDebug() << "Acceso denegado o error.";
    return false;
}
