#include <iostream>

using namespace std;

// devuelve true si hay elementos iguales o si hay algún cero
bool verificarElementosArray(int numero, int siguiente, int array[9])
{	
	if (numero > 7) return false;

	int i = siguiente;
	cout <<"\n\t verificarElementosArray"<<endl;

	cout <<"numero: "<<numero<<endl;
	cout <<"siguiente: "<<siguiente<<endl;
	
	while (numero <= 7 && i <= 8)
	{
		cout <<"i: "<<i<<endl;
		cout <<"A[numero]: A["<<numero<<"]: "<<array[numero]<<endl;
		cout <<"A[i]: A["<<i<<"]: "<<array[i]<<endl;
		if ( /*(array[numero] == 0 || array[i] == 0) ||*/ (array[numero] == array[i]) )  
		{
			return true;
		}
		i++;
	}

	return verificarElementosArray(numero +1, siguiente +1, array);
}

bool verificarColumnas(int tablero[9][9])
{
	int arr[9];

	for(int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[j] = tablero[j][i];
		}

		return verificarElementosArray(0, 1, arr);

	}
}

bool verificarCuadrantes (int tablero[3][3])
{
	int indice;
	int arrayMatriz[9];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			indice = tablero[i][j] - 1;
			arrayMatriz[indice] = tablero[i][j];
		}
	}

	return verificarElementosArray(0, 1, arrayMatriz);
}


void obtenerCuadrantes (int tablero[9][9]) // esta función debe devolver una matriz de 3x3
{
	int  columna = 0;
	int limiteColumna = 3;
	int cambioLimitesColumna;

	int fila = 0;
	int limiteFila = 3;
	int cambioLimitesFila;

	int subMatriz[3][3];

	int i = 0;
	while (i < 9)
	{
		for (fila; fila < limiteFila; fila++)
		{
			for (columna; columna < limiteColumna; columna++)
			{
				subMatriz[fila][columna] = tablero[fila][columna];
			}
		}

		verificarCuadrantes(subMatriz);
	}

	cambioLimitesFila = limiteFila;
	fila = cambioLimitesFila;
	limiteFila += 3;

	if (limiteFila > 9)
	{
		limiteFila = 3;
		fila = 0;
		
		cambioLimitesColumna = limiteColumna;
		columna = cambioLimitesColumna;
		limiteColumna += 3;
	}

	i++;

}

void imprimirArray(int a[]){

		for (int j = 0; j < 9; j++)
		{
			cout << a[j] << " ";
		}
		cout <<endl;
}

int main ()
{
	int matriz[9][9] = {
		{00, 01 ,02, 03, 04, 05, 06, 07,  8},
		{10, 11, 12, 13, 14, 15, 16, 17, 18},
		{20, 21, 22, 23, 24, 25, 26, 27, 28},
		{30, 31, 32, 33, 34, 35, 36, 37, 38},
		{40, 41, 42, 43, 44, 45, 46, 47, 48},
		{50, 51, 52, 53, 54, 55, 56, 57, 58},
		{60, 61, 62, 63, 64, 65, 66, 67, 68},
		{70, 71, 72, 73, 74, 75, 76, 77, 78},
		{80, 81, 82, 83, 84, 85, 86, 87, 88}
	};

	


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n\n";

	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	
	imprimirArray(arr);
	
	bool respuesta = verificarElementosArray(0, 1, arr);
	cout <<" -> "<<respuesta<<endl;

	if (respuesta) cout << " hay elementos repeditos\n";
	else cout << "no hay elementos repetidos\n";
	
	return 0;
}
