#include <cstdlib>
#include <iostream>

#include <ESDHeader.hpp>

using namespace std;

// #define TAMANHOMAXIMO 5

const int TAMANHOMAXIMO = 5;

int main()
{
    int lista[TAMANHOMAXIMO];
    int tamanhoAtual = 0;
    int continuarInserindo = 0;
    int valor_digitado = 0;
    int iAsc, iDes = 0;

    cout << "Lista de Inteiros" << endl;
    cout << "Digite um valor inteiro: " << endl;

    while(true)
    {
        cin >> valor_digitado;
        continuarInserindo = buscarElementoRepetido(lista, tamanhoAtual, valor_digitado, TAMANHOMAXIMO);

        if (continuarInserindo == 0)
           inserirSemRepetir(lista, valor_digitado, tamanhoAtual);
        else if (continuarInserindo == -1)
            break;
    }

    imprimeLista(lista);

    bool ordenada =  estaOrdenada(lista, iAsc, iDes );

    if (ordenada)
    {
        cout << endl << "A lista esta ordenada " << endl;
        if (iAsc == 1)
            cout << "Ascendente" << endl << endl;


        if (iDes == 1)
            cout << "Descendente" << endl << endl;
    }
    else
        cout << "A lista não esta ordenada " << endl;


    cout << endl << "Remover da Lista" << endl;
    cout << "Digite" << endl;
    cout << "0 - Para remover inteiros pares" << endl;
    cout << "1 - Para remover inteiros impares" << endl;

    int Opcao;

    cin >> Opcao;

    removerDaLista(lista, Opcao);

    cout << endl << "Lista Atualizada" << endl;
    imprimeLista(lista);

    //system("PAUSE");
    return EXIT_SUCCESS;
}
