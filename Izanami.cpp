#include "Izanami.h"

namespace Entidades
{
	namespace Personagens
	{
		Izanami::Izanami(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Personagens::Samurai* samurai_input) :
			Inimigo{gerenciador_grafico_input, caminho_textura_input, posicao_input, samurai_input},
			dobra_atributos{false}
		{
			velocidade = Vetor2D<float>(0.0f, 0.0f);
			corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
			tipo_entidade = ID_IZANAMI;
			vidas = 20;
			vivo = true;
			dano = 2;

			srand(static_cast<unsigned int>(time(nullptr)));

			if (1 + rand() % 100 >= 90)
				dobra_atributos = true;

			if (dobra_atributos)
			{
				vidas = vidas * 2;
				dano = dano * 2;
			}
		}

		Izanami::~Izanami()
		{
		}

		void Izanami::executar(float delta_t)
		{
			velocidade.set_x(0.0f);
			velocidade.set_y(velocidade.get_y() + 981000000.0f * delta_t);

			if (this->posicao.get_x() < samurai->get_posicao().get_x())
				velocidade.set_x(velocidade.get_x() + 10000.0f);

			else if (this->posicao.get_x() > samurai->get_posicao().get_x())
				velocidade.set_x(velocidade.get_x() - 10000.0f);

			if (dobra_atributos)
				posicao = Vetor2D<float>(posicao.get_x() + 2 * velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);

			else
				posicao = Vetor2D<float>(posicao.get_x() + 2 * velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
		}
	}
}
