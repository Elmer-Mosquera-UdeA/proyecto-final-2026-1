#include "pelota.h"
#include <QPixmap>

Pelota::Pelota()
{
    QPixmap imagen(":/resources/imgs/pelota-golf.png");


    setPixmap(imagen.scaled( 32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation ));
    // setPixmap(imagen);
}