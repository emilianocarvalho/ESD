#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <Exercicio.h>

using namespace std;


const int tamanhoMaximo = 5;

int main()
{
    int lista[tamanhoMaximo];
    int tamanhoAtual = 0;
    int continuarInserindo = 0;
    int valor_digitado = 0;
    int iAsc, iDes = 0;

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

    imprimeLista(lista);

    bool ordenada =  estaOrdenada(lista, iAsc, iDes );

    if (ordenada)
    {
        cout << "A lista esta ordenada " << endl;

        if (iAsc == 1)
            cout << "Ascendente" << endl;


        if (iDes == 1)
            cout << "Descendente" << endl;
    }
    else
        cout << "A lista não esta ordenada " << endl;


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
            cout << "O valor " << valor << " não foi considerado" << endl << endl;
            return -1;
    }

    /// verifica se o elemento já foi digitado
    for (int i = 0; i < pos; i++)
    {
        if (vet[i] == valor)
        {
            cout << "Valor já digitado:" << endl;
            cout << "vet[" << i <<"] = " << vet[i] << endl << endl;
            return 1;
        }
    }
    return 0;
}

void imprimeLista(int vet[])
{
    for (int i=0; i < tamanhoMaximo; i++)
        cout << "lista[" << i << "] = " << vet[i] << endl;
}

bool estaOrdenada(int vet[], int &asc, int &des)
{
    int ultimo, maior, menor;
    //int anterior = 0;

    bool ordenada = true;

    for (int i = 0; i < tamanhoMaximo; ++i)
    {
        if (i == 0)
        {
           ultimo = vet[i];
           //anterior = ultimo;
           maior = ultimo;
           menor = ultimo;
        }

        if ((vet[i] >= ultimo) && (vet[i] >= maior))
        {
            //anterior = ultimo;
            ultimo = vet[i];
            maior = ultimo;
            asc = 1;
            des = 0;
        }
        else if ((vet[i] <= ultimo) && (vet[i] <= menor))
        {
            //anterior = ultimo;
            ultimo = vet[i];
            menor = ultimo;
            asc = 0;
            des = 1;
        }
        else
        {
            ordenada = false;
            break;
        }

    }
    return ordenada;
}
