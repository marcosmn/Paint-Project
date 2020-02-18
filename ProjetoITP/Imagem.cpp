// Include da IDE (Visual Studio 2017)
#include "pch.h"

// Include das bibliotecas
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Include de outros arquivos
//#include "Imagem.h"

int quantidadeRedAtual = 0;
int quantidadeGreenAtual = 0;
int quantidadeBlueAtual = 0;

// Função para definir uma nova cor atual
void setColor(int quantidadeRed, int quantidadeGreen, int quantidadeBlue)
{
	// Atualização das cores atuais
	quantidadeRedAtual = quantidadeRed;
	quantidadeGreenAtual = quantidadeGreen;
	quantidadeBlueAtual = quantidadeBlue;
}

// Função para retornar a cor atual
/*
Pixel getColor()
{
	// Declarando um pixel para armazenar a cor atual
	Pixel corAtual;
	corAtual.quantidadeRed = _quantidadeRedAtual;
	corAtual.quantidadeGreen = _quantidadeGreenAtual;
	corAtual.quantidadeBlue = _quantidadeBlueAtual;

	// Retornando o pixel com a cor atual
	return corAtual;
}
*/
int getColorRed()
{
	return quantidadeRedAtual;
}

int getColorGreen()
{
	return quantidadeGreenAtual;
}

int getColorBlue()
{
	return quantidadeBlueAtual;
}