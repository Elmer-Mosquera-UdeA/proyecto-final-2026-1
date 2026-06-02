#include "juegomodounowidget.h"


JuegoModoUnoWidget::JuegoModoUnoWidget(QWidget *parent) : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignLeft | Qt::AlignTop);


    escena = new QGraphicsScene(this);
    setScene(escena);

    inicializarNivel();
}

JuegoModoUnoWidget::~JuegoModoUnoWidget()
{

}

void JuegoModoUnoWidget::inicializarNivel()
{

}
