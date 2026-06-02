#include "iniciowindow.h"
#include "ui_iniciowindow.h"
#include "../../cerebro/gestorbasedatos.h"


// Widgets
#include "../widgets/portadawidget.h"
#include "../widgets/modosgamewidget.h"
#include "../widgets/loginwidget.h"
#include "../widgets/registrarsewidget.h"
#include "../widgets/juegomodunowidget.h"

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
    ModosGameWidget *pantallaModosJuego = new ModosGameWidget(this);
    JuegoModUnoWidget *pantallaJuegoModUno = new JuegoModUnoWidget(this);

    ui->stackedWidget->addWidget(pantallaPortada); // 0
    ui->stackedWidget->addWidget(pantallaLogin);  // 1
    ui->stackedWidget->addWidget(pantallaRegistrarse); // 2
    ui->stackedWidget->addWidget(pantallaModosJuego); // 3


    ui->stackedWidget->addWidget(pantallaJuegoModUno); // -- TODO: Cambiar a carga peresoza

    // Mostramos
    ui->stackedWidget->setCurrentIndex(0);

    connect(pantallaPortada, &PortadaWidget::usuarioOld, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(pantallaPortada, &PortadaWidget::usuarioNew, this, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(pantallaLogin, &LoginWidget::volverAtras, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(pantallaLogin, &LoginWidget::loginExitoso, this, [this]() {
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(pantallaRegistrarse,&RegistrarseWidget::volverAtras,this,[this](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(pantallaRegistrarse,&RegistrarseWidget::registroExitoso,this,[this](){
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(pantallaModosJuego,&ModosGameWidget::sesionCerrada,this,[this](){
        ui->stackedWidget->setCurrentIndex(0);
    });
}

InicioWindow::~InicioWindow()
{
    delete ui;
}
