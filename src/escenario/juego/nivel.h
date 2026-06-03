#ifndef NIVEL_H
#define NIVEL_H

#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Pelota;
class Hoyo;
class Obstaculo;
class Portal;

class Nivel : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Nivel(QObject *parent = nullptr);
    ~Nivel();

    void limpiarNivel();
    void cargarNivel1();

    // Función de debug para marcar posiciones
    static void marcarPosicion(QGraphicsScene* escena, double x, double y, const QString& etiqueta = "");

public slots:
    void aplicarFuerzaTiro(const QPointF &origen, const QPointF &vector);

private:
    Pelota *pelota;
    Hoyo *hoyo;

    QList<Obstaculo*> obstaculos;
    QList<Portal*> portales;

    QTimer *timerPrincipal;
    QPixmap fondoEscalado;

    QPointF puntoInicioTiro;

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;

private slots:
    void actualizarJuego();
};

#endif // NIVEL_H
