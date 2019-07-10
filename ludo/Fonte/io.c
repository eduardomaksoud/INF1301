/***************************************************************************
*  $MCI Módulo de implementação: IO Input e Output
*
*  Arquivo gerado:              io.c
*  Letras identificadoras:      IO
*
*
*  Projeto: INF 1301 - Implementação de jogo de Ludo.
*  Autores: Daniel Zimmer,Eduardo Maksoud e Gabriel Vasconcellos
*
***************************************************************************/

#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabuleiro.h"

#define TRUE 1

//Função: IO &errMalloc
void IO_ErrMalloc(void *p) {
	if (p == NULL) { printf("erro alocando memória!"); exit(TAB_ErrMalloc); }
}

//Função: IO &printTabuleiro
void IO_PrintTabuleiro(TAB_Tabuleiro *tab) {
	int i, j;
	char* s;

	char c[40][3];
	char sA[4][3];
	char sB[4][3];
	char sC[4][3];
	char sD[4][3];
	char rA[4][3];
	char rB[4][3];
	char rC[4][3];
	char rD[4][3];

	TAB_ProcurarCasa(tab, 1, -1, "  ");

	for (i = 0; i < NUM_CASAS; i++) {
		s = TAB_ObterValorCasa(tab);
		strcpy(c[i], s);
		TAB_AvancarCasa(tab, 1);
	}


	for (i = 0; i < NUM_PECAS_JOGADOR; i++) {
		strcpy(sA[i], TAB_ObterValorSpawn(tab, TAB_A));
		strcpy(sB[i], TAB_ObterValorSpawn(tab, TAB_B));
		strcpy(sC[i], TAB_ObterValorSpawn(tab, TAB_C));
		strcpy(sD[i], TAB_ObterValorSpawn(tab, TAB_D));

		TAB_AvancarSpawn(tab, TAB_A, 1);
		TAB_AvancarSpawn(tab, TAB_B, 1);
		TAB_AvancarSpawn(tab, TAB_C, 1);
		TAB_AvancarSpawn(tab, TAB_D, 1);
	}

	for(i = 0; i < NUM_JOGADORES_MAX; i++){ //voltar para casa inicial de desenho
		TAB_ProcurarReta(tab, (TAB_jogador)i, 1, -1, "  ");
	}

	for(i = 0; i < NUM_CASAS_RETA; i++){
		strcpy(rA[i], TAB_ObterValorReta(tab, TAB_A));
		strcpy(rB[i], TAB_ObterValorReta(tab, TAB_B));
		strcpy(rC[i], TAB_ObterValorReta(tab, TAB_C));
		strcpy(rD[i], TAB_ObterValorReta(tab, TAB_D));

		if( i < 3){
			for(j = 0; j < NUM_JOGADORES_MAX; j++){
				TAB_AvancarReta(tab, (TAB_jogador) j, 1);
			}
		}
	}


	printf(
		"\n"
		" \\\\==============================================================//\n"
		" ||                                                              ||\n"
		" ||                        ____ ____ ____                        ||\n"
		" ||      ____A____        |    |    |   v|        ____B____      ||\n"
		" ||     |    |    |       | %s   %s   %s |       |    |    |     ||\n"
		" ||     | %s | %s |       |_  _|_  _|_  _|       | %s | %s |     ||\n"
		" ||     |____|____|       |    |   B|    |       |____|____|     ||\n"
		" ||     |    |    |       | %s | %s | %s |       |    |    |     ||\n"
		" ||     | %s | %s |       |_  _|_  _|_  _|       | %s | %s |     ||\n"
		" ||     |____|____|       |    |   B|    |       |____|____|     ||\n"
		" ||                       | %s | %s | %s |                       ||\n"
		" ||                       |_  _|_  _|_  _|                       ||\n"
		" ||                       |    |   B|    |                       ||\n"
		" ||                       | %s | %s | %s |                       ||\n"
		" ||    ____ ____ ____ ____|_  _|_  _|_  _|____ ____ ____ ____    ||\n"
		" ||   |>   |    |    |    |    |   B|    |    |    |    |    |   ||\n"
		" ||   | %s   %s   %s   %s   %s | %s | %s   %s   %s   %s   %s |   ||\n"
		" ||   |_  _|____|____|____|____|____|____|____|____|____|_  _|   ||\n"
		" ||   |    |   A|   A|   A|   A|    |   C|   C|   C|   C|    |   ||\n"
		" ||   | %s   %s   %s   %s   %s | ## | %s   %s   %s   %s   %s |   ||\n"
		" ||   |_  _|____|____|____|____|____|____|____|____|____|_  _|   ||\n"
		" ||   |    |    |    |    |    |   D|    |    |    |    |    |   ||\n"
		" ||   | %s   %s   %s   %s   %s | %s | %s   %s   %s   %s   %s |   ||\n"
		" ||   |____|____|____|____|_  _|_  _|_  _|____|____|____|___<|   ||\n"
		" ||                       |    |   D|    |                       ||\n"
		" ||                       | %s | %s | %s |                       ||\n"
		" ||                       |_  _|_  _|_  _|                       ||\n"
		" ||                       |    |   D|    |                       ||\n"
		" ||      ____D____        | %s | %s | %s |        ____C____      ||\n"
		" ||     |    |    |       |_  _|_  _|_  _|       |    |    |     ||\n"
		" ||     | %s | %s |       |    |   D|    |       | %s | %s |     ||\n"
		" ||     |____|____|       | %s | %s | %s |       |____|____|     ||\n"
		" ||     |    |    |       |_  _|_  _|_  _|       |    |    |     ||\n"
		" ||     | %s | %s |       |    |    |    |       | %s | %s |     ||\n"
		" ||     |____|____|       | %s | %s | %s |       |____|____|     ||\n"
		" ||                       |^___|____|____|                       ||\n"
		" ||                                                              ||\n"
		" ||                                                              ||\n"
		" //==============================================================\\\\\n\n",

		                            c[ 0], c[ 1], c[ 2],
		     sA[0], sA[1],                                     sB[0], sB[1],
		                            c[39], rB[0], c[ 3],
		     sA[3], sA[2],                                     sB[3], sB[2],
		                            c[38], rB[1], c[ 4],

		                            c[37], rB[2], c[ 5],

		c[32], c[33], c[34], c[35], c[36], rB[3], c[ 6], c[ 7], c[ 8], c[ 9], c[10],

		c[31], rA[0], rA[1], rA[2], rA[3],        rC[3], rC[2], rC[1], rC[0], c[11],
		
		c[30], c[29], c[28], c[27], c[26], rD[3], c[16], c[15], c[14], c[13], c[12],
		
		                            c[25], rD[2], c[17],

		                            c[24], rD[1], c[18],
		     sD[0], sD[1],                                     sC[0], sC[1],
		                            c[23], rD[0], c[19],
		     sD[3], sD[2],                                     sC[3], sC[2],
		                            c[22], c[21], c[20]
		);

}

void IO_PrintMensagem(char* str){
	printf(str);
}

void IO_InputNumeroJogadores(int * n){
	printf(IO_NumeroJogadores);
	*n = IO_ReceberDigito();
	if(*n<2 || *n>4){
		printf(IO_NumeroJogadoresInvalido);
		IO_InputNumeroJogadores(n);
	}
}

int IO_ReceberDigito(){
    int digito;

    while (TRUE) {
        char str[256];
        scanf("%s", str);

        if(str[0] >= '0' && str[0] <= '4' && str[1] == '\0'){
            digito = str[0] - '0';
            break;
        }

        printf("\nO input tem que ser um numero entre 0 e 4.\n");
    }

    return digito;
}

/********** Fim do módulo de implementação: IO Input e Output **********/
