#include "Jogo.h"

Jogo::Jogo() :
	gerenciador_grafico(),
	samurai{ &gerenciador_grafico, "assets//samurai.png" , Vetor2D<float>(0.0f, 0.0f) },
	samurai_2{nullptr},
	relogio(),
	menu_inicial{true},
	menu_ganhou{false},
	menu_perdeu{false},
	fase_1_1_jog{false},
	fase_1_2_jog{false},
	fase_2_1_jog{false},
	fase_2_2_jog{false},
	fase1{&gerenciador_grafico, "assets//fase_1.png", &samurai},
	fase2{&gerenciador_grafico, "assets//fase_2.png", &samurai},
	menu{&gerenciador_grafico, "assets//ethn.otf", true},
	criar_fase_1{false},
	criar_fase_2{false}
{
	executar();
}

Jogo::~Jogo()
{
	samurai_2 = nullptr;
}

void Jogo::executar()
{
	float dt = 0.0f;

	while (gerenciador_grafico.get_janela()->isOpen())
	{
		sf::Event event;

		while (gerenciador_grafico.get_janela()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gerenciador_grafico.get_janela()->close();

			if (event.type == sf::Event::Resized)
				gerenciador_grafico.reajustar_camera();

			if (menu_inicial)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !menu.pressionado) 
				{
					if (menu.posicao < 4) {
						menu.posicao++;
						menu.pressionado = true;
						menu.textos[menu.posicao].setOutlineThickness(4);
						menu.textos[menu.posicao - 1].setOutlineThickness(0);
						menu.pressionado = false;
						menu.selecionado = false;
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !menu.pressionado) 
				{
					if (menu.posicao > 1) {
						menu.posicao--;
						menu.pressionado = true;
						menu.textos[menu.posicao].setOutlineThickness(4);
						menu.textos[menu.posicao + 1].setOutlineThickness(0);
						menu.pressionado = false;
						menu.selecionado = false;
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !menu.selecionado) 
				{
					menu.selecionado = true;
					if (menu.posicao == 1)
					{
						menu_inicial = false;
						fase_1_1_jog = true;
						criar_fase_1 = false;
						criar_fase_2 = false;
						samurai.set_vidas(5);
						samurai.set_vivo(true);
						gerenciador_grafico.limpar();
						gerenciador_grafico.centralizar(samurai.get_posicao() + Vetor2D<float>(0.0f, -100.0f));
						gerenciador_grafico.set_camera();
					}

					if (menu.posicao == 2)
					{
						menu_inicial = false;
						fase_1_2_jog = true;
						gerenciador_grafico.limpar();
						gerenciador_grafico.centralizar(samurai.get_posicao() + Vetor2D<float>(0.0f, -100.0f));
						gerenciador_grafico.set_camera();
						samurai.set_vidas(5);
						samurai.set_vivo(true);
						samurai_2 = new Entidades::Personagens::Samurai(&gerenciador_grafico, "assets//samurai.png", Vetor2D<float>(600.0f, 0.0f));
						samurai_2->set_jogador_principal(false);
						samurai_2->set_vivo(true);
						fase1.set_samurai_2(samurai_2, Vetor2D<float>(600.0f, 600.0f));
					}

					if (menu.posicao == 3)
					{
						menu_inicial = false;
						fase_2_1_jog = true;
						gerenciador_grafico.limpar();
						gerenciador_grafico.centralizar(samurai.get_posicao() + Vetor2D<float>(0.0f, -100.0f));
						gerenciador_grafico.set_camera();
						samurai.set_vidas(5);
						samurai.set_vivo(true);
					}

					if (menu.posicao == 4)
					{
						menu_inicial = false;
						fase_2_2_jog = true;
						while (samurai.get_posicao().get_x() != 600.0f)
						{
							gerenciador_grafico.limpar();
							samurai.set_posicao(Vetor2D<float>(600.0f, 600.0f));
							gerenciador_grafico.centralizar(samurai.get_posicao() + Vetor2D<float>(0.0f, -100.0f));
							gerenciador_grafico.set_camera();
							samurai.set_vivo(true);
						}
						samurai.set_vidas(5);
						samurai_2 = new Entidades::Personagens::Samurai(&gerenciador_grafico, "assets//samurai.png", Vetor2D<float>(0.0f, 0.0f));
						samurai_2->set_jogador_principal(false);
						samurai_2->set_vivo(true);
						fase2.set_samurai_2(samurai_2, Vetor2D<float>(650.0f, 600.0f));
					}
				}
			}
		}

		if (menu_inicial)
		{
			gerenciador_grafico.set_camera_menu();
			gerenciador_grafico.centralizar_menu(Vetor2D<float>(650, 200.0f));
			menu.desenhar();
		}

		else if (menu_ganhou)
		{
			gerenciador_grafico.set_camera_menu();
			gerenciador_grafico.centralizar_menu(Vetor2D<float>(650, 200.0f));
			menu.desenhar(1);
		}

		else if (menu_perdeu)
		{
			gerenciador_grafico.set_camera_menu();
			gerenciador_grafico.centralizar_menu(Vetor2D<float>(650, 200.0f));
			menu.desenhar(2);
		}

		else
		{
			if (fase_1_1_jog)
			{
				if (!criar_fase_1)
				{
					criar_fase_1 = true;
					fase1.criar_mapa();
				}

				if (!fase1.get_ganhou_fase() && criar_fase_1)
				{
					if (!samurai.get_vivo())
					{
						fase_1_1_jog = false;
						menu_perdeu = true;
					}

					fase1.executar(dt*4);

					if (samurai.get_posicao().get_y() >= 1300.0f)
					{
						samurai.set_vivo(false);
						menu_perdeu = true;
					}

					if (samurai.get_posicao().get_x() >= 1050.0f * 4 + 100.0f)
						fase1.set_ganhou_fase(true);

					if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 5000)
						samurai.set_posicao(Vetor2D<float>(5000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

					else if (samurai.get_posicao().get_x() < 500.0f)
						samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

					dt = relogio.restart().asSeconds();
				}

				if (!criar_fase_2 && fase1.get_ganhou_fase())
				{
					criar_fase_2 = true;
					fase2.criar_mapa();
					while (samurai.get_posicao().get_x() != 600.0f)
						samurai.set_posicao(Vetor2D<float>(600.0f, 0.0f));
				}

				if (!fase2.get_ganhou_jogo() && criar_fase_2)
				{
					if (!samurai.get_vivo())
					{
						fase_1_1_jog = false;
						menu_perdeu = true;
					}

					fase2.executar(dt * 4);

					if (samurai.get_posicao().get_y() >= 1300.0f)
					{
						samurai.set_vivo(false);
						menu_perdeu = true;
					}

					if (samurai.get_posicao().get_x() >= 1050.0f * 4 + 100.0f)
					{
						fase2.set_ganhou_jogo(true);
						menu_ganhou = true;
					}

					if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 5000)
						samurai.set_posicao(Vetor2D<float>(5000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

					else if (samurai.get_posicao().get_x() < 500.0f)
						samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

					dt = relogio.restart().asSeconds();
				}
			}

			else if (fase_1_2_jog)
			{
				if (!criar_fase_1)
				{
					criar_fase_1 = true;
					fase1.criar_mapa();
				}

				if (!fase1.get_ganhou_fase() && criar_fase_1)
				{
					if (!samurai.get_vivo() || !samurai_2->get_vivo())
					{
						fase_1_2_jog = false;
						menu_perdeu = true;
					}

					fase1.executar(dt * 4);

					if (samurai.get_posicao().get_y() >= 1300.0f || samurai_2->get_posicao().get_y() >= 1300.0f)
					{
						samurai.set_vivo(false);
						samurai_2->set_vivo(false);
						menu_perdeu = true;
					}

					if (samurai.get_posicao().get_x() >= 1050.0f * 4 + 100.0f || samurai_2->get_posicao().get_x() >= 1050.0f * 4 + 100.0f)
						fase1.set_ganhou_fase(true);

					if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 5000)
						samurai.set_posicao(Vetor2D<float>(5000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

					else if (samurai.get_posicao().get_x() < 500.0f)
						samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

					if (samurai_2->get_posicao().get_x() + samurai_2->get_corpo()->getGlobalBounds().width > 5000)
						samurai_2->set_posicao(Vetor2D<float>(5000 - samurai_2->get_corpo()->getGlobalBounds().width, samurai_2->get_posicao().get_y()));

					else if (samurai_2->get_posicao().get_x() < 500.0f)
						samurai_2->set_posicao(Vetor2D<float>(500.0f, samurai_2->get_posicao().get_y()));

					dt = relogio.restart().asSeconds();
				}

				if (!criar_fase_2 && fase1.get_ganhou_fase())
				{
					criar_fase_2 = true;
					fase2.criar_mapa();
					fase2.set_samurai_2(samurai_2, Vetor2D<float>(600.0f, 600.0f));
					while (samurai.get_posicao().get_x() != 600.0f)
						samurai.set_posicao(Vetor2D<float>(600.0f, 400.0f));
				}

				if (!fase2.get_ganhou_jogo() && criar_fase_2)
				{
					if (!samurai.get_vivo() || !samurai_2->get_vivo())
					{
						fase_1_2_jog = false;
						menu_perdeu = true;
					}

					fase2.executar(dt * 4);

					if (samurai.get_posicao().get_y() >= 1300.0f || samurai_2->get_posicao().get_y() >= 1300.0f)
					{
						samurai.set_vivo(false);
						samurai_2->set_vivo(false);
						menu_perdeu = true;
					}

					if (samurai.get_posicao().get_x() >= 1050.0f * 4 + 100.0f || samurai_2->get_posicao().get_y() >= 1050.0f * 4 + 100.0f)
					{
						fase2.set_ganhou_jogo(true);
						menu_ganhou = true;
					}

					if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 5000)
						samurai.set_posicao(Vetor2D<float>(5000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

					else if (samurai.get_posicao().get_x() < 500.0f)
						samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

					if (samurai_2->get_posicao().get_x() + samurai_2->get_corpo()->getGlobalBounds().width > 5000)
						samurai_2->set_posicao(Vetor2D<float>(5000 - samurai_2->get_corpo()->getGlobalBounds().width, samurai_2->get_posicao().get_y()));

					else if (samurai_2->get_posicao().get_x() < 500.0f)
						samurai_2->set_posicao(Vetor2D<float>(500.0f, samurai_2->get_posicao().get_y()));

					dt = relogio.restart().asSeconds();
				}
			}

			else if (fase_2_1_jog)
			{
				if (!criar_fase_2)
				{
					criar_fase_2 = true;
					fase2.criar_mapa();
				}

				if (!fase2.get_ganhou_jogo() && criar_fase_2)
				{
					if (!samurai.get_vivo())
					{
						fase_2_1_jog = false;
						menu_perdeu = true;
					}

					fase2.executar(dt * 4);

					if (samurai.get_posicao().get_y() >= 1300.0f)
					{
						samurai.set_vivo(false);
						menu_perdeu = true;
					}

					if (samurai.get_posicao().get_x() >= 1050.0f * 4 + 100.0f)
					{
						fase2.set_ganhou_jogo(true);
						menu_ganhou = true;
					}

					if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 5000)
						samurai.set_posicao(Vetor2D<float>(5000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

					else if (samurai.get_posicao().get_x() < 500.0f)
						samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

					dt = relogio.restart().asSeconds();
				}
			}

			else if (fase_2_2_jog)
			{
				if (!criar_fase_2)
				{
					criar_fase_2 = true;
					fase2.criar_mapa();
				}

				if (!fase2.get_ganhou_jogo() && criar_fase_2)
				{
					if (!samurai.get_vivo() || !samurai_2->get_vivo())
					{
						fase_2_2_jog = false;
						menu_perdeu=true;
					}

					fase2.executar(dt * 4);

					if (samurai.get_posicao().get_y() >= 1300.0f || samurai_2->get_posicao().get_y() >= 1300.0f)
					{
						samurai.set_vivo(false);
						samurai_2->set_vivo(false);
						menu_perdeu = true;
					}

					if (samurai.get_posicao().get_x() >= 1050.0f * 4 + 100.0f || samurai_2->get_posicao().get_x() >= 1050.0f * 4 + 100.0f)
					{
						fase2.set_ganhou_jogo(true);
						menu_ganhou = true;
					}

					if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 5000)
						samurai.set_posicao(Vetor2D<float>(5000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

					else if (samurai.get_posicao().get_x() < 500.0f)
						samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

					if (samurai_2->get_posicao().get_x() + samurai_2->get_corpo()->getGlobalBounds().width > 5000)
						samurai_2->set_posicao(Vetor2D<float>(5000 - samurai_2->get_corpo()->getGlobalBounds().width, samurai_2->get_posicao().get_y()));

					else if (samurai_2->get_posicao().get_x() < 500.0f)
						samurai_2->set_posicao(Vetor2D<float>(500.0f, samurai_2->get_posicao().get_y()));

					dt = relogio.restart().asSeconds();
				}
			}
		}
	}
}
