#include "registrarsewidget.h"
#include "ui_registrarsewidget.h"

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
