#ifndef INICIOWINDOW_H
#define INICIOWINDOW_H

#include <QMainWindow>

namespace Ui {
class InicioWindow;
}

class InicioWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InicioWindow(QWidget *parent = nullptr);
    ~InicioWindow();

    // Metodos personalizados
    void inicarSecion();

private:
    Ui::InicioWindow *ui;
};

#endif // INICIOWINDOW_H
