// Exercício de Estrutura de dados 08/11/2018 - Tabela de Espalhamento


#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

#define tam 5

struct matricula {
	int RA;
	char nome[20];
};
typedef struct matricula MatAluno;
typedef MatAluno* Hash[tam];

int funcao_Esp(int RA) {
	return (RA % tam);
}

MatAluno* insere_Esp(Hash tab, int RA, char name[]) {
	
	int h = funcao_Esp(RA); 

	/*while (tab[h] != NULL){
		if (tab[h]->RA == RA) {
			break;
		}
		h = (h + 1) % tam;
	}*/

	/*if (tab[h] == NULL) {
		
	}*/

	tab[h] = (MatAluno *)malloc(sizeof(MatAluno));
	tab[h]->RA = RA;
	strcpy_s(tab[h]->nome, name);
	printf("RA: d% - Nome: %c", tab[h]->RA, tab[h]->nome);

	return tab[h];

}

void imprimir(Hash tab) {
	int h = 0;
	
	while (h > tam){
		if (tab[h] != NULL) {
			printf("RA: d% - Nome: %c", tab[h]->RA, tab[h]->nome);
		}
		h += 1;
	}
}


int main(){
	MatAluno* cadAlunos;
	Hash hashAlunos;
	
	int RA;
	char nome[20];

	RA = 123;
	strcpy_s(nome, "Thiago");

	cadAlunos = insere_Esp(hashAlunos, RA, nome);

	imprimir(hashAlunos);

	

	system("Pause");


}
