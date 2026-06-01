#include "juegomodunowidget.h"
#include "ui_juegomodunowidget.h"

JuegoModUnoWidget::JuegoModUnoWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JuegoModUnoWidget)
{
    ui->setupUi(this);
}

JuegoModUnoWidget::~JuegoModUnoWidget()
{
    delete ui;
}
