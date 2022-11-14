#include "Principal.h"

Principal::Principal() :
	lista_entidades(),
	lista_obstaculos(),
	gerenciador_grafico(),
	p1{ &gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png" , Vetor2D<float>(100.0f,0.0f), Vetor2D<float>(200.0f, 170.0f), ID_SAMURAI, Vetor2D<float>(0.0f, 0.0f), 100 },
	i1{ &gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png" , Vetor2D<float>(100.0f,0.0f), Vetor2D<float>(200.0f, 170.0f), 0, Vetor2D<float>(0.0f, 0.0f), 10, 10, &p1},
	gerenciador_colisao{&p1, &vetor_personagens, &lista_obstaculos },
	plataforma_1{ &gerenciador_grafico,"C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//plataforma.png", Vetor2D<float>(200.0f, 600.0f), Vetor2D<float>(2000.0f, 200.0f)},
	relogio()
{
	lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(&p1));
	lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(&i1));
	lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(&plataforma_1));
	lista_obstaculos.push_back(static_cast<Obstaculos::Obstaculo*>(&plataforma_1));
	vetor_personagens.push_back(static_cast<Personagens::Personagem*>(&p1));
	vetor_personagens.push_back(static_cast<Personagens::Personagem*>(&i1));
	executar();
}

Principal::~Principal()
{
}

void Principal::executar()
{
	while (gerenciador_grafico.get_janela()->isOpen())
	{
		float delta_t = relogio.restart().asSeconds();
		sf::Event event;
		while (gerenciador_grafico.get_janela()->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				gerenciador_grafico.get_janela()->close();
		}
		gerenciador_grafico.limpar();
		lista_entidades.executar_entidades(delta_t);
		gerenciador_colisao.executar(delta_t);
		lista_entidades.desenhar_entidades();
		gerenciador_grafico.centralizar(p1.get_posicao());
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
