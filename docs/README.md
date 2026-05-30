<p align="center">
  <img src="docs/img/Escudo-UdeA.svg" width="150">
</p>

# Golf en el universo del planeta Cronos

Proyecto para la asignatura de Informática (Universidad de Antioquia). El objetivo es desarrollar un videojuego sencillo usando C++ y Qt, adecuado al nivel del curso y pensado para trabajo en equipo.

## Objetivo

Crear una versión jugable y documentada de un mini-golf ambientado en el planeta Cronos, que permita practicar conceptos de programación en C++ y uso básico de Qt para la interfaz.

## Temáticas necesarias para el desarrollo

1. C++ básico: tipos de datos, variables, operadores, entradas/salidas y estructuras de control (if, for, while).
2. Arreglos y funciones: manejo de colecciones estáticas (arrays), creación y uso de funciones para modularizar el código; conceptos básicos de gestión de memoria.
3. Programación orientada a objetos (POO): clases, atributos, métodos y uso simple de encapsulación y composición.
4. Qt básico: creación de ventanas, widgets, y manejo de señales y slots para la interacción con el usuario.

> [!NOTE]
> En este punto hay que realizar algo de investigacion hacerca de como hacer aquello, y que otras tematicas necesitamos para desarrallar esta actividad

## Características esperadas del juego

- Mecánicas de interaccion bola con el entorno.
- 2 Niveles o escenarios con obstáculos básicos.
- Interfaz mínima con score/contador de golpes y opción de reiniciar nivel.
- Código modular y documentado para evaluar conceptos vistos en clase.

> [!NOTE]
> En la seccion `docs/` se agregara una documentacion mas detallada de las partes desarrolladas, deberias darle un vistaso.

## Tecnologías y herramientas

- Lenguaje: C++ (estándar mínimo recomendado: C++11).
- Framework/UI: Qt (versión recomendada: Qt 5.x o superior).
- Sistema de compilación: qmake o CMake.
- IDE sugerido: Qt Creator (opcional: Visual Studio / CLion).

> [!WARNING]
> Las tecnologias y herramientas en este stack tecnologico son resultado de investigacion simple, sin embargo en las etapas actuales no se ha probado funcionamiento con esandar de c++ inferiores al altual predeterminado en QT, version de QT, sistema de compilacion y IDEs opcionales, se dejan aqui por la credibilidad en los resultados de investigacion.

## Instalación y ejecución

1. Instalar Qt y un compilador C++ compatible (g++, clang o MSVC según SO).
2. Clonar el repositorio: git clone https://github.com/Elmer-Mosquera-UdeA/proyecto-final-2026-1
3. Abrir el proyecto en Qt Creator o generar archivos de construcción con CMake/qmake.
4. Construir y ejecutar desde el IDE o con las herramientas de línea de comandos.

## Estructura del repositorio (pendiente)

> [!TIP]
> Para la estructura actual se uso el comando `tree`, es muy util puedes revisar la documentacion [AQUI](https://learn.microsoft.com/es-es/windows-server/administration/windows-commands/tree)

```

\proyecto-final-2026-1
│   README.md
│
├───docs
│   └───img
│          Escudo-UdeA.svg
│
└───momento-1
        momento-uno.md

```

> [!NOTE]
> Usaremos la predeterminada al crear el proyecto en QT Creator (desconocida actualmente).

## Buenas prácticas y trabajo en equipo

- Usar control de versiones: ramas por funcionalidad y Pull Requests para integrar cambios.
- Documentar funciones y clases con comentarios claros.
- Mantener commits pequeños y con mensajes descriptivos.
- Coordinar tareas y dividir el trabajo (programación, diseño de niveles, pruebas, documentación).

> [!TIP]
> Esta seccion reune algunas recomendaciones que intentaremos ir aplicando como equipo y de la que se deja bajo la consideracion de filosofia de trabajo en equipo, **aplicar buenas practicas desde el principio para no tener que desaprender luego**.

## Flujo de trabajo

1. Crear una rama feature/nombre-descriptivo.
2. Hacer commits frecuentes y limpiar el código antes del PR.
3. Abrir Pull Request describiendo cambios y pruebas realizadas.
4. Revisar y corregir comentarios de revisión antes de mergear.

## Colaboradores

- Colaborador 1: Claudia Nataly Orozco Ocampo
- Colaborador 2: Elmer David Mosquera Martinez

## Licencia y créditos (no definida)
