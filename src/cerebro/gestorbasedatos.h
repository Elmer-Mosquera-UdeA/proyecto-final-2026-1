#ifndef GESTORBASEDATOS_H
#define GESTORBASEDATOS_H

#include <QString>

class GestorBaseDatos
{
public:

    static bool conectarBD();
    static bool inicializarTablas();
    static bool registrarJugador(const QString& idJugador, const QString& pin);
    static bool validarAcceso(const QString& idJugador, const QString& pin);
    static bool exitAuth();
    static bool retomarJuego(const QString& idJugador, const QString& modoJuego);
    static QString obtenerJugadorActivo();
private:
    inline static QString m_jugadorActivo = "";
    GestorBaseDatos() = default;
};

#endif // GESTORBASEDATOS_H

