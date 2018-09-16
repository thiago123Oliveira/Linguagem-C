//Exrecício lista ligadas AVA pág 36 - Programa que cria uma lista de livros - Função incluir / Buscar / Excluir

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

//Comando que cria uma Struct que vai armazenar um valor e um endereço de memória
struct lista {
	char teste[31];
	struct lista* prox;
};


//Comando que define a Struct Lista como um tipo
typedef struct lista listaLivros;



//Inicializa a listaLivros
listaLivros* inicializa(void) {
	return NULL;
}


//Função para inserir informações na listaLivros
listaLivros* inserir(listaLivros *lst, char teste[]) {
	listaLivros *novoLivro = (listaLivros *)malloc(sizeof(listaLivros));

	strcpy_s(novoLivro->teste, teste);
	novoLivro->prox = lst;

	return novoLivro;
}

//Função que retorna o tamanho da "Lista"
int tamanhoLista(listaLivros* lst) {
	int cont = 0;
	listaLivros *p = lst;

	while (p != NULL) {
		p = p->prox;
		cont++;
	}
	return cont;
}

//Função para incluir um valor na "Lista" na posição definida
listaLivros* inserirPosicao(listaLivros* lst, int pos, char teste[]) {
	listaLivros *novo = (listaLivros *)malloc(sizeof(listaLivros));

	int cont = 1;
	listaLivros *p = lst;

	if (pos <= 0) {
		strcpy_s(novo->teste, teste);
		novo->prox = p;
		return novo;
	}

	if (pos >= (tamanhoLista(p) + 1)) {
		while (cont != (pos-1)) {
			p = p->prox;
			cont++;
		}
		strcpy_s(novo->teste, teste);
		p->prox = novo;
		return lst;
	}

	while (cont != pos) {
		p = p->prox;
		cont++;
	}
	strcpy_s(novo->teste, teste);
	novo->prox = p->prox;
	p->prox = novo;
	return lst;
}

//Função que Busca se um valor "v" pertence a lista
listaLivros* busca(listaLivros* lst, char nome[]) {
	listaLivros *p;

	for (p = lst; p != NULL; p = p->prox) {
		if (_stricmp(p->teste, nome) == 0) {
			printf("***********************************************\n");
			printf("\nO Livro %s pertence a Lista", nome);
			printf("***********************************************\n");
			return lst;
		}
	}
	printf("***********************************************\n");
	printf("O Livro %s não pertence a Lista", nome);
	printf("***********************************************\n");
	return lst;
}



//Função para imprimir a Lista
void imprimi(listaLivros* l) {
	listaLivros *p = l;
	int cont = 1;

	printf("***********************************************\n");
	while (p != NULL) {
		printf("%d -> %s", cont, p->teste);
		p = p->prox;
		cont++;
	}
	printf("***********************************************\n");
}



int main(){
	setlocale(LC_ALL, "Portuguese");

	int teste = 0;
	int opcao = 0;
	char nome[31];
	int posicao = 0;

	listaLivros *novaLista;
	novaLista = inicializa();


	do
	{
		printf("\nEscolha uma Opção:\n\n1 - Consultar Livros\n2 - Adicionar Livros\n3 - Excluir Livros\n5 - SAIR\n\n");
		scanf_s("%d", &opcao);
		system("cls");

		switch (opcao){
		case 1:
			printf("\nBuscar Livros\n");
			printf("\nDigite o nome do livro: ");
			getchar();
			fgets(nome, sizeof(nome), stdin);
			busca(novaLista, nome);

			break;

		case 2:
			if (novaLista == NULL) {
				printf("***********************************************\n");
				printf("* Sua lista de Livros está vazia              *\n");
				printf("***********************************************\n");
			}
			else {
				printf("***********************************************\n");
				printf("* Sua lista de Livros                         *\n");
				printf("***********************************************\n");
				imprimi(novaLista);
			}
			printf("\nAdicionar Livros\n");
			printf("\nDigite o nome do livro: ");
			getchar();
			fgets(nome, sizeof(nome),stdin);

			if (novaLista == NULL) {
				novaLista = inserir(novaLista, nome);
				imprimi(novaLista);
				break;
			}
			printf("\nQual a posição do livro: ");
			scanf_s("%d", &posicao);
			if (posicao > (tamanhoLista(novaLista) + 1)) {
				while (posicao > (tamanhoLista(novaLista) + 1)) {
					printf("Digite uma posição válida\n");
					printf("\nQual a posição do livro: ");
					scanf_s("%d", &posicao);
				}
			}
			novaLista = inserirPosicao(novaLista, (posicao-1), nome);
			imprimi(novaLista);
			break;

		case 3:
			printf("opção 3");
			break;


		case 5:
			printf("FIM DO PROGRAMA\n\n");
			break;

		default:
			printf("Opção Inválida");
			break;
		}

	} while (opcao!=5);



	system("\nPause");

}