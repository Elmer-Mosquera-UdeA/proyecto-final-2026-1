#ifndef JUEGOMODODOSQGRAPHICSVIEW_H
#define JUEGOMODODOSQGRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QPixmap>
#include <QPainter>

class JuegoModoDosQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JuegoModoDosQGraphicsView(QWidget *parent = nullptr);
    ~JuegoModoDosQGraphicsView();

private:
    int nivelActual = 0;
    QGraphicsScene *escena;
    QPixmap fondoEscalado;
    void inicializarNivel();

protected:

    void drawBackground(QPainter *painter, const QRectF &rect) override;

};

#endif // JUEGOMODODOSQGRAPHICSVIEW_H
