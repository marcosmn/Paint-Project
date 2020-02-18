#pragma once

// Variavel armazenando a resolu��o maxima da imagem
//const int resolucaoMaxima = 15; // 50

// Estrutura para armazenar variaveis relacionadas ao pixel
struct Pixel
{
	int quantidadeRed = 255;
	int quantidadeGreen = 255;
	int quantidadeBlue = 255;
};

// Estrutura para armazenar variaveis relacionadas a moldura
struct Moldura
{
	int largura;
	int altura;
};

// Estrutura para armazenar variaveis relacionadas a imagem
struct Imagem
{
	int largura;
	int altura;

	Pixel pixel[3000][3000];
};

#ifndef IMG

#define IMG

extern Imagem imagem;
extern Pixel corAntiga;

//Auxiliares para a fun��o Fill
extern bool fim;
extern int novaDistanciaX;
extern int novaDistanciaY;
extern int cont;

#endif // !IMG

// Fun��es para retornar e atualizar cor atual
void setColor(int quantidadeRed, int quantidadeGreen, int quantidadeBlue);
Pixel getColor();
int getColorRed();
int getColorGreen();
int getColorBlue();
