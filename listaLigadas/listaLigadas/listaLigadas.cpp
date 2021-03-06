// listaLigadas.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//Comando que cria uma Struct que vai armazenar um valor e um endereço de memória
struct lista {
	int info;
	struct lista* prox;
};

//Comando que define a Struct Lista como um tipo
typedef struct lista Lista;

//Função´para Inicializar "Lista"
Lista* inicializa(void) {
	return NULL;
}

//Função para inserir valores na Lista
Lista* inserir(Lista* lst, int V) {
	Lista *novo = (Lista *)malloc(sizeof(lista));
	novo->info = V;
	novo->prox = lst;
	return novo;
}


//Função para incluir um valor na "Lista" na posição definida
Lista* inserirPosicao(Lista* lst, int pos, int v) {
	Lista *novo = (Lista *)malloc(sizeof(Lista));

	int cont = 0;
	Lista *p = lst;

	while (cont != pos) {
		p = p->prox;
		cont++;
	}
	novo->info = v;
	novo->prox = p->prox;
	p->prox = novo;
	return lst;
}

//Função para incluir um valor na "lista" na posição Final
Lista* inserirPosicaoFinal(Lista* lst, int v) {
	Lista *novo = (Lista *)malloc(sizeof(Lista));

	Lista *p = lst;

	while (p->prox != NULL) {
		p = p->prox;
	}
	novo->info = v;
	novo->prox = p->prox;
	p->prox = novo;
	return lst;
}

//Função para remover um nó da Lista
Lista* removerNo(Lista* lst, int v) {
	Lista* anterior = NULL;
	Lista* p = lst;

	while (p->prox != NULL && p->info != v) {
		anterior = p;
		p = p->prox;
	}

	if (p == NULL) {
		return lst;
	}

	if (anterior == NULL) {
		lst = p->prox;
	}
	else {
		anterior->prox = p->prox;

		return lst;
	}


}

//Função que retorna o tamanho da "Lista"
int tamanhoLista(Lista* lst) {
	int cont = 0;
	Lista *p = lst;

	while (p != NULL) {
		p = p->prox;
		cont++;
	}
	return cont;
}

//Função para retornar o endreço de memória do índice
Lista* retornaMemoria(Lista* lst, int pos) {
	int cont = 0;

	Lista *p = lst;

	if (pos == 0) {
		return p->prox;
	}
	else {
		for (cont = 0; cont <= pos; cont++) {
			p = p->prox;
		}
	}
	return p->prox;
}


//Função para trocar 2 itens da lista de lugar a partir da função menor
/*Lista* trocarPosicao(Lista* lst, int pos1, int pos2) {
	int invertePos;
	int cont = 0;
	int itensLista = tamanhoLista(lst);

	Lista *p = lst;
	Lista *auxiliar;
	Lista *memoriaPos1menos;
	Lista *memoriaPos2menos;
	Lista *memoriaPos1mais;
	Lista *memoriaPos2mais;


	if (pos1 == pos2) {
		return p;
	}

	if (pos1 > pos2) {
		invertePos = pos1;
		pos1 = pos2;
		pos2 = invertePos;
	}

	if (pos1 == 0) {
		memoriaPos1mais = retornaMemoria(p, pos1);
		memoriaPos2menos = retornaMemoria(p, (pos2-1));
		memoriaPos2mais = retornaMemoria(p, pos2);


		for (cont = 0; cont <= (itensLista-1); cont++) {
			if (cont == pos2) {
				p->prox = memoriaPos1mais;
			}
			if (cont == (pos2 + 1)) {
				p->prox = memoriaPos2menos;
			}
			if (cont == (pos2 + 2)) {
				p->prox = memoriaPos2mais;
			}
			p = p->prox;
		}
	}
	return p;
}*/


//Função para imprimir a Lista
void imprimi(Lista* l) {
	Lista *p = l;

	while (p != NULL) {
		printf("%d -> ", p->info);
		p = p->prox;
	}
	printf("\n\n");
}

//Função para imprimir a Lista com todos os endereços
void imprimiCompleto(Lista* l) {
	Lista *p = l;
	int no = 1;

	while (p != NULL) {
		printf("Nó %2d - End: (%p) Vlr: %3d Próx: (%p) ->\n ", no, p, p->info, p->prox);
		p = p->prox;
		no++;
	}
}

//Função que Busca se um valor "v" pertence a lista
Lista* busca(Lista* lst, int v) {
	Lista *p;

	for (p = lst; p != NULL; p = p->prox) {
		if (p->info == v) {
			printf("\nO número %d pertence a Lista\n\n", v);
			return lst;
		}
	}
	printf("\nO número %d não pertence a Lista\n\n", v);
	return lst;
}

//Função que retorna a posição do menor número da lista
int menornumeroLista(Lista* lst) {
	int cont = 0;
	int posMenor = 0;
	int compara = 0;
	int contFinal = 0;
	int comparaLista = tamanhoLista(lst);
	Lista *p = lst;
	Lista *p2 = lst;

	while (p != NULL) {
		compara = p->info;
		contFinal = 0;
		p2 = lst;

		while (p2 != NULL) {
			if (compara == p2->info) {
				p2 = p2->prox;
				contFinal++;
			}
			else {
				if (compara < p2->info) {
					p2 = p2->prox;
					contFinal++;
				}
				else {
					p = p->prox;
					cont++;
					break;
				}
			}
		}
		if (contFinal == comparaLista) {
			posMenor = cont;
			break;
		}
	}
	return posMenor;
}


int main() {
	setlocale(LC_ALL, "Portuguese");

	Lista *listaNova;

	listaNova = inicializa(); //Inicializa a Lista
	listaNova = inserir(listaNova, 10); //Inseri o valor 10 a Lista
	listaNova = inserir(listaNova, 30); //Inseri o valor 34 a Lista
	printf("\npos 2 %x\n", listaNova->prox);
	listaNova = inserir(listaNova, 50); //Inseri o valor 50 a Lista
	listaNova = inserir(listaNova, 22); //Inseri o valor 22 a Lista
	printf("\npos0 %x\n", listaNova->prox);
	imprimi(listaNova); //Imprimi a Lista

	listaNova = inserirPosicao(listaNova, 2, 1); //Inseri o valor 100 na posição 2 da Lista
	imprimi(listaNova); //Imprimi a Lista Atualizada

	listaNova = inserirPosicaoFinal(listaNova, 95); //Inseri o valor 95 no final da Lista
	imprimi(listaNova); //Imprimi a Lista Atualizada

	printf("\nTamanho da Lista: %d\n\n", tamanhoLista(listaNova)); //Informa o tamanho da Lista
	printf("\nA posição do menor é: %d\n\n", menornumeroLista(listaNova));

	printf("\n%x\n", retornaMemoria(listaNova, 2));
	printf("\n%x\n", retornaMemoria(listaNova, 0));

	listaNova = busca(listaNova, 95);

	listaNova = removerNo(listaNova, 95);
	imprimi(listaNova);

	//listaNova = trocarPosicao(listaNova, 0, 2);
	//imprimi(listaNova);



	system("\npause\n");

	return 0;
}
