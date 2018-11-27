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

int main(){
	setlocale(LC_ALL, "portuguese");

	Acervo* cadLivro;
	Hash hashLivros;

	inicializa_Esp(hashLivros);

	insere_Esp(hashLivros, 01, "Titulo 1", "Teste Autor 1", "A");

	printf("\nCódigo: ", cadLivro->codigo);
	printf("\nTitulo: ", cadLivro->titulo);
	printf("\nAutor: ", cadLivro->autor);
	printf("\nArea: ", cadLivro->area);

	getchar();
}


