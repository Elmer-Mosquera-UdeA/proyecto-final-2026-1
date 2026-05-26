#include "inicio/iniciowindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/resources/icons/lab.ico"));

    InicioWindow w;
    w.show();
    return app.exec();
}
