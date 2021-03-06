// Lista de Exercícios Estrutura de dados para Nota - Exercício 2

/*
2) Implemente uma função que receba um vetor de valores inteiros com n elementos e construa uma lista encadeada armazenando 
os elementos do vetor nos nós da lista. Assim, se for recebido o vetor v[5] = { 3, 8, 1, 7,  2}, a função deve retornar 
uma nova lista cujo primeiro nó tem a informação 3, o segundo nó a informação 8, e assim por diante. Se o vetor tiver zero elementos, 
a função deve ter como valor de retorno uma lista vazia. 

Thiago de Sousa Oliveira - RA:225626711932
Robson Zakalski - RA: 225729811932
Isaías Micael de Sousa Simões - RA: 216272511932
*/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista {
	int info;
	struct lista* prox;
};
typedef struct lista Lista;


Lista* inicializa(void) {
	return NULL;
}

//Função que recebe um vetor e preenche os nós da lista com os elementos do vetor
Lista* constroi(int i, int *v) {
	int tamanho = i;

	Lista* novaLista = NULL;


	while (tamanho >= 0) {
		Lista* novo = (Lista*)malloc(sizeof(Lista));
		novo->info = v[tamanho];
		novo->prox = novaLista;
		novaLista = novo;
		tamanho--;
	}

	return novaLista;

}

//Função para imprimir todos os elemntos do vetor
void imprimiVetor(int n, int *v){
	int i;
	
	printf("\nVetor: ");

	if (n <= 0) {
		printf("\n");
		printf("***********************************************\n");
		printf("*Seu Vetor está vazio                        *\n");
		printf("***********************************************\n");
	}
	else {
		for (i = 0; i < n; i++) {
			printf("%d-> ", v[i]);
		}
	}

	printf("\n\n");
}

//Função para imprimir todos os elemntos da Lista
void imprimiLista(Lista *lst) {
	int i;

	printf("Lista: ");
	if (lst == NULL) {
		printf("\n");
		printf("***********************************************\n");
		printf("*Sua lista está vazia                         *\n");
		printf("***********************************************\n");
	}
	else {

		for (i = 0; lst != NULL; lst = lst->prox) {
			printf("%d-> ", lst->info);
		}
		printf("\n\n");
	}
}


//Função Principal - Para imprimir o vetor utilizamos a função "imprimiVetor" e para imprimir a lista "imprimirLista"
int main(){
	setlocale(LC_ALL, "Portuguese");

	int i;
	int n = 0;
	int vetor[5];
	int vetor2[5];

	Lista *novaLista;
	novaLista = inicializa();

	printf("TESTE COM VETOR 5 POISÇÕES\n ");
	for (i = 0; i < 5; i++) {
		vetor[i] = i;
		n++;
	}
	imprimiVetor(n, vetor);
	
	novaLista = constroi((n-1), vetor);
	imprimiLista(novaLista);

	printf("TESTE COM VETOR 0 POISÇÕES\n ");
	
	n = 0;

	for (i = 0; i < 0; i++) {
		vetor2[i] = i;
		n++;
	}
	imprimiVetor(n, vetor2);

	novaLista = constroi((n - 1), vetor2);
	imprimiLista(novaLista);

	getchar();

}

