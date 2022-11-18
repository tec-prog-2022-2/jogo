#include"Fase1.h"

namespace Fases
{
	Fase1::Fase1(Gerenciadores::GerenciadorGrafico* gerenciador_grafico, const char* background, Entidades::Personagens::Samurai* samurai_input) :
		Fase(gerenciador_grafico, background, samurai_input)
	{
		criar_mapa();
	}

	Fase1::~Fase1()
	{
		
	}

	void Fase1::criar_mapa()
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		
		set_samurai(Vetor2D<float>(600.0f, 0.0f));

		//Criando o chão
		criar_plataforma(Vetor2D<float>(0.0f, 700.0f), Vetor2D<float>(4000.0f, 300.0f));

		//Criando plataformas
		int i = 0;
		float delta_x = 600.0f;
		for (i = 0; i < 3; i++)
		{
			criar_plataforma(Vetor2D<float>(delta_x, 550.0f));
			delta_x+=750.0f;
		}

		//Criando a plataforma aleatória
		int aleatorio = 1 + rand() % 100;
		if(aleatorio>=50)
			criar_plataforma(Vetor2D<float>(delta_x, 550.0f));

		delta_x = 700.0f;
		for (i = 0; i < 3; i++)
		{
			criar_pedra(Vetor2D<float>(delta_x, 300.0f));
			delta_x += 750.0f;
		}

		//criar_ninja(Vetor2D<float>((100.0f, 450.0f)));
	}

	void Fase1::criar_plataforma(Vetor2D<float> posicao_input, Vetor2D<float> tamanho_input)
	{
		Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//plataforma.png", posicao_input);
		plataforma->get_corpo()->setSize(sf::Vector2f(tamanho_input.get_x(), tamanho_input.get_y()));
		if (!plataforma)
		{
			std::cout << "Nao foi possivel criar plataforma!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(plataforma));
		lista_obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(plataforma));
	}

	void Fase1::criar_espinho(Vetor2D<float> posicao_input)
	{
		Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input);
		if (!espinho)
		{
			std::cout << "Nao foi possivel criar espinho!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(espinho));
		lista_obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(espinho));
	}

	void Fase1::criar_pedra(Vetor2D<float> posicao_input)
	{
		Entidades::Obstaculos::Pedra* pedra = new Entidades::Obstaculos::Pedra(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input);
		if (!pedra)
		{
			std::cout << "Nao foi possivel criar pedra!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(pedra));
		lista_obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(pedra));
	}

	void Fase1::criar_ninja(Vetor2D<float> posicao_input)
	{
		Entidades::Personagens::Ninja* ninja = new Entidades::Personagens::Ninja(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input, samurai);
		if (!ninja)
		{
			std::cout << "Nao foi possivel criar ninja!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(ninja));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(ninja));
	}

	void Fase1::criar_kamikaze(Vetor2D<float> posicao_input)
	{
		Entidades::Personagens::Kamikaze* kamikaze = new Entidades::Personagens::Kamikaze(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input);
		if (!kamikaze)
		{
			std::cout << "Nao foi possivel criar kamikaze!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(kamikaze));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(kamikaze));
	}
}
