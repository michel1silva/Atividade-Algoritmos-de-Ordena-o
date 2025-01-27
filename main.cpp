#include <iostream>
#include <string>
using namespace std;

struct Prato {
    int prioridade;
    int tempo;
    string nome;
};


void bubbleSort(Prato pratos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((pratos[j].prioridade < pratos[j + 1].prioridade) ||
                (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo > pratos[j + 1].tempo)) {
                Prato aux = pratos[j];
                pratos[j] = pratos[j + 1];
                pratos[j + 1] = aux;
            }
        }
    }
}

void QuickSort(Prato *pratos, int n) {
    QuickSort_ordena(pratos, 0, n - 1);
}

void QuickSort_ordena(Prato *pratos, int esq, int dir) {
    int i, j;
    QuickSort_particao(pratos, esq, dir, &i, &j);
    if (esq < j) QuickSort_ordena(pratos, esq, j);
    if (i < dir) QuickSort_ordena(pratos, i, dir);
}

void QuickSort_particao(Prato *pratos, int esq, int dir, int *i, int *j) {
    Prato pivo, aux;
    *i = esq;
    *j = dir;
    pivo = pratos[(*i + *j) / 2];

    do {
        while (pratos[*i].prioridade > pivo.prioridade || 
              (pratos[*i].prioridade == pivo.prioridade && pratos[*i].tempo <= pivo.tempo)) {
            (*i)++;
        }
        while (pratos[*j].prioridade < pivo.prioridade || 
              (pratos[*j].prioridade == pivo.prioridade && pratos[*j].tempo > pivo.tempo)) {
            (*j)--; 
        }
        if (*i <= *j) {
            aux = pratos[*i];
            pratos[*i] = pratos[*j];
            pratos[*j] = aux;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

int main() {
    Prato pratos[] = {
        {3, 15, "Macarrao"},
        {1, 10, "Sopa"},
        {2, 20, "Churrasco"},
        {3, 10, "Lasanha"},
        {1, 5, "Salada"}
    };
    int n = sizeof(pratos) / sizeof(pratos[0]);

    bubbleSort(pratos, n);
    cout << "Resultado do Bubble Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << pratos[i].nome << " (Prioridade: " << pratos[i].prioridade
             << ", Tempo: " << pratos[i].tempo << ")" << endl;
    }

    cout << endl;

    QuickSort(pratos, n);
    cout << "Resultado do Quick Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << pratos[i].nome << " (Prioridade: " << pratos[i].prioridade
             << ", Tempo: " << pratos[i].tempo << ")" << endl;
    }

    return 0;
}
