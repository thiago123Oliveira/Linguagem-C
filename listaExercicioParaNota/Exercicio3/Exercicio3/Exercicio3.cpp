// Lista de Exercícios Estrutura de dados para Nota - Exercício 3

/*
3) Implemente uma função que, dados uma lista encadeada e um número inteiro não negativo n, remova da lista seus n primeiros nós 
e retorne a lista resultante. Caso n seja maior do que o comprimento da lista, todos os seus elementos devem ser removidos 
e o resultado da função deve ser uma lista vazia.

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

//Função para inserir valores na Lista
Lista* inserir(Lista* lst, int v) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = lst;
	return novo;
}

//Função para imprimir todos os elemntos da Lista
void imprimir(Lista* lst) {
	Lista* p = lst;

	if (p == NULL) {
		printf("***********************************************\n");
		printf("*Sua lista está vazia                         *\n");
		printf("***********************************************\n");
	}

	while (p != NULL) {
		printf("%d -> ", p->info);
		p = p->prox;
	}
	printf("\n\n");
}

//Função que retorna o tamanho da Lista
int tamanhoLista(Lista* lst) {
	int cont = 0;
	Lista *p = lst;

	while (p != NULL) {
		p = p->prox;
		cont++;
	}
	return cont;
}


//Função que recebe uma lista e um valor inteiro n, remove "n" primeiros nós da lista e retorna a lista resultante
//Se "n" for maior que o tamanho da Lista, retorna uma lista vazia.
//Para verificar se "n" é maior que o tamanho da lista utiliza a função "tamanhoLista"
Lista* retira_no(int n, Lista* l) {
	Lista* novo = NULL;
	Lista* p = l;
	int pos = 0;

	if(p == NULL) {
		imprimir(l);
		return l;
	}

	if ((n > tamanhoLista(l))) {
		while (p->prox != NULL) {
			novo = p;
			p = p->prox;
			free(novo);
		}
		p = NULL;
		return p;
	}
	else {
		while (pos <= (n-1)){
			novo = p->prox;
			p = p->prox;
			pos++;
		}
	}
	if (novo == NULL) {
		printf("***********************************************\n");
		printf("Todos os Elementos da Lista foram removidos   *\n");
		printf("***********************************************\n");
	}
	return novo;
}


//Programa Principal
//Para incluir elementos na lista utiiza a função "inserir"
//Para imprimir os elementos da lista utiliza a função "imprimir"
//Função "retina_no" recebe a Lista original e retira os "n" primiros nós da lista e retrona a Lista resultante
//Se "n" for maior que o número de elementos da lista, a função "retira_no" retorna uma lista vazia
int main(){
	setlocale(LC_ALL, "Portuguese");

	int n;
	
	Lista *novaLista;
	novaLista = inicializa();

	novaLista = inserir(novaLista, 1);
	novaLista = inserir(novaLista, 2);
	novaLista = inserir(novaLista, 3);
	novaLista = inserir(novaLista, 4);

	printf("Lista Original\n");
	imprimir(novaLista);

	n = 2;
	printf("Lista com %d nós removidos\n", n);
	novaLista = retira_no(n, novaLista);
	imprimir(novaLista);
   
	getchar();
}


