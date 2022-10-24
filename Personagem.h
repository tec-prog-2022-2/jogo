#pragma once

#include"stdafx.h"

class Personagem
{
private:
	sf::RectangleShape body; //corpo do personagem
	sf::Texture texture; //textura do personagem
	sf::Vector2f position; //vetor posição do personagem
	sf::Vector2f speed; //vetor velocidade do personagem

public:
	Personagem(sf::Vector2f position_ = sf::Vector2f(0.0f, 0.0f), sf::Vector2f speed = sf::Vector2f(0.0f, 0.0f), const char* path_to_texture = nullptr);
	~Personagem();
	void atualizar(float time=1.0); //atualiza a posição do personagem, time está em segundos
	void desenhar(sf::RenderWindow* window); //desenha o corpo do personagem na tela principal
};
