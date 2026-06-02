#ifndef JUEGOMODOUNOWIDGET_H
#define JUEGOMODOUNOWIDGET_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class JuegoModoUnoWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JuegoModoUnoWidget(QWidget *parent = nullptr);
    ~JuegoModoUnoWidget();

private:
    QGraphicsScene *escena;

    void inicializarNivel();
};

#endif // JUEGOMODOUNOWIDGET_H
