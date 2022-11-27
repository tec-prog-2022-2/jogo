#include "Izanagi.h"

namespace Entidades
{
	namespace Personagens
	{
		Izanagi::Izanagi(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Personagens::Samurai* samurai_input) :
			Inimigo{gerenciador_grafico_input, caminho_textura_input, posicao_input, samurai_input},
			mais_vidas{false}
		{
			velocidade = Vetor2D<float>(0.0f, 0.0f);
			corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 100.f));
			tipo_entidade = ID_IZANAGI;
			vidas = 2;
			vivo = true;
			dano = 5;

			srand(static_cast<unsigned int>(time(nullptr)));

			if (1+rand() % 100 >= 50)
				mais_vidas = true;

			if (mais_vidas)
				vidas += 2;
		}

		Izanagi::~Izanagi()
		{
		}

		void Izanagi::executar(float delta_t)
		{
			if (pode_executar)
			{
				velocidade.set_x(0.0f);
				velocidade.set_y(velocidade.get_y() + GRAVIDADE * delta_t);

				if (fabs(this->posicao.get_x() - samurai->get_posicao().get_x()) < 400)
				{
					samurai->set_perto_izanagi(true);
				}

				if (this->posicao.get_x() < samurai->get_posicao().get_x() && fabs(this->posicao.get_x() - samurai->get_posicao().get_x()) < 500)
				{
					velocidade.set_x(velocidade.get_x() + 20.0f);
				}

				else if (this->posicao.get_x() > samurai->get_posicao().get_x() && fabs(this->posicao.get_x() - samurai->get_posicao().get_x()) < 500)
				{
					velocidade.set_x(velocidade.get_x() - 20.0f);
				}

				posicao = Vetor2D<float>(posicao.get_x() + 2 * velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
			}
		
			else
			{
				temporizador_pode_executar++;

				if (temporizador_pode_executar >= 5)
					this->set_pode_executar(true);
			}
		}
	}
}
