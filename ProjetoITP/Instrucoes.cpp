// Include da IDE (Visual Studio 2017)
#include "pch.h"

// Include das bibliotecas
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Include de outros arquivos
#include "Imagem.h"

// Criação da imagem
void instrucao_image(int largura, int altura)
{
	imagem.largura = largura;
	imagem.altura = altura;
}

// Atualizar a cor atual
void instrucao_color(int quantidadeRed, int quantidadeGreen, int quantidadeBlue)
{
	// PARA TESTE (Pinta tudo)
	/*
	for (int linha = 0; linha < imagem.altura; linha++)
	{
		for (int coluna = 0; coluna < imagem.largura; coluna++)
		{
			imagem.pixel[linha][coluna].quantidadeRed = quantidadeRed;
			imagem.pixel[linha][coluna].quantidadeGreen = quantidadeGreen;
			imagem.pixel[linha][coluna].quantidadeBlue = quantidadeBlue;
		}
	}
	*/
	// Atualizando a cor atual
	setColor(quantidadeRed, quantidadeGreen, quantidadeBlue);
}

// Desenhar um retangulo
void instrucao_rect(int distanciaX, int distanciaY, int largura, int altura)
{
	// Variaveis para armazenar os 4 pontos do retangulo
	int xPonto1 = distanciaX;
	int yPonto1 = distanciaY;

	int xPonto2 = distanciaX;
	int yPonto2 = distanciaY + altura;

	int xPonto3 = distanciaX + largura;
	int yPonto3 = distanciaY + altura;

	int xPonto4 = distanciaX + largura;
	int yPonto4 = distanciaY;

	// Desenho das 4 arestas
	desenharReta(xPonto1, yPonto1, xPonto2, yPonto2);
	desenharReta(xPonto2, yPonto2, xPonto3, yPonto3);
	desenharReta(xPonto3, yPonto3, xPonto4, yPonto4);
	desenharReta(xPonto4, yPonto4, xPonto1, yPonto1);
}

// Desenhar um circulo
void instrucao_circle(int distanciaX, int distanciaY, int raio)
{
	// Desenho dos arcos
	desenharArco(distanciaX, distanciaY, raio);
}

// Desenhar um poligono
void instrucao_polygon(int quantidadePontos, int distanciaX[15], int distanciaY[15])
{
	// Loop para percorrer todos os pontos e desenhar as retas
	for (int contador = 0; contador < quantidadePontos-1; contador++)
	{
		desenharReta(distanciaX[contador], distanciaY[contador], distanciaX[contador+1], distanciaY[contador+1]);
	}
	desenharReta(distanciaX[quantidadePontos-1], distanciaY[quantidadePontos-1], distanciaX[0], distanciaY[0]);
}

// Preencher um espaço a partir de um ponto
void instrucao_fill(int distanciaX, int distanciaY)
{
	corAntiga.quantidadeRed = imagem.pixel[distanciaX][distanciaY].quantidadeRed;
	corAntiga.quantidadeGreen = imagem.pixel[distanciaX][distanciaY].quantidadeGreen;
	corAntiga.quantidadeBlue = imagem.pixel[distanciaX][distanciaY].quantidadeBlue;

	if (imagem.pixel[distanciaX][distanciaY].quantidadeRed == corAntiga.quantidadeRed &&
		imagem.pixel[distanciaX][distanciaY].quantidadeGreen == corAntiga.quantidadeGreen &&
		imagem.pixel[distanciaX][distanciaY].quantidadeBlue == corAntiga.quantidadeBlue)
	{
		imagem.pixel[distanciaX][distanciaY].quantidadeRed = getColorRed();
		imagem.pixel[distanciaX][distanciaY].quantidadeGreen = getColorGreen();
		imagem.pixel[distanciaX][distanciaY].quantidadeBlue = getColorBlue();
	}

	int contadorAcumulado = 4000;
	cont = 4000;
	while (contadorAcumulado >= 4000)
	{
		contadorAcumulado = 0;
		cont = 0;
		preencherPixelArea(distanciaX + 1, distanciaY);
		contadorAcumulado = contadorAcumulado + cont;
		cont = 0;
		preencherPixelArea(distanciaX, distanciaY + 1);
		contadorAcumulado = contadorAcumulado + cont;
		cont = 0;
		preencherPixelArea(distanciaX - 1, distanciaY);
		contadorAcumulado = contadorAcumulado + cont;
		cont = 0;
		preencherPixelArea(distanciaX, distanciaY - 1);
		contadorAcumulado = contadorAcumulado + cont;
		distanciaX = novaDistanciaX;
		distanciaY = novaDistanciaY;
	}
	/*
	preencherPixelArea(distanciaX + 1, distanciaY);
	cont = 0;
	preencherPixelArea(distanciaX, distanciaY + 1);
	cont = 0;
	preencherPixelArea(distanciaX - 1, distanciaY);
	cont = 0;
	preencherPixelArea(distanciaX, distanciaY - 1);
	cont = 0;
	*/
	/*
	preencherPixelArea(distanciaX + cont, distanciaY);
	preencherPixelArea(distanciaX, distanciaY + cont);
	preencherPixelArea(distanciaX - cont, distanciaY);
	preencherPixelArea(distanciaX, distanciaY - cont);
	*/
	/*
	preencherPixelColunaPositiva(distanciaX, distanciaY + 1);
	preencherPixelColunaNegativa(distanciaX, distanciaY - 1);
	preencherPixelLinha(distanciaX + 1, distanciaY);
	preencherPixelLinha(distanciaX - 1, distanciaY);
	*/
}

// Salvamento da imagem criada
void instrucao_save(char nomeArquivo[50])
{
	// Criação de um arquivo para armazenar a imagem
	FILE *arquivoPPM;
	fopen_s(&arquivoPPM, nomeArquivo, "w");

	// Declaração da struct relacionada a imagem

	// Escrevendo as especificações da imagem no arquivo
	fprintf(arquivoPPM, "P3\n%d %d\n255\n", imagem.largura, imagem.altura);

	// Escrevendo as espicificações dos pixels da imagem
	for (int linha = 0; linha < imagem.altura; linha++)
	{
		for (int coluna = 0; coluna < imagem.largura; coluna++)
		{
			fprintf(arquivoPPM, "%d %d %d\n", 
				imagem.pixel[linha][coluna].quantidadeRed, 
				imagem.pixel[linha][coluna].quantidadeGreen, 
				imagem.pixel[linha][coluna].quantidadeBlue);
		}
	}

	// Fechamento do arquivo PPM
	fclose(arquivoPPM);
}

// Instrução extra para desenho de grafico (Apenas funções polinomiais)
void instrucao_grafico(int variavel, int constantes[5], char expressao[30])
{
	int contador = 0;
	while (expressao[contador+1] != NULL)
	{

	}
}