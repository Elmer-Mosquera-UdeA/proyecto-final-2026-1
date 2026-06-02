#ifndef PORTADAWIDGET_H
#define PORTADAWIDGET_H

#include <QWidget>

namespace Ui {
class PortadaWidget;
}

class PortadaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PortadaWidget(QWidget *parent = nullptr);
    ~PortadaWidget();

private:
    Ui::PortadaWidget *ui;

signals:
    void usuarioOld();
    void usuarioNew();

private slots:
    void on_btn_toLogin_clicked();
    void on_btn_toRegistrarse_clicked();
};

#endif // PORTADAWIDGET_H
