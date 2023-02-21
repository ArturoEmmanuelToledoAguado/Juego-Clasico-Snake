# Introducción 📖
El siguiente código es un juego basico de Snake 🐍, la mecanica es muy simple, la serpiente consume la fruta y crece un caracter, al llegar a 100 se termina el juego o si la serpiente se muerde a si misma.

# Explicando el código 👾
A continuación explicare lo que considero es más relevante

## Ventana
La verdad es una ventana pequeña, de 119 x 30 pixeles, estas variables se almacenan en:
~~~
VentanaX
Ventana Y
~~~
Uno de los puntos a tomar en cuenta es hacer que el cursor no sea visible, esto se logra con  las lineas de código 36 a la 45, ya que si este se ve en la pantalla puede arruinar la experiencia del jugador

## Flechas
Otro punto que considero importante son los mandos, ya que el juego esta diseñado para un teclado por comodidad yo use los códigos numericos correspondientes a las flechas:
* ⬆ = 80
* ⬇ = 72
* ➡ = 77
* ⬅ = 75

pero si se quiere usar las letras clasicas **(A,S,D,W)** basta con cambiar el código de la línea 116: <code>int dir</code> por <code>char dir</code>

<a href="https://github.com/ArturoEmmanuelToledoAguado/Juego-Clasico-Snake/blob/main/Snake.cpp">Código</a>