#include "Samurai.h"

namespace Entidades
{
	Samurai::Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, Vetor2D<float> velocidade_input, int vidas_input):
		Personagem{gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, velocidade_input, vidas_input},
		colisao_chao{false}
	{
	}

	Samurai::~Samurai()
	{
	}

	void Samurai::executar(sf::Clock relogio)
	{
		sf::Int64 delta_t = relogio.getElapsedTime().asMicroseconds();

		if (colisao_chao)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{

			}
		}	

		else
		{
			posicao = Vetor2D<float>(posicao.get_x(), posicao.get_y()+velocidade.get_y()*delta_t);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			posicao = Vetor2D<float>(static_cast<float>(posicao.get_x() - velocidade.get_x() * delta_t), posicao.get_y());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			posicao = Vetor2D<float>(static_cast<float>(posicao.get_x() + velocidade.get_x() * delta_t), posicao.get_y());
		}
	}

	void Samurai::set_colisao_chao(const bool colisao_chao_input)
	{
		colisao_chao = colisao_chao_input;
	}
}
