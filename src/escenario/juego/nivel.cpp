#include "nivel.h"

// Items de jeugo
#include "items/pelota.h"

Nivel::Nivel(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1366, 768);



    QPixmap imagenFondo(":/resources/imgs/fondo_juego_m_u.png");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }


    Pelota *p_golf = new Pelota();
    // p_golf->setPos(500, 400);
    this->addItem(p_golf);

    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, &QTimer::timeout, this, &Nivel::actualizarJuego);

    timerPrincipal->start(16);
}

Nivel::~Nivel()
{
}

void Nivel::actualizarJuego()
{
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