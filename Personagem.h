#pragma once

#include"stdafx.h"
#include"Vetor2D.h"
#include"GerenciadorGrafico.h"

class Personagem
{
private:
	Vetor2D<float> posicao; 
	Vetor2D<float> velocidade; 
	const char* caminho_textura;

public:
	Personagem(Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), Vetor2D<float> velocidade_input = Vetor2D<float>(0, 0), const char* caminho_textura_input = nullptr);
	~Personagem();
	void inicializar(GerenciadorGrafico* gerenciador_grafico_input);
	void atualizar(float tempo_input=1.0); //atualiza a posição do personagem, time está em segundos
	void desenhar(GerenciadorGrafico* gerenciador_grafico_input); //desenha o corpo do personagem na tela principal
};
