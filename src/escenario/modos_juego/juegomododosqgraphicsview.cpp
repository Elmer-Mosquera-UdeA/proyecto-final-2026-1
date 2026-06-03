#include "juegomododosqgraphicsview.h"
#include <QGraphicsPixmapItem>

JuegoModoDosQGraphicsView::JuegoModoDosQGraphicsView(QWidget *parent)  : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignCenter);

    setStyleSheet("background-color: black; border: none; margin: 0px; padding: 0px;");
    setMouseTracking(true);

    escena = new QGraphicsScene(0, 0, 1366, 768, this);
    setScene(escena);

    nivelActual = 1;

    inicializarNivel();
}


// Destructor
JuegoModoDosQGraphicsView::~JuegoModoDosQGraphicsView() {}

void JuegoModoDosQGraphicsView::inicializarNivel()
{
    escena->clear();

    QPixmap imagenFondo(":/resources/imgs/fondo_juego_m_u.png");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    if (nivelActual == 1) {
        // crearNivel1();
    } else if (nivelActual == 2) {
        // crearNivel2();
    }

    escena->update();
}

void JuegoModoDosQGraphicsView::drawBackground(QPainter *painter, const QRectF & /* sin nombre */)
{
    painter->fillRect(0, 0, 1366, 768, Qt::black);

    if (!fondoEscalado.isNull()) {
        painter->drawPixmap(0, 0, fondoEscalado);
    }
}
