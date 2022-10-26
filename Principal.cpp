#include "Principal.h"

Principal::Principal():
	lista_personagens(),
	window{ sf::VideoMode(800, 600), "jogo do joao" },

	//inicializando o personagem na posi��o (0, 0)
	//passamos tamb�m o caminho para o arquivo png que ser� usado como textura
	p1{ sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_dev//jogo_dev//assets//Bamboo-Free-PNG.png" },
	p2{ sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.02f, 0.0f), "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_dev//jogo_dev//assets//Bamboo-Free-PNG.png" }
{
	lista_personagens.add_info(&p1);
	lista_personagens.add_info(&p2);
	executar();
}

Principal::~Principal()
{

}

void Principal::executar()
{
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(); //limpa a janela
		Listas::Lista<Personagem>::Iterador i;

		for (i = lista_personagens.begin(); i != lista_personagens.end(); ++i)
		{
			Personagem* personagem = *i;
			personagem->atualizar(); //atualizamos a posi��o do personagem 
			personagem->desenhar(&window); //desenhamos na janela principal (que � passada por refer�ncia � fun��o o personagem p1
		}
		window.display(); //necess�rio
	}
}
