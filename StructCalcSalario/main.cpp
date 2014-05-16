/*
Faça um programa que leia os dados (matrícula e salário
bruto) de 5 empregados de uma empresa e calcule e
apresente a matricula e salário líquido, sabendo-se que: O
salário líquido é calculado a partir do salário base,
descontando-se o imposto de renda, de acordo com a
tabela

A cálculo do imposto de renda deve ser a seguinte:
BASE_DE_CÁLCULO= SALÁRIO BRUTO – PAGO AO INSS
IMPOSTO_MENSAL = BASE_DE_CÁLCULO * ALIQUOTA - VALOR FAIXA
*/

#include <iostream>

using namespace std;

/* Declaracao de Tipo */
struct Empregados {
    string nome;
    float matricula;
    float salariobruto;
    float salariobase;
    float salarioliquido;
    float vlrIRPF;
    float vlrINSS;
};

/* Prototypes */
float valorINSS (float salario_bruto);
float valorIRPF (float base_calc);

/* programa principal */
int main()
{
    setlocale(LC_ALL, "ptb");

    // Cria uma variável do tipo
    Empregados Funcionarios[5];

    cout << "||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "Cálculo Imposto de Renda     >||||||||||||" << endl;

    for(int i = 0; i < 5; ++i)
    {
        // recebe os dados
        cout << "Registro: " << i << endl;

        cout << "Informe o nome" << endl;
        cin >> Funcionarios[i].nome;

        cout << "Informe a matrícula" << endl;
        cin >> Funcionarios[i].matricula;

        cout << "Informe o salário base" << endl;
        cin >> Funcionarios[i].salariobruto;

        // calcula
        Funcionarios[i].vlrINSS        = valorINSS(Funcionarios[i].salariobruto);
        Funcionarios[i].salariobase    = Funcionarios[i].salariobruto - Funcionarios[i].vlrINSS;

        Funcionarios[i].vlrIRPF        = valorIRPF(Funcionarios[i].salariobase);
        Funcionarios[i].salarioliquido = Funcionarios[i].salariobase - Funcionarios[i].vlrIRPF;

        // imprime
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "Salario Base: "    << Funcionarios[i].salariobase << endl;
        cout << "Salario Liquido: " << Funcionarios[i].salarioliquido << endl;
        cout << "Valor IRPF: "      << Funcionarios[i].vlrIRPF << endl;
        cout << "Valor INSS: "      << Funcionarios[i].vlrINSS << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||" << endl;

        cout << endl << endl;

    }

    cout << "Fim dos Calculos >|||||||||||||||||||||||||" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||" << endl;

    return 0;
}

float valorINSS (float salario_bruto)
{
    if (salario_bruto < 1107.52) {
        return salario_bruto * 0.08;
    }
    else if (salario_bruto < 1845.87) {
        return salario_bruto * 0.09;
    }
    else if (salario_bruto < 3691.74) {
        return salario_bruto * 0.11;
    }
    else
        return 0;
}

float valorIRPF (float base_calc)
{
    if (base_calc < 1499.16)
        return 0;
    else if (base_calc < 2246.76) {
        return base_calc * 0.075 - 112.43;
    }
    else if (base_calc < 3418.59) {
        return base_calc * 0.15 - 280.94;
    }
    else if (base_calc < 4271.59) {
        return base_calc * 0.225 - 505.62;
    }
    else
        return base_calc * 0.275 - 692.78;
}
