#if ! defined( LerParm_ )
#define LerParm_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: LER  Ler par�metros de comandos
*
*  Arquivo gerado:              LerParm.h
*  Letras identificadoras:      LER
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: C:\AUTOTEST\PROJETOS\INSTRUM.BSW
*
*  Membros do Grupo do trabalho: Daniel Zimmer,Eduardo Maksoud,Gabriel Vasconcellos
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     4       avs   01/fev/2006 criar linguagem script simb�lica
*     3       avs   08/dez/2004 uniformiza��o dos exemplos
*     2       avs   07/jul/2003 unifica��o de todos os m�dulos em um s� projeto
*     1       avs   16/abr/2003 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Le par�metros contidos em um buffer.
*     Os par�metros podem ser simb�licos ou literais.
*     Par�metros simb�licos devem ser declarados antes de serem utilizados.
*
***************************************************************************/
 
#if defined( LerParm_OWN )
   #define LerParm_EXT
#else
   #define LerParm_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

#define  LER_DIM_NOME     32
#define  LER_DIM_STRING  500
#define  LER_DIM_BUFFER      250


/***********************************************************************
*
*  $TC Tipo de dados: LER Condi��es de retorno
*
*
***********************************************************************/

   typedef enum {

         LER_CondRetOK ,
               /* Ler retorno OK */

         LER_CondRetNaoAbriu
               /* Ler n�o abriu arquivo */

   } LER_tpCondRet ;

/***** Dados exportados pelo m�dulo *****/

   /* Estrutura de dados: *LER  Dados globais p�blicos */

   LerParm_EXT int LER_TamBuffer ;
         /* Tamanho do string contido no buffer de leitura */

   LerParm_EXT char LER_Buffer[ LER_DIM_BUFFER + 1 ] ;
         /* Buffer de leitura */


/***********************************************************************
*
*  $FC Fun��o: LER  &Inicializar m�dulo LerParm
*
*  $ED Descri��o da fun��o
*     Inicializa o m�dulo.
*     Deve ser chamada antes de iniciar a an�lise de comandos.
*     Deve ser chamada uma �nica vez no in�cio ou ap�s terminar o m�dulo.
*
***********************************************************************/

   int LER_InicializarLeitura( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Obter nome do arquivo script
*
***********************************************************************/

   char * LER_ObterNomeArqScript( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Interpretar comandos de teste
*
*  $ED Descri��o da fun��o
*     Interpreta os comandos de teste disponibilizados pelo m�dulo
*     de leitura.
*
*     Ver a descri��o do m�dulo para mais detalhes
*
***********************************************************************/

   TST_tpCondRet LER_InterpretarComandos( char * ComandoTeste ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Terminar m�dulo LerParm
*
***********************************************************************/

   void LER_TerminarLeitura( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Abrir arquivo script de teste
*
*  $ED Descri��o da fun��o
*     Abre o arquivo que cont�m o script de teste.
*     A extens�o default do arquivo de comandos script de teste �
*     ".script" e ser� acrescida ao nome do arquivo caso este n�o
*     contenha nome de extens�o.
*
*  $EP Par�metros
*     $P NomeArqParm - nome do arquivo contendo o script de teste
*
*  $FV Valor retornado
*     LER_CondRetOK        - caso tenha sido poss�vel abrir o arquivo.
*     LER_CondRetNaoAbriu  - caso tenha ocorrido algum erro.
*                            N�o h� discrimina��o do erro encontrado.
*
***********************************************************************/

   LER_tpCondRet LER_AbrirArquivoScript( char * NomeArqParm ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Fechar arquivo script
*
***********************************************************************/

   void LER_FecharScript( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Declarar par�metro simb�lico
*
***********************************************************************/

   int LER_DeclararParametro( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Exibir declara��o de s�mbolo
*
***********************************************************************/

   void LER_ExibirParametro( char * Simbolo ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Ler linha script eliminando brancos ao final
*
*  $ED Descri��o da fun��o
*     L� uma linha do arquivo script e elimina os caracteres branco,
*     fim de linha, tabula��o etc. do final da linha lida.
*
*  $FV Valor retornado
*     Retorna o tamanho da linha lida.
*     Ser�:
*        -1 caso tenha ocorrido fim de arquivo.
*        -2 caso tenha ocorrido algum problema de leitura.
*
***********************************************************************/

   int LER_LerLinhaScript( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Obter n�mero de linhas lidas at� o momento
*
***********************************************************************/

   int LER_ObterNumLinhas( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Ler linha de par�metros
*
*  $ED Descri��o da fun��o
*     L� um n�mero vari�vel de par�metros
*
*  $EP Par�metros
*     Tipos   � um string contendo a identifica��o dos tipos dos par�metros
*             a serem lidos.
*     ...     Os demais par�metros s�o refer�ncias (ponteiros) para os
*             espa�os onde dever�o ser armazenados os valores lidos.
*
*     Tal como em scanf deve-se tomar o cuidado de assegurar que a lista
*     de refer�ncia e o string de tipos tenha o mesmo tamanho
*     e que os indicadores de tipo sejam consistentes com a refer�ncia
*     posicionalmente correspondente.
*
*     Ao ler um campo primeiro procura ler um nome de par�metro j�
*     declarado. Caso isto seja poss�vel e o tipo esteja correto
*     � " lido" o valor contido no par�metro
*     Caso n�o seja poss�vel tenta ler um literal em acordo com o tipo
*     dado.
*
*     Gera mensagens de erro para par�metros desconhecidos, sintaxe errada
*     e tipo inconsistente com o solicitado.
*
*  $FV Valor retornado
*     Retorna o n�mero de campos lidos at� concluir ou at� encontrar
*     um erro.
*
***********************************************************************/

   int LER_LerParametros( char * Tipos , ... ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Ler par�metro caractere
*
***********************************************************************/

   int LER_LerParmChar( char * Parm ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Ler par�metro flutuante
*
***********************************************************************/

   int LER_LerParmDouble( double * Parm ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Ler par�metro nome
*
***********************************************************************/

   int LER_LerParmNome( char * Parm , int * tamNome , int dimNome ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Ler par�metro inteiro
*
***********************************************************************/

   int LER_LerParmInt( int * Parm ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Ler par�metro string
*
***********************************************************************/

   int LER_LerParmString( char * Parm , int * tamString , int dimString ) ;


/***********************************************************************
*
*  $FC Fun��o: LER  &Pular comando de teste
*
***********************************************************************/

   void LER_PularComando( void ) ;

#undef LerParm_EXT

/********** Fim do m�dulo de defini��o: LER  Ler par�metros de comandos **********/

#else
#endif
