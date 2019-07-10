/***************************************************************************
*  $MCI Módulo de implementação: LISC Lista duplamente encadeada circular
*
*  Arquivo gerado:              LISTAC.c
*  Letras identificadoras:      LISC
*
*
*  Projeto: INF 1301 - Implementação de jogo de Ludo.
*  Autores: Daniel Zimmer,Eduardo Maksoud e Gabriel Vasconcellos
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define tabuleiro_OWN
#include "tabuleiro.h"
#undef tabuleiro_OWN

#include "LISTAC.h"
#include "LISTA.h"
#include "io.h"

/***********************************************************************
*
*  $TC Tipo de dados: TAB tabuleiro
*
***********************************************************************/

struct TAB_tabuleiro {
	LISC_tppLista casaCircular;
	LISC_tppLista spawn[NUM_JOGADORES_MAX];
	LIS_tppLista reta[NUM_JOGADORES_MAX];
	int casasAvancadas[NUM_JOGADORES_MAX][NUM_PECAS_JOGADOR];
	int numPecasConcluidas[NUM_JOGADORES_MAX];
	int pecasConcluidas[NUM_JOGADORES_MAX][NUM_PECAS_JOGADOR];
};

typedef struct casa{
	int primeira; // se é a primeira casa a ser desenhada
	int ocupada; // se esta ocupada por uma peca
	int pontoDeDesova; // se > -1 é um ponto de desova para a peca, é referente ao jogador do numero 
	char string[NUM_CHAR_PECA];
}TAB_casa ;


char * TAB_GerarCharPeca(TAB_jogador jogador, int nPeca);

TAB_casa *TAB_CriarCasa(int p, int o, int pD, char* s){
	TAB_casa* casa = (TAB_casa*)malloc(sizeof(TAB_casa));
	IO_ErrMalloc(casa);
	casa->primeira = p;
	casa->ocupada = o;
	casa->pontoDeDesova = pD;
	strcpy(casa->string, s);
	return casa;
}

/***************************************************************************
*
*  Função: TAB &Cria o Tabuleiro.
*  ****/

TAB_Tabuleiro* TAB_CriarTabuleiro(int n) {
	int i, j;
	TAB_casa *casa;
	TAB_Tabuleiro *tab = (TAB_Tabuleiro *)malloc(sizeof(TAB_Tabuleiro));
	IO_ErrMalloc(tab);

	// bota as peças na área de espera de cada jogador

	for(i = 0; i < NUM_JOGADORES_MAX; i++) {
		tab->spawn[i] = LISC_CriarLista(NULL);

		for(j = 0; j < NUM_PECAS_JOGADOR; j++) {
			switch(n){
				case 2:
					if(i<n){
						char * peca = (char *)malloc(3 * sizeof(char));
						IO_ErrMalloc(peca);
						peca[0] = (char) i + 'A'; peca[1] = (char) j + '1'; peca[2] = '\0';
						LISC_InserirElementoApos(tab->spawn[i], TAB_CriarCasa(0, 0, -1, peca));
					}
					else{
						LISC_InserirElementoApos(tab->spawn[i], TAB_CriarCasa(0, 0, -1, "  "));
					}
					break;
				case 3:
					if(i<n){
						char * peca = (char *)malloc(3 * sizeof(char));
						IO_ErrMalloc(peca);
						peca[0] = (char) i + 'A'; peca[1] = (char) j + '1'; peca[2] = '\0';
						LISC_InserirElementoApos(tab->spawn[i], TAB_CriarCasa(0, 0, -1, peca));
					}
					else{
						LISC_InserirElementoApos(tab->spawn[i], TAB_CriarCasa(0, 0, -1, "  "));
					}
					break;
				case 4:
					{
						char * peca = (char *)malloc(3 * sizeof(char));
						IO_ErrMalloc(peca);
						peca[0] = (char) i + 'A'; peca[1] = (char) j + '1'; peca[2] = '\0';
						LISC_InserirElementoApos(tab->spawn[i], TAB_CriarCasa(0, 0, -1, peca));
					}
					break;
				}
			}

		LISC_AvancarElementoCorrente(tab->spawn[i], 1); //Colocar na posicao correta de desenho
	}

	for (i = 0; i < NUM_JOGADORES_MAX; i++) {
		tab->reta[i] = LIS_CriarLista(NULL);
		IO_ErrMalloc(tab->reta[i]);

		LIS_InserirElementoApos(tab->reta[i], TAB_CriarCasa(1, 0, -1, "  "));

		for(j = 1; j < NUM_CASAS_RETA; j++) {
			LIS_InserirElementoApos(tab->reta[i], TAB_CriarCasa(0, 0, -1, "  "));
		}
	}

	// deixa as casas vazias e define os pontos de spawn
	tab->casaCircular = LISC_CriarLista(NULL);
	IO_ErrMalloc(tab->casaCircular);

	for (i = 0; i < NUM_CASAS; i++) {

		LISC_InserirElementoApos(tab->casaCircular, TAB_CriarCasa(0, 0, -1, "  "));

		switch (i) {
			//armazenar ponteiros para a casa anterior a inicial de cada jogador
			case 32: casa = (TAB_casa *)LISC_ObterValor(tab->casaCircular); casa->pontoDeDesova = 0; break;
			case 2:  casa = (TAB_casa *)LISC_ObterValor(tab->casaCircular); casa->pontoDeDesova = 1; break;
			case 12: casa = (TAB_casa *)LISC_ObterValor(tab->casaCircular); casa->pontoDeDesova = 2; break;
			case 22: casa = (TAB_casa *)LISC_ObterValor(tab->casaCircular); casa->pontoDeDesova = 3; break;

			//casa de referencia para onde o tabuleiro comeca a ser desenhado
			case 0: casa = (TAB_casa *)LISC_ObterValor(tab->casaCircular); casa->primeira = 1; break;
		}
	}

	//iniciar o contador de casas avancadas e pecas concluidas para cada peca
	for(i = 0; i < NUM_JOGADORES_MAX; i++){
		tab->numPecasConcluidas[i] = 0;
		for(j = 0; j < NUM_PECAS_JOGADOR; j++){
			tab->casasAvancadas[i][j] = 0;
			tab->pecasConcluidas[i][j] = 0;
		}
	}

	return tab;
}
/* Fim função: TAB &Cria o Tabuleiro.*/

/***************************************************************************
*
*  Função: TAB &Obter valor do elemento corrente, na lista casa circular.
*  ****/

char* TAB_ObterValorCasa(TAB_Tabuleiro *tab) {
	TAB_casa *casa = (TAB_casa *) LISC_ObterValor(tab->casaCircular);
	return casa->string;
}

/* Fim função: TAB &Obter valor do elemento corrente, na lista casa circular.*/

/***************************************************************************
*
*  Função: TAB &Proucura a casa com o valor corresponde ao passado na função.
*  ****/

int TAB_ProcurarCasa(TAB_Tabuleiro *tab, int p, int pD, char* s){
	int i;
	TAB_casa* casa;
	for(i = 0; i < NUM_CASAS; i++){
		casa = (TAB_casa*)LISC_ObterValor(tab->casaCircular);
		if( p != -1){
			if(casa->primeira == p){
				return 1;
			}
		}
		else if(pD != -1){
			if(casa->pontoDeDesova == pD){
				return 1;
			}
		}
		else if(strcmp(casa->string, s) == 0){
				return 1;
		}
		LISC_AvancarElementoCorrente(tab->casaCircular, 1);
	}
	return 0;
}

int TAB_ProcurarReta(TAB_Tabuleiro *tab, TAB_jogador j, int p, int pD, char* s){
	int i;
	TAB_casa* casa;

	IrInicioLista(tab->reta[j]);

	for(i = 0; i < NUM_CASAS_RETA; i++){
		casa = (TAB_casa*)LIS_ObterValor(tab->reta[j]);
		if( p != -1){
			if(casa->primeira == p){
				return 1;
			}
		}
		else if(pD != -1){
			if(casa->pontoDeDesova == pD){
				return 1;
			}
		}
		else if(strcmp(casa->string, s) == 0){
				return 1;
		}
		LIS_AvancarElementoCorrente(tab->reta[j], 1);
	}
	return 0;
}

int TAB_ProcurarSpawn(TAB_Tabuleiro *tab, TAB_jogador j, int p, int pD, char* s){
	int i;
	TAB_casa* casa;

	for(i = 0; i < NUM_PECAS_JOGADOR; i++){
		casa = (TAB_casa*)LISC_ObterValor(tab->spawn[j]);
		if( p != -1){
			if(casa->primeira == p){
				return 1;
			}
		}
		else if(pD != -1){
			if(casa->pontoDeDesova == pD){
				return 1;
			}
		}
		else if(strcmp(casa->string, s) == 0){
				return 1;
		}
		LISC_AvancarElementoCorrente(tab->spawn[j], 1);
	}
	return 0;
}

/* Fim função: TAB &Procura a casa com o valor corresponde ao passado na função.*/

/***************************************************************************
*
*  Função: TAB &Obter valor do elemento corrente, na lista spawn.
*  ****/

char* TAB_ObterValorSpawn(TAB_Tabuleiro *tab, TAB_jogador jogador) {
	TAB_casa *casa = (TAB_casa *) LISC_ObterValor(tab->spawn[jogador]);
	return casa->string;
}

/* Fim função: TAB &Obter valor do elemento corrente, na lista spawn.*/

/***************************************************************************
*
*  Função: TAB &Obter valor do elemento corrente, na lista reta.
*  ****/

char* TAB_ObterValorReta(TAB_Tabuleiro *tab, TAB_jogador jogador) {
	TAB_casa *casa = (TAB_casa *) LIS_ObterValor(tab->reta[jogador]);
	return casa->string;
}

/* Fim função: TAB &Obter valor do elemento corrente, na lista reta.*/

/***************************************************************************
*
*  Função: TAB &Avança o elemento corrente, na lista casa circular.
*  ****/

void TAB_AvancarCasa(TAB_Tabuleiro *tab, int n) {
	LISC_AvancarElementoCorrente(tab->casaCircular, n);
}

/* Fim função: TAB &Avança o elemento corrente, na lista casa circular.*/

/***************************************************************************
*
*  Função: TAB &Avança o elemento corrente, na lista spawn.
*  ****/

void TAB_AvancarSpawn(TAB_Tabuleiro *tab, TAB_jogador jogador, int n) {
	LISC_AvancarElementoCorrente(tab->spawn[jogador], n);
}

/* Fim função: TAB &Avança o elemento corrente, na lista spawn.*/

/***************************************************************************
*
*  Função: TAB &Avança o elemento corrente, na lista reta.
*  ****/

void TAB_AvancarReta(TAB_Tabuleiro *tab, TAB_jogador jogador, int n) {
	LIS_AvancarElementoCorrente(tab->reta[jogador], n);
}

void TAB_IrInicioReta(TAB_Tabuleiro *tab, TAB_jogador jogador){
	IrInicioLista(tab->reta[jogador]);
}

/* Fim função: TAB &Avança o elemento corrente, na lista reta.*/

void TAB_SairSpawn(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca){
	char * peca = TAB_GerarCharPeca(jogador, nPeca);
	TAB_casa *casa;

	TAB_ProcurarSpawn(tab, jogador, -1, -1, peca);

	casa = (TAB_casa *)LISC_ObterValor(tab->spawn[jogador]);
	strcpy(casa->string, "  ");

	TAB_ProcurarCasa(tab, -1, jogador, "  ");

	casa = (TAB_casa *)LISC_ObterValor(tab->casaCircular);
	strcpy(casa->string, peca);
}

int TAB_VerificarSpawnPeca(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca){
	char * peca = TAB_GerarCharPeca(jogador, nPeca);
	if((TAB_ProcurarSpawn(tab, jogador, -1, -1, peca))){
		return 1;
	}
	else{
		return 0;
	}
}

int TAB_VerificarSpawnJogador(TAB_Tabuleiro *tab, TAB_jogador jogador){
	int i;
	for(i = 1; i <= NUM_PECAS_JOGADOR; i++){
		char * peca = TAB_GerarCharPeca(jogador, i);
		if(!TAB_ConferirPecaConcluida(tab, jogador, i)){
			if(!(TAB_ProcurarSpawn(tab, jogador, -1, -1, peca))){
				return 0;
			}
		}
	}
	return 1;
}

int TAB_VerificarReta(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca){
	char * peca = TAB_GerarCharPeca(jogador, nPeca);
	if(TAB_ProcurarReta(tab, jogador , -1, -1, peca)){
		return 1;
	}
	else{
		return 0;
	}
}

int TAB_VerificarTabuleiro(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca){
	char * peca = TAB_GerarCharPeca(jogador, nPeca);
	if(TAB_ProcurarCasa(tab, -1, -1, peca)){
		return 1;
	}
	else{
		return 0;
	}
}

int TAB_VerificarCasa(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca, int dado){
	TAB_casa *casa;
	char *peca = TAB_GerarCharPeca(jogador, nPeca);
	TAB_jogador j;

	if(TAB_ProcurarReta(tab, jogador, -1, -1, peca)){
		return 1;
	}

	if(!(TAB_ProcurarCasa(tab, -1, -1, peca))){
		TAB_ProcurarCasa(tab, -1, jogador, "  ");
		dado = 0;
	}

	LISC_AvancarElementoCorrente(tab->casaCircular, dado);

	casa = (TAB_casa*)LISC_ObterValor(tab->casaCircular);

	strcpy(peca, casa->string);

	if(peca[0] == ('A' + jogador)){
		return 0;
	}
	else if(peca[0] >= 'A' && peca[0] <= 'D'){
		strcpy(casa->string, "  ");

		j = (TAB_jogador) (peca[0] - 'A');

		TAB_ProcurarSpawn(tab, j, -1, -1, "  ");

		casa = (TAB_casa *)LISC_ObterValor(tab->spawn[j]);

		strcpy(casa->string, peca);
	}

	TAB_ProcurarCasa(tab, 1, -1, "  ");

	return 1;
}

char * TAB_GerarCharPeca(TAB_jogador jogador, int nPeca){
	char *cPeca = (char*) malloc(sizeof(char)*3);
	IO_ErrMalloc(cPeca);
	cPeca[0] = 'A' + (char) jogador; //Codigo ASCII para letra A + int equivalente ao enum do jogador
	cPeca[1] = '0' + (char) nPeca; //Codigo ASCII para numero 1 + int equivalente ao numero da peca
	cPeca[2] = '\0';
	return cPeca;
}

void TAB_MoverPeca(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca, int n){
	TAB_casa *casa;
	char* peca = TAB_GerarCharPeca(jogador, nPeca);

	if(!TAB_VerificarReta(tab, jogador, nPeca)){

		TAB_ProcurarCasa(tab, -1, -1, peca);

		casa = (TAB_casa*)LISC_ObterValor(tab->casaCircular);

		casa->ocupada = 0;
		strcpy(casa->string, "  ");

		TAB_AvancarCasa(tab, n);

		casa = (TAB_casa*)LISC_ObterValor(tab->casaCircular);

		casa->ocupada = 1;
		strcpy(casa->string, peca);

		tab->casasAvancadas[jogador][nPeca-1] += n;
	}
	else{
		if(n == 3 - tab->numPecasConcluidas[jogador]){
			tab->numPecasConcluidas[jogador] += 1;
			
			casa = (TAB_casa*)LIS_ObterValor(tab->reta[jogador]);

			casa->ocupada = 0;

			strcpy(casa->string, "  ");

			TAB_AvancarReta(tab, jogador, n);
			
			casa = (TAB_casa*)LIS_ObterValor(tab->reta[jogador]);

			strcpy(casa->string, peca);

			tab->pecasConcluidas[jogador][nPeca-1] = 1;
		}
	}
}

int TAB_RolarDado(){
	return (rand() % 6) + 1; //retornar o numero aleatorio com intervalo [1, 6]
}

void TAB_Transicionar(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca){
	TAB_casa *casa;
	char* peca = TAB_GerarCharPeca(jogador, nPeca);

	if(tab->casasAvancadas[jogador][nPeca-1] >= NUM_CASAS){

		TAB_ProcurarReta(tab, jogador, 1, -1, "  ");

		casa = (TAB_casa*)LIS_ObterValor(tab->reta[jogador]);

		if(!casa->ocupada && !tab->pecasConcluidas[jogador][nPeca-1]){
			TAB_ProcurarCasa(tab, -1, -1, peca);
		
			casa = (TAB_casa*)LISC_ObterValor(tab->casaCircular);

			casa->ocupada = 0;
			strcpy(casa->string, "  ");

			casa = (TAB_casa*)LIS_ObterValor(tab->reta[jogador]);

			casa->ocupada = 1;
			strcpy(casa->string, peca);

			if(tab->numPecasConcluidas[jogador] >= 3 ){
				tab->pecasConcluidas[jogador][nPeca] = 0;
				tab->numPecasConcluidas[jogador] += 1;
			}
		}
	}

}

int TAB_ConferirVitoria(TAB_Tabuleiro *tab, char *c){
	int i;
	for(i = 0; i < NUM_JOGADORES_MAX; i++){
		if(tab->numPecasConcluidas[i] > 3){
			*c = (char) i + 'A';
			return 1;
		}
	}
	return 0;
}

int TAB_ConferirPecaConcluida(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca){
	return tab->pecasConcluidas[jogador][nPeca-1];
}

/********** Fim do módulo de implementação: TAB tabuleiro **********/
