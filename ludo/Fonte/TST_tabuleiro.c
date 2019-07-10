/***************************************************************************
*  $MCI Módulo de implementação: TTAB Teste Tabuleiro
*
*  Arquivo gerado:              tabuleiro.c
*  Letras identificadoras:      TTAB
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*
*  Autores: Baseado no código de avs - Desenvolvido por Daniel Zimmer,Eduardo Maksoud e
*  Gabriel Vasconcellos
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "tabuleiro.h"

static const char RESET_TABULEIRO_CMD     [ ] = "=resetteste"       ;
static const char CRIAR_TABULEIRO_CMD     [ ] = "=criartabuleiro"   ;
static const char OBTER_CASA_CMD  		  [ ] = "=obtercasa"        ;
static const char OBTER_SPAWN_CMD  		  [ ] = "=obterspawn"       ;
static const char OBTER_RETA_CMD  		  [ ] = "=obterreta"        ;
static const char AVANCAR_CASA_CMD        [ ] = "=avancarcasa"      ;
static const char AVANCAR_SPAWN_CMD       [ ] = "=avancarspawn"     ;
static const char AVANCAR_RETA_CMD        [ ] = "=avancarreta"      ;
static const char TABULEIRO_VAZIO_CMD	  [ ] = "=tabuleirovazio"	;


#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VALOR     100
#define DIM_VT_TABULEIRO 10

TAB_Tabuleiro*  vtTabuleiros[ DIM_VT_TABULEIRO ] ;

/***** Protótipos das funções encapuladas no módulo *****/

	int ValidarInxTab( int inxLista , int Modo );

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TTAB &Testar tabuleiro
*
*  $ED Descrição da função
*     Teste do tabuleiro. Apenas um estático por módulo.
*
*     Comandos disponíveis:
*
*     =resetteste           
*     =criartabuleiro               inxTab                      
*     =obtercasa                    string  ValEsp
*     =obterspawn                   inxTab  jogador string  ValEsp
*	  =obterreta                    inxTab  jogador string  ValEsp  
*     =avancarcasa					inxTab
*     =avancarspawn                 inxTab
*     =avancarreta                  inxTab
*     =tabuleirovazio				inxTab
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int i = -1,
		  inxTab = -1,
		  numLidos = -1 ,
		  jogador = -1,
		  ValEsp = -1;

      //TST_tpCondRet CondRet ;

      char   StringDado[ DIM_VALOR ] ;
      char * pDado ;

      StringDado[ 0 ] = 0 ;

      /* Efetuar reset de teste do tabuleiro */

         if ( strcmp( ComandoTeste , RESET_TABULEIRO_CMD ) == 0 )
         {
			for( i = 0 ; i < DIM_VT_TABULEIRO ; i++ )
            {
               vtTabuleiros[ inxTab ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste do tabuleiro */

      /* Testar CriarTabuleiro */

         else if ( strcmp( ComandoTeste , CRIAR_TABULEIRO_CMD ) == 0 )
         {

			numLidos = LER_LerParametros("ii",&inxTab, &i);
			
			if((numLidos != 2)  || ( ! ValidarInxTab( inxTab , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */
			
            vtTabuleiros[inxTab] = TAB_CriarTabuleiro(i);

            return TST_CompararPonteiroNulo( 1 , vtTabuleiros[inxTab],
               "Erro no ponteiro do tabuleiro criado."  ) ;

         } /* fim ativa: Testar CriarTabuleiro */

      /* Testar obter valor de uma casa */

         else if ( strcmp( ComandoTeste , OBTER_CASA_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,&inxTab,
                        StringDado , &ValEsp ) ;
						
            pDado = ( char * ) TAB_ObterValorCasa(vtTabuleiros[inxTab]) ;
			
			if((numLidos != 3)  || ( ! ValidarInxTab( inxTab , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            if ( ValEsp == 0 )
            {
               return TST_CompararPonteiroNulo( 0 , pDado ,
                         "Valor nao deveria existir." ) ;
            } /* if */
			
            if ( pDado == NULL )
            {
               return TST_CompararPonteiroNulo( 1 , pDado ,
                         "Dado tipo um deveria existir." ) ;
            } /* if */

            return TST_CompararString( StringDado , pDado ,
                         "Valor do elemento errado." ) ;

         } /* fim ativa: Testar obter valor da casa */
		 
	/* Testar obter valor do spawn */

         else if ( strcmp( ComandoTeste , OBTER_SPAWN_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "iisi" ,&inxTab,&jogador,
                        StringDado , &ValEsp ) ;
						
			if((numLidos != 4)  || ( ! ValidarInxTab( inxTab , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */			
						
            pDado = ( char * ) TAB_ObterValorSpawn(vtTabuleiros[inxTab],jogador) ;

            if ( ValEsp == 0 )
            {
               return TST_CompararPonteiroNulo( 0 , pDado ,
                         "Valor nao deveria existir." ) ;
            } /* if */
			
            if ( pDado == NULL )
            {
               return TST_CompararPonteiroNulo( 1 , pDado ,
                         "Dado tipo um deveria existir." ) ;
            } /* if */

            return TST_CompararString( StringDado , pDado ,
                         "Valor do elemento errado." ) ;

         } /* fim ativa: Testar obter valor da spawn */
		 
	/* Testar obter valor da reta */
	 else if ( strcmp( ComandoTeste , OBTER_RETA_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "iisi" ,&inxTab,&jogador,
                        StringDado , &ValEsp ) ;
						
			if((numLidos != 4)  || ( ! ValidarInxTab( inxTab , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */
						
            pDado = ( char * ) TAB_ObterValorReta(vtTabuleiros[inxTab],jogador) ;

            if ( ValEsp == 0 )
            {
               return TST_CompararPonteiroNulo( 0 , pDado ,
                         "Valor nao deveria existir." ) ;
            } /* if */
			
            if ( pDado == NULL )
            {
               return TST_CompararPonteiroNulo( 1 , pDado ,
                         "Dado tipo um deveria existir." ) ;
            } /* if */

            return TST_CompararString( StringDado , pDado ,
                         "Valor do elemento errado." ) ;

         } /* fim ativa: Testar obter valor da reta */
	else if ( strcmp( ComandoTeste , AVANCAR_CASA_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,&inxTab, &i) ;
						
			if((numLidos != 2)  || ( ! ValidarInxTab( inxTab , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

			TAB_AvancarCasa(vtTabuleiros[inxTab], i);

			return TST_CondRetOK;
	 }

	 else if ( strcmp( ComandoTeste , AVANCAR_SPAWN_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,&inxTab, &jogador, &i) ;
						
			if((numLidos != 3)  || ( ! ValidarInxTab( inxTab , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

			TAB_AvancarSpawn(vtTabuleiros[inxTab], jogador, i);

			return TST_CondRetOK;
	 }
	else if ( strcmp( ComandoTeste , AVANCAR_RETA_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,&inxTab, &jogador, &i) ;
						
			if((numLidos != 3)  || ( ! ValidarInxTab( inxTab , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

			TAB_AvancarReta(vtTabuleiros[inxTab], jogador,i);

			return TST_CondRetOK;
	 }
	 else if ( strcmp( ComandoTeste , TABULEIRO_VAZIO_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "i", &inxTab) ;
						
			if((numLidos != 1)  || (!ValidarInxTab( inxTab , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

			for(i = 0; i < NUM_CASAS; i++)
			{
				 pDado = ( char * ) TAB_ObterValorCasa(vtTabuleiros[inxTab]) ;
				 if(TST_CompararString("  ", pDado,"") == TST_CondRetErro )
				 {
					 return TST_CompararString("  ", pDado,"Tabuleiro nao esta com somente a string "  ".");
				 }
				TAB_AvancarCasa(vtTabuleiros[inxTab], 1);
			}

			return TST_CondRetOK;
	 }

      return TST_CondRetNaoConhec ;

   } /* Fim função: TTAB &Testar tabuleiro*/


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TTAB -ValidarInxTab
*
***********************************************************************/

    int ValidarInxTab( int inxTab , int Modo )
   {

      if ( ( inxTab <  0 )
        || ( inxTab >= DIM_VT_TABULEIRO ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtTabuleiros[ inxTab ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtTabuleiros[ inxTab ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim função: TTAB -Validar indice de tabuleiro*/


/********** Fim do módulo de implementação: TTAB Teste tabuleiro **********/

