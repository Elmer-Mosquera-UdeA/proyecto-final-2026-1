#include "modosgamewidget.h"
#include "ui_modosgamewidget.h"

#include "../../cerebro/gestorbasedatos.h"

ModosGameWidget::ModosGameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModosGameWidget)
{
    ui->setupUi(this);
}

ModosGameWidget::~ModosGameWidget()
{
    delete ui;
}

void ModosGameWidget::on_btn_exitAth_clicked()
{
    bool exito = GestorBaseDatos::conectarBD();

    if (!exito) {
        qDebug() << "ERROR: Falló la conexión a la base de datos en GestorBaseDatos::conectarBD()";
    }

    GestorBaseDatos::exitAuth();

    emit sesionCerrada();
}
