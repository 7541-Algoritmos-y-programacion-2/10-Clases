#include <iostream>
#include <climits>

using namespace std;


void reporteMaxMin(int n)
{
	int max = INT_MIN;
	int min = INT_MAX;
	int numero;
	int contador;
	int frecuenciaMin;
	int frecuenciaMax;

	for (int i = 0; i < n; ++i)
	{
		cout << "Ingrese un numero: " << endl;
		cin >> numero;

		if (numero > max)
		{
			max = numero;
			frecuenciaMax = 0;
		}

		if (numero == max)
			frecuenciaMax++;

		if (numero < min)
		{
			min = numero;
			frecuenciaMin = 0;
		}

		if (numero == min)
			frecuenciaMin++;
	}

	cout << "El mayor numero ingresado es: " << max << endl;
	cout << "El menor numero ingresado es: " << min << endl;

	cout << "El mayor numero aparece " << frecuenciaMax << " veces" << endl;
	cout << "El menor numero aparece " << frecuenciaMin << " veces" << endl;
}

int main(){

	int N;

	cout << "Ingrese la cantidad de nros a comparar" << endl;
	cin >> N;

	reporteMaxMin (N);

	return 0;
}
