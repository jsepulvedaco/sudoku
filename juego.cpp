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
bool verificarElementos(int numero, int siguiente, int array[9]);
int * convertirMatriz (int matriz[3][3]);
bool verificarColumnas(int tablero[9][9]);
bool verificarFilas(int matriz[9][9]);
bool verificarCuadrantes (int matriz[9][9]);

int main ()
{
	int sudoku[FILAS][COLUMNAS] = {
		{1,0,0,0,2,0,5,9,3},
		{8,0,3,6,0,1,0,4,0},
		{4,2,0,3,5,0,0,0,6},
		{9,0,2,5,1,8,0,0,0},
		{0,8,0,0,7,6,9,0,1},
		{5,0,7,0,0,0,6,2,8},
		{0,4,0,1,6,0,7,3,0},
		{0,9,1,7,0,5,4,0,0},
		{0,3,5,0,0,2,0,6,9}
	};

	bool contunuarJuego = verificarCuadrantes(sudoku) && verificarColumnas(sudoku) && verificarFilas(sudoku); 

	/* inicializamos la variable para las teclas del movimiento
	 * y para los números del 0 - 9 que se ingresen en el tablero
	 */

	char opcion = 'x'; // solo se eligió inicializar «opcion» con 'x' arbitrariamente
	int posx = 0, posy = 0;

	while (opcion != 'P' && opcion != 'p' && contunuarJuego)
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

	if (contunuarJuego == false) cout << "¡GANASTE!" << endl;

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

/* OPERACIONES */

bool verificarElementos(int numero, int siguiente, int array[9])
{	
	/* devuelve true si hay elementos iguales */

	if (numero > 7) return false;

	int i = siguiente;
	
	while (numero <= 7 && i <= 8)
	{
		if ( (array[numero] == 0 || array[i] == 0) || (array[numero] == array[i]) )  
		{
			return true;
		}
		i++;
	}

	return verificarElementos(numero +1, siguiente +1, array);
}

int * convertirMatriz (int matriz[3][3])
{
	/* recibe la matriz de los cuadrantes y retorna un vector
	   de 9 componentes a partir de esta, para luego verificar sus elementos
	   con otros métodos
	 */
	int indice = 0;
	int * vector = new int[9];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			vector[indice] = matriz[i][j];
			indice++;
		}

		if (indice > 9) break;
	}
	
	return vector;
}

bool verificarColumnas(int tablero[9][9])
{
	// retorna true si hay elementos iguales en alguan columna
	int arr[9];

	for(int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[j] = tablero[j][i];
		}

		return verificarElementos(0, 1, arr);

	}
}

bool verificarCuadrantes (int matriz[9][9])
{
	/* crea un vector de 9 componentes a partir de cada uno de los cuadrantes
	   del tablero de sudoku para luego verificar con alguna función sus elementos.
	   retorna true si hay algún elemento repetido en cada cuadrante.
	*/
	int inicioColumna = 0;
	int finColumna = 3;

	int * array = new int[9];
	int submatriz[3][3];

	for (int veces = 0; veces < 3; veces++)
	{
		/* itera tres veces sobre tres columnas, luego sobre otras tres, y finalmente sobre las últimas 3.
		 mientras tanto, se van obteniendo tres elementos por cada fila */
		int i;
		int inicioFila = 0;
		int finFila = 3;
		int columna;

		for (columna = 0; columna < 3; columna++)
		{
			/* se toman los primeros 3 elementos por iteración de todas las filas  por cada 3 columnas */
			for (i = inicioFila; i < finFila; i++) // inicio y fin de fila van a ir aumentando de 3 en 3
			{
				for (int j = inicioColumna; j < finColumna; j++)
				{
					submatriz[i - inicioFila][j - inicioColumna] = matriz[i][j];
				}
			}

			array = convertirMatriz(submatriz);
			if (verificarElementos(0, 1, array)) return true;

			inicioFila += 3;
			finFila += 3;

			if (finFila > 9) break;
		}

		inicioColumna += 3;
		finColumna += 3;
	}

	return false;
}

bool verificarFilas(int matriz[9][9])
{
	int fila[9]; 
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fila[j] = matriz[i][j];
		}

		verificarElementos(0, 1, fila);
	}
}