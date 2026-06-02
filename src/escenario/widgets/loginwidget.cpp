#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

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

void LoginWidget::on_btnVolver_clicked()
{
    emit volverAtras();
}



void LoginWidget::on_btnIngresar_clicked()
{

    bool exito = GestorBaseDatos::conectarBD();


    if (!exito) {
        qDebug() << "ERROR: Falló la conexión a la base de datos en GestorBaseDatos::conectarBD()";
    }

    QString usuario = ui->txtUsuario->text();
    QString clave = ui->txtPin->text();

    if (usuario == "" or clave == ""){
        QMessageBox::critical(this,"Error","No se pueden dejar los campos en blanco");
        return;
    }

    if (GestorBaseDatos::validarAcceso(usuario, clave)) {
        emit loginExitoso();
    } else {
        QMessageBox::critical(this, "Error", "Clave o usuario incorrecto");
    }
}
