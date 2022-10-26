#pragma once

#include"stdafx.h"
#include"Vetor2D.h"

class Personagem
{
private:
	sf::RectangleShape body; //corpo do personagem
	sf::Texture texture; //textura do personagem
	Vetor2D<float> posicao; //vetor posição do personagem
	Vetor2D<float> velocidade; //vetor velocidade do personagem

public:
	Personagem(Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), Vetor2D<float> velocidade_input = Vetor2D<float>(0, 0), const char* path_to_texture = nullptr);
	~Personagem();
	void atualizar(float time=1.0); //atualiza a posição do personagem, time está em segundos
	void desenhar(sf::RenderWindow* window); //desenha o corpo do personagem na tela principal
};
