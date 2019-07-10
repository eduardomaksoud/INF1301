#ifndef LISTAC_ 
#define LISTAC_
/***************************************************************************
*
*  $MCD Módulo de definição: LISC  Lista duplamente encadeada circular
*
*  Arquivo gerado:              LISTAC.h
*  Letras identificadoras:      LISC
*
*  Autores: Baseado no código de avs - Desenvolvido por Daniel Zimmer,Eduardo Maksoud e
*  Gabriel Vasconcellos 
*
*  $ED Descrição do módulo
*     Implementa listas genéricas duplamente encadeadas circulares.
*     Podem existir n listas em operação simultaneamente.
*     As listas possuem uma cabeça encapsulando o seu estado.
*
*     Cada lista é homogênea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que contém.
*
*     Os ponteiros para os dados são copiados para elementos da lista.
*        Não é copiado o valor apontado por estes ponteiros.
*
*     O controle da destruição do valor de um elemento a ser excluído
*        é realizado por uma função fornecida pelo usuário.
*
*     Cada lista referencia uma função que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A função de liberação dos valores contidos nos elementos deve
*        assegurar a liberação de todos os espaços referênciados pelo
*        valor contido em um elemento.
*        Esta função é chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso não seja necessário desalocar o valor referenciado pelo
*        elemento, o ponteiro para a função de liberação poderá ser NULL .
*        Caso o elemento da lista seja a única âncora do valor referenciado,
*        esta função deve promover a destruição (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( LISTAC_OWN )
   #define LISTAC_EXT
#else
   #define LISTAC_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef struct LISC_tagLista * LISC_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: LISC Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         LISC_CondRetOK ,
               /* Concluiu corretamente */

         LISC_CondRetListaVazia ,
               /* A lista não contém elementos */

         LISC_CondRetNaoAchou ,
               /* Não encontrou o valor procurado */

         LISC_CondRetFaltouMemoria
               /* Faltou memória ao tentar criar um elemento de lista */

   } LISC_tpCondRet ;


/***********************************************************************
*
*  $FC Função: LISC  &Criar lista
*
*  $ED Descrição da função
*     Cria uma lista genérica duplamente encadeada circular.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     ExcluirValor  - ponteiro para a função que processa a
*                     exclusão do valor referenciado pelo elemento
*                     a ser excluído.
*                     Ver descrição do módulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro será utilizado pelas funções que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
* ¨$AE Assertivas de entrada
*      Caso haja uma função específica para excluir o valor armazenado na lista é possível fazê-lo.
*
* ¨$AS Assertivas de Saída
*      Gera a lista circular genérica duplamente encadeada.
*
***********************************************************************/

   LISC_tppLista LISC_CriarLista(
             void   ( * ExcluirValor ) ( void * pDado ) ) ;


/***********************************************************************
*
*  $FC Função: LISC  &Destruir lista
*
*  $ED Descrição da função
*     Destrói a lista fornecida.
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $FV Valor retornado
*     LISC_CondRetOK    - destruiu sem problemas
*
* ¨$AE Assertivas de entrada
*      pLista não pode ser NULL.
*
* ¨$AS Assertivas de Saída
*      A lista é liberada.
*
***********************************************************************/

   void LISC_DestruirLista( LISC_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Função: LISC  &Esvaziar lista
*
*  $ED Descrição da função
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Parâmetros
*     pLista - ponteiro para a lista a ser esvaziada
*
* ¨$AE Assertivas de entrada
*      pLista não pode ser NULL.
*
* ¨$AS Assertivas de Saída
*      Gera uma lista vazia.
*
***********************************************************************/

   void LISC_EsvaziarLista( LISC_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Função: LISC  &Inserir elemento antes
*
*  $ED Descrição da função
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*     O elemento corrente é setado posteriormente para o elemento adicionado a esquerda.
*
*  $EP Parâmetros
*     pLista - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
* ¨$AE Assertivas de entrada
*      pLista não pode ser NULL.
*	   pValor não pode ser NULL.
*
* ¨$AS Assertivas de Saída
*      Gera a lista com o elemento pValor incluído.
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
*  $FC Função: LISC  &Inserir elemento após
*
*  $ED Descrição da função
*     Insere novo elemento após o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*     O elemento corrente é setado posteriormente para o elemento adicionado a direita. 
*
*  $EP Parâmetros
*     Parâmetros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*           
* ¨$AE Assertivas de entrada
*      pLista não pode ser NULL.
*	   pValor não pode ser NULL.
*
* ¨$AS Assertivas de Saída
*      Gera a lista com o elemento pValor incluído.
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
*  $FC Função: LISC  &Excluir elemento
*
*  $ED Descrição da função
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento a esquerda do corrente será o novo corrente.
*     Se não existir e existir o elemento à direita, este se tornará corrente.
*     Se este também não existir a lista tornou-se vazia.
*
*  $EP Parâmetros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $AE Assertivas de entrada
*      pLista não pode ser NULL.
*	 
* ¨$AS Assertivas de Saída
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
*  $FC Função: LISC  &Obter referência para o valor contido no elemento
*
*  $ED Descrição da função
*     Obtem a referência para o valor contido no elemento corrente da lista
*
*  $EP Parâmetros
*     pLista - ponteiro para a lista de onde se quer o valor
*
* ¨$AE Assertivas de entrada
*      pLista não pode ser NULL.
*	 
* ¨$AS Assertivas de Saída
*      Permite armazenar o elemento corrente da lista circular.
*
*  $FV Valor retornado
*     não NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

   void * LISC_ObterValor( LISC_tppLista pLista ) ;

/***********************************************************************
*
*  $FC Função: LISC  &Avançar elemento
*
*  $ED Descrição da função
*     Avança o elemento corrente numElem elementos na lista
*     Se numElem for positivo avança para direita.
*     Se numElem for negativo avança para a esquerda.
*     numElem pode ser maior do que o número de elementos existentes na
*               direção desejada.
*     Se numElem for zero somente verifica se a lista está vazia.
*
*  $EP Parâmetros
*     pLista  - ponteiro para a lista a ser manipulada
*     numElem - o número de elementos a andar
*
* ¨$AE Assertivas de entrada
*      pLista não pode ser NULL.
*	 
* ¨$AS Assertivas de Saída
*      Gera a lista com um elemento corrente adiantado.
*
*  $FV Valor retornado
*     CondRetOK         - se numElem elementos tiverem sido andados
*     CondRetFimLista   - se encontrou o fim da lista antes de andar numElem
*                         elementos
*     CondRetListaVazia - se a lista está vazia
*
***********************************************************************/

   LISC_tpCondRet LISC_AvancarElementoCorrente( LISC_tppLista pLista ,
                                              int numElem ) ;


/***********************************************************************
*
*  $FC Função: LISC  &Procurar elemento contendo valor
*
*  $ED Descrição da função
*     Procura o elemento que referencia o valor dado.
*     A função compara ponteiro e não conteúdo apontado.
*
*  $EP Parâmetros
*     pLista  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*     tipo    - Se i != 0, o pValor é do tipo char *
*
* ¨$AE Assertivas de entrada
*      pLista não pode ser NULL.
*	   pValor não pode ser NULL.
*	 
* ¨$AS Assertivas de Saída
*      Gera a lista com um elemento corrente adiantado.		
*
*  $FV Valor retornado
*     LISC_CondRetOK  - se encontrou.
*                     
*     LISC_CondRetNaoEncontrou - se o ponteiro não foi encontrado
*                      O elemento corrente continua o mesmo
*     LISC_CondRetListaVazia   - se a lista estiver vazia
*
***********************************************************************/

   LISC_tpCondRet LISC_ProcurarValor( LISC_tppLista pLista ,
                                    void * pValor) ;

#undef LISTAC_EXT

/********** Fim do módulo de definição: LISC  Lista duplamente encadeada **********/

#else
#endif

