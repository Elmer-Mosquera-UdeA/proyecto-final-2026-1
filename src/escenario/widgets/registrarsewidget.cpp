#include "registrarsewidget.h"
#include "ui_registrarsewidget.h"
#include <QMessageBox>

#include "../../cerebro/gestorbasedatos.h"

RegistrarseWidget::RegistrarseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegistrarseWidget)
{
    ui->setupUi(this);
}

RegistrarseWidget::~RegistrarseWidget()
{
    delete ui;
}

void RegistrarseWidget::on_btnVolver_clicked()
{
    emit volverAtras();
}


void RegistrarseWidget::on_btnRegistrarse_clicked()
{

    bool exito = GestorBaseDatos::conectarBD();

    if (!exito) {
        qDebug() << "ERROR: Falló la conexión a la base de datos en GestorBaseDatos::conectarBD()";
    }

    QString usuario = ui->txtUsuario->text();
    QString clave = ui->txtPin->text();

    if (GestorBaseDatos::registrarJugador(usuario, clave)) {
        emit registroExitoso();
    } else {
        QMessageBox::critical(this, "Error", "No se puede registrar usuario");
    }
}
