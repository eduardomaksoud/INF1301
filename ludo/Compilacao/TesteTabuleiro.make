##################################################
###
### Diretivas de MAKE para o construto: TesteTabuleiro
### Gerado a partir de: TesteTabuleiro.comp
###
### ----- Arquivo gerado, NÃO EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteTabuleiro


### Nomes de paths

Ph                   = ..\Fonte
Pobj                 = ..\Objetos
Perr                 = ..\Produto
PDEFAULT             = ..\Fonte
Pc                   = ..\Fonte

### Nomes de diretórios para geração

Fh                   = ..\Fonte
Fobj                 = ..\Objetos
Ferr                 = ..\Produto
FDEFAULT             = ..\Fonte
Fc                   = ..\Fonte

### Macros da plataforma


O       = /D_CRT_SECURE_NO_DEPRECATE
OD      = /Zi /Od /D_CRT_SECURE_NO_DEPRECATE
L       =
LD      = /DEBUG /DEBUGTYPE:CV

!IFDEF PRD
O       = /Ox /D_CRT_SECURE_NO_DEPRECATE
!ENDIF

OPT     = /c /J /W4 /nologo
INCLUDE = $(INCLUDE);$(PDEFAULT)


### Regras de geração

all : limpa \
   $(Fobj)\tst_tabuleiro.obj   $(Fobj)\tabuleiro.obj   $(Fobj)\lista.obj \
   $(Fobj)\listac.obj   $(Fobj)\io.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Dependências de módulos objeto a compilar

$(Fobj)\tst_tabuleiro.obj :  {$(Pc)}\tst_tabuleiro.c \
    {$(Ph)}generico.h           {$(Ph)}lerparm.h            {$(Ph)}tabuleiro.h          \
    {$(Ph)}tst_espc.h          
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\tabuleiro.obj :  {$(Pc)}\tabuleiro.c \
    {$(Ph)}io.h                 {$(Ph)}lista.h              {$(Ph)}listac.h             \
    {$(Ph)}tabuleiro.h         
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\lista.obj :  {$(Pc)}\lista.c \
    {$(Ph)}lista.h             
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\listac.obj :  {$(Pc)}\listac.c \
    {$(Ph)}conta.h              {$(Ph)}listac.h            
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\io.obj :  {$(Pc)}\io.c \
    {$(Ph)}io.h                 {$(Ph)}tabuleiro.h         
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Terminação

Construto : \
   $(Fobj)\tst_tabuleiro.obj   $(Fobj)\tabuleiro.obj   $(Fobj)\lista.obj \
   $(Fobj)\listac.obj   $(Fobj)\io.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteTabuleiro
###
##################################################

