// Exercícios Anhanguera Estrutura de Dados - Reforço Listas Ligadas


#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct lista {
	int info;
	struct lista* prox;

};
typedef struct lista ListaEnc;

ListaEnc* inicializa(void) {
	return NULL;
}

//Função para inserir valores na Lista
ListaEnc* inserir(ListaEnc* lst, int V) {
	ListaEnc *novo = (ListaEnc *)malloc(sizeof(lista));
	novo->info = V;
	novo->prox = lst;
	return novo;
}

//Função Para modelo de Menu
int menu(void) {
	int op;

	printf("\nEscolha uma Opção:\n\n1 - Destruir Lista\n2 - Imprimir Lista\n3 - Retirar Elemento do Fim da Lista"
			"\n4 - Incluir Elemento em uma Posição da Lista\n5 - Retirar Elemento de uma posição da Lista"
			"\n6 - Retornar a posição de um Elemento da Lista\n7 - Sair\n\n");
	scanf_s("%d", &op);
	system("cls");
	
	return op;
}

//Função que retorna o tamanho da Lista
int tamanhoLista(ListaEnc* lst) {
	int cont = 0;
	ListaEnc *p = lst;

	while (p != NULL) {
		p = p->prox;
		cont++;
	}
	return cont;
}

//Função para incluir um valor na Lista na posição definida
ListaEnc* adicionaNaPosicao(ListaEnc* lista, int valor, int pos) {
	ListaEnc *novo = (ListaEnc *)malloc(sizeof(ListaEnc));

	int cont = 1;
	ListaEnc *p = lista;

	if (pos <= 0) {
		novo->info = valor;
		novo->prox = p;
		return novo;
	}

	if (pos >= (tamanhoLista(p) + 1)) {
		while (cont != (pos - 1)) {
			p = p->prox;
			cont++;
		}
		novo->info = valor;
		p->prox = novo;
		return lista;
	}

	while (cont != pos) {
		p = p->prox;
		cont++;
	}
	novo->info = valor;
	novo->prox = p->prox;
	p->prox = novo;
	return lista;
}

//Função para imprimir a Lista
void imprimi_lista(ListaEnc* lista) {
	ListaEnc *p = lista;

	if (lista == NULL) {
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

// Função para zerar a Lista
ListaEnc* destroi_lista(ListaEnc* lista) {
	ListaEnc* anterior = NULL;
	ListaEnc* p = lista;

	if (p == NULL) {
		imprimi_lista(lista);
		return lista;
	}
	
	while (p->prox != NULL) {
		anterior = p;
		p = p->prox;
		free(anterior);
	}
	p = NULL;

	imprimi_lista(p);
	printf("***********************************************\n\n");
	return p;
}

// Função para remover um nó da Lista
ListaEnc* retiraNaPosicao(ListaEnc* lista, int pos) {
	ListaEnc* anterior = NULL;
	ListaEnc* p = lista;
	int posicao = 1;

	while (p->prox != NULL && posicao != pos) {
		anterior = p;
		p = p->prox;
		posicao++;
	}

	if (p == NULL) {
		return lista;
	}

	if (anterior == NULL) {
		lista = p->prox;
	}
	else {
		anterior->prox = p->prox;
	}
	return lista;

}

// Função para remover um nó no Final da Lista
ListaEnc* retiraDoFim(ListaEnc* lista) {
	ListaEnc* anterior = NULL;
	ListaEnc* p = lista;


	if (p == NULL) {
		return lista;
	}
	
	else {
		while (p->prox != NULL) {
			anterior = p;
			p = p->prox;
		}
		if (anterior != NULL) {
			anterior->prox = NULL;
			return lista;
		}
	}
	lista = NULL;
	return lista;
}

//Função que retorna a posição do Elemento valor
int posicaoDoElemento(ListaEnc* lista, int valor) {
	ListaEnc *p = lista;
	int cont = 0;
	int pos = 0;

	while (p != NULL) {
		if (p->info == valor) {
			pos = (cont + 1);
		}
		cont++;
		p = p->prox;
	}
	if (pos >= 1) {
		return pos;
	}
	else {
		return (0);
	}
}


//Programa Principal
int main()
{
	setlocale(LC_ALL, "Portuguese");

	int opcao = 0;
	int elemento = 0;
	int posicao = 0;
	
	ListaEnc *novaLista;
	novaLista = inicializa();

	novaLista = inserir(novaLista, 1);
	novaLista = inserir(novaLista, 2);
	novaLista = inserir(novaLista, 3);
	novaLista = inserir(novaLista, 4);
	
	do
	{
		opcao = menu();
		

		switch (opcao)
		{
		case 1:
			printf("***********************************************\n");
			printf("*\t\tDestruir Lista                *\n");
			printf("***********************************************\n\n");

			novaLista = destroi_lista(novaLista);

			break;

		case 2:
			printf("***********************************************\n");
			printf("*\t\tImprimir Lista                *\n");
			printf("***********************************************\n\n");

			imprimi_lista(novaLista);
			printf("***********************************************\n\n");
		
			break;

		case 3:
			printf("***********************************************\n");
			printf("*\tRetirar Último Elemento da Lista      *\n");
			printf("***********************************************\n\n");

			novaLista = retiraDoFim(novaLista);
			printf("***********************************************\n");
			imprimi_lista(novaLista);
			printf("***********************************************\n\n");

			break;

		case 4:
			if (novaLista == NULL) {
				printf("***********************************************\n");
				printf("*\t\tSua lista está vazia          *\n");
				printf("***********************************************\n");
			}
			else {
				printf("***********************************************\n");
				printf("*\t\tSua lista                     *\n");
				printf("***********************************************\n");
				imprimi_lista(novaLista);
			}
			printf("***********************************************\n");
			printf("*\t\tAdicionar Elementos           *\n");
			printf("***********************************************\n");
			printf("\nDigite o Valor do Elemento: ");
			getchar();
			scanf_s("%d", &elemento);

			if (novaLista == NULL) {
				novaLista = inserir(novaLista, elemento);
				printf("***********************************************\n");
				imprimi_lista(novaLista);
				printf("***********************************************\n\n");

				break;
			}
			printf("\nIncluir o Elemento na posição: ");
			scanf_s("%d", &posicao);
			if (posicao > (tamanhoLista(novaLista) + 1)) {
				while (posicao > (tamanhoLista(novaLista) + 1)) {
					printf("Digite uma posição válida\n");
					printf("\nIncluir o Elemento na posição: ");
					scanf_s("%d", &posicao);
				}
			}
			novaLista = adicionaNaPosicao(novaLista, elemento, (posicao - 1));
			printf("***********************************************\n");
			imprimi_lista(novaLista);
			printf("***********************************************\n\n");
			
			break;

		case 5:
			printf("***********************************************\n");
			printf("*\t\tExcluir Elemento              *\n");
			printf("***********************************************\n");

			if (novaLista == NULL) {
				printf("***********************************************\n");
				printf("*\t\tSua lista está vazia          *\n");
				printf("***********************************************\n");
				break;
			}
			else {
				printf("***********************************************\n");
				printf("*\t\tSua lista                     *\n");
				printf("***********************************************\n");
				imprimi_lista(novaLista);
			}

			printf("\nPosição do Elemento que deseja excluir: ");
			scanf_s("%d", &posicao);
			if (posicao > (tamanhoLista(novaLista) + 1)) {
				while (posicao > (tamanhoLista(novaLista) + 1)) {
					printf("Digite uma posição válida\n");
					printf("\nPosição do Elemento que deseja excluir: ");
					scanf_s("%d", &posicao);
				}
			}
			novaLista = retiraNaPosicao(novaLista, posicao);
			printf("***********************************************\n");
			imprimi_lista(novaLista);
			printf("***********************************************\n\n");

			break;

		case 6:
			printf("***********************************************\n");
			printf("*\t\tPosição do Elemento           *\n");
			printf("***********************************************\n");
			
			if (novaLista == NULL) {
				printf("***********************************************\n");
				printf("*\t\tSua lista está vazia          *\n");
				printf("***********************************************\n");
				break;
			}

			printf("\nDigite o Valor do Elemento: ");
			scanf_s("%d", &elemento);

			posicao = posicaoDoElemento(novaLista, elemento);

			if (posicao >= 1) {
				printf("***********************************************\n");
				printf("Posição do Elemento: %d", posicao);
				printf("\n***********************************************\n\n");
			}
			else {
				printf("***********************************************\n");
				printf("Elemento não encontrado na Lista");
				printf("\n***********************************************\n\n");
			}
			
			break;

		case 7:
			printf("FIM DO PROGRAMA\n\n");
			break;

		default:
			printf("Opção Inválida\n");
			break;
		}

	} while (opcao != 7);
	

	system("\n\nPause");
}

