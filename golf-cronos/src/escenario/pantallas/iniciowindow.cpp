#include "iniciowindow.h"
#include "ui_iniciowindow.h"
#include "../../cerebro/gestorbasedatos.h"

#include <QMessageBox>

InicioWindow::InicioWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InicioWindow)
{
    ui->setupUi(this);
    setWindowTitle("Golf En El Paneta Cronos");
    connect(ui->bIniciarSecion,&QPushButton::clicked,this,&InicioWindow::inicarSecion);
}

InicioWindow::~InicioWindow()
{
    delete ui;
}


void InicioWindow::inicarSecion()
{
    // Usamos trimmed() para eliminar espacios accidentales al inicio o al final
    QString usuario = ui->entradaUsuario->text().trimmed();
    QString pin = ui->entradaPin->text().trimmed();

    // 1. Validación de seguridad en la interfaz (Frontend)
    if (usuario.isEmpty() || pin.isEmpty()) {
        QMessageBox::warning(this, "Campos Incompletos", "Por favor, introduce tu Identificador y PIN de Cronos.");
        return;
    }

    // 2. Instanciamos el gestor para interactuar con SQLite (Backend)
    GestorBaseDatos gestorDB;

    // 3. Validamos las credenciales contra la base de datos
    if (gestorDB.validarAcceso(usuario, pin)) {
        QMessageBox::information(this, "Bienvenido", "¡Acceso concedido, " + usuario + "! Preparando el nivel...");

        // --- AQUÍ VA LA LÓGICA PARA CAMBIAR DE PANTALLA ---
        // Ejemplo:
        // VentanaJuego *juego = new VentanaJuego(usuario, this);
        // juego->show();
        // this->hide(); // Ocultamos la ventana de inicio

    } else {
        // Si el usuario no existe o el PIN está mal
        QMessageBox::critical(this, "Error de Acceso", "Identificador o PIN incorrectos. Inténtalo de nuevo.");
        ui->entradaPin->clear(); // Limpiamos el PIN para que lo vuelva a intentar
        ui->entradaPin->setFocus(); // Ponemos el cursor de vuelta en la caja del PIN
    }
}
