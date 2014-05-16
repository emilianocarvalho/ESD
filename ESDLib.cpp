#include <cstdlib>
#include <iostream>

#include <ESDHeader.hpp>

using namespace std;

const int tamanhoMaximo = 5;

/* inserir elementos na lista não permitindo repeticoes */
void inserirSemRepetir(int vet[], int valor, int &pos)
{
    vet[pos] = valor;
    pos++;
}

/* verifica se o elemento já foi digitado */
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

/* imprime na tela a lista */
void imprimeLista(int vet[])
{
    for (int i=0; i < tamanhoMaximo; i++)
        cout << "lista[" << i << "] = " << vet[i] << endl;
}


/* verifica se está ordenada e qual ordenacao */
bool estaOrdenada(int vet[], int &asc, int &des)
{
    int ultimo, maior, menor;

    bool ordenada = true;

    for (int i = 0; i < tamanhoMaximo; ++i)
    {
        if (i == 0)
        {
           ultimo = vet[i];
           maior = ultimo;
           menor = ultimo;
        }

        if ((vet[i] >= ultimo) && (vet[i] >= maior))
        {
            ultimo = vet[i];
            maior = ultimo;
            asc = 1;
            des = 0;
        }
        else if ((vet[i] <= ultimo) && (vet[i] <= menor))
        {
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

/* retorna o indice do vetor onde se encontra o valor */
int buscarSequencial(int vet[], int valor)
{
    int encontrado = 0;

    for (int i = 0; i < tamanhoMaximo; ++i)
    {
        if (vet[i] == valor)
            encontrado = i;

    }

    if (encontrado == 0)
        encontrado = -1;

    return encontrado;
}

/* remove os elementos da lista */
void removerDaLista(int vet[], int ParImpar)
{
    int vetorTemporario[tamanhoMaximo];

    int j = 0;

    for (int i = 0; i < tamanhoMaximo; ++i)
    {
        if (ParImpar == 1) // remove impar
        {
            if ((vet[i] % 2) == 0)
            {

                vetorTemporario[j] = vet[i];
                ++j;

            }
        }
        else if (ParImpar == 0) // remove par
        {
            if ((vet[i] % 2) != 0)
            {

                vetorTemporario[j] = vet[i];
                ++j;

            }
        }
    }

    //int vetorAtualizado[j+1];

    for (int i = 0; i < tamanhoMaximo; ++i)
    {
        if (i < j)
            vet[i] = vetorTemporario[i];
        else
            vet[i] = 0;
    }

}
/*
void removerDaLista2(int vet[], int ParImpar)
{


    for (int i = 0; i < tamanhoMaximo; ++i)
    {
        if (ParImpar == 1) // remove impar
        {
            if ((vet[i] % 2) == 0)
            {
                int i = buscarSequencial(vet, );

                vetorTemporario[j] = vet[i];
                ++j;

            }
        }
        else if (ParImpar == 0) // remove par
        {
            if ((vet[i] % 2) != 0)
            {

                vetorTemporario[j] = vet[i];
                ++j;

            }
        }
    }

    //int vetorAtualizado[j+1];

    for (int i = 0; i < tamanhoMaximo; ++i)
    {
        if (i < j)
            vet[i] = vetorTemporario[i];
        else
            vet[i] = 0;
    }

}
*/
