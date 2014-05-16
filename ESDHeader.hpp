#ifndef ESDHEADER_H
#define ESDHEADER_H

void inserirSemRepetir(int vet[], int valor, int &pos);
int buscarElementoRepetido(int vet[], int &pos, int valor, int lim);
void imprimeLista(int vet[]);
bool estaOrdenada(int vet[], int &asc, int &des);
int buscarSequencial(int vet[], int valor);
void removerDaLista(int vet[], int ParImpar);
void removerDaLista2(int vet[], int ParImpar);

#endif // ESDHEADER_H
