/* TABBLERO DE SUDOKU
 *
 * Este código sólo muestra el tablero del sudoku y permite moverse en él usando un cursor.
 * Las téclas para moverse son «a» izquierda, «d»  derecha , «w» arriba y «s» abajo (minúsculas).
 * Cada letra implica moverse un espacio. en el tablero hacia alguna de las direcciones. Luego de presionar la tecla
 * en cuestión, se debe presionar «ENTER» para ejecutar el movimiento.
 * Se puede editar cualquier valor en el tablero (o crear uno), dirigiéndose hasta la posición deseada y
 * editar el valor allí con los números del 0 a 9 (el cero es para borrar) y luego «ENTER».
**/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
// #include <termios.h>

using namespace std;

// CONSTANTES
#define FILAS 9
#define COLUMNAS 9

// las únicas dos funciones que se usan. Su definición está abajo del main.
void menu();
void imprimirTablero(int tablero[FILAS][COLUMNAS], int x, int y); // imprime el tablero

int main ()
{

	int sudoku[FILAS][COLUMNAS] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,2,3,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}
	};

	/* inicializamos la variable para las teclas del movimiento
	 * y para los números del 0 - 9 que se ingresen en el tablero
	 */

	char opcion = 'x'; // solo se eligió inicializar «opcion» con 'x' arbitrariamente
	int posx = 0, posy = 0;

	while (opcion != 'P' && opcion != 'p')
	{
		/* aquí hay que seleccionar (comentar o descomentar alguna de las dos siguientes líneas)
		 * dependiendo del sistema operativo.
		 * Lo que hace estas dos líneas de código es limpiar la terminal luego de cada iteración
		 * del ciclo para dibujar el tablero y los elementos cada vez.
		 */

  		//system("cls"); // descomentar para windows
  		system("clear"); // descomentar para linux

		menu();
		imprimirTablero (sudoku, posx, posy);
		opcion = cin.get();

		switch (opcion)
		{
			case 'a':
				posx--;
				if (posx < 0) posx = 8;
				break;

			case 's':
				posy++;
				if (posy > 8) posy = 0;
				break;

			case 'd':
				posx++;
				if (posx > 8) posx = 0;
				break;

			case 'w':
				posy--;
				if (posy < 0) posy = 8;
				break;

			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				sudoku[posy][posx] = (int)opcion - '0'; // para editar el número y convertirlo de char a entero
				break;

			case 'P': case 'p': // cuando se presiona «p» o «P» se sale del juego
				cout << "Juego Terminado\n";
				break;
		}
	}

	return 0;
}

/*** DEFINICIÓN DE LAS FUNCIONES UTILIZADAS EN EL JUEGO ***/

void menu()
{
    for (int i = 0; i < 32; i++) cout << "* ";
	cout << "\n*\tMenú:\t\t\t\t\t\t      *\n*\t\t\t\t\t\t\t      *\n";
	cout << "*  Teclas para el movimiento del cursor (minúsculas):\t      *\n";
	cout << "*  a: «izquierda», w: «arriba», d: «deracha» y s: «abajo»     *\n";
	cout << "*  Presione «ENTER» luego de la tecla para mover el cursor    *\n";
	cout << "*  Para editar los valores del tablero:\t\t\t      *\n";
	cout << "*  1 - 9 para asignar un valor a cada celda\t\t      *\n";
	cout << "*  0 para borrar el valor a cada celda\t\t\t      *\n";
	cout << "*\t\t\t\t\t\t\t      *\n";
	for (int i = 0; i < 32; i++) cout << "* ";
	cout << "\n\n";
}


void imprimirTablero(int tablero[FILAS][COLUMNAS], int x, int y)
{
	int columna, fila; // índices para dibujar el tablero

	for (fila = 0; fila < FILAS; fila++)
	{
		if (fila > 0 && fila % 3 == 0) cout << endl; // cada 3 líneas imprime un salto de línea

		for (columna = 0; columna < COLUMNAS; columna++)
        {
			if(columna > 0 && columna % 3 == 0) cout << "  "; // cada tres columnas imprime dos espacios

			if (fila == y && columna == x)
			{
				if (tablero[fila][columna] != 0) cout << ">" << tablero[fila][columna] << "<"; // cursores
				else cout << ">" << "-" << "<"; // se imprime un «-» cuando el número es cero
			}

			else
			{
				if (tablero[fila][columna] != 0) cout << " " << tablero[fila][columna] << " ";
				else cout << " " << "-" << " ";
			}
		}
		cout << endl; // imprime un salto de línea cuando termina de imprimir cada fila del tablero
	}
}
