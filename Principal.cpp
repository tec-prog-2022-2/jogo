#include "Principal.h"

Principal::Principal() :
	gerenciador_grafico(),
	samurai{ &gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png" , Vetor2D<float>(100.0f,0.0f)},
	relogio(),
	fase1{&gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", &samurai}
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

		fase1.executar(dt*4);

		if (samurai.get_posicao().get_x() + samurai.get_corpo()->getGlobalBounds().width > 3000)
			samurai.set_posicao(Vetor2D<float>(3000 - samurai.get_corpo()->getGlobalBounds().width, samurai.get_posicao().get_y()));

		else if (samurai.get_posicao().get_x() < 500.0f)
			samurai.set_posicao(Vetor2D<float>(500.0f, samurai.get_posicao().get_y()));

		dt = relogio.restart().asSeconds();
	}
}
