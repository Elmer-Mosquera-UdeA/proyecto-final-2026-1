#ifndef JUEGOMODOUNOQGRAPHICSVIEW_H
#define JUEGOMODOUNOQGRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>

class JuegoModoUnoQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JuegoModoUnoQGraphicsView(QWidget *parent = nullptr);
    ~JuegoModoUnoQGraphicsView();

private:
    int nivelActual;
    bool isLeftClickPressed;

    QGraphicsScene *escena;
    QPixmap fondoEscalado;

    void inicializarNivel();

protected:

    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif

