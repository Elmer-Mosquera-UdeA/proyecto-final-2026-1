#include "juegomodounoqgraphicsview.h"
#include <QGraphicsPixmapItem>
#include <QDebug>

JuegoModoUnoQGraphicsView::JuegoModoUnoQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignCenter);

    setStyleSheet("background-color: black; border: none; margin: 0px; padding: 0px;");
    setMouseTracking(true);

    escena = new QGraphicsScene(0, 0, 1366, 768, this);
    setScene(escena);

    nivelActual = 1;
    isLeftClickPressed = false;

    inicializarNivel();
}

JuegoModoUnoQGraphicsView::~JuegoModoUnoQGraphicsView()
{
}

void JuegoModoUnoQGraphicsView::inicializarNivel()
{
    escena->clear();

    QPixmap imagenFondo(":/resources/imgs/fondo_juego_m_u.png");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    // 2. Control de lógica por nivel
    if (nivelActual == 1) {
        // crearNivel1();
    } else if (nivelActual == 2) {
        // crearNivel2();
    }

    escena->update();
    qDebug() << "Avanzando al Nivel:" << nivelActual << "sobre el mismo fondo fijo de 1366x768.";
}


void JuegoModoUnoQGraphicsView::drawBackground(QPainter *painter, const QRectF & /* sin nombre */)
{
    painter->fillRect(0, 0, 1366, 768, Qt::black);

    if (!fondoEscalado.isNull()) {
        painter->drawPixmap(0, 0, fondoEscalado);
    }
}

// LOGICA DE CAPTURA DEL CLIC SOSTENIDO (Aprovecha todo el ancho)
void JuegoModoUnoQGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isLeftClickPressed = true;
        QPointF posEnJuego = mapToScene(event->pos());
        qDebug() << "¡CLIC FUNCIONANDO EN UI! X:" << posEnJuego.x();
    }
    // CRUCIAL: Si quitas esta línea de abajo, el clic se bloquea
    QGraphicsView::mousePressEvent(event);
}

void JuegoModoUnoQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (isLeftClickPressed) {
        QPointF posEnJuego = mapToScene(event->pos());

        // AQUÍ INSERTA TU JUEGO: posEnJuego.x() y posEnJuego.y() te darán el arrastre continuo
        qDebug() << "Arrastrando en:" << posEnJuego.x() << "," << posEnJuego.y();
    }
    QGraphicsView::mouseMoveEvent(event);
}

void JuegoModoUnoQGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isLeftClickPressed = false;
        qDebug() << "Clic soltado";
    }
    QGraphicsView::mouseReleaseEvent(event);
}

