#pragma once
#include "Imagem.h"

void desenharReta(int pontoInicialX, int pontoInicialY, int pontoFinalX, int pontoFinalY);

void desenharRetaO1(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX);

void desenharRetaO2(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY);

void desenharRetaO3(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY);

void desenharRetaO4(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX);

void desenharRetaO5(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX);

void desenharRetaO6(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY);

void desenharRetaO7(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalY);

void desenharRetaO8(int pontoInicialX, int pontoInicialY, float razaoInicial, int deslocamentoTotalX);

void preencherPixelReta(int distanciaX, int distanciaY);

void desenharArco(int pontoBaseX, int pontoBaseY, int raio);

void preencherPixelArea(int distanciaX, int distanciaY);

void preencherPixelLinha(int distanciaX, int distanciaY);

void preencherPixelColunaPositiva(int distanciaX, int distanciaY);

void preencherPixelColunaNegativa(int distanciaX, int distanciaY);