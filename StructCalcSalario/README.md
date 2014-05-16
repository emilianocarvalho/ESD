ESD
===

Exercício I
-----------
Faça um programa que leia os dados (matrícula e salário bruto) de 5 empregados de uma empresa e calcule e apresente a matricula e salário líquido, sabendo-se que: O salário líquido é calculado a partir do salário base, descontando-se o imposto de renda, de acordo com a tabela a seguir:

O salário base é obtido aplicando-se um desconto no salário bruto para o INSS, de acordo com a tabela a seguir, até o limite de R$ 406,09

Protótipos :

– float valorINSS (float salario_bruto);
  Valor do salario bruto para calcular salário base
- float valorIRPF (float base_calc);
  Base de calculo sobre a qual será calculado o imposto de renda