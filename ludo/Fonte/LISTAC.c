/***************************************************************************
*  $MCI M�dulo de implementa��o: LISC Lista duplamente encadeada circular
*
*  Arquivo gerado:              LISTAC.c
*  Letras identificadoras:      LISC
*
*
*  Projeto: INF 1301 - Implementa��o de jogo de Ludo.
*  Autores: Baseado no c�digo de avs - Desenvolvido por Daniel Zimmer,Eduardo Maksoud e
*  Gabriel Vasconcellos
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#ifdef _DEBUG
	#include   "CONTA.H"
#endif

#define LISTAC_OWN
#include "LISTAC.h"
#undef LISTAC_OWN

/***********************************************************************
*
*  $TC Tipo de dados: LISC Elemento da lista
*
*
***********************************************************************/

typedef struct tagElemLista {

		void * pValor ;
				/* Ponteiro para o valor contido no elemento */

		struct tagElemLista * pAnt ;
				/* Ponteiro para o elemento predecessor */

		struct tagElemLista * pProx ;
				/* Ponteiro para o elemento sucessor */

} tpElemLista ;

/***********************************************************************
*
*  $TC Tipo de dados: LISC Descritor da cabe�a de lista
*
*
***********************************************************************/

typedef struct LISC_tagLista {

		tpElemLista *pElemCorr;
				/* Ponteiro para o elemento corrente da lista */

		int numElem;
				/* N�mero de elementos da lista */

		void (* ExcluirValor)(void *pValor);
				/* Ponteiro para a fun��o de destrui��o do valor contido em um elemento */

} LISC_tpLista;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static void LiberarElemento(LISC_tppLista pLista, tpElemLista  *pElem);

static tpElemLista* CriarElemento(LISC_tppLista pLista, void *pValor);

static void LimparCabeca(LISC_tppLista pLista);

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/* Fun��o: LISC  &Criar lista*/

LISC_tppLista LISC_CriarLista(void (* ExcluirValor)(void *pDado)) {

	LISC_tpLista *pLista = NULL;
	
	#ifdef _DEBUG
         CNT_CONTAR( "LISC_CriarLista" ) ;
    #endif

	pLista = (LISC_tpLista *)malloc(sizeof(LISC_tpLista));
	if (pLista == NULL){
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_CriarLista_malloc" ) ;
		#endif
		return NULL;
	}

	LimparCabeca(pLista);

	pLista->ExcluirValor = ExcluirValor;
	
	#ifdef _DEBUG
         CNT_CONTAR( "LISC_CriarLista" ) ;
    #endif

	return pLista;
}

/*Fun��o: LISC  &Destruir lista*/
void LISC_DestruirLista( LISC_tppLista pLista ) {

	#ifdef _DEBUG
		assert( pLista != NULL );
	#endif
	
	#ifdef _DEBUG
         CNT_CONTAR( "LISC_DestruirLista" ) ;
    #endif
	
	if(pLista->pElemCorr != NULL){
		LISC_EsvaziarLista( pLista );
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_DestruirLista_elemNull" ) ;
		#endif
	}
	
	free( pLista );
	
	#ifdef _DEBUG
         CNT_CONTAR( "LISC_DestruirLista" ) ;
    #endif
}

/*Fun��o: LISC  &Esvaziar lista*/
void LISC_EsvaziarLista( LISC_tppLista pLista ) {

    tpElemLista * pElem ;
    tpElemLista * pProx ;
    tpElemLista * pPrimeiroElem;

    #ifdef _DEBUG
        assert(pLista  != NULL);
    #endif

    pElem  = pLista->pElemCorr;
    pPrimeiroElem = pElem;
	
	#ifdef _DEBUG
         CNT_CONTAR( "LISC_EsvaziarLista" ) ;
    #endif

    do {
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_EsvaziarLista_loop" ) ;
		#endif
        pProx = pElem->pProx ;
        LiberarElemento( pLista , pElem ) ;
        pElem  = pProx;
    } while (pElem != pPrimeiroElem);
	
    LimparCabeca(pLista);
	
	#ifdef _DEBUG
         CNT_CONTAR( "LISC_EsvaziarLista" ) ;
    #endif
}

/*Fun��o: LISC  &Inserir elemento antes*/
LISC_tpCondRet LISC_InserirElementoAntes(LISC_tppLista pLista, void *pValor) {

	tpElemLista *pElem ;

	#ifdef _DEBUG
		assert(pLista != NULL);
	#endif
	
	#ifdef _DEBUG
		assert(pValor != NULL);
	#endif
	
	#ifdef _DEBUG
         CNT_CONTAR( "LISC_InserirElementoAntes" ) ;
    #endif

	/* Criar elemento a inserir antes */
	pElem = CriarElemento( pLista , pValor );
	if (pElem == NULL){
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_InserirElementoAntes_elemNull" ) ;
		#endif
		return LISC_CondRetFaltouMemoria;
	}

	/* Encadear o elemento antes do elemento corrente */
	if (pLista->pElemCorr == NULL) {	// nenhum elemento na lista
		pLista->pElemCorr = pElem;
		pLista->pElemCorr->pProx = pElem;
		pLista->pElemCorr->pAnt = pElem;
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_InserirElementoAntes_elemCorrNull" ) ;
		#endif

	} else {
		
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_InserirElementoAntes" ) ;
		#endif
		if (pLista->pElemCorr->pAnt == NULL) { // um elemento na lista

			pLista->pElemCorr->pProx = pElem;
			pElem->pAnt = pLista->pElemCorr;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_InserirElementoAntes_pAntNull" ) ;
			#endif

		} else { // mais de um elemento na lista

			pElem->pAnt = pLista->pElemCorr->pAnt;
			pLista->pElemCorr->pAnt->pProx = pElem;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_InserirElementoAntes" ) ;
			#endif
		}

		// linka o elemento corrente com o novo elemento
		pLista->pElemCorr->pAnt = pElem;
		pElem->pProx = pLista->pElemCorr;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_InserirElementoAntes" ) ;
			#endif
	}
	pLista->pElemCorr = pElem;
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_InserirElementoAntes" ) ;
	#endif
	return LISC_CondRetOK;
}

/*Fun��o: LISC  &Inserir elemento ap�s*/
LISC_tpCondRet LISC_InserirElementoApos(LISC_tppLista pLista, void *pValor) {

	tpElemLista *pElem ;

	#ifdef _DEBUG
		assert( pLista != NULL ) ;
	#endif
	
	#ifdef _DEBUG
		assert(pValor != NULL);
	#endif
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_InserirElementoApos" ) ;
	#endif

	/* Criar elemento a inserir ap�s */
	pElem = CriarElemento(pLista, pValor);
	if (pElem == NULL){
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_InserirElementoApos_elemNull" ) ;
		#endif
		return LISC_CondRetFaltouMemoria;
	}
	
	/* Encadear o elemento ap�s o elemento */
	if (pLista->pElemCorr == NULL) { // nenhum elemento na lista
			pLista->pElemCorr = pElem;
			pLista->pElemCorr->pProx = pElem;
			pLista->pElemCorr->pAnt = pElem;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_InserirElementoApos_elemCorrNull" ) ;
			#endif

	} else {
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_InserirElementoApos" ) ;
		#endif
		if (pLista->pElemCorr->pAnt == NULL) { // um elemento na lista

				pLista->pElemCorr->pAnt = pElem;
				pElem->pProx = pLista->pElemCorr;
				#ifdef _DEBUG
					CNT_CONTAR( "LISC_InserirElementoApos_pAntNull" ) ;
				#endif

		} else { // mais de um elemento na lista

			pElem->pProx = pLista->pElemCorr->pProx;
			pLista->pElemCorr->pProx->pAnt = pElem;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_InserirElementoApos" ) ;
			#endif

		}
	
		// linka o elemento corrente com o novo elemento
		pLista->pElemCorr->pProx = pElem;
		pElem->pAnt = pLista->pElemCorr;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_InserirElementoApos" ) ;
			#endif		
	}

	pLista->pElemCorr = pLista->pElemCorr->pProx;
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_InserirElementoApos" ) ;
	#endif

	return LISC_CondRetOK ;
}

/*Fun��o: LISC  &Excluir elemento*/
LISC_tpCondRet LISC_ExcluirElemento(LISC_tppLista pLista) {

	tpElemLista *pElem;

	#ifdef _DEBUG
		assert(pLista != NULL);
	#endif
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ExcluirElemento" ) ;
	#endif

	if (pLista->pElemCorr == NULL){
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ExcluirElemento_elemCorrNull" ) ;
	#endif
		return LISC_CondRetListaVazia;
	}
	if (pLista->numElem == 1) { // um elemento na lista
		LiberarElemento(pLista, pLista->pElemCorr);
		pLista->pElemCorr = NULL;
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_ExcluirElemento" ) ;
		#endif

		return LISC_CondRetOK ;

	} else {

		pLista->pElemCorr->pProx->pAnt = pLista->pElemCorr->pAnt;
		pLista->pElemCorr->pAnt->pProx = pLista->pElemCorr->pProx;
		pElem = pLista->pElemCorr->pAnt;
		
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ExcluirElemento" ) ;
	#endif
	}

	LiberarElemento(pLista, pLista->pElemCorr);

	pLista->pElemCorr = pElem;
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ExcluirElemento" ) ;
	#endif

	return LISC_CondRetOK ;
}

/*Fun��o: LISC  &Obter refer�ncia para o valor contido no elemento*/
void* LISC_ObterValor(LISC_tppLista pLista) {

	#ifdef _DEBUG
		assert(pLista != NULL);
	#endif
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ObterValor" ) ;
	#endif


	if (pLista->pElemCorr == NULL){
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_ObterValor_elemCorrNull" ) ;
		#endif
		return NULL;
	}
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ObterValor" ) ;
	#endif


	return pLista->pElemCorr->pValor;
}

/*Fun��o: LISC  &Avan�ar elemento*/
LISC_tpCondRet LISC_AvancarElementoCorrente(LISC_tppLista pLista, int numElem) {

	#ifdef _DEBUG
		assert(pLista != NULL);
	#endif
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_AvancarElementoCorrente" ) ;
	#endif
	
	if (pLista->pElemCorr == NULL){	                // lista vazia
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_AvancarElementoCorrente_elemCorrNull" ) ;
		#endif
		return LISC_CondRetListaVazia;
	}
	if (numElem > 0) {
		while(numElem--){
			pLista->pElemCorr = pLista->pElemCorr->pProx;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_AvancarElementoCorrente" ) ;
			#endif
		}
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_AvancarElementoCorrente" ) ;
		#endif
	}
	else {
			while(numElem++){
			pLista->pElemCorr = pLista->pElemCorr->pAnt;
			#ifdef _DEBUG
				CNT_CONTAR( "LISC_AvancarElementoCorrente" ) ;
			#endif
			}
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_AvancarElementoCorrente" ) ;
		#endif
	}
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_AvancarElementoCorrente" ) ;
	#endif
	return LISC_CondRetOK ;
} 

/*Fun��o: LISC  &Procurar elemento contendo valor*/
LISC_tpCondRet LISC_ProcurarValor(LISC_tppLista pLista, void *pValor) {
	tpElemLista * pElem ;
	tpElemLista * pPrimeiroElem;

	#ifdef _DEBUG
		assert(pLista  != NULL);
	#endif
	
	#ifdef _DEBUG
		assert(pValor != NULL);
	#endif
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ProcurarValor" ) ;
	#endif

	if (pLista->pElemCorr == NULL){	        	// caso lista esteja vazia
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_ProcurarValor_elemCorrNull" ) ;
		#endif
		
		return LISC_CondRetListaVazia;
	}
	
	pElem  = pLista->pElemCorr;
	pPrimeiroElem = pElem;
	
	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ProcurarValor" ) ;
	#endif
	do {
			if(pElem->pValor == pValor){
				#ifdef _DEBUG
					CNT_CONTAR( "LISC_ProcurarValor" ) ;
				#endif
				pLista->pElemCorr = pElem;
				return LISC_CondRetOK;	
			}
		#ifdef _DEBUG
			CNT_CONTAR( "LISC_ProcurarValor" ) ;
		#endif
		pElem  = pElem->pProx;
	} while (pElem != pPrimeiroElem);

	#ifdef _DEBUG
		CNT_CONTAR( "LISC_ProcurarValor" ) ;
	#endif
	
	return LISC_CondRetNaoAchou;
}

/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: LISC  -Liberar elemento da lista
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pelo valor do elemento e o
*     pr�prio elemento.
*
***********************************************************************/

void LiberarElemento(LISC_tppLista pLista, tpElemLista *pElem) {
	if (pLista->ExcluirValor != NULL && pElem->pValor != NULL)
		pLista->ExcluirValor(pElem->pValor);

	free(pElem);

	pLista->numElem--;
}


/***********************************************************************
*
*  $FC Fun��o: LISC  -Criar o elemento
*
***********************************************************************/

tpElemLista* CriarElemento(LISC_tppLista pLista, void *pValor) {

	tpElemLista *pElem;

	pElem = (tpElemLista *)malloc(sizeof(tpElemLista));
	if (pElem == NULL)
		return NULL;

	pElem->pValor = pValor;
	pElem->pAnt   = NULL;
	pElem->pProx  = NULL;

	pLista->numElem++;

	return pElem;
}

/***********************************************************************
*
*  $FC Fun��o: LISC -Limpar a cabe�a da lista
*
***********************************************************************/

void LimparCabeca(LISC_tppLista pLista) {

	pLista->pElemCorr = NULL;
	pLista->numElem = 0;

}

/********** Fim do m�dulo de implementa��o: LISC Lista duplamente encadeada **********/

