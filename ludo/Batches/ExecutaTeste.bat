ECHO Executa os testes já compilados baseados nos scripts.
pushd .
cd..\Produto
TesteLista.exe /s..\Script\TesteLista.script
TesteListaC.exe /s..\Script\TesteListaC.script
TesteTabuleiro.exe /s..\Script\TesteTabuleiro.script
popd