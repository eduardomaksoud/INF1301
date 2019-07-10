ECHO Compila os testes 
REM Nao esqueca de rodar vsvars32.bat

REM Gera o arquivo make baseado em TesteListaC.comp
pushd .
cd ..\Compilacao\gmake
gmake /b..\ /cTesteLista
gmake /b..\ /cTesteListaC
gmake /b..\ /cTesteTabuleiro
popd

REM Compila o programa baseado nas instrucoes do arquivo make gerado
pushd .
cd..\Compilacao
nmake /FTesteLista.make
nmake /FTesteListaC.make
nmake /FTesteTabuleiro.make

REM Abre o arquivo de erro gerado (feche para continuar)
cd ..\Produto
notepad TesteLista.err
notepad TesteListaC.err
notepad TesteTabuleiro.err
popd



