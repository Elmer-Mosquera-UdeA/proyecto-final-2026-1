#include "iniciowindow.h"
#include "ui_iniciowindow.h"
#include "../../cerebro/gestorbasedatos.h"


// Widgets
#include "../widgets/loginwidget.h"
#include "../widgets/registrarsewidget.h"
#include "../widgets/portadawidget.h"
#include "../widgets/juegomodunowidget.h"
#include "../widgets/juegomoddoswidget.h"

InicioWindow::InicioWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InicioWindow)
{
    ui->setupUi(this);
    setWindowTitle("Golf En El Paneta Cronos");


    // Widgets

    // Se crean
    PortadaWidget *pantallaPortada = new PortadaWidget(this);
    LoginWidget *pantallaLogin = new LoginWidget(this);
    RegistrarseWidget *pantallaRegistrarse = new RegistrarseWidget(this);
    JuegoModUnoWidget *pantallaJuegoModUno = new JuegoModUnoWidget(this);
    JuegoModDosWidget *pantallaJuegoModDos = new JuegoModDosWidget(this);

    // Se agregan
    ui->stackedWidget->addWidget(pantallaPortada); // 0
    ui->stackedWidget->addWidget(pantallaLogin);  // 1
    ui->stackedWidget->addWidget(pantallaRegistrarse); // 2
    ui->stackedWidget->addWidget(pantallaJuegoModUno); // 3
    ui->stackedWidget->addWidget(pantallaJuegoModDos); // 4

    // Mostramos
    ui->stackedWidget->setCurrentIndex(2);

    // Conectado signals con comportamientos

    connect(pantallaLogin, &LoginWidget::loginExitoso, this, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });


    connect(pantallaRegistrarse,&RegistrarseWidget::volverAtras,this,[this](){
        // Comportamientos aqui
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(pantallaJuegoModDos, &JuegoModDosWidget::volverAtras, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
}

InicioWindow::~InicioWindow()
{
    delete ui;
}
