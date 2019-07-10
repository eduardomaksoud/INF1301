##################################################
###
### Diretivas de MAKE para o construto: TesteListaC
### Gerado a partir de: TesteListaC.comp
###
### ----- Arquivo gerado, NÃO EDITE!!! -----
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
   $(Fobj)\listac.obj   $(Fobj)\tst_listac.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Dependências de módulos objeto a compilar

$(Fobj)\listac.obj :  {$(Pc)}\listac.c \
    {$(Ph)}conta.h              {$(Ph)}listac.h            
   cl /D_DEBUG $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\tst_listac.obj :  {$(Pc)}\tst_listac.c \
    {$(Ph)}generico.h           {$(Ph)}lerparm.h            {$(Ph)}listac.h             \
    {$(Ph)}tst_espc.h          
   cl /D_DEBUG $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Terminação

Construto : \
   $(Fobj)\listac.obj   $(Fobj)\tst_listac.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteListaC
###
##################################################

