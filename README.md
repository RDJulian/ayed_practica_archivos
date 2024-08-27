# AYED: Práctica de Archivos

Andy necesita tener registro de todas las partidas de Tateti que se juegan, por lo que les pidió a los alumnos de AYED
que planteen una forma de persistir las partidas, para luego poder consultarlas. En este sentido:

1. Plantear un formato para guardar una partida de Tateti. Es necesario guardar:
    1. El tablero final. Asuman que siempre es correcto.
    2. Quién ganó, o si hubo empate.
    3. El nombre de los jugadores.
    4. Las fichas utilizadas.
    5. Qué jugador usó cada tipo de ficha.
       NOTA: El archivo puede ser de cualquier tipo de extensión (.txt, .csv, .json, .xml, etc.)
2. Escribir un programa sencillo que, utilizando el formato anterior, cargue en memoria toda la información y la imprima
   por pantalla, dándole un formato amigable para el usuario.

El formato elegido para resolver este ejercicio es:

> FICHA_J1,FICHA_J2,TABLERO,NOMBRE_J1,NOMBRE_J2,RESULTADO