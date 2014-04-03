#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <Exercicio.h>

using namespace std;

const int tamanhoMaximo = 5;

int main(int argc, char *argv[])
{
    int lista[tamanhoMaximo];
    int tamanhoAtual = 0;
    int continuarInserindo = 0;
    int valor_digitado = 0;

    cout << "Lista de Inteiros" << endl;
    cout << "Digite um valor inteiro: " << endl;

    while(true)
    {
        cin >> valor_digitado;
        continuarInserindo = buscarElementoRepetido(lista, tamanhoAtual, valor_digitado, tamanhoMaximo);

        if (continuarInserindo == 0)
           inserirSemRepetir(lista, valor_digitado, tamanhoAtual);
        else if (continuarInserindo == -1)
            break;
    }

    for (int i=0; i < tamanhoMaximo; i++)
        cout << "lista[" << i << "] = " << lista[i] << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

void inserirSemRepetir(int vet[], int valor, int &pos)
{
    vet[pos] = valor;
    pos++;
}

int buscarElementoRepetido(int vet[], int &pos, int valor, int lim)
{
    /// caso seja atingido o limite
    if (lim == pos)
    {
            cout << "Capacidade máxima do lista atingida" << endl;
            return -1;
    }

    /// verifica se o elemento já foi digitado
    for (int i = 0; i < pos; i++)
    {
        if (vet[i] == valor)
        {
            cout << "Valor já digitado:" << endl << endl;
            cout << "vet[" << i <<"] = " << vet[i] << endl << endl;
            return 1;
        }
    }
    return 0;
}
