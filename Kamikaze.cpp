#include "Kamikaze.h"

namespace Entidades
{
	namespace Personagens
	{
		Kamikaze::Kamikaze(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Personagens::Samurai* samurai_input) :
			Inimigo{ gerenciador_grafico_input, caminho_textura_input, posicao_input, samurai_input },
			samurai_direita{ false },
			samurai_esquerda{ false },
			temporizador_atirar{ 0 },
			duracao_tiro{0}
		{
			const char* caminho_textura_shuriken = "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//shuriken.png";
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
			velocidade.set_x(0.0f);

			if (shuriken->get_pode_atirar())
			{
				if (this->posicao.get_x() < samurai->get_posicao().get_x() && fabs(this->posicao.get_x() - samurai->get_posicao().get_x()) < 600)
				{
					shuriken->atirar_direita(delta_t);
					shuriken->set_atirou_direita(true);
				}

				else if (this->posicao.get_x() > samurai->get_posicao().get_x() && fabs(this->posicao.get_x() - samurai->get_posicao().get_x()) < 600)
				{
					shuriken->atirar_esquerda(delta_t);
					shuriken->set_atirou_esquerda(true);
				}

				/*else if (shuriken->get_atirou_direita())
					shuriken->atirar_direita(delta_t);

				else if (shuriken->get_atirou_esquerda())
					shuriken->atirar_esquerda(delta_t);*/
				
				duracao_tiro++;

				if (duracao_tiro >= 200)
				{
					shuriken->set_atirou_direita(false);
					shuriken->set_atirou_esquerda(false);
					shuriken->set_pode_atirar(false);
					shuriken->set_posicao(shuriken->get_posicao_inicial());
					duracao_tiro = 0;
				}

				posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
			}

			else if(!shuriken->get_pode_atirar())
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

		const int Kamikaze::get_duracao_tiro() const
		{
			return(duracao_tiro);
		}
	}
}
