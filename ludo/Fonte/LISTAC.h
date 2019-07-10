#ifndef LISTAC_ 
#define LISTAC_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: LISC  Lista duplamente encadeada circular
*
*  Arquivo gerado:              LISTAC.h
*  Letras identificadoras:      LISC
*
*  Autores: Baseado no c�digo de avs - Desenvolvido por Daniel Zimmer,Eduardo Maksoud e
*  Gabriel Vasconcellos 
*
*  $ED Descri��o do m�dulo
*     Implementa listas gen�ricas duplamente encadeadas circulares.
*     Podem existir n listas em opera��o simultaneamente.
*     As listas possuem uma cabe�a encapsulando o seu estado.
*
*     Cada lista � homog�nea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que cont�m.
*
*     Os ponteiros para os dados s�o copiados para elementos da lista.
*        N�o � copiado o valor apontado por estes ponteiros.
*
*     O controle da destrui��o do valor de um elemento a ser exclu�do
*        � realizado por uma fun��o fornecida pelo usu�rio.
*
*     Cada lista referencia uma fun��o que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A fun��o de libera��o dos valores contidos nos elementos deve
*        assegurar a libera��o de todos os espa�os refer�nciados pelo
*        valor contido em um elemento.
*        Esta fun��o � chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso n�o seja necess�rio desalocar o valor referenciado pelo
*        elemento, o ponteiro para a fun��o de libera��o poder� ser NULL .
*        Caso o elemento da lista seja a �nica �ncora do valor referenciado,
*        esta fun��o deve promover a destrui��o (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( LISTAC_OWN )
   #define LISTAC_EXT
#else
   #define LISTAC_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct LISC_tagLista * LISC_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: LISC Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         LISC_CondRetOK ,
               /* Concluiu corretamente */

         LISC_CondRetListaVazia ,
               /* A lista n�o cont�m elementos */

         LISC_CondRetNaoAchou ,
               /* N�o encontrou o valor procurado */

         LISC_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar um elemento de lista */

   } LISC_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Criar lista
*
*  $ED Descri��o da fun��o
*     Cria uma lista gen�rica duplamente encadeada circular.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     ExcluirValor  - ponteiro para a fun��o que processa a
*                     exclus�o do valor referenciado pelo elemento
*                     a ser exclu�do.
*                     Ver descri��o do m�dulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
* �$AE Assertivas de entrada
*      Caso haja uma fun��o espec�fica para excluir o valor armazenado na lista � poss�vel faz�-lo.
*
* �$AS Assertivas de Sa�da
*      Gera a lista circular gen�rica duplamente encadeada.
*
***********************************************************************/

   LISC_tppLista LISC_CriarLista(
             void   ( * ExcluirValor ) ( void * pDado ) ) ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Destruir lista
*
*  $ED Descri��o da fun��o
*     Destr�i a lista fornecida.
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $FV Valor retornado
*     LISC_CondRetOK    - destruiu sem problemas
*
* �$AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*
* �$AS Assertivas de Sa�da
*      A lista � liberada.
*
***********************************************************************/

   void LISC_DestruirLista( LISC_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Esvaziar lista
*
*  $ED Descri��o da fun��o
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a ser esvaziada
*
* �$AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*
* �$AS Assertivas de Sa�da
*      Gera uma lista vazia.
*
***********************************************************************/

   void LISC_EsvaziarLista( LISC_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Inserir elemento antes
*
*  $ED Descri��o da fun��o
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*     O elemento corrente � setado posteriormente para o elemento adicionado a esquerda.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
* �$AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*	   pValor n�o pode ser NULL.
*
* �$AS Assertivas de Sa�da
*      Gera a lista com o elemento pValor inclu�do.
*
*  $FV Valor retornado
*     LISC_CondRetOK
*     LISC_CondRetFaltouMemoria
*
***********************************************************************/

   LISC_tpCondRet LISC_InserirElementoAntes( LISC_tppLista pLista ,
                                           void * pValor        ) ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Inserir elemento ap�s
*
*  $ED Descri��o da fun��o
*     Insere novo elemento ap�s o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*     O elemento corrente � setado posteriormente para o elemento adicionado a direita. 
*
*  $EP Par�metros
*     Par�metros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*           
* �$AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*	   pValor n�o pode ser NULL.
*
* �$AS Assertivas de Sa�da
*      Gera a lista com o elemento pValor inclu�do.
*
*  $FV Valor retornado
*     Valor retornado
*        LISC_CondRetOK
*        LISC_CondRetFaltouMemoria
*
***********************************************************************/

   LISC_tpCondRet LISC_InserirElementoApos( LISC_tppLista pLista ,
                                          void * pValor        )
       ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Excluir elemento
*
*  $ED Descri��o da fun��o
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento a esquerda do corrente ser� o novo corrente.
*     Se n�o existir e existir o elemento � direita, este se tornar� corrente.
*     Se este tamb�m n�o existir a lista tornou-se vazia.
*
*  $EP Par�metros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*	 
* �$AS Assertivas de Sa�da
*      Gera uma nova lista sem o elemento corrente anterior.
*
*  $FV Valor retornado
*     LISC_CondRetOK
*     LISC_CondRetListaVazia
*
***********************************************************************/

   LISC_tpCondRet LISC_ExcluirElemento( LISC_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Obter refer�ncia para o valor contido no elemento
*
*  $ED Descri��o da fun��o
*     Obtem a refer�ncia para o valor contido no elemento corrente da lista
*
*  $EP Par�metros
*     pLista - ponteiro para a lista de onde se quer o valor
*
* �$AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*	 
* �$AS Assertivas de Sa�da
*      Permite armazenar o elemento corrente da lista circular.
*
*  $FV Valor retornado
*     n�o NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

   void * LISC_ObterValor( LISC_tppLista pLista ) ;

/***********************************************************************
*
*  $FC Fun��o: LISC  &Avan�ar elemento
*
*  $ED Descri��o da fun��o
*     Avan�a o elemento corrente numElem elementos na lista
*     Se numElem for positivo avan�a para direita.
*     Se numElem for negativo avan�a para a esquerda.
*     numElem pode ser maior do que o n�mero de elementos existentes na
*               dire��o desejada.
*     Se numElem for zero somente verifica se a lista est� vazia.
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista a ser manipulada
*     numElem - o n�mero de elementos a andar
*
* �$AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*	 
* �$AS Assertivas de Sa�da
*      Gera a lista com um elemento corrente adiantado.
*
*  $FV Valor retornado
*     CondRetOK         - se numElem elementos tiverem sido andados
*     CondRetFimLista   - se encontrou o fim da lista antes de andar numElem
*                         elementos
*     CondRetListaVazia - se a lista est� vazia
*
***********************************************************************/

   LISC_tpCondRet LISC_AvancarElementoCorrente( LISC_tppLista pLista ,
                                              int numElem ) ;


/***********************************************************************
*
*  $FC Fun��o: LISC  &Procurar elemento contendo valor
*
*  $ED Descri��o da fun��o
*     Procura o elemento que referencia o valor dado.
*     A fun��o compara ponteiro e n�o conte�do apontado.
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*     tipo    - Se i != 0, o pValor � do tipo char *
*
* �$AE Assertivas de entrada
*      pLista n�o pode ser NULL.
*	   pValor n�o pode ser NULL.
*	 
* �$AS Assertivas de Sa�da
*      Gera a lista com um elemento corrente adiantado.		
*
*  $FV Valor retornado
*     LISC_CondRetOK  - se encontrou.
*                     
*     LISC_CondRetNaoEncontrou - se o ponteiro n�o foi encontrado
*                      O elemento corrente continua o mesmo
*     LISC_CondRetListaVazia   - se a lista estiver vazia
*
***********************************************************************/

   LISC_tpCondRet LISC_ProcurarValor( LISC_tppLista pLista ,
                                    void * pValor) ;

#undef LISTAC_EXT

/********** Fim do m�dulo de defini��o: LISC  Lista duplamente encadeada **********/

#else
#endif

