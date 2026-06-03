#ifndef PELOTA_H
#define PELOTA_H

#include <QGraphicsPixmapItem>
#include <QPointF>

class Pelota : public QGraphicsPixmapItem
{
public:
    Pelota(QGraphicsItem *parent = nullptr);
    ~Pelota();

    // Física
    void actualizarFisica(double deltaTime = 0.016);  // ~60 FPS
    void setVelocidad(double vx, double vy);
    void setPosition(double x, double y);

    // Getters
    double getVelocidadX() const { return velocidadX; }
    double getVelocidadY() const { return velocidadY; }
    double getRadio() const { return radio; }
    QPointF obtenerCoordenada() const;

    // Debug
    void marcarPosicion(const QString& etiqueta = "");

private:
    // Propiedades físicas
    double velocidadX;
    double velocidadY;
    double radio;

    // Parámetros de física
    double gravedad;           // Pixels/s² (caída)
    double friccion;           // Factor 0-1 (ralentización)
    double velocidadMinima;    // Threshold para "detener"
};

#endif // PELOTA_H