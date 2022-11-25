#include "Plataforma.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Plataforma::Plataforma(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
			Obstaculo{ gerenciador_grafico_input, caminho_textura_input, posicao_input },
			metade_tamanho{ false }
		{
			velocidade = Vetor2D<float>(0.0f, 0.0f);
			corpo = new sf::RectangleShape(sf::Vector2f(200.0f, 20.f));
			tipo_entidade = ID_PLATAFORMA;

			srand(static_cast<unsigned int>(time(nullptr)));

			if (1 + rand() % 100 >= 75)
			{
				metade_tamanho = true;
			}

			if (metade_tamanho)
				corpo->setSize(sf::Vector2f(corpo->getSize().x / 2, corpo->getSize().y));
		}

		Plataforma::~Plataforma()
		{

		}

		void Plataforma::executar(float delta_t)
		{
			if (pode_executar)
			{
				//Efeito gravitacional
				velocidade.set_y(velocidade.get_y() + GRAVIDADE * delta_t);
				velocidade.set_y(velocidade.get_y() - GRAVIDADE * delta_t);
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
