#include "Principal.h"

Principal::Principal():
	lista_personagens(),
	gerenciador_grafico(),

	//inicializando o personagem na posição (0, 0)
	//passamos também o caminho para o arquivo png que será usado como textura
	p1{ Vetor2D<float>(0.0f, 0.0f), Vetor2D<float>(0.01f, 0.01f), "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_dev//jogo_dev//assets//Bamboo-Free-PNG.png" },
	p2{ Vetor2D<float>(1.0f, 1.0f), Vetor2D<float>(0.02f, 0.0f), "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_dev//jogo_dev//assets//Bamboo-Free-PNG.png" }
{
	lista_personagens.add_info(&p1);
	lista_personagens.add_info(&p2);
	p1.inicializar(&gerenciador_grafico);
	p2.inicializar(&gerenciador_grafico);
	executar();
}

Principal::~Principal()
{

}

void Principal::executar()
{
	while (gerenciador_grafico.get_janela()->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (gerenciador_grafico.get_janela()->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				gerenciador_grafico.get_janela()->close();
		}

		gerenciador_grafico.limpar();
		
		Listas::Lista<Personagem>::Iterador i;
		for (i = lista_personagens.begin(); i != lista_personagens.end(); ++i)
		{
			Personagem* personagem = *i;
			personagem->atualizar(); //atualiza posicao do personagem
			personagem->desenhar(&gerenciador_grafico); //e entao desenha o personagem com a nova posicao
		}

		gerenciador_grafico.mostrar(); 
	}
}
