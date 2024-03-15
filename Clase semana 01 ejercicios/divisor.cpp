#include <iostream>
using namespace std;

int main ()
{
	int N, M;

	cout <<"Ingrese el valor de N: ";
	cin >> N;

	cout <<"Ingrese el valor de M: ";
	cin >> M;

	if (N % M ==0)
		cout << "son divisibles";
	else
		cout << "no son divisibles";

	return 0;

}
