#ifndef MODOSGAMEWIDGET_H
#define MODOSGAMEWIDGET_H

#include <QWidget>

namespace Ui {
class ModosGameWidget;
}

class ModosGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModosGameWidget(QWidget *parent = nullptr);
    ~ModosGameWidget();

private:
    Ui::ModosGameWidget *ui;

signals:
    void jugarModUno();
    void jugarModoDos();
    void sesionCerrada();

private slots:
    void on_btn_exitAth_clicked();
    void on_btn_modoU_clicked();
    void on_btn_modoD_clicked();
};

#endif // MODOSGAMEWIDGET_H
