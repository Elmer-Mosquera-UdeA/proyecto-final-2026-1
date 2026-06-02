# Creación de diagrama de clases

Respondamos al las preguntas que van de la mano con las entidades que intervienen en el juego, que propiedades intrínsecas tienes.
## Entidades

### ElementoJuego

Esta clase es de la que parten todos los elementos de jugabilidad contiene las propiedades en comun de todos los elementos.

Debido a que algunos elementos poseen un área de colisión irregular se mantiene **bounding Box** para una detección preliminar rápida, hay que recalcar que aprovecharemos los elementos propios de **framework QT** para gestionar las colisiones y no diseñaremos un sistema de colisiones basado en estados. La documentación del del proyecto recibirá actualizaciones frecuentes recurrentes que pueden verse en  **formalizacion**. Además, se formaliza un diagrama de clases  que no esta enfocado en el motor físico sino en las entidades propias del juego.

Mas detalle en [Documentacion Formalizada](formalizacion/index)
### Pelota

- Representa el objeto principal del juego que debe llegar al hoyo.
- Puede moverse por el escenario aplicando las físicas del juego.
- Puede colisionar con obstáculos y superficies especiales.
- Puede atravesar portales gravitacionales.
- Almacena su posición, velocidad y estado especial actual.
### Chronoa

- Personaje controlado por el jugador.
- Puede golpear la pelota.
- Puede activar habilidades especiales.
- Mantiene la puntuación y las vidas disponibles.
### Obstáculo

- Elemento que dificulta el avance de la pelota.
- Puede ser fijo o móvil.
- Puede modificar la dirección o velocidad de la pelota tras una colisión.
### Portal Gravitacional

- Conecta dos puntos del escenario.
- Puede transportar la pelota entre ellos.
- Puede alterar o conservar la trayectoria de salida.
### Superficie Especial

- Modifica el comportamiento físico de la pelota.
- Puede alterar la fricción, el rebote o la aceleración.
### Nivel

- Representa un escenario jugable.
- Contiene obstáculos, portales y superficies.
- Verifica las condiciones de victoria o derrota.

## Agente


## Impulsor gravitatorio



### Creación de base de datos

El análisis e identificación de los datos que actúan sobre el juego, datos que pueden guardarse para que la información.

Jugador:
- Usuario
- pin
- vidas
- puntuación total

Partido
- id progreso
- id nivel
- golpes realizados
- Mejor tiempo
- estrellas
- usuario

> [!NOTA]
> Con el fin de que el juego no se reinicie en cada sección, se implementa una base de datos sqlite simple para almacenar.



