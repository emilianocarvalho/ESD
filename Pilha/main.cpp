#include <cstdlib>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int tos = -1; // top of stack

// PROTOTYPES

// stack functions
void push(int s[], int val);
void sPush(string s[], string vlr);
void pop();
int top(int s[]);
bool isEmpty();
int defStack(string s, int Pilha, bool compare);

// activitys
void convertBinary();
void countParentheses();
void isPalindrome();
void polishNotation();

int main(int argc, char *argv[])
{
    int opcao;
    do {
        cout << "MENU |||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "1 -  Conversao Decimal / Binario"  << endl;
        cout << "2 -  Verifica Parenteses"  << endl;
        cout << "3 -  Palindromo"  << endl;
        cout << "4 -  Notacao Polonesa Reversa"  << endl;
        cout << "5 -  Sair"  << endl;

        cout << "Escolha uma opcao no Menu: ";
        cin >> opcao;

        switch(opcao){

         case 1: //system("clear");
                 convertBinary();
                 //system("PAUSE");
                 break;

         case 2: //system("cls");
                 countParentheses();
                 //system("PAUSE");
                 break;

         case 3: //system("cls");
                 isPalindrome();
                 //system("PAUSE");
                 break;

         case 4: //system("cls");
                 cout << "opcao 4";
                 //system("PAUSE");
                 break;
        }

        //system("cls");
        //system("clear");


     } while(opcao != 5);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// funções de pilha
void push(int s[], int val){
  s[++tos]=val;
}

void sPush(string s[], string vlr){
  s[++tos]=vlr;
}

void pop(){
  if(!isEmpty()) tos--;
}
int top(int s[]){
  return s[tos];
}
bool isEmpty(){
  return (tos==-1)? true:false;
}

int defStack(string s, int Pilha, bool compare = false)
{
    int tam = 0;
    string elem;

    for (int i = 0; i < Pilha; ++i)
    {
        elem = s[i];
        if (compare)
        {
            if ((elem == "{") || (elem == "}"))
                tam++;
        }
        else
            tam++;
    }
    return tam;
}

//1. Faca um programa em C++ para ler um numero inteiro maior que zero, converter este numero
//de decimal para binario, usando pilha e apresentar na tela, o resultado da conversao.
void convertBinary()
{
    // problema com esvaziamento da pilha - deve ser inicializada novamente
    if (isEmpty() == false)
        tos = -1;

    int valorDig, valorDiv;
    int resto = 0;
    int binary[5];

    cout << "Convert to Binary ||||||||||||||||||||||||||||" << endl;
    cout << "Valor Decimal Inteiro: ";
    cin >> valorDig;

    valorDiv = valorDig;

    while (true)
    {
       resto = (valorDiv%2);

       // add to stack
       push(binary, resto);

       if (valorDiv <= 1)
          break;

       valorDiv = valorDiv/2;
    }

    for (int x = tos ; x >= 0 ; x--)
       cout << binary[x];

    cout << " Binary" << endl;

    cout << endl << "|||||||||||||||||||||||||||||||||||||||||<<<<<" << endl << endl;

}

//2. Construa um programa em C++, que use a estrutura pilha e verifique se o numero de abre
//parenteses eh igual ao numero de fecha parenteses
void countParentheses()
{
    // problema com esvaziamento da pilha - deve ser inicializada novamente
    if (isEmpty() == false)
        tos = -1;

    string sentenca, elemento;

    cout << endl << "Count Parentheses ||||||||||||||||||||||||||||" << endl;
    cout << "Digite a sentenca :" << endl << endl;
    cin >> sentenca;

    int tamSentenca = sentenca.length();

    string pilha[defStack(sentenca, tamSentenca)];

    for (int i = 0; i < tamSentenca; ++i)
    {
        elemento = sentenca[i];
        if (elemento == "{")
        {
            sPush(pilha, elemento); // pilha string
        }
        else if (elemento == "}")
        {
            if (isEmpty()==false)
                pop();
        }

    }

    if (isEmpty() == false)
        cout << "Ainda restam = " << tos + 1 << endl;
    else
        cout << "Fechamento correto!" << endl;
    cout << endl << "|||||||||||||||||||||||||||||||||||||||||<<<<<" << endl << endl;

}

//3. Uma palavra eh um palindromo se a sequencia de letras que a forma eh a mesma, quer seja lida
//da esquerda para a direita ou da direita para a esquerda (exemplo: raiar, ovo, ana, mussum).
//Escreva um programa em C++ que reconheca se uma dada palavra eh uma palindromo.
void isPalindrome()
{
    // problema com esvaziamento da pilha - deve ser inicializada novamente
    if (isEmpty() == false)
        tos = -1;

    string palavra, elemento;

    palavra = "";
    elemento = "";
    cout << endl << "Palindrome |||||||||||||||||||||||||||||||||||" << endl;
    cout << "Digite a palavra :" << endl << endl;
    cin >> palavra;

    int tampalavra = palavra.length();
    string pilha[tampalavra];

    for (int i = 0; i < tampalavra; i++) {
       elemento = palavra[i];
       sPush(pilha, elemento);
    }
    /// fazer comparacao entre a palavra e o seu inverso

    string palindromo = "";
    for (int x = tos; x >= 0; x--)
    {
       palindromo = palindromo + pilha[x];
    }

    if (palindromo == palavra)
        cout << "Eh palindromo" << endl;
    else
        cout << "Não e palindromo" << endl;

}

//4. Escreva um programa em C++ que calcule o valor de uma expressao em notacao polonesa
//reversa (notacao pos-fixa). Considere as 4 operacoes e que se esta trabalhando apenas com
//digitos (valores de 0 a 9).
//Obs: Na notacao polonesa reversa o operador eh posto apos os operandos. Assim sendo, não eh mais necessaria a utilizacao de
//parenteses, ja que nao ha ambiguidade, como na notacao infixa.
//Ex: Notacao infixa : (2 + 3)* 5 Notacao Polonesa Reversa: 23+5*
//Notacao infixa : 2 + 3*5 Notacao Polonesa Reversa: 235*+
void polishNotation()
{

}
