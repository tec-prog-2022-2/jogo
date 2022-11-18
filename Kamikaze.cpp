#include "Kamikaze.h"

namespace Entidades
{
	namespace Personagens
	{
		Kamikaze::Kamikaze(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Personagens::Samurai* samurai_input) :
			Inimigo{ gerenciador_grafico_input, caminho_textura_input, posicao_input, samurai_input },
			samurai_direita{ false },
			samurai_esquerda{ false },
			temporizador_atirar{ 0 }
		{
			const char* caminho_textura_shuriken = "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png";
			velocidade = Vetor2D<float>(0.0f, 0.0f);
			corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
			tipo_entidade = ID_KAMIKAZE;
			vidas = 5;
			vivo = true;
			dano = 0;
			shuriken = new Entidades::Shuriken(gerenciador_grafico_input, caminho_textura_shuriken, posicao_input);
			shuriken->set_posicao_inicial(posicao_input);
		}

		Kamikaze::~Kamikaze()
		{
			delete shuriken;
			shuriken = nullptr;
		}

		void Kamikaze::executar(float delta_t)
		{
			if (shuriken->get_pode_atirar())
			{
				if (this->posicao.get_x() < samurai->get_posicao().get_x())
				{
					shuriken->atirar_direita(delta_t);
				}

				else
				{
					shuriken->atirar_esquerda(delta_t);
				}
			}

			else
			{
				temporizador_atirar++;
				if (temporizador_atirar == 200)
				{
					shuriken->set_pode_atirar(true);
					temporizador_atirar = 0;
				}
			}
		}

		Entidades::Shuriken* Kamikaze::get_shuriken() const
		{
			return(shuriken);
		}
	}
}
