#include <stdio.h>
#include <stdlib.h>
#include "LISTAC.h"
#include "tabuleiro.h"
#include "io.h"
#include <string.h>
#include <conio.h>

/*  Membros do Grupo do trabalho: Daniel Zimmer,Eduardo Maksoud,Gabriel Vasconcellos
*	
*   Partida.c - Arquivo que contém a main utilizada para gerar o programa TRAB2-1.exe
*
*/

void GerenciarTurno(TAB_Tabuleiro *tab, int n);

int main() {
	//inicializar variaveis
	char c;
	TAB_Tabuleiro *tab;
	int numeroJogadores = 0, condicaoDeVitoria = 0;

	//iniciar o jogo
	IO_PrintMensagem(IO_MensagemInicio);
	IO_InputNumeroJogadores(&numeroJogadores);
	tab = TAB_CriarTabuleiro(numeroJogadores);
	IO_PrintTabuleiro(tab);

	while(!condicaoDeVitoria){
		GerenciarTurno(tab, numeroJogadores);
		condicaoDeVitoria = TAB_ConferirVitoria(tab, &c);
	}

	IO_PrintTabuleiro(tab);

	printf("\nParabens! O jogador %c ganhou!\n", c);
	getch();

	return 0;
}

void GerenciarTurno(TAB_Tabuleiro *tab, int n){

	int i, dado, nPeca, comandoCorreto;
	TAB_jogador jogador;
	char c = 'A';

	for(i = 0; i < n; ++i){

		dado = 0;
		nPeca = 0;
		comandoCorreto = 0; //esperar receber um comando correto
		jogador = (TAB_jogador) i; // armazena o jogador deste turno
		c = 'A' + i; // armazena o char do jogador

		printf("\nVez do jogador %c, aperte enter para rolar o dado.\n", c);
		getch();

		dado = TAB_RolarDado();

		if(TAB_VerificarSpawnJogador(tab, jogador) && dado != 6){
			printf("Nao foi dessa vez, tente na proxima rodada!");
			comandoCorreto = 1;
		}
		else{
			printf("\nO jogador %c rolou %d, escolha qual peca deseja mover.\n", c, dado);
			nPeca = IO_ReceberDigito();
		}

		while(!comandoCorreto){
			if(nPeca <= 4 && nPeca >= 1){
				if(!TAB_ConferirPecaConcluida(tab, jogador, nPeca)){
					if(dado == 6){
						if(TAB_VerificarSpawnPeca(tab, jogador, nPeca)){
							if(TAB_VerificarCasa(tab, jogador, nPeca, dado)){
								TAB_SairSpawn(tab, jogador, nPeca);
								printf("a\n");
								comandoCorreto = 1;
							}
							else{
								IO_PrintMensagem(IO_NaoPodeComer);
								nPeca= IO_ReceberDigito();
							}
						}
						else if(!TAB_VerificarTabuleiro(tab, jogador, nPeca) && !(TAB_VerificarReta(tab, jogador, nPeca))){
							IO_PrintMensagem(IO_PecaNaoEstaNoTabuleiro);
							nPeca = IO_ReceberDigito();
						}
						else if(!TAB_VerificarCasa(tab, jogador, nPeca, dado)){
							IO_PrintMensagem(IO_NaoPodeComer);
							nPeca = IO_ReceberDigito();
						}
						else{
							TAB_MoverPeca(tab, jogador, nPeca, dado);
							TAB_Transicionar(tab, jogador, nPeca);
							comandoCorreto = 1;
						}
					}
					else if(!TAB_VerificarTabuleiro(tab, jogador, nPeca) && !(TAB_VerificarReta(tab, jogador, nPeca))){
						IO_PrintMensagem(IO_PecaNaoEstaNoTabuleiro);
						nPeca = IO_ReceberDigito();
					}
					else if(!TAB_VerificarCasa(tab, jogador, nPeca, dado)){
						IO_PrintMensagem(IO_NaoPodeComer);
						nPeca = IO_ReceberDigito();
					}
					else if(!TAB_VerificarSpawnPeca(tab, jogador, nPeca)){
						TAB_MoverPeca(tab, jogador, nPeca, dado);
						TAB_Transicionar(tab, jogador, nPeca);
						comandoCorreto = 1;
					}
					else{
						IO_PrintMensagem(IO_PecaInvalida);
						nPeca = IO_ReceberDigito();
					}
				}
				else{
					IO_PrintMensagem(IO_PecaInvalida);
					nPeca = IO_ReceberDigito();
				}
			}
		}

		IO_PrintTabuleiro(tab);
	}
}