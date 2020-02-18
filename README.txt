Estilo de escrita do codigo:
	A forma de programação, de identação e de estruturação já podem ser vistas
	ao longo do codigo, bem como os comentarios que explicam cada linha do codigo
	detalhadamente

Modularização:
	Tendo trabalhado no desenvolvimento desse projeto percebi que com relação as 
	implementações das primitivas o projeto sera principalmente constituido dos 
	seguintes arquivos:
		- ProjetoITP.cpp
		- Imagem.cpp
		- Imagem.h
		- Instrucoes.cpp
		- Instrucoes.h
		- InstrucoesAuxiliares.cpp
		- InstrucoesAuxiliares.h
		- Arquivos de leitura
		- Arquivos de gravura

Oque foi feito:
	- A leitura das instruções e a geração do arquivo com a extensão .ppm
	já foram devidamente implementações e testadas.
	- O script principal com as funções para ler a instrução e aplicar
	as funcionalides.
	- O arquivo de Instruções que contem as implementações das funcionalidades
	dessa etapa.
	- O arquivo com as Structs relacionadas com a Imagem e suas variaveis
	- O arquivo com funções auxiliares que são chamadas pelas funções referentes
	primitivas do programa, ou instruções.
	- A implementação do desenho de retas, que é chamado pelas primitivas encarregadas 
	de desenhar retangulos e de desenhar poligonos.
	- Foi implementado o desenho de circulos.
	- Foi adicionado a função de preenchimento de areas.
	- Foi arrumado o problema com o tamanho da imagem, agora a resolução pode ir até 
	3000 x 3000 tranquilamente.
	- Também foi inserido uma verificação para impedir stack overflow na função recursiva
	relacionada a primitiva "fill".

Oque não foi feito:
	- Graças a implementação do metodo fill de forma recursiva com a verificação
	de pilha para não crashar o programa é possivel perceber alguns bugs no prenchimento
	quando relacionado a imagem como um todo.

Oque seria feito:
	Não foi feita a parte de interface, por não ser obrigatorio nessa etapa,
	mas já planejo acrescento uma interação com o usuario mais para frente.

Compilando:
	O projeto foi feito no Visual Studio 2017, por isso a pasta tem alguns arquivos 
	extras por padrão por causa do formato de solução que a IDE utiliza, mas não 
	interfere na programação nem nada demais, o codigo foi testado com um arquivo
	que eu usei como base e nenhum erro foi encontrado.