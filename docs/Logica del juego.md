# Creación de diagrama de clases

Respondamos al las preguntas que van de la mano con las entidades que intervienen en el juego, que propiedades intrínsecas tienes.
## Entidades
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

- 

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



