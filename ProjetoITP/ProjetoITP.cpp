// ProjetoITP.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

// Include da IDE (Visual Studio 2017)
#include "pch.h"

// Include das bibliotecas
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdexcept>

#include "Imagem.h"

// Include de outros arquivos
//#include "Instrucoes.h"
//#include "Imagem.h"
//#include "InstrucoesAuxiliares.h"

Imagem imagem;
Pixel corAntiga;
int novaDistanciaX = 0;
int novaDistanciaY = 0;
int cont = 1;

// Declaração da função para ler as instruções do arquivo
void ler_instrucao(FILE *arquivoInstrucional);

// Declaração da função para ler um arquivo com as funções
void ler_arquivo_instrucional();

// Função principal
int main()
{
	// Tratamento de exceções
	/*
	try
	{
		ler_arquivo_instrucional(); //cause an exception to throw
	}

	catch (Exception)
	{
		throw;
	}
	*/

	// Chamada da função inicial
	ler_arquivo_instrucional();

	// Retorno padrão
	return 0;
}

// Função para ler as instruções do arquivo
void ler_instrucao(FILE *arquivoInstrucional) // Erro por exceção sem tratamento nessa função
{
	// Declaração da variavel para armazenar os dados da imagem
	
	try
	{
		// Verificando arquivo passado por parametro
		if (arquivoInstrucional == NULL)
		{
			printf("Não foi possivel abrir o arquivo \n");
			//throw 1;
			//return;
		}
		else
		{
			// Declaração da variavel que armazenara a instrução
			char instrucao[15];

			// Declaração de variaveis para armazenar a resolução da imagem (largura e altura)
			int altura = 0;
			int largura = 0;

			// Loop para percorrer todo o arquivo
			while (!feof(arquivoInstrucional))
			{
				// Leitura da string relacionada a instrução
				fscanf_s(arquivoInstrucional, "%s ", instrucao, sizeof(instrucao));

				// Sequencia relacionada a instrução "image"
				if (strcmp(instrucao, "image") == 0)
				{
					// Ler resolução da imagem (largura e altura)
					fscanf_s(arquivoInstrucional, "%d %d\n", &altura, &largura);

					// Chamada da função
					instrucao_image(altura, largura);

					// Declaração dos pixeis da imagem com valor maximo
					
					//const int resolucaoMaximaVetor = 40000;
					//const int resolucaoMaximaMatrix = 200;
					//Pixel pixel[resolucaoMaximaVetor];
					//Pixel pixel[resolucaoMaximaMatrix][resolucaoMaximaMatrix];
					
				}
				// Sequencia relacionada a instrução "color"
				else if (strcmp(instrucao, "color") == 0)
				{
					// Declaração de variaveis para armazenar cor atual
					int Cr;
					int Cg;
					int Cb;

					// Leitura da cor atual
					fscanf_s(arquivoInstrucional, "%d %d %d\n", &Cr, &Cg, &Cb);

					// Chamada da função
					instrucao_color(Cr, Cg, Cb);
				}
				// Sequencia relacionada a instrução "clear"
				else if (strcmp(instrucao, "clear") == 0)
				{
				}
				// Sequencia relacionada a instrução "rect"
				else if (strcmp(instrucao, "rect") == 0)
				{
					// Declaração de variaveis para armazenar cor atual
					int distanciaX = 0;
					int distanciaY = 0;
					int larguraRetangulo = 0;
					int alturaRetangulo = 0;

					// Leitura do ponto inicial e do tamanho
					fscanf_s(arquivoInstrucional, "%i %i %i %i\n", &distanciaX, &distanciaY, &larguraRetangulo, &alturaRetangulo);

					// Chamada da função
					instrucao_rect(distanciaX, distanciaY, larguraRetangulo, alturaRetangulo);
				}
				// Sequencia relacionada a instrução "circle"
				else if (strcmp(instrucao, "circle") == 0)
				{
					int distanciaX = 0;
					int distanciaY = 0;
					int raio = 0;

					// Leitura do ponto inicial e do raio
					fscanf_s(arquivoInstrucional, "%i %i %i\n", &distanciaX, &distanciaY, &raio);

					// Chamada da função
					instrucao_circle(distanciaX, distanciaY, raio);
				}
				// Sequencia relacionada a instrução "polygon"
				else if (strcmp(instrucao, "polygon") == 0)
				{
					// Declaração de variaveis para armazenar cor atual
					int quantidadePontos = 0;

					// Leitura da quantidade de pontos
					fscanf_s(arquivoInstrucional, "%d ", &quantidadePontos);

					// Leitura dos pontos
					int distanciaX[15];
					int distanciaY[15];
					for (int contador = 0; contador < quantidadePontos; contador++)
					{
						fscanf_s(arquivoInstrucional, "%d %d ", &distanciaX[contador], &distanciaY[contador]);
					}

					// Chamada da função
					instrucao_polygon(quantidadePontos, distanciaX, distanciaY);
				}
				// Sequencia relacionada a instrução "fill"
				else if (strcmp(instrucao, "fill") == 0)
				{
					// Declaração de variaveis para armazenar cor atual
					int distanciaX = 0;
					int distanciaY = 0;

					// Leitura do ponto inicial e do tamanho
					fscanf_s(arquivoInstrucional, "%i %i\n", &distanciaX, &distanciaY);

					// Chamada da função
					instrucao_fill(distanciaX, distanciaY);
				}
				// Sequencia relacionada a instrução "save"
				else if (strcmp(instrucao, "save") == 0)
				{
					// Ler nome do arquivo desejado
					char nomeArquivo[50];
					fscanf_s(arquivoInstrucional, "%s\n", nomeArquivo, sizeof(nomeArquivo));

					// Salvar o arquivo com o nome lido
					instrucao_save(nomeArquivo);
				}
				// Sequencia relacionada a instrução "open"
				else if (strcmp(instrucao, "open") == 0)
				{
				}
			}
		}
	}
	catch (int erro)
	{
		if (erro == 1)
		{
			printf("Erro na hora de abrir o arquivo \n");
		}
	}
}

// Função para ler um arquivo com as funções
void ler_arquivo_instrucional()
{
	// Declaração do arquivo instrucional
	FILE *arquivoInstrucional;

	// Abrindo o arquivo intrucional
	//fopen_s(&arquivoInstrucional, "ArquivoInstrucional.txt", "r");
	fopen_s(&arquivoInstrucional, "ArquivoInstrucional_Casa.txt", "rt");

	// Verificação de problemas na abertura do arquivo
	if (arquivoInstrucional == NULL)
	{
		printf("Não foi possivel abrir o arquivo \n");
		//throw invalid_argument("Não foi possivel abrir o arquivo");
		return;
	}

	// Iniciando a leitura das instruções
	ler_instrucao(arquivoInstrucional); // Erro depois dessa chamada de função

	// Fechando o arquivo instrucional
	fclose(arquivoInstrucional);
}