#include "portadawidget.h"
#include "ui_portadawidget.h"

PortadaWidget::PortadaWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PortadaWidget)
{
    ui->setupUi(this);
}

PortadaWidget::~PortadaWidget()
{
    delete ui;
}

void PortadaWidget::on_btn_toLogin_clicked()
{
    emit usuarioOld();
}

void PortadaWidget::on_btn_toRegistrarse_clicked()
{
    emit usuarioNew();
}
