
1. Descripción General

Se ha creado e integrado el módulo correspondiente al **Nivel 2 (Modo de Juego Dos)** dentro de la arquitectura principal de la aplicación. Este nivel se maneja como una vista independiente que se inserta de forma dinámica dentro del contenedor de pantallas global (`QStackedWidget`) gestionado por la ventana principal (`InicioWindow`).

2. Estructura de Archivos Creados

Para mantener el patrón de diseño y la separación de conceptos (interfaz y lógica), se implementó la clase `JuegoModDosWidget` mediante tres archivos esenciales:

- **`juegomoddoswidget.h` (Cabecera):** Define la interfaz de la clase, las variables miembro, los métodos privados/públicos, y declara las señales (`signals`) que emitirá el componente (por ejemplo, `volverAtras`).
- **`juegomoddoswidget.cpp` (Implementación):** Contiene la lógica interna del nivel, el comportamiento de las físicas, el manejo de eventos y el renderizado (pintado) de elementos en pantalla.
- **`juegomoddoswidget.ui` (Diseño Visual):** Archivo XML administrado por _Qt Designer_ que define la disposición espacial de los elementos gráficos (botones, etiquetas, contenedores) de este nivel.

3. Integración y Flujo de Navegación (`iniciowindow.cpp`)

La comunicación y el ciclo de vida del Nivel 2 se gestionan desde la clase contenedora `InicioWindow`. El proceso de acoplamiento se divide en las siguientes etapas:

A. Inclusión del Componente

Se enlaza la cabecera del widget para que la ventana principal reconozca la nueva clase y sus propiedades:

 cpp

```
#include "../widgets/juegomoddoswidget.h"
```


B. Instanciación e Inyección en el Contenedor

Se crea el objeto en memoria asignando a `InicioWindow` como su entorno padre (`this`) para asegurar una correcta gestión de memoria, y se añade al gestor de pantallas indexado:

cpp

```
// Instanciación del widget del nivel 2
JuegoModDosWidget *pantallaJuegoModDos = new JuegoModDosWidget(this);

// Inyección del widget en el QStackedWidget general
ui->stackedWidget->addWidget(pantallaJuegoModDos); 
```


C. Mecanismo de Comunicación (Signals and Slots)

Para evitar el acoplamiento fuerte entre pantallas, se utiliza el sistema de **Señales y Ranuras de Qt**. El widget del nivel no cambia la pantalla por sí mismo; en su lugar, notifica a la ventana principal mediante una señal, y esta reacciona modificando el índice visual:

cpp

```
// Conexión para el retorno a la pantalla principal mediante una función Lambda
connect(pantallaJuegoModDos, &JuegoModDosWidget::volverAtras, this, [this]() {
    ui->stackedWidget->setCurrentIndex(0); // Cambia al índice de la pantalla de inicio
});
```