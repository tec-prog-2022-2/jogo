#include "Principal.h"

Principal::Principal() :
	gerenciador_grafico(),
	samurai{ &gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//samurai.png" , Vetor2D<float>(100.0f,0.0f)},
	relogio(),
	fase1{&gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", &samurai},
	fase2{&gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", &samurai},
	menu{&gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//arial//arial.ttf"}
{
	executar();
}

Principal::~Principal()
{
}

void Principal::executar()
{
	float dt = 0;

	while (gerenciador_grafico.get_janela()->isOpen())
	{
		sf::Event event;

		while (gerenciador_grafico.get_janela()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gerenciador_grafico.get_janela()->close();

			if (event.type == sf::Event::Resized)
				gerenciador_grafico.reajustar_camera();
		}

		if (!fase1.get_ganhou_fase())
		{
			fase1.executar(dt * 4);

			if (samurai.get_posicao().get_x() == 2950)
			{
				fase1.set_ganhou_fase(true);
			}

			if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 3000)
				samurai.set_posicao(Vetor2D<float>(3000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

			else if (samurai.get_posicao().get_x() < 500.0f)
				samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

			dt = relogio.restart().asSeconds();
		}

		else if (fase1.get_ganhou_fase() && !fase2.get_ganhou_jogo())
		{
			fase2.executar(dt * 4);

			if (samurai.get_posicao().get_x() == 2950)
			{
				fase2.set_ganhou_jogo(true);
			}

			if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 3000)
				samurai.set_posicao(Vetor2D<float>(3000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

			else if (samurai.get_posicao().get_x() < 500.0f)
				samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

			dt = relogio.restart().asSeconds();
		}
	}
}
