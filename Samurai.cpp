#include "Samurai.h"

namespace Personagens
{
	Samurai::Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, Vetor2D<float> velocidade_input, int vidas_input):
		Personagem{gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, velocidade_input, vidas_input},
		pode_pular{false},
		altura_maxima{200.0f}
	{
	}

	Samurai::~Samurai()
	{
	}

	//Hilze Vonck
	void Samurai::executar(float delta_t)
	{
		velocidade.set_x(0.0f);
		velocidade.set_y(velocidade.get_y() + 981000000.0f * delta_t);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pode_pular)
		{
			set_pode_pular(false);
			velocidade.set_y(-sqrtf(2.0f * 981000000.0f * altura_maxima));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			velocidade.set_x(velocidade.get_x() - 100000.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			velocidade.set_x(velocidade.get_x() + 100000.0f);
		}

		posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
	}

	void Samurai::set_pode_pular(const bool pode_pular_input)
	{
		pode_pular = pode_pular_input;
	}
}
