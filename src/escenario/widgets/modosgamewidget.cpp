#include "modosgamewidget.h"
#include "ui_modosgamewidget.h"

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
