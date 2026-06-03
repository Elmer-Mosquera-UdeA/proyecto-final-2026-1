#include "nivel.h"

//Items
#include "items/pelota.h"
#include "items/portal.h"
#include "items/obstaculo.h"

// Procesamiento datos
#include <QtMath>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>

Nivel::Nivel(QObject *parent)
    : QGraphicsScene(parent), pelota(nullptr), hoyo(nullptr)
{
    setSceneRect(0, 0, 1366, 768);

    QPixmap imagenFondo(":/resources/imgs/fondo_juego_m_u.png");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, &QTimer::timeout, this, &Nivel::actualizarJuego);

    timerPrincipal->start(16);  // ~60 FPS
}

Nivel::~Nivel()
{
    // Qt gestiona la memoria automáticamente
}

void Nivel::limpiarNivel()
{
    clear();
    pelota = nullptr;
    hoyo = nullptr;
    obstaculos.clear();
    portales.clear();
}

void Nivel::cargarNivel1()
{
    limpiarNivel();

    // Crear pelota
    pelota = new Pelota();
    pelota->setPosition(683, 600);  // Centro inferior de la escena
    addItem(pelota);

    // Debug: marcar posición inicial
    marcarPosicion(this, 683, 600, "Pelota Inicial");

    qDebug() << "[Nivel] Nivel 1 cargado - Pelota creada en (683, 600)";
}

void Nivel::aplicarFuerzaTiro(const QPointF &origen, const QPointF &vector)
{
    if (!pelota) return;

    // Calcular parámetros del tiro
    double magnitud = qSqrt(vector.x() * vector.x() + vector.y() * vector.y());
    double anguloRadianes = qAtan2(vector.y(), vector.x());
    double anguloGrados = qRadiansToDegrees(anguloRadianes);

    qDebug() << QString("[Tiro] Origen: (%1, %2) | Vector: (%3, %4) | Magnitud: %5 | Ángulo: %6°")
                    .arg(origen.x(), 0, 'f', 1)
                    .arg(origen.y(), 0, 'f', 1)
                    .arg(vector.x(), 0, 'f', 1)
                    .arg(vector.y(), 0, 'f', 1)
                    .arg(magnitud, 0, 'f', 1)
                    .arg(anguloGrados, 0, 'f', 1);

    // Aplicar velocidad a la pelota
    pelota->setVelocidad(vector.x(), vector.y());
}

void Nivel::actualizarJuego()
{
    // Actualizar física de la pelota
    if (pelota) {
        pelota->actualizarFisica(0.016);  // deltaTime de ~60 FPS
    }
}

void Nivel::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    if (!fondoEscalado.isNull()) {
        painter->drawPixmap(0, 0, fondoEscalado);
    } else {
        painter->fillRect(sceneRect(), Qt::gray);
    }
}

void Nivel::marcarPosicion(QGraphicsScene* escena, double x, double y, const QString& etiqueta)
{
    if (!escena) return;

    // Crear círculo marcador
    QGraphicsEllipseItem* circulo = escena->addEllipse(
        x - 5, y - 5, 10, 10,
        QPen(QColor(255, 0, 0), 2),
        QBrush(QColor(255, 0, 0))
        );
    circulo->setZValue(1000);

    // Crear etiqueta
    if (!etiqueta.isEmpty()) {
        QGraphicsTextItem* texto = escena->addText(etiqueta);
        texto->setPos(x + 10, y - 5);
        texto->setDefaultTextColor(QColor(255, 0, 0));
        QFont fuente;
        fuente.setPointSize(8);
        texto->setFont(fuente);
        texto->setZValue(1001);
    }

    qDebug() << QString("[Marcador] (%1, %2) - %3").arg(x).arg(y).arg(etiqueta);
}