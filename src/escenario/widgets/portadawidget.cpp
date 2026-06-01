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
