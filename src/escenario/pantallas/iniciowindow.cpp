#include "iniciowindow.h"
#include "ui_iniciowindow.h"
// #include "../../cerebro/gestorbasedatos.h"


// Widgets
#include "../widgets/portadawidget.h"
#include "../widgets/modosgamewidget.h"
#include "../widgets/loginwidget.h"
#include "../widgets/registrarsewidget.h"
#include "../modos_juego//juegomodounowidget.h"

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


    ui->stackedWidget->addWidget(pantallaPortada); // 0
    ui->stackedWidget->addWidget(pantallaLogin);  // 1
    ui->stackedWidget->addWidget(pantallaRegistrarse); // 2
    ui->stackedWidget->addWidget(pantallaModosJuego); // 3




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

    connect(pantallaModosJuego,&ModosGameWidget::jugarModUno,this,[this]() {
        // 1. Crear el objeto bajo demanda
        JuegoModoUnoWidget *pantallaJuegoModUno = new JuegoModoUnoWidget(this);

        // Indicar a Qt que libere la memoria RAM cuando el objeto se cierre o destruya
        pantallaJuegoModUno->setAttribute(Qt::WA_DeleteOnClose);

        // 3. Añadir y mostrar
        ui->stackedWidget->addWidget(pantallaJuegoModUno);
        ui->stackedWidget->setCurrentWidget(pantallaJuegoModUno);
    });
}

InicioWindow::~InicioWindow()
{
    delete ui;
}
