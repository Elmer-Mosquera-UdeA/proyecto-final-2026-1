#include "nivel.h"

Nivel::Nivel(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1366, 768);

    timerPrincipal = new QTimer(this);

    QPixmap imagenFondo(":/resources/imgs/fondo_juego_m_u.png");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    connect(timerPrincipal, &QTimer::timeout, this, &Nivel::actualizarJuego);

    timerPrincipal->start(16);
}

Nivel::~Nivel()
{
}

void Nivel::actualizarJuego()
{
    // Aqui irá la lógica principal del juego
}

void Nivel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // lógica clic
    QGraphicsScene::mousePressEvent(event);
}

void Nivel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // lógica arrastre
    QGraphicsScene::mouseMoveEvent(event);
}

void Nivel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // lógica soltar

    QGraphicsScene::mouseReleaseEvent(event);
}

void Nivel::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    painter->drawPixmap(sceneRect().toRect(),fondoEscalado);
}