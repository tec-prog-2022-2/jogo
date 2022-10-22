#include "Personagem.h"

Personagem::Personagem(Vector2f position_, Vector2f speed, const char* path_to_texture):
	position{position_},
	speed{speed}
{
	if (path_to_texture)
		texture.loadFromFile(path_to_texture); //adiciona o arquivo png para a textura

	body.setSize(Vector2f(200.0f, 200.0f)); //setando as dimensões do corpo do personagem
	body.setTexture(&texture); //passamos a textura por referência para o corpo do personagem
}

Personagem::~Personagem()
{
}

void Personagem::atualizar(const float time)
{
	position = speed * time;

	body.setPosition(position);
}

void Personagem::desenhar(RenderWindow* window)
{
	window->draw(body); //a window é a janela principal, passada por referência a esta função
	//basicamente, a função desenha o corpo do personagem na tela
}
