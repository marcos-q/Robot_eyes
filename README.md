# Robot_eyes

Este proyecto permite crear expresiones faciales usando dos matrices de leds 8x8 y el driver MAX7219.
Yo he usado un Arduino Nano como controlador, ya que puede ocultarse fàcilmente en el montaje, pero cualquier otro sirve.

La idea está tomada de un proyecto de Steve Quinn que podéis encontrar en https://www.instructables.com/id/Animated-Halloween-Evil-Eyes/ .

Sobre su código, he añadido algunos fotogramas, y los he combinado en diferentes movimientos oculares. Para falicitar el uso, he definido una función para cada movimiento básico. En cada función se crea una variable que contiene los fotogramas a utilizar y los envía a la matriz de leds.

En el bucle principal (void Loop()), se reproduce una primera secuencia de movientos, para mostrar las posibilidades. A continuación los movimientos de ojos se van sucediendo de forma aleatoria. Cada movimiento tiene una probabilidad de aparición determinada. Así se consigue que unos gestos aparezcan más frecuentemente que otros.

El código se podría mejorar añadiendo más expresiones, encapsulando en envío de datos al MAX7219 en una función y puliendo algún que otro detalle.


