#include "pelota.h"
#include <QPixmap>
#include <QDebug>
#include <cmath>

Pelota::Pelota(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent),
    velocidadX(0.0),
    velocidadY(0.0),
    radio(16.0),  // 32 pixels de diámetro
    gravedad(0.5),  // Aceleración por frame
    friccion(0.98),  // 2% de pérdida por frame
    velocidadMinima(0.1)
{
    // Cargar imagen de pelota
    QPixmap imagen(":/resources/imgs/pelota-golf.png");
    if (!imagen.isNull()) {
        setPixmap(imagen.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // Posición por defecto (será establecida en Nivel)
    setPos(683, 600);
}

Pelota::~Pelota()
{
}

void Pelota::actualizarFisica(double deltaTime)
{
    // 1. Aplicar gravedad (aceleración hacia abajo)
    velocidadY += gravedad;

    // 2. Aplicar fricción (ralentización)
    velocidadX *= friccion;
    velocidadY *= friccion;

    // 3. Actualizar posición
    double newX = pos().x() + velocidadX;
    double newY = pos().y() + velocidadY;
    setPos(newX, newY);

    // 4. Detener si velocidad es muy pequeña
    double magnitud = std::sqrt(velocidadX * velocidadX + velocidadY * velocidadY);
    if (magnitud < velocidadMinima) {
        velocidadX = 0.0;
        velocidadY = 0.0;
    }

    // 5. Debug - Mostrar en consola cada N frames
    static int contador = 0;
    if (contador++ % 10 == 0) {
        qDebug() << QString("Pelota: pos(%1, %2) vel(%3, %4) mag(%5)")
        .arg(newX, 0, 'f', 1)
            .arg(newY, 0, 'f', 1)
            .arg(velocidadX, 0, 'f', 2)
            .arg(velocidadY, 0, 'f', 2)
            .arg(magnitud, 0, 'f', 2);
    }
}

void Pelota::setVelocidad(double vx, double vy)
{
    velocidadX = vx;
    velocidadY = vy;
    qDebug() << QString("Pelota: velocidad aplicada (%1, %2)").arg(vx).arg(vy);
}

void Pelota::setPosition(double x, double y)
{
    setPos(x, y);
    qDebug() << QString("Pelota: posición establecida (%1, %2)").arg(x).arg(y);
}

QPointF Pelota::obtenerCoordenada() const
{
    return pos();
}

void Pelota::marcarPosicion(const QString& etiqueta)
{
    double x = pos().x();
    double y = pos().y();
    qDebug() << QString("[DEBUG] Pelota en (%1, %2) - %3").arg(x).arg(y).arg(etiqueta);
}