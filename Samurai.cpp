#include "Samurai.h"

namespace Entidades
{
	namespace Personagens
	{
		Samurai::Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
			Personagem{ gerenciador_grafico_input, caminho_textura_input, posicao_input},
			jogador_principal{true},
			pontos{ 0 },
			pode_pular{ false },
			altura_maxima{ 300.0f },
			temporizador_movimento{ 0 },
			colisao_dir_inimigo{ false },
			colisao_esq_inimigo{ false },
			colisao_cima_inimigo{ false },
			colisao_dir_espinho{ false },
			colisao_esq_espinho{ false },
			colisao_cima_espinho{ false },
			colisao_pedra{false},
			perto_izanagi{false}
		{
			velocidade = Vetor2D<float>(0.0f, 0.0f);
			corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
			tipo_entidade = ID_SAMURAI;
			vidas = 5;
			vivo = true;
		}

		Samurai::~Samurai()
		{
		}

		//Hilze Vonck
		void Samurai::executar(float delta_t)
		{
			if (pode_executar)
			{
				if (!pode_pular)
					colisao_pedra = false;
					
				if (jogador_principal)
				{
					velocidade.set_x(0.0f);
					velocidade.set_y(velocidade.get_y() + GRAVIDADE * delta_t);

					if (colisao_dir_espinho && temporizador_movimento <= 100)
					{
						velocidade.set_x(velocidade.get_x() + 30.0f);
						temporizador_movimento++;

						if (temporizador_movimento == 10)
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
						velocidade.set_y(-sqrtf(GRAVIDADE * altura_maxima/4));
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
						velocidade.set_y(-sqrtf(GRAVIDADE * altura_maxima/4));
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
						velocidade.set_y(-sqrtf(GRAVIDADE * altura_maxima));
					}

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						velocidade.set_x(velocidade.get_x() - 30.0f);

						if (colisao_pedra)
							velocidade.set_x(velocidade.get_x() / 2);

						if(perto_izanagi)
							velocidade.set_x(velocidade.get_x() / 2);
					}

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						velocidade.set_x(velocidade.get_x() + 40.0f);

						if (colisao_pedra)
							velocidade.set_x(velocidade.get_x() / 2);

						if (perto_izanagi)
							velocidade.set_x(velocidade.get_x() / 2);
					}
				}

				else
				{
					velocidade.set_x(0.0f);
					velocidade.set_y(velocidade.get_y() + GRAVIDADE * delta_t);

					if (colisao_dir_espinho && temporizador_movimento <= 100)
					{
						velocidade.set_x(velocidade.get_x() + 30.0f);
						temporizador_movimento++;

						if (temporizador_movimento == 10)
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
						velocidade.set_y(-sqrtf(GRAVIDADE * altura_maxima / 4));
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
						velocidade.set_y(-sqrtf(GRAVIDADE * altura_maxima / 4));
						temporizador_movimento++;

						if (temporizador_movimento == 10)
						{
							colisao_cima_inimigo = false;
							temporizador_movimento = 0;
						}
					}

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pode_pular)
					{
						set_pode_pular(false);
						velocidade.set_y(-sqrtf(GRAVIDADE * altura_maxima));
					}

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					{
						velocidade.set_x(velocidade.get_x() - 30.0f);

						if (colisao_pedra)
							velocidade.set_x(velocidade.get_x() / 2);

						if (perto_izanagi)
							velocidade.set_x(velocidade.get_x() / 2);
					}

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					{
						velocidade.set_x(velocidade.get_x() + 40.0f);

						if (colisao_pedra)
							velocidade.set_x(velocidade.get_x() / 2);

						if (perto_izanagi)
							velocidade.set_x(velocidade.get_x() / 2);
					}
				}

				posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
			}
			
			else
			{
				temporizador_pode_executar++;
				
				if(temporizador_pode_executar>=5)
					this->set_pode_executar(true);	
			}
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

		void Samurai::set_jogador_principal(const bool jogador_principal_input)
		{
			jogador_principal = jogador_principal_input;
		}

		const bool Samurai::get_jogador_principal() const
		{
			return(jogador_principal);
		}

		void Samurai::set_colisao_pedra(const bool colisao_pedra_input)
		{
			colisao_pedra = colisao_pedra_input;
		}

		void Samurai::set_perto_izanagi(const bool perto_izanagi_input)
		{
			perto_izanagi = perto_izanagi_input;
		}
	}
}
