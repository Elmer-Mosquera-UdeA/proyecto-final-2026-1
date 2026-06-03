#include "juegomodounoqgraphicsview.h"
#include "../juego/nivel.h"

JuegoModoUnoQGraphicsView::JuegoModoUnoQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    nivelActual = new Nivel(this);

    setScene(nivelActual);

    setRenderHint(QPainter::Antialiasing);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignCenter);
}

// Destructor
JuegoModoUnoQGraphicsView::~JuegoModoUnoQGraphicsView(){}

