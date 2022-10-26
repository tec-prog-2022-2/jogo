#include "Personagem.h"

Personagem::Personagem(Vetor2D<float> posicao_input, Vetor2D<float> velocidade_input, const char* path_to_texture):
	position{position_},
	speed{speed}
{
	if (path_to_texture)
		texture.loadFromFile(path_to_texture); //adiciona o arquivo png para a textura

	body.setSize(sf::Vector2f(200.0f, 200.0f)); //setando as dimens�es do corpo do personagem
	body.setTexture(&texture); //passamos a textura por refer�ncia para o corpo do personagem
}

Personagem::~Personagem()
{
}

void Personagem::atualizar(const float time)
{
	position += speed * time;

	body.setPosition(position);
}

void Personagem::desenhar(sf::RenderWindow* window)
{
	window->draw(body); //a window � a janela principal, passada por refer�ncia a esta fun��o
	//basicamente, a fun��o desenha o corpo do personagem na tela
}
