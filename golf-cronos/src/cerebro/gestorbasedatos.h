#ifndef GESTORBASEDATOS_H
#define GESTORBASEDATOS_H

#include <QSqlDatabase>
#include <QString>

class GestorBaseDatos
{
public:
    GestorBaseDatos();
    ~GestorBaseDatos();

    // Metodos para tablas
    bool inicializarTablas();
    bool registrarJugador(const QString& idJugador, const QString& pin);
    bool validarAcceso(const QString& idJugador, const QString& pin);

private:
    QSqlDatabase db;
};

#endif // GESTORBASEDATOS_H
