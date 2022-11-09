#include "Principal.h"

Principal::Principal():
	lista_entidades(),
	lista_obstaculos(),
	gerenciador_grafico(),
	//gerenciador_colisao{&vetor_personagens, &lista_obstaculos},
	p1{ &gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_dev//jogo_dev//assets//Bamboo-Free-PNG.png" , Vetor2D<float>(0.0f,0.0f), Vetor2D<float>(200.0f, 200.0f), ID_SAMURAI, Vetor2D<float>(0.01f, 0.01f), 3},
	//o1{},
	relogio()
{
	lista_entidades.add_entidade(&p1);
	executar();
}

Principal::~Principal()
{
}

void Principal::executar()
{
	while (gerenciador_grafico.get_janela()->isOpen())
	{
		sf::Event event;
		while (gerenciador_grafico.get_janela()->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				gerenciador_grafico.get_janela()->close();
		}

		gerenciador_grafico.limpar();
		lista_entidades.executar_entidades(relogio);
		lista_entidades.desenhar_entidades();
		gerenciador_grafico.mostrar();
		relogio.restart();
	}
}

//tranfroamar o principal em fase
//criar classe jogo q agrega fase
//ente tem o ponteiro para gerenciador grafico
//jogador que cuida do teclado
//ter fase rodando com plataformas, inimigos (criados aleatoriamente)
//com um jogador e colisao

//O lance do clock está na executar da lista e o executar das entidades etc
