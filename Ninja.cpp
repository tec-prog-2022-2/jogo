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
			dano = 2;

			srand(static_cast<unsigned int>(time(nullptr)));

			if (1 + rand() % 100 >= 80)
				dobrar_velocidade = true;

			else
				dobrar_velocidade = false;
		}

		Ninja::~Ninja()
		{
		}

		void Ninja::executar(float delta_t)
		{
			velocidade.set_x(0.0f);
			velocidade.set_y(velocidade.get_y() + 30.0f * delta_t);

			if (this->posicao.get_x() < samurai->get_posicao().get_x())
				velocidade.set_x(velocidade.get_x() + 10.0f);

			else if (this->posicao.get_x() > samurai->get_posicao().get_x())
				velocidade.set_x(velocidade.get_x() - 10.0f);

			if (dobrar_velocidade)
				posicao = Vetor2D<float>(posicao.get_x() + 2 * velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);

			else
				posicao = Vetor2D<float>(posicao.get_x() + 2 * velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
		}
	}
}
