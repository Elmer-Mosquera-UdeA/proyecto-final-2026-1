#ifndef ELEMENTOJUEGO_H
#define ELEMENTOJUEGO_H
#include  <QString>
#include <QObject>

class ElementoJuego : public QObject
{
    Q_OBJECT
public:
    explicit ElementoJuego(QObject *parent = nullptr);
    virtual void actualizarFisica(qreal dt) = 0;
    virtual void reaccionarAColision(ElementoJuego* otro) = 0;

    void setTipo(const QString& t) { tipo = t; }
    QString getTipo() const { return tipo; }
private:
    QString tipo;

signals:
};

#endif // ELEMENTOJUEGO_H
