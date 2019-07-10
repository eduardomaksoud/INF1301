#ifndef io_ 
#define io_

#define IO_MensagemInicio "\n _    _   _ ____   ___ \n| |  | | | |  _ \\ / _ \\ \n| |  | | | | | | | | | |\n| |__| |_| | |_| | |_| |\n|_____\\___/|____/ \\___/ \nSeja bem-vindo ao jogo!\n"
#define IO_PecaNaoEstaNoTabuleiro "\nA peca nao esta no tabuleiro, escolha outra.\n"
#define IO_PecaInvalida "\nPeca invalida, escolha outra.\n"
#define IO_NumeroJogadores "\nDigite o numero de jogadores: "
#define IO_NumeroJogadoresInvalido "Numero de jogadores invalidos, digite novamente."
#define IO_NaoPodeComer "\nVoce nao pode comer essa peca!\n"

/***************************************************************************
*
*  $MCD Módulo de definição: IO  
*
*  Arquivo gerado:              io.h
*  Letras identificadoras:      IO
*
*  Autores: Daniel Zimmer, Eduardo Maksoud e Gabriel Vasconcellos 
*
*  $ED Descrição do módulo
*      
*  Módulo responsável pelo Input e Output do Jogo.
*
***************************************************************************/

#include "tabuleiro.h"

/***********************************************************************
*
*  $FC Função: IO  &Verifica se houve erro de memória.
*
*  $ED Descrição da função
*     
*  Verifica se o ponteiro passado como parâmetro possui valor nulo.
*
*  $EP Parâmetros
*     p  - ponteiro onde será realizado o teste.
*   
***********************************************************************/

void IO_ErrMalloc(void *p);

/***********************************************************************
*
*  $FC Função: IO  &Printa o tabuleiro.
*
*  $ED Descrição da função
*     
*  Exibe o tabuleiro.
*
*  $EP Parâmetros
*     tab  - ponteiro para o tabuleiro que se deseja printar.
*   
***********************************************************************/

void IO_PrintTabuleiro(TAB_Tabuleiro *tab);

void IO_PrintMensagem(char * str);

void IO_InputNumeroJogadores(int * n);

int IO_ReceberDigito();

/********** Fim do módulo de definição: IO **********/

#endif
