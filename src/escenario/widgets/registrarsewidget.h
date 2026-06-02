#ifndef REGISTRARSEWIDGET_H
#define REGISTRARSEWIDGET_H

#include <QWidget>

namespace Ui {
class RegistrarseWidget;
}

class RegistrarseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrarseWidget(QWidget *parent = nullptr);
    ~RegistrarseWidget();

private:
    Ui::RegistrarseWidget *ui;

signals:
    void volverAtras();
    void registroExitoso();

private slots:
    void on_btnRegistrarse_clicked();
    void on_btnVolver_clicked();
};



#endif // REGISTRARSEWIDGET_H
