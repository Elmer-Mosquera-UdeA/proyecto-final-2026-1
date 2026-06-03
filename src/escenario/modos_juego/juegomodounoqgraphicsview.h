#ifndef JUEGOMODOUNOQGRAPHICSVIEW_H
#define JUEGOMODOUNOQGRAPHICSVIEW_H

#include <QGraphicsView>

class Nivel;

class JuegoModoUnoQGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit JuegoModoUnoQGraphicsView(QWidget *parent = nullptr);

    ~JuegoModoUnoQGraphicsView();

private:
    Nivel *nivelActual;
};

#endif

