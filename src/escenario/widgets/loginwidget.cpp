#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QString>
#include <QMessageBox>

#include "../../cerebro/gestorbasedatos.h"


LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_btnIngresar_clicked()
{
    QString usuario = ui->txtUsuario->text();
    QString clave = ui->txtPin->text();

    if (GestorBaseDatos::validarAcceso(usuario, clave)) {
        emit loginExitoso();
    } else {
        QMessageBox::critical(this, "Error", "Clave o usuario incorrecto");
    }
}
