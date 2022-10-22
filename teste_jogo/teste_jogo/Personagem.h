#pragma once

#include"stdafx.h"

class Personagem
{
private:
	RectangleShape body; //corpo do personagem
	Texture texture; //textura do personagem
	Vector2f position; //vetor posição do personagem
	Vector2f speed; //vetor velocidade do personagem

public:
	Personagem(Vector2f position_ = Vector2f(0.0f, 0.0f), Vector2f speed = Vector2f(0.0f, 0.0f), const char* path_to_texture = nullptr);
	~Personagem();
	void atualizar(float time=1); //atualiza a posição do personagem, time está em segundos
	void desenhar(RenderWindow* window); //desenha o corpo do personagem na tela principal
};
