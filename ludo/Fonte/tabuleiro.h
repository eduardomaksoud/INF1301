#if ! defined( tabuleiro_) 
#define tabuleiro_

/***************************************************************************
*
*  $MCD Módulo de definição: TAB  tabuleiro
*
*  Arquivo gerado:              tabuleiro.h
*  Letras identificadoras:      TAB
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Daniel Zimmer, Eduardo Maksoud e Gabriel Vasconcellos 
*
*  $ED Descrição do módulo
*      
*  Módulo responsável pela criação dos três tipos de lista que compõe o tabuleiro.
*  Os três tipos de lista são casaCircular(40 casas),spawn(4 casas) e reta(4 casas).
*
*  Permite através de suas funções, obter os valores armazenados nas casas de
*  cada lista.
*  
*  Também é possível avançar com o elemento corrente nas três listas, ou proucurar
*  nas listas um determinado valor.
*
***************************************************************************/
#define NUM_CASAS 40
#define NUM_JOGADORES_MAX 4
#define NUM_PECAS_JOGADOR 4
#define NUM_CASAS_RETA 4
#define NUM_DESENHAVEIS 5
#define NUM_CHAR_PECA 3
/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do tabuleiro.
*
***********************************************************************/

typedef enum {
	TAB_OK,
	TAB_ErrMalloc
} TAB_CondRet;

/***********************************************************************
*
*  $TC Tipo de dados: TAB Jogadores
*
*
*  $ED Descrição do tipo
*     Identifica os valores de cada jogador.
*
***********************************************************************/

typedef enum {
		TAB_A,
		TAB_B,
		TAB_C,
		TAB_D

	} TAB_jogador;

typedef struct TAB_tabuleiro TAB_Tabuleiro;

/***********************************************************************
*
*  $FC Função: TAB  &Criar tabuleiro
*
*  $ED Descrição da função
*     Cria o tabuleiro de ludo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o tabuleiro.
*     Este ponteiro será utilizado pelas funções que manipulem e
*
*     Se ocorreu algum erro, a função IO_errMalloc() é chamada.
*     Não será dada mais informação quanto ao problema ocorrido.
*
*	
*
***********************************************************************/	

TAB_Tabuleiro* TAB_CriarTabuleiro(int n);

/***********************************************************************
*
*  $FC Função: TAB  &Obter valor do elemento corrente na lista casa circular.
*
*  $ED Descrição da função
*     Obtem o valor do elemento corrente na lista casa circular.
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*
*	$AE Assertivas de entrada
*	tab deve ser diferente de NULL
*
*	$AS Assertivas de Saída
*	Permite armazenar o elemento corrente da lista casa circular.
*
*  $FV Valor retornado
*     não NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
***********************************************************************/

char* TAB_ObterValorCasa(TAB_Tabuleiro *tab);

/***********************************************************************
*
*  $FC Função: TAB  &Procura a casa com o valor corresponde ao passado na função.
*
*  $ED Descrição da função
*    Proucura a casa com o valor corresponde ao passado na função.
*
*	$AE Assertivas de entrada
*	tab deve ser diferente de NULL
*	s deve ser diferente de NULL
*
*  $EP Parâmetros
*     tab - Ponteiro para o tabuleiro.
*	  p - parametro de casa que informa se ela é inicial.
*	  pD - parametro de casa que informa se ela é "spawn"
*     s - valor da casa, em string
*
*	$FV Valor retornado
*    Retorna o int 1 se achou, e 0 se não achou.
*
***********************************************************************/

int TAB_ProcurarCasa(TAB_Tabuleiro *tab, int p, int pD, char* s);

/***********************************************************************
*
*  $FC Função: TAB  &Procurar reta
*
*  $ED Descrição da função
*    Localiza peças na reta do jogador desejado.
*
*	$AE Assertivas de entrada
*	tab deve ser diferente de NULL
*   
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro.
*	 jogador - número que representa o jogador.
* 	  p - parametro de casa que informa se ela é inicial.
*	  pD - parametro de casa que informa se ela é "spawn"
*     s - valor da casa, em string
*	
*	$FV Valor retornado
*    Retorna o int 1 se achou, e 0 se não achou.
*
***********************************************************************/

int TAB_ProcurarReta(TAB_Tabuleiro *tab, TAB_jogador j, int p, int pD, char* s);

/***********************************************************************
*
*  $FC Função: TAB  &Obter valor do elemento corrente na lista spawn.
*
*  $ED Descrição da função
*     Obtem o valor do elemento corrente na lista spawn.
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*
*  $FV Valor retornado
*     não NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

char* TAB_ObterValorSpawn(TAB_Tabuleiro *tab, TAB_jogador jogador);


/***********************************************************************
*
*  $FC Função: TAB  &Obter valor do elemento corrente na lista reta.
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*
*  $ED Descrição da função
*     Obtem o valor do elemento corrente na lista reta.
*
*  $FV Valor retornado
*     não NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

char* TAB_ObterValorReta(TAB_Tabuleiro *tab, TAB_jogador jogador);

/***********************************************************************
*
*  $FC Função: TAB &Avança o elemento corrente, na lista casa circular.
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 n - o número que se deseja avançar
*
*  $ED Descrição da função
*     Avança o elemento corrente, na lista casa circular.
*
***********************************************************************/

void TAB_AvancarCasa(TAB_Tabuleiro *tab, int n);

/***********************************************************************
*
*  $FC Função: TAB &Avança o elemento corrente, na lista spawn.
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 n - o número que se deseja avançar
*
*  $ED Descrição da função
*     Avança o elemento corrente, na lista spawn.
***********************************************************************/

void TAB_AvancarSpawn(TAB_Tabuleiro *tab, TAB_jogador jogador, int n);

/***********************************************************************
*
*  $FC Função: TAB &Avança o elemento corrente, na lista reta.
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 n - o número que se deseja avançar
*
*  $ED Descrição da função
*     Avança o elemento corrente, na lista reta.
***********************************************************************/
 
void TAB_AvancarReta(TAB_Tabuleiro *tab, TAB_jogador jogador, int n);

/***********************************************************************
*
*  $FC Função: TAB &Ir para o inicio da reta
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquela reta.
*
*  $ED Descrição da função
*     Vai para o início da reta daquele jogador.
***********************************************************************/

void TAB_IrInicioReta(TAB_Tabuleiro *tab, TAB_jogador jogador);

/***********************************************************************
*
*  $FC Função: TAB &Sair do Spawn
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*	 nPeca - o número da peça daquele jogador
*
*  $ED Descrição da função
*     Sai do spawn com a peça escolhida.
***********************************************************************/

void TAB_SairSpawn(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca);

/***********************************************************************
*
*  $FC Função: TAB &VerificarSpawnPeca
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*	 nPeca - o número da peça daquele jogador
*
*  $ED Descrição da função
*     Verifica se uma peça qualquer está dentro do "spawn" de um certo jogador.
***********************************************************************/

int TAB_VerificarSpawnPeca(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca);

/***********************************************************************
*
*  $FC Função: TAB &VerificarSpawnJogador
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*
*  $ED Descrição da função
*     Verifica se um certo jogador possui qualquer peça no seu "spawn".
***********************************************************************/

int TAB_VerificarSpawnJogador(TAB_Tabuleiro *tab, TAB_jogador jogador);

/***********************************************************************
*
*  $FC Função: TAB &VerificarReta
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*	 nPeca - o número da peça daquele jogador
*
*  $ED Descrição da função
*     Verifica se uma peça específica de um jogador está dentro da reta, de acordo com o número inserido pelo jogador no input.
***********************************************************************/

int TAB_VerificarReta(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca);

/***********************************************************************
*
*  $FC Função: TAB &VerificarTabuleiro
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*	 nPeca - o número da peça 
*
*  $ED Descrição da função
*     Verifica se uma certa peça está no tabuleiro.
***********************************************************************/

int TAB_VerificarTabuleiro(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca);

/***********************************************************************
*
*  $FC Função: TAB &VerificarCasa
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*	 nPeca - o número da peça 
*    dado - valor tirado no dado por aquele jogador
*
*  $ED Descrição da função
*     Trata o ato de "comer" uma peça, na qual a peça que estava inicialmente na casa, é redirecionada para o "spawn" do seu jogador.
***********************************************************************/

int TAB_VerificarCasa(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca, int dado);

/***********************************************************************
*
*  $FC Função: TAB &Mover Peca
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*	 nPeca - o número da peça 
*    n - o número de casa que serão andadas
*
*  $ED Descrição da função
*     Movimenta a peca do jogador pelo tabuleiro.
***********************************************************************/

void TAB_MoverPeca(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca, int n);

/***********************************************************************
*
*  $FC Função: TAB &Rolar Dado
*
*
*  $ED Descrição da função
*     Gera um número aleatório de 1 a 6, que será utilizado para definir a movimentacao das pecas.
***********************************************************************/

int TAB_RolarDado();

/***********************************************************************
*
*  $FC Função: TAB &Transicionar
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - o número que representa o jogador daquele spawn.
*	 nPeca - o número da peça que será transicionada
*   
*
*  $ED Descrição da função
*     Responsável por realizar a transição de uma peca do tabuleiro para a reta.
***********************************************************************/

void TAB_Transicionar(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca);

/***********************************************************************
*
*  $FC Função: TAB &ConferirVitoria
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	
*
*  $ED Descrição da função
*     Confere se algum jogador já levou todas as suas pecas até o centro do tabuleiro.
***********************************************************************/

int TAB_ConferirVitoria(TAB_Tabuleiro *tab, char *c);

/***********************************************************************
*
*  $FC Função: TAB &ProcurarSpawn
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - Número que representa o jogador.
*    p - parametro da casa que informa se ela é uma casa de saída inicial.
*    pD - parametro da casa que informa se é uma casa de "spawn"
*	 s - guarda uma string com o valor da casa
*
*  $ED Descrição da função
*     Localiza uma peça específica no spawn de um jogador desejado.
***********************************************************************/

int TAB_ProcurarSpawn(TAB_Tabuleiro *tab, TAB_jogador j, int p, int pD, char* s);

/***********************************************************************
*
*  $FC Função: TAB &Conferir Peca Concluida
*
*  $EP Parâmetros
*    tab - Ponteiro para o tabuleiro onde a obtenção deve ser realizada.
*	 jogador - Número que representa o jogador.
*	 nPeca - Número da peça
*
*  $ED Descrição da função
*     Confere se a peça já se encontra na sua posição final.
***********************************************************************/

int TAB_ConferirPecaConcluida(TAB_Tabuleiro *tab, TAB_jogador jogador, int nPeca);

/********** Fim do módulo de definição: TAB tabuleiro **********/


#else
#endif