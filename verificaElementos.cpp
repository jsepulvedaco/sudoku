#include <iostream>

using namespace std;

// 
bool verificarElementos(int numero, int siguiente, int array[9])
{	
	/* devuelve true si hay elementos iguales */

	if (numero > 7) return false;

	int i = siguiente;
	
	while (numero <= 7 && i <= 8)
	{
		if (array[numero] == array[i])  
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


int main ()
{
	int matriz[9][9] = {
		{00, 01 ,02, 03, 04, 05, 06, 07,  8},
		{10, 11, 12, 13, 14, 15, 16, 17, 18},
		{20, 21, 22, 23, 24, 25, 26, 27, 28},
		{30, 31, 32, 33, 34, 35, 36, 37, 38},
		{40, 41, 42, 43, 44, 45, 46, 47, 48},
		{50, 00, 52, 53, 54, 05, 56, 57, 58},
		{60, 61, 62, 63, 64, 65, 66, 67, 68},
		{70, 71, 72, 73, 74, 75, 76, 77, 78},
		{80, 81, 82, 83, 84, 85, 86, 87, 87}
	};


	if (verificarCuadrantes(matriz)) cout << "hay elementos repetidos"<< endl;
	else cout << "no hay elementos repetidos" << endl;


	return 0;
}
