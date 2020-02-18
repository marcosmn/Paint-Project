#pragma once

void instrucao_image(int largura, int altura);

void instrucao_color(int quantidadeRed, int quantidadeGreen, int quantidadeBlue);

//void instrucao_clear(FILE *arquivoInstrucional);

void instrucao_rect(int distanciaX, int distanciaY, int largura, int altura);

void instrucao_circle(int distanciaX, int distanciaY, int raio);

void instrucao_polygon(int quantidadePontos, int distanciaX[15], int distanciaY[15]);

void instrucao_fill(int distanciaX, int distanciaY);

void instrucao_save(char nomeArquivo[50]);

//void instrucao_open(FILE *arquivoInstrucional);