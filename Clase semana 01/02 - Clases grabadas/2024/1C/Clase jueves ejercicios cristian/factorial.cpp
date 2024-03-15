#include <iostream>

using namespace std;

long factorial (int n)
{

	if (n == 0 || n ==1) 	//caso base
		return 1;
	else					//caso recursivo
		return n * factorial(n-1);
}

int main ()
{
	int N;

	cout << "Ingrese un nro";
	cin >> N;

	if (N > 0)
		cout << "El factorial del nro " << N << " es: " << factorial (N) << endl;
	else
		cout << "Ingrese un nro positivo!" << endl;

	return 0;
}
