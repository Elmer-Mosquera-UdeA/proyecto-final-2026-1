
Para la creación de la vistas optamos por multiples fichero **.ui** y **StackedWidget** para las ventanas.

A la fecha se tiene 1 única clase con la plantilla de **MainWindow**, las demás interfaces estáticas excepto las de juego son widgets, siendo la excepción el modo de juego 1 que es un **GraphicsView**, este hereda de **widgets** por lo tanto la logica de añadir **widgets** a StackedWidget se mantiene intacta.

## Carga de lazzy

Las **GraphicsView** de juegos, son gestionadas con carga perezosa mediante señales, se conecta el llamado a la interfaz o cambio de widgets en stackedwidget con su creación la del GraphicsView que contiene el modo de juego respectivo, y si la vista cambia, caso en que dejamos salimos del modo 1, se gestiona su eliminación para que no consuma recursos en segundo plano.

