#include "Samurai.h"

namespace Entidades
{
	Samurai::Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> velocidade_input, int vidas_input) :
		Personagem{gerenciador_grafico_input, caminho_textura_input, posicao_input, velocidade_input, vidas_input}
	{
	}

	Samurai::~Samurai()
	{
	}

	void Samurai::executar(sf::Clock relogio)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			posicao = Vetor2D<float>(posicao.get_x(), static_cast<float>(posicao.get_y() - velocidade.get_y() * relogio.getElapsedTime().asMicroseconds()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			posicao = Vetor2D<float>(posicao.get_x(), static_cast<float>(posicao.get_y() + velocidade.get_y() * relogio.getElapsedTime().asMicroseconds()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			posicao = Vetor2D<float>(static_cast<float>(posicao.get_x() - velocidade.get_x() * relogio.getElapsedTime().asMicroseconds()), posicao.get_y());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			posicao = Vetor2D<float>(static_cast<float>(posicao.get_x() + velocidade.get_x() * relogio.getElapsedTime().asMicroseconds()), posicao.get_y());
		}

		/*if (pulo)
		{
			posicao = Vetor2D<float>(posicao.get_x(), static_cast<float>(posicao.get_y() - 0.3));
		}*/
	}
}
