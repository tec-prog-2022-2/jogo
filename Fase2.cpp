#include "Fase2.h"

namespace Fases
{
	Fase2::Fase2(Gerenciadores::GerenciadorGrafico* gerenciador_grafico, const char* background, Entidades::Personagens::Samurai* samurai_input):
		Fase(gerenciador_grafico, background, samurai_input),
		ganhou_jogo{ false }
	{
	}

	Fase2::~Fase2()
	{
		samurai = nullptr;
		samurai_2 = nullptr;
	}

	void Fase2::criar_mapa()
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		int aleatorio = 0;
		int i = 0;

		aleatorio = 8 + rand() % 2;
		for (i = 1; i <= 8; i++)
		{
			if(i==1)
				criar_plataforma(Vetor2D<float>(0.0f, 700.0f), Vetor2D<float>(1000.0f, 800.0f));

			if(i==2)
				criar_plataforma(Vetor2D<float>(1500.0f, 700.0f), Vetor2D<float>(600.0f, 800.0f));

			if(i==3)
				criar_plataforma(Vetor2D<float>(2600.0f, 700.0f), Vetor2D<float>(400.0f, 800.0f));

			if(i==4)
				criar_plataforma(Vetor2D<float>(3200.0f, 700.0f), Vetor2D<float>(400.0f, 800.0f));

			if(i==5)
				criar_plataforma(Vetor2D<float>(3400.0f, 700.0f), Vetor2D<float>(400.0f, 800.0f));

			if(i==6)
				criar_plataforma(Vetor2D<float>(4000.0f, 700.0f), Vetor2D<float>(400.0f, 800.0f));

			if(i==7)
				criar_plataforma(Vetor2D<float>(1100.0f, 550.0f));

			if(i==8)
				criar_plataforma(Vetor2D<float>(2250.0f, 550.0f), Vetor2D<float>(250.0f, 20.0f));

			if(i==9)
				criar_plataforma(Vetor2D<float>(3000.0f, 550.0f), Vetor2D<float>(100.0f, 20.0f));
		}

		aleatorio = 3 + rand() % 2;
		for (i = 1; i <= aleatorio; i++)
		{
			if(i==1)
				criar_ninja(Vetor2D<float>(900.0f, 450.0f));

			if(i==2)
				criar_ninja(Vetor2D<float>(1700.0f, 450.0f));

			if(i==3)
				criar_ninja(Vetor2D<float>(1200.0f, 380.0f));

			if(i==4)
				criar_ninja(Vetor2D<float>(3350.0f, 450.0f));
		}

		aleatorio = 3 + rand() % 3;
		for (i = 1; i <= aleatorio; i++)
		{
			if(i==1)
				criar_espinho(Vetor2D<float>(1150.0f, 470.0f));

			if(i==2)
				criar_espinho(Vetor2D<float>(1500.0f, 620.0f));

			if(i==3)
				criar_espinho(Vetor2D<float>(2600.0f, 620.0f));
			
			if(i==4)
				criar_espinho(Vetor2D<float>(2900.0f, 620.0f));

			if(i==5)
				criar_espinho(Vetor2D<float>(3600.0f, 620.0f));
		}

		aleatorio = 3 + rand() % 2;
		for (i = 1; i <= aleatorio; i++)
		{
			if(i==1)
				criar_izanagi(Vetor2D<float>(2000.0f, 450.0f));

			if(i==2)
				criar_izanagi(Vetor2D<float>(3600.0f, 450.0f));

			if(i==3)
				criar_izanagi(Vetor2D<float>(2700.0f, 450.0f));

			if(i==4)
				criar_izanagi(Vetor2D<float>(4350.0f, 450.0f));
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(samurai));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(samurai));
		set_samurai(Vetor2D<float>(600.0f, 600.0f));
	}


	//Criacao inspirada no gege++
	void Fase2::criar_plataforma(Vetor2D<float> posicao_input, Vetor2D<float> tamanho_input)
	{
		Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(gerenciador_grafico, "assets//plataforma.png", posicao_input);
		plataforma->get_corpo()->setSize(sf::Vector2f(tamanho_input.get_x(), tamanho_input.get_y()));
		if (!plataforma)
		{
			std::cout << "Nao foi possivel criar plataforma!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(plataforma));
		lista_obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(plataforma));
	}

	void Fase2::criar_espinho(Vetor2D<float> posicao_input)
	{
		Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(gerenciador_grafico, "assets//espinho.png", posicao_input);
		if (!espinho)
		{
			std::cout << "Nao foi possivel criar espinho!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(espinho));
		lista_obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(espinho));
	}

	void Fase2::criar_ninja(Vetor2D<float> posicao_input)
	{
		Entidades::Personagens::Ninja* ninja = new Entidades::Personagens::Ninja(gerenciador_grafico, "assets//ninja.png", posicao_input, samurai);
		if (!ninja)
		{
			std::cout << "Nao foi possivel criar ninja!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(ninja));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(ninja));
	}

	void Fase2::criar_izanagi(Vetor2D<float> posicao_input)
	{
		Entidades::Personagens::Izanagi* izanagi = new Entidades::Personagens::Izanagi(gerenciador_grafico, "assets//izanagi.png", posicao_input, samurai);
		if (!izanagi)
		{
			std::cout << "Nao foi possivel criar izanami!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(izanagi));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(izanagi));
	}

	void Fase2::set_ganhou_jogo(const bool ganhou_jogo_input)
	{
		ganhou_jogo = ganhou_jogo_input;
	}

	const bool Fase2::get_ganhou_jogo() const
	{
		return(ganhou_jogo);
	}
}
