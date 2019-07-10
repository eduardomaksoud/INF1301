##################################################
###
### Diretivas de MAKE para o construto: TesteListaC
### Gerado a partir de: TesteListaC.comp
###
### ----- Arquivo gerado, N�O EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteListaC


### Nomes de paths

Ph                   = ..\Fonte
Pobj                 = ..\Objetos
Perr                 = ..\Produto
PDEFAULT             = ..\Fonte
Pc                   = ..\Fonte

### Nomes de diret�rios para gera��o

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


### Regras de gera��o

all : limpa \
   $(Fobj)\listac.obj   $(Fobj)\tst_listac.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Depend�ncias de m�dulos objeto a compilar

$(Fobj)\listac.obj :  {$(Pc)}\listac.c \
    {$(Ph)}conta.h              {$(Ph)}listac.h            
   cl /D_DEBUG $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\tst_listac.obj :  {$(Pc)}\tst_listac.c \
    {$(Ph)}generico.h           {$(Ph)}lerparm.h            {$(Ph)}listac.h             \
    {$(Ph)}tst_espc.h          
   cl /D_DEBUG $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Termina��o

Construto : \
   $(Fobj)\listac.obj   $(Fobj)\tst_listac.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteListaC
###
##################################################

