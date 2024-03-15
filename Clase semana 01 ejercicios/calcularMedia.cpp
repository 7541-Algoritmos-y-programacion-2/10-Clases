#include <iostream>

using namespace std;

void leerLote(double& sum, int& count) {
    double num;
    cout << "Ingrese un número (0 para terminar el lote): ";
    cin >> num;
    while (num != 0) {
        sum += num;
        count++;
        cout << "Ingrese un número (0 para terminar el lote): ";
        cin >> num;
    }
}

double calcularMedia(double sum, int count) {
    if (count == 0) return 0.0;
    return sum / count;
}

int main() {
    int N;
    cout << "Ingrese la cantidad de lotes (N): ";
    cin >> N;

    double total_sum = 0.0;
    int total_count = 0;

    for (int i = 0; i < N; ++i) {
        cout << "Lote " << i + 1 << ":\n";
        double lote_sum = 0.0;
        int lote_count = 0;
        leerLote(lote_sum, lote_count);
        double average = calcularMedia(lote_sum, lote_count);
        cout << "La media del lote " << i + 1 << " es: " << average << endl;

        total_sum += lote_sum;
        total_count += lote_count;
    }

    double total_average = calcularMedia(total_sum, total_count);
    cout << "La media total de todos los números ingresados es: " << total_average << endl;

    return 0;
}
