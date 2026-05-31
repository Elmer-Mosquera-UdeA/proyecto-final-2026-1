El proyecto final UdeA - Informática 2 2026-1: es un **producto** cuyo proceso de creación tiene unos requisitos, que deben cumplirse además de algunos requisitos que también abordan, el tiempo de desarrollo, la presentación y el contenido del producto.
## Primeras condiciones de desarrollo.

1. **El producto** es un **video juego sencillo**, énfasis en ==sencillo==.
2. La temática: juego deportivo en un universo especial.
3. Tener 2 niveles o modos de juego, estos parten de la misma base pero con vistas y dinámicas distintas.
4. Definir al menos tres físicas diferentes para implementar el movimiento de los objetos en pantalla.

> En respuesta a ambos requisitos tenernos el siguiente planteamiento.
# CRONO GOLF

El personaje principal **Chronoa** es una jugadora de golf, un mundo mundo casi destruido donde el tiempo se detuvo y quedaron muchas cosa flotando en el espacio, algunas atrapadas es un bucle temporal. La tecnología que hizo posible detener el tiempo fue ampliada y hoy es ampliamente utilizada en los deportes. **Chronoa** nuestra personaje 

## Modos de Juegos
### 1. Plataformero con vista fija y scroll lateral finito

El mapa esta definido desde un principio; pero se mostrará secciones escenarios a superar con transiciones laterales en la medida de que hagan emboques.

En este modo el **Chronoa** se mantiene flotando sobre una isla.

![vista del personaje en una isla flotante](../img/guia-visual/pesonaje-montado-en-nube.png)

El objetivo es aprovechar las propiedades del mapa para eludir obstáculos y  embocar la pelota. Los elementos en el mapa hacen de este juego uno basado en estrategia y técnica,.

- Lanzar la pelota con la potencia y el ángulo adecuado.
- Aprovechar las habilidades especiales de las que dispone el jugador por partida.

> Usar elementos de jugabilidad para determinar trayectoria de la pelota aprovechando la gravedad, la fricción y el rebote.

### 2 SIN DEFINIR

## Físicas

1. **Oscilador Armónico Simple:** Algunos objetos quedaron atrapados en pequeños bucles temporales, por lo que se mueven repetidamente entre dos posiciones. Esta física se utilizará para plataformas móviles y obstáculos.

2. **Movimiento Parabólico:** La pelota sigue una trayectoria parabólica determinada por el ángulo y la potencia del golpe. Esta será la principal física utilizada durante el juego.

3. **Alteración del Coeficiente de Restitución:** Algunas superficies fueron afectadas por experimentos temporales y presentan comportamientos inusuales al impactar la pelota, provocando rebotes más fuertes o más débiles de lo esperado.

**CRONO GOLF** NIVEL 2

El personaje principal Chronoa se adentra ahora en la superficie inestable de Cronos, donde el tiempo corre en su contra y el entorno es controlado dinámicamente por un Agente IA. La tecnología temporal de sus habilidades será vital para evitar que el campo colapse antes de cumplir su objetivo.

![[Pasted image 20260531031117.png]]

**Modos de Juegos**

**2. Laberinto Temporal con vista cenital (top-down)**

El mapa es un intrincado laberinto en la superficie del planeta, mostrando el escenario completamente desde arriba (distinto al scroll lateral). En este modo, el núcleo del planeta actúa como el centro del nivel, pulsando e interfiriendo constantemente con la gravedad.

El objetivo es aprovechar las propiedades del mapa y las habilidades de Chronoa para eludir las grietas temporales del Agente IA y embocar la pelota antes de que el temporizador (45 segundos) provoque el colapso del nivel. Los elementos dinámicos hacen de este juego uno basado en la reacción rápida y la planificación espacial.

- Lanzar la pelota calculando el empuje rítmico del escenario y sorteando los bloqueos.
    
- Aprovechar las habilidades especiales del nivel: `isPesada` (mayor inercia para resistir las anomalías) e `isCrononauta` (detener el reloj y congelar al Agente IA por 5 segundos).
    
- Usar elementos de jugabilidad para determinar la trayectoria de la pelota aprovechando la nueva vista cenital, la física oscilatoria y los drásticos cambios de fricción en el suelo.
    

**Físicas**

- **Fuerza Oscilatoria:** El núcleo del planeta emite pulsos periódicos de gravedad ($F = A\cdot\sin(\omega t + \phi)$). Esta física empuja rítmicamente la pelota hacia los lados mientras rueda, obligando a calcular el momento exacto del golpe.
    
- **Fricción Dinámica:** El suelo está afectado por anomalías y presenta zonas de distintos materiales que alteran bruscamente el desplazamiento: roca normal, hielo crónico (superficies altamente deslizantes) y lava solidificada (frenado inmediato).
### Diagrama de clases
