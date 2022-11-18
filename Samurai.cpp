#include "Samurai.h"

namespace Entidades
{
	namespace Personagens
	{
		Samurai::Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
			Personagem{ gerenciador_grafico_input, caminho_textura_input, posicao_input},
			pontos{ 0 },
			pode_pular{ false },
			altura_maxima{ 300.0f },
			temporizador_movimento{ 0 },
			colisao_dir_inimigo{ false },
			colisao_esq_inimigo{ false },
			colisao_cima_inimigo{ false },
			colisao_dir_espinho{ false },
			colisao_esq_espinho{ false },
			colisao_cima_espinho{ false }
		{
			velocidade = Vetor2D<float>(0.0f, 0.0f);
			corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
			tipo_entidade = ID_SAMURAI;
			vidas = 15;
			vivo = true;
		}

		Samurai::~Samurai()
		{
		}

		//Hilze Vonck
		void Samurai::executar(float delta_t)
		{
			velocidade.set_x(0.0f);
			velocidade.set_y(velocidade.get_y() + 40.0f * delta_t);

			if (colisao_dir_espinho && temporizador_movimento <= 100)
			{
				velocidade.set_x(velocidade.get_x() + 30.0f);
				temporizador_movimento++;

				if (temporizador_movimento == 100)
				{
					colisao_dir_espinho = false;
					temporizador_movimento = 0;
				}
			}

			else if (colisao_esq_espinho && temporizador_movimento <= 10)
			{
				velocidade.set_x(velocidade.get_x() - 30.0f);
				temporizador_movimento++;

				if (temporizador_movimento == 10)
				{
					colisao_esq_espinho = false;
					temporizador_movimento = 0;
				}
			}

			else if (colisao_cima_espinho && temporizador_movimento <= 10)
			{
				velocidade.set_y(-sqrtf(2.0f * 20.0f * altura_maxima));
				temporizador_movimento++;

				if (temporizador_movimento == 10)
				{
					colisao_cima_espinho = false;
					temporizador_movimento = 0;
				}
			}

			else if (colisao_dir_inimigo && temporizador_movimento <= 10)
			{
				velocidade.set_x(velocidade.get_x() + 30.0f);
				temporizador_movimento++;

				if (temporizador_movimento == 10)
				{
					colisao_dir_inimigo = false;
					temporizador_movimento = 0;
				}
			}

			else if (colisao_esq_inimigo && temporizador_movimento <= 10)
			{
				velocidade.set_x(velocidade.get_x() - 30.0f);
				temporizador_movimento++;

				if (temporizador_movimento == 10)
				{
					colisao_esq_inimigo = false;
					temporizador_movimento = 0;
				}
			}

			else if (colisao_cima_inimigo && temporizador_movimento <= 10)
			{
				velocidade.set_y(-sqrtf(2.0f * 10.0f * altura_maxima));
				temporizador_movimento++;

				if (temporizador_movimento == 10)
				{
					colisao_cima_inimigo = false;
					temporizador_movimento = 0;
				}
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pode_pular)
			{
				set_pode_pular(false);
				velocidade.set_y(-sqrtf(2.0f * 20.0f * altura_maxima));
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				velocidade.set_x(velocidade.get_x() - 30.0f);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				velocidade.set_x(velocidade.get_x() + 40.0f);
			}

			posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
		}

		void Samurai::set_pode_pular(const bool pode_pular_input)
		{
			pode_pular = pode_pular_input;
		}

		void Samurai::set_colisao_dir_inimigo(const bool colisao)
		{
			colisao_dir_inimigo = colisao;
		}

		void Samurai::set_colisao_esq_inimigo(const bool colisao)
		{
			colisao_esq_inimigo = colisao;
		}

		void Samurai::set_colisao_cima_inimigo(const bool colisao)
		{
			colisao_cima_inimigo = colisao;
		}

		void Samurai::set_colisao_dir_espinho(const bool colisao)
		{
			colisao_dir_espinho = colisao;
		}

		void Samurai::set_colisao_esq_espinho(const bool colisao)
		{
			colisao_esq_espinho = colisao;
		}

		void Samurai::set_colisao_cima_espinho(const bool colisao)
		{
			colisao_cima_espinho = colisao;
		}

		void Samurai::set_pontos(const int pontos_input)
		{
			pontos = pontos_input;
		}

		const int Samurai::get_pontos() const
		{
			return(pontos);
		}
	}
}
