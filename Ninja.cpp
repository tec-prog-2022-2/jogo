#include "Ninja.h"

namespace Entidades
{
	namespace Personagens
	{
		Ninja::Ninja(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Personagens::Samurai* samurai_input) :
			Inimigo{ gerenciador_grafico_input, caminho_textura_input, posicao_input, samurai_input }
		{
			corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
			tipo_entidade = ID_NINJA;
			vidas = 3;
			vivo = true;
			dano = 5;

			srand(static_cast<unsigned int>(time(nullptr)));

			if (1 + rand() % 100 >= 80)
				aumentar_velocidade = true;

			else
				aumentar_velocidade = false;
		}

		Ninja::~Ninja()
		{
		}

		void Ninja::executar(float delta_t)
		{
			if (pode_executar)
			{
				velocidade.set_x(0.0f);
				velocidade.set_y(velocidade.get_y() + GRAVIDADE * delta_t);

				if (this->posicao.get_x() < samurai->get_posicao().get_x() && fabs(this->posicao.get_x() - samurai->get_posicao().get_x()) < 300)
					velocidade.set_x(velocidade.get_x() + 35.0f);

				else if (this->posicao.get_x() > samurai->get_posicao().get_x() && fabs(this->posicao.get_x() - samurai->get_posicao().get_x()) < 300)
					velocidade.set_x(velocidade.get_x() - 35.0f);

				if (aumentar_velocidade)
					posicao = Vetor2D<float>(posicao.get_x() + 1.3 * velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);

				else
					posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
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
