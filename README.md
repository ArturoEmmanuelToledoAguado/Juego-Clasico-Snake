# Introducci贸n 馃摉
El siguiente c贸digo es un juego basico de Snake 馃悕, la mecanica es muy simple, la serpiente consume la fruta y crece un caracter, al llegar a 100 se termina el juego o si la serpiente se muerde a si misma.

# Explicando el c贸digo 馃懢
A continuaci贸n explicare lo que considero es m谩s relevante

## Ventana
La verdad es una ventana peque帽a, de 119 x 30 pixeles, estas variables se almacenan en:
~~~
VentanaX
Ventana Y
~~~
Uno de los puntos a tomar en cuenta es hacer que el cursor no sea visible, esto se logra con  las lineas de c贸digo 36 a la 45, ya que si este se ve en la pantalla puede arruinar la experiencia del jugador

## Flechas
Otro punto que considero importante son los mandos, ya que el juego esta dise帽ado para un teclado por comodidad yo use los c贸digos numericos correspondientes a las flechas:
* 猬? = 80
* 猬? = 72
* 鉃? = 77
* 猬? = 75

pero si se quiere usar las letras clasicas **(A,S,D,W)** basta con cambiar el c贸digo de la l铆nea 116: <code>int dir</code> por <code>char dir</code>

<a href="https://github.com/ArturoEmmanuelToledoAguado/Juego-Clasico-Snake/blob/main/Snake.cpp">C贸digo</a>