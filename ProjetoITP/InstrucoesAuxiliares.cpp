// Include da IDE (Visual Studio 2017)
#include "pch.h"

// Include das bibliotecas
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Include de outros arquivos

//#include "Instrucoes.h"
//#include "Imagem.h"
//#include "InstrucoesAuxiliares.h"

// Variaveis globais
int quantidadePreto = 000;

// Função para determinar o Octante do ponto final em relação ao ponto inicial, 
// e consequentemente a direção da reta
void desenharReta(int pontoInicialX, int pontoInicialY, int pontoFinalX, int pontoFinalY)
{
	// Verificando se pertence aos quadrantes direitos
	if (pontoFinalX > pontoInicialX)
	{
		// Verificando se pertence aos quadrantes superiores
		if (pontoFinalY > pontoInicialY)
		{
			int diferencaX = pontoFinalX - pontoInicialX;
			int diferencaY = pontoFinalY - pontoInicialY;

			// Verificando se pertence ao Octogno 1
			if (diferencaX > diferencaY)
			{
				float razaoInicial = diferencaY / diferencaX;

				desenharRetaO1(pontoInicialX, pontoInicialY, razaoInicial, diferencaX);
			}
			// Pertence ao Octogno 2
			else
			{
				float razaoInicial = diferencaX / diferencaY;

				desenharRetaO2(pontoInicialX, pontoInicialY, razaoInicial, diferencaY);
			}
		}
		// Pertence aos quadrantes inferiores
		else
		{
			int diferencaX = pontoFinalX - pontoInicialX;
			int diferencaY = pontoInicialY - pontoFinalY;

			// Verificando se pertence ao Octogno 8
			if (diferencaX > diferencaY)
			{
				float razaoInicial = diferencaY / diferencaX;

				desenharRetaO8(pontoInicialX, pontoInicialY, razaoInicial, diferencaX);
			}
			// Pertence ao Octogno 7
			else
			{
				float razaoInicial = diferencaX / diferencaY;

				desenharRetaO7(pontoInicialX, pontoInicialY, razaoInicial, diferencaY);
			}
		}
	}
	// Pertence aos quadrantes esquerdos
	else
	{
		// Verificando se pertence aos quadrantes superiores
		if (pontoFinalY > pontoInicialY)
		{
			int diferencaX = pontoInicialX - pontoFinalX;
			int diferencaY = pontoFinalY - pontoInicialY;

			// Verificando se pertence ao Octogno 4
			if (diferencaX > diferencaY)
			{
				float razaoInicial = diferencaY / diferencaX;

				desenharRetaO4(pontoInicialX, pontoInicialY, razaoInicial, diferencaX);
			}
			// Pertence ao Octogno 3
			else
			{
				float razaoInicial = diferencaX / diferencaY;

				desenharRetaO3(pontoInicialX, pontoInicialY, razaoInicial, diferencaY);
			}
		}
		// Pertence aos quadrantes inferiores
		else
		{
			int diferencaX = pontoInicialX - pontoFinalX;
			int diferencaY = pontoInicialY - pontoFinalY;

			// Verificando se pertence ao Octogno 5
			if (diferencaX > diferencaY)
			{
				float razaoInicial = diferencaY / diferencaX;

				desenharRetaO5(pontoInicialX, pontoInicialY, razaoInicial, diferencaX);
			}
			// Pertence ao Octogno 6
			else
			{
				float razaoInicial = diferencaX / diferencaY;

				desenharRetaO6(pontoInicialX, pontoInicialY, razaoInicial, diferencaY);
			}
		}
	}
}

// Função para traçar a trajetoria da reta no 1º octante (PRONTO)
void desenharRetaO1(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX)
{
	// Declaração de variaveis auxiliares
	int deslocamentoY = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoX = 0; deslocamentoX < deslocamentoTotalX; deslocamentoX++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoY++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX + deslocamentoX, pontoInicialY + deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para traçar a trajetoria da reta no 2º octante (PRONTO)
void desenharRetaO2(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY)
{
	// Declaração de variaveis auxiliares
	int deslocamentoX = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoY = 0; deslocamentoY < deslocamentoTotalY; deslocamentoY++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoX++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX + deslocamentoX, pontoInicialY + deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para traçar a trajetoria da reta no 3º octante (PRONTO)
void desenharRetaO3(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY)
{
	// Declaração de variaveis auxiliares
	int deslocamentoX = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoY = 0; deslocamentoY < deslocamentoTotalY; deslocamentoY++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoX++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX - deslocamentoX, pontoInicialY + deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para traçar a trajetoria da reta no 4º octante (PRONTO)
void desenharRetaO4(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX)
{
	// Declaração de variaveis auxiliares
	int deslocamentoY = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoX = 0; deslocamentoX < deslocamentoTotalX; deslocamentoX++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoY++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX - deslocamentoX, pontoInicialY + deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para traçar a trajetoria da reta no 5º octante (PRONTO)
void desenharRetaO5(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX)
{
	// Declaração de variaveis auxiliares
	int deslocamentoY = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoX = 0; deslocamentoX < deslocamentoTotalX; deslocamentoX++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoY++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX - deslocamentoX, pontoInicialY - deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para traçar a trajetoria da reta no 6º octante (PRONTO)
void desenharRetaO6(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY)
{
	// Declaração de variaveis auxiliares
	int deslocamentoX = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoY = 0; deslocamentoY < deslocamentoTotalY; deslocamentoY++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoX++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX - deslocamentoX, pontoInicialY - deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para traçar a trajetoria da reta no 7º octante (PRONTO)
void desenharRetaO7(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY)
{
	// Declaração de variaveis auxiliares
	int deslocamentoX = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoY = 0; deslocamentoY < deslocamentoTotalY; deslocamentoY++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoX++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX + deslocamentoX, pontoInicialY - deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para traçar a trajetoria da reta no 8º octante (PRONTO)
void desenharRetaO8(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX)
{
	// Declaração de variaveis auxiliares
	int deslocamentoY = 0;
	float razaoAuxiliar = razaoInicial;

	// Declaração da cor padrão para retas

	// Preenchimento dos pixeis correspondentes ao trajeto da reta
	for (int deslocamentoX = 0; deslocamentoX < deslocamentoTotalX; deslocamentoX++)
	{
		if (razaoAuxiliar > 1)
		{
			deslocamentoY++;
			razaoAuxiliar = razaoInicial;
		}

		preencherPixelReta(pontoInicialX + deslocamentoX, pontoInicialY - deslocamentoY);

		razaoAuxiliar = razaoAuxiliar + razaoAuxiliar;
	}
}

// Função para pintar o pixel com a cor padrão para retas
void preencherPixelReta(int distanciaX, int distanciaY)
{
	imagem.pixel[distanciaX][distanciaY].quantidadeRed = getColorRed();
	imagem.pixel[distanciaX][distanciaY].quantidadeGreen = getColorGreen();
	imagem.pixel[distanciaX][distanciaY].quantidadeBlue = getColorBlue();
}

// Função para desenhar o arco em um octante
void desenharArco(int pontoBaseX, int pontoBaseY, int raio)
{
	// Declaração das variaveis auxiliares
	int pontoRelativoY = raio;
	int pontoMedio = 1 - raio;

	// Algoritmo para traçar a curva
	for (int pontoRelativoX = 0; (pontoRelativoX * 2) < (pontoRelativoY * 2); pontoRelativoX++)
	{
		if (pontoMedio < 0)
		{
			pontoMedio = pontoMedio + (2 * pontoRelativoX) + 1;
		}
		else
		{
			pontoRelativoY = pontoRelativoY - 1;
			pontoMedio = pontoMedio + (2 * pontoRelativoX) + 1 - (pontoRelativoY * 2);
		}

		// Preencher pixels correspondentes
		
		preencherPixelReta((pontoBaseX + pontoRelativoX), (pontoBaseY + pontoRelativoY));
		preencherPixelReta((pontoBaseX - pontoRelativoX), (pontoBaseY + pontoRelativoY));
		preencherPixelReta((pontoBaseX - pontoRelativoX), (pontoBaseY - pontoRelativoY));
		preencherPixelReta((pontoBaseX + pontoRelativoX), (pontoBaseY - pontoRelativoY));

		preencherPixelReta((pontoBaseX + pontoRelativoY), (pontoBaseY + pontoRelativoX));
		preencherPixelReta((pontoBaseX + pontoRelativoY), (pontoBaseY - pontoRelativoX));
		preencherPixelReta((pontoBaseX - pontoRelativoY), (pontoBaseY - pontoRelativoX));
		preencherPixelReta((pontoBaseX - pontoRelativoY), (pontoBaseY + pontoRelativoX));
		
		/*
		preencherPixelReta((pontoBaseX + pontoRelativoY), (pontoBaseY + pontoRelativoX));
		preencherPixelReta((pontoBaseY + pontoRelativoX), (pontoBaseX + pontoRelativoY));
		preencherPixelReta((pontoBaseY + pontoRelativoX), (pontoBaseX - pontoRelativoY));
		preencherPixelReta((pontoBaseX - pontoRelativoY), (pontoBaseY + pontoRelativoX));
		preencherPixelReta((pontoBaseX - pontoRelativoY), (pontoBaseY - pontoRelativoX));
		preencherPixelReta((pontoBaseY - pontoRelativoX), (pontoBaseX - pontoRelativoY));
		preencherPixelReta((pontoBaseY - pontoRelativoX), (pontoBaseX + pontoRelativoY));
		preencherPixelReta((pontoBaseX + pontoRelativoY), (pontoBaseY - pontoRelativoX));
		*/
	}
}

// Função para pintar o espaço com a cor atual usando recursividade
void preencherPixelArea(int distanciaX, int distanciaY)
{
	if (cont < 4000)
	{
		if (distanciaX < imagem.largura && distanciaY < imagem.altura && distanciaX >= 0 && distanciaY >= 0)
		{
			if (imagem.pixel[distanciaX][distanciaY].quantidadeRed == corAntiga.quantidadeRed &&
				imagem.pixel[distanciaX][distanciaY].quantidadeGreen == corAntiga.quantidadeGreen &&
				imagem.pixel[distanciaX][distanciaY].quantidadeBlue == corAntiga.quantidadeBlue)
			{
				imagem.pixel[distanciaX][distanciaY].quantidadeRed = getColorRed();
				imagem.pixel[distanciaX][distanciaY].quantidadeGreen = getColorGreen();
				imagem.pixel[distanciaX][distanciaY].quantidadeBlue = getColorBlue();

				cont++;

				novaDistanciaX = distanciaX;
				novaDistanciaY = distanciaY;

				preencherPixelArea(distanciaX + 1, distanciaY);
				preencherPixelArea(distanciaX, distanciaY + 1);
				preencherPixelArea(distanciaX - 1, distanciaY);
				preencherPixelArea(distanciaX, distanciaY - 1);

			}
			return;
		}
		return;
	}
	else
	{
		/*
		if (cont > 7900)
		{
			novaDistanciaX = distanciaX;
			novaDistanciaY = distanciaY;

			cont = 0;

			return;
		}
		*/
		cont++;
		//cont--;
		
		return;
	}

	return;
}

void preencherPixelLinha(int distanciaX, int distanciaY)
{
	if (distanciaX < imagem.largura && distanciaY < imagem.altura && distanciaX >= 0 && distanciaY >= 0)
	{
		if (imagem.pixel[distanciaX][distanciaY].quantidadeRed == corAntiga.quantidadeRed &&
			imagem.pixel[distanciaX][distanciaY].quantidadeGreen == corAntiga.quantidadeGreen &&
			imagem.pixel[distanciaX][distanciaY].quantidadeBlue == corAntiga.quantidadeBlue)
		{
			imagem.pixel[distanciaX][distanciaY].quantidadeRed = getColorRed();
			imagem.pixel[distanciaX][distanciaY].quantidadeGreen = getColorGreen();
			imagem.pixel[distanciaX][distanciaY].quantidadeBlue = getColorBlue();

			// Preencher colunas
			preencherPixelColunaPositiva(distanciaX, distanciaY + 1);
			preencherPixelColunaNegativa(distanciaX, distanciaY - 1);

			// Preencher linhas
			preencherPixelLinha(distanciaX + 1, distanciaY);
			preencherPixelLinha(distanciaX - 1, distanciaY);
		}
	}
}

void preencherPixelColunaPositiva(int distanciaX, int distanciaY)
{
	if (distanciaX < imagem.largura && distanciaY < imagem.altura && distanciaX >= 0 && distanciaY >= 0)
	{
		if (imagem.pixel[distanciaX][distanciaY].quantidadeRed == corAntiga.quantidadeRed &&
			imagem.pixel[distanciaX][distanciaY].quantidadeGreen == corAntiga.quantidadeGreen &&
			imagem.pixel[distanciaX][distanciaY].quantidadeBlue == corAntiga.quantidadeBlue)
		{
			imagem.pixel[distanciaX][distanciaY].quantidadeRed = getColorRed();
			imagem.pixel[distanciaX][distanciaY].quantidadeGreen = getColorGreen();
			imagem.pixel[distanciaX][distanciaY].quantidadeBlue = getColorBlue();

			preencherPixelColunaPositiva(distanciaX, distanciaY + 1);
		}
		else
		{
			preencherPixelLinha(distanciaX, distanciaY);

			return;
		}
	}
	else
	{
		preencherPixelLinha(distanciaX, distanciaY);
		
		return;
	}
}

void preencherPixelColunaNegativa(int distanciaX, int distanciaY)
{
	if (distanciaX < imagem.largura && distanciaY < imagem.altura && distanciaX >= 0 && distanciaY >= 0)
	{
		if (imagem.pixel[distanciaX][distanciaY].quantidadeRed == corAntiga.quantidadeRed &&
			imagem.pixel[distanciaX][distanciaY].quantidadeGreen == corAntiga.quantidadeGreen &&
			imagem.pixel[distanciaX][distanciaY].quantidadeBlue == corAntiga.quantidadeBlue)
		{
			imagem.pixel[distanciaX][distanciaY].quantidadeRed = getColorRed();
			imagem.pixel[distanciaX][distanciaY].quantidadeGreen = getColorGreen();
			imagem.pixel[distanciaX][distanciaY].quantidadeBlue = getColorBlue();

			preencherPixelColunaNegativa(distanciaX, distanciaY - 1);
		}
	}
}