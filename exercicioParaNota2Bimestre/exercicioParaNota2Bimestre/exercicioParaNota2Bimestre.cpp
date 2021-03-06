/*
Instituição: Faculdade Anhanguera de São José dos Campos
Curso......: Engenharia da Computação
Disciplina.: Algoritmos e Estruturas de Dados
Professor..: Me Fernando Salles Claro
Alunos.....: Thiago de Sousa Oliveira - RA:225626711932
             Robson Zakalski - RA: 225729811932
             Isaías Micael de Sousa Simões - RA: 216272511932: 

Objetivo...: Desenvolver uma solução computacional completa em C, para demonstrar o desafio proposto no tópico 
“Sem medo de errar” disponível no nosso livro-texto, página 128.
Data.......: 29/11/2018
Plataforma.: Microsoft Visual Studio
*/

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
	int cont = 0;

	while (tab[h] != NULL){
		if (tab[h]->codigo == codigo)
			break;

		h = (h + 1) % tam;

		if (cont > (tam-1)) {
			printf("\nNão existe posições Disponiveis\n\n");
			break;
		}
		cont++;
	}

	if (tab[h] == NULL) {
		tab[h] = (Acervo*)malloc(sizeof(Acervo));
		tab[h]->codigo = codigo;
	}
	
	strcpy_s(tab[h]->titulo, titulo);
	strcpy_s(tab[h]->autor, autor);
	strcpy_s(tab[h]->area, area);

	return tab[h];

}

//Função para excluir um livro na tabela
Acervo* remove_Esp(Hash tab, int codigo) {
	int h = funcao_Esp(codigo);

	if (tab[h] == NULL) {
		printf("\nExemplar não encontrado\n\n");
	}
	else {
		if (tab[h]->codigo == codigo) {
			tab[h] = NULL;
			printf("\nExemplar Excluido!\n\n");
		}
	}
	return tab[h];
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

//Função para imprimir a tabela Hash
void imprime_Esp(Hash tab) {
	int i = 0;

	while (i<tam){
		printf("\nPosição %d: \n", i);

		if (tab[i] == NULL) {
			printf("Posição Disponível\n");
		}
		else {
			printf("Código: %d\n", tab[i]->codigo);
			printf("Título: %s\n", tab[i]->titulo);
			printf("Autor: %s\n", tab[i]->autor);
			printf("Segmento: %s\n", tab[i]->area);
		}
		i++;
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

//Programa Principal
int main(){
	setlocale(LC_ALL, "portuguese");

	int opcao = 0;
	int codLivro = 0;
	int contCodLivros = 01;

	char tituloLivro[100];
	char autorLivro[41];
	char areaLivro[7];

	//Definição das tabelas Hash por segmento
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


	//Rotina Menu com as opções do programa
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
			gets_s(tituloLivro);
			printf("Autor do Livro: ");
			gets_s(autorLivro);
			printf("Área de segmento do Livro: ");
			gets_s(areaLivro);

			//Condicional para validar se é uma área válida
			if ((_stricmp(areaLivro, "A") != 0) && (_stricmp(areaLivro, "B") != 0) && (_stricmp(areaLivro, "C") != 0) 
				&& (_stricmp(areaLivro, "D") != 0) && (_stricmp(areaLivro, "E") != 0)) {
				printf("\nO Livro não foi adicionado - Digite uma Área Válida\n");
				break;
			}

			//Verifica o Segmento escolhido pelo usuário e seleciona a tabela Hash por segmento
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
			printf("BUSCAR LIVRO POR SEGMENTO\n\n");
			printf("Área de segmento do Livro: \n\nA - Artes\nB - Ciências Biológicas\n"
				"C - Ciências da Saúde\nD - Ciências Humanas\nE - Ciências Exatas e a Terra\n\n");
			printf("\nÁrea de segmento do Livro: ");
			getchar();
			gets_s(areaLivro);
			printf("\nQual o código do livro: ");
			scanf_s("%d", &codLivro);

			cadLivro = busca_Esp(hashLivrosA, codLivro);

			//Condicional para validar se é uma área válida
			if ((_stricmp(areaLivro, "A") != 0) && (_stricmp(areaLivro, "B") != 0) && (_stricmp(areaLivro, "C") != 0) 
				&& (_stricmp(areaLivro, "D") != 0) && (_stricmp(areaLivro, "E") != 0)) {
				printf("\nBusca não concluida - Digite uma Área Válida\n");
				break;
			}
			
			//Verifica o Segmento escolhido pelo usuário e seleciona a tabela Hash por segmento
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
			
			if (cadLivro == NULL) {
				printf("\nNão foi encontrado livro para esse código\n");
			}
			else {
				printf("\nCódigo: %d", cadLivro->codigo);
				printf("\nTitulo: %s", cadLivro->titulo);
				printf("\nAutor: %s", cadLivro->autor);
				printf("\nSegmento: %s\n", cadLivro->area);
			}
			break;

		case 3:
			printf("REMOVER LIVRO POR SEGMENTO\n\n");
			printf("Área de segmento do Livro: \n\nA - Artes\nB - Ciências Biológicas\n"
				"C - Ciências da Saúde\nD - Ciências Humanas\nE - Ciências Exatas e a Terra\n\n");
			printf("\nÁrea de segmento do Livro: ");
			getchar();
			gets_s(areaLivro);
			printf("\nQual o código do livro: ");
			scanf_s("%d", &codLivro);

			//Condicional para validar se é uma área válida
			if ((_stricmp(areaLivro, "A") != 0) && (_stricmp(areaLivro, "B") != 0) && (_stricmp(areaLivro, "C") != 0) 
				&& (_stricmp(areaLivro, "D") != 0) && (_stricmp(areaLivro, "E") != 0)) {
				printf("\nA remoção não foi Concluida - Digite uma área Válida\n");
				break;
			}

			//Verifica o Segmento escolhido pelo usuário e seleciona a tabela Hash por segmento
			if (_stricmp(areaLivro, "A") == 0) {
				cadLivro = remove_Esp(hashLivrosA, codLivro);
			}
			if (_stricmp(areaLivro, "B") == 0) {
				cadLivro = remove_Esp(hashLivrosB, codLivro);
			}
			if (_stricmp(areaLivro, "C") == 0) {
				cadLivro = remove_Esp(hashLivrosC, codLivro);
			}
			if (_stricmp(areaLivro, "D") == 0) {
				cadLivro = remove_Esp(hashLivrosD, codLivro);
			}
			if (_stricmp(areaLivro, "E") == 0) {
				cadLivro = remove_Esp(hashLivrosE, codLivro);
			}

			break;

		case 4:
			printf("IMPRIMIR LISTA DE LIVROS POR SEGMENTO\n\n");
			printf("Área de segmento do Livro: \n\nA - Artes\nB - Ciências Biológicas\n"
				"C - Ciências da Saúde\nD - Ciências Humanas\nE - Ciências Exatas e a Terra\n\n");
			printf("\nÁrea de segmento do Livro: ");
			getchar();
			gets_s(areaLivro);

			//Condicional para validar se é uma área válida
			if ((_stricmp(areaLivro, "A") != 0) && (_stricmp(areaLivro, "B") != 0) && (_stricmp(areaLivro, "C") != 0)
				&& (_stricmp(areaLivro, "D") != 0) && (_stricmp(areaLivro, "E") != 0)) {
				printf("\nNão é possível imprimir - Digite uma área Válida\n");
				break;
			}

			//Verifica o Segmento escolhido pelo usuário e seleciona a tabela Hash por segmento
			if (_stricmp(areaLivro, "A") == 0) {
				imprime_Esp(hashLivrosA);
			}
			if (_stricmp(areaLivro, "B") == 0) {
				imprime_Esp(hashLivrosB);
			}
			if (_stricmp(areaLivro, "C") == 0) {
				imprime_Esp(hashLivrosC);
			}
			if (_stricmp(areaLivro, "D") == 0) {
				imprime_Esp(hashLivrosD);
			}
			if (_stricmp(areaLivro, "E") == 0) {
				imprime_Esp(hashLivrosE);
			}

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


