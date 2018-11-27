// Estrutura de Dados - Exercício para Nota 2 Bimestre - Exercicio Proposto no tópico "sem medo de errar" pág 128 do Livro

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#define tam 10

//Função que cria a Struct
struct exemplares {
	int codigo;
	char titulo[100];
	char autor[41];
	char area[7];
};
typedef struct exemplares Acervo;
typedef Acervo* Hash[tam];


//Função Hash
int funcao_Esp(int codigo) {
	return (codigo%tam);
}

//Função para inserir um livro na tabela
Acervo* insere_Esp(Hash tab, int codigo, const char* titulo, const char* autor, const char* area) {
	int h = funcao_Esp(codigo);

	tab[h] = (Acervo*) malloc(sizeof(Acervo));
	
	tab[h]->codigo = codigo;
	strcpy_s(tab[h]->titulo, titulo);
	strcpy_s(tab[h]->autor, autor);
	strcpy_s(tab[h]->area, area);

	return tab[h];

}

//Função para excluir um livro na tabela
void remove_Esp(Hash tab, int codigo) {
	int h = funcao_Esp(codigo);

	if (tab[h]->codigo == codigo) {
		tab[h] = NULL;
		printf("\nExemplar Excluido!");
	}
	else {
		printf("\nExemplar não encontrado");
	}
}

//Função de busca
Acervo* busca_Esp(Hash tab, int codigo) {
	int h = funcao_Esp(codigo);

	while (tab[h] != NULL){
		if (tab[h]->codigo == codigo) 
			return tab[h];

		h = (h + 1) % tam;
	}
	return NULL;
}

//Função que inicializa a Hash
void inicializa_Esp(Hash tab) {
	int cont = 0;

	while (cont < tam){
		tab[cont] = NULL;
		cont++;
	}
}

//Função Para modelo de Menu
int menu(void) {
	int op = 0;

	printf("******************************************************************************************************************\n");
	printf("\nEscolha uma Opção:\n\n1 - Inserir Livro\n2 - Buscar Livro\n3 - Remover Livro"
		"\n4 - Imprimir Lista de Livro por Segmento\n5 - Sair\n");

	scanf_s("%d", &op);
	system("cls");

	return op;
}

int main(){
	setlocale(LC_ALL, "portuguese");

	int opcao = 0;
	int codLivro = 0;
	int contCodLivros = 02;

	char tituloLivro[100];
	char autorLivro[41];
	char areaLivro[7];

	Acervo* cadLivro;
	Hash hashLivrosA;
	inicializa_Esp(hashLivrosA);
	Hash hashLivrosB;
	inicializa_Esp(hashLivrosB);
	Hash hashLivrosC;
	inicializa_Esp(hashLivrosC);
	Hash hashLivrosD;
	inicializa_Esp(hashLivrosD);
	Hash hashLivrosE;
	inicializa_Esp(hashLivrosE);


	insere_Esp(hashLivrosA, 01, "Titulo 1", "Teste Autor 1", "A");


	do
	{
		opcao = menu();


		switch (opcao)
		{
		case 1:
			printf("INSERIR LIVROS\n\n");
			printf("Área de segmento do Livro: \n\nA - Artes\nB - Ciências Biológicas\n"
				"C - Ciências da Saúde\nD - Ciências Humanas\nE - Ciências Exatas e a Terra\n\n");
			
			printf("Código Do Livro: %d\n", contCodLivros);
			printf("Titulo do Livro: ");
			getchar();
			fgets(tituloLivro, sizeof(tituloLivro), stdin);
			printf("Autor do Livro: ");
			gets_s(autorLivro);
			printf("Área de segmento do Livro: ");
			gets_s(areaLivro);

			if (_stricmp(areaLivro, "A") == 0) {
				insere_Esp(hashLivrosA, contCodLivros, tituloLivro, autorLivro, areaLivro);
			}
			if (_stricmp(areaLivro, "B") == 0) {
				insere_Esp(hashLivrosB, contCodLivros, tituloLivro, autorLivro, areaLivro);
			}
			if (_stricmp(areaLivro, "C") == 0) {
				insere_Esp(hashLivrosC, contCodLivros, tituloLivro, autorLivro, areaLivro);
			}
			if (_stricmp(areaLivro, "D") == 0) {
				insere_Esp(hashLivrosD, contCodLivros, tituloLivro, autorLivro, areaLivro);
			}
			if (_stricmp(areaLivro, "E") == 0) {
				insere_Esp(hashLivrosE, contCodLivros, tituloLivro, autorLivro, areaLivro);
			}
			
			contCodLivros++;
			
			break;

		case 2:
			printf("BUSCAR LIVRO POR SEGMENTO");
			fflush(stdin);
			printf("\nÁrea de segmento do Livro: ");
			getchar();
			gets_s(areaLivro);
			printf("\nQual o código do livro: ");
			getchar();
			scanf_s("%d", &codLivro);
			
			if (_stricmp(areaLivro, "A") == 0) {
				cadLivro = busca_Esp(hashLivrosA, codLivro);
			}
			if (_stricmp(areaLivro, "B") == 0) {
				cadLivro = busca_Esp(hashLivrosB, codLivro);
			}
			if (_stricmp(areaLivro, "C") == 0) {
				cadLivro = busca_Esp(hashLivrosC, codLivro);
			}
			if (_stricmp(areaLivro, "D") == 0) {
				cadLivro = busca_Esp(hashLivrosD, codLivro);
			}
			if (_stricmp(areaLivro, "E") == 0) {
				cadLivro = busca_Esp(hashLivrosE, codLivro);
			}
			cadLivro = busca_Esp(hashLivrosA, codLivro);
			
			if (cadLivro == NULL) {
				printf("\nNão foi encontrado livro para esse código\n");
			}
			else {
				printf("\nCódigo: %d", cadLivro->codigo);
				printf("\nTitulo: %s", cadLivro->titulo);
				printf("\nAutor: %s", cadLivro->autor);
				printf("\nArea: %s\n", cadLivro->area);
			}
			break;

		case 3:
			printf("case3\n");
			break;

		case 4:
			printf("case4\n");
			break;

		case 5:
			printf("FIM DO PROGRAMA\n\n");
			break;

		default:
			printf("Opção Inválida\n");
			break;
		}

	} while (opcao != 5);
	
	getchar();
}


