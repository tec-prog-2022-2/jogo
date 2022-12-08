#include"Fase1.h"

namespace Fases
{
	Fase1::Fase1(Gerenciadores::GerenciadorGrafico* gerenciador_grafico, const char* background, Entidades::Personagens::Samurai* samurai_input) :
		Fase(gerenciador_grafico, background, samurai_input),
		ganhou_fase{false}
	{
	}

	Fase1::~Fase1()
	{
		samurai = nullptr;
		samurai_2 = nullptr;
	}

	void Fase1::criar_mapa()
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		int aleatorio = 0;
		int i = 0;
		float delta_x = 0;

		aleatorio = 5 + rand() % 2;
		delta_x = 3000.0f;

		for (i = 1; i <= aleatorio; i++)
		{
			if (i == 1)
				criar_pedra(Vetor2D<float>(1400.0f, 655.0f));

			else if (i >= 2 && i <= 5)
			{
				criar_pedra(Vetor2D<float>(delta_x, 655.0f));
				delta_x += 300.0f;
			}

			else
				criar_pedra(Vetor2D<float>(950.0f, 655.0f));
		}

		aleatorio = 3 + rand() % 2;
		delta_x = 1300.0f;

		for (i = 1; i <= aleatorio; i++)
		{
			if (i >= 1 && i <= 2)
			{
				criar_kamikaze(Vetor2D<float>(delta_x, 450.0f));
				delta_x += 1050.0f;
			}

			else if (i == 3)
				criar_kamikaze(Vetor2D<float>(3200.0f, 520.0f));

			else
				criar_kamikaze(Vetor2D<float>(4000.0f, 520.0f));
		}

		aleatorio = 3 + rand() % 2;
		delta_x = 900.0f;

		for (i = 1; i <= aleatorio; i++)
		{
			if (i >= 1 && i <= 3)
			{
				criar_ninja(Vetor2D<float>(delta_x, 450.0f));
				delta_x += 900.f;
			}

			else
				criar_ninja(Vetor2D<float>(4300, 450.0f));
		}

		aleatorio = 7 + rand() % 2;
		delta_x = 1050.0f;
		
		for (i = 1; i <= aleatorio; i++)
		{
			if (i >= 1 && i <= 2)
			{
				criar_plataforma(Vetor2D<float>(delta_x, 550.0f));
				delta_x += 1050.0f;
			}

			else if (i == 3)
				criar_plataforma(Vetor2D<float>(1050.0f * 4, 550.0f));

			else if (i == 4)
				criar_plataforma(Vetor2D<float>(0.0f, 700.0f), Vetor2D<float>(1000.0f, 800.0f));

			else if(i==5)
				criar_plataforma(Vetor2D<float>(1600.0f, 700.0f), Vetor2D<float>(400.0f, 800.0f));
			
			else if(i==6)
				criar_plataforma(Vetor2D<float>(2400.0f, 700.0f), Vetor2D<float>(400.0f, 800.0f));

			else if(i==7)
				criar_plataforma(Vetor2D<float>(4000.0f, 700.0f), Vetor2D<float>(400.0f, 800.0f));

			else
				criar_plataforma(Vetor2D<float>(2400.0f, 550.0f));
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(samurai));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(samurai));
		set_samurai(Vetor2D<float>(600.0f, 600.0f));

		gerenciador_colisao.inicializar_lista_shurikens();
	}

	void Fase1::criar_plataforma(Vetor2D<float> posicao_input, Vetor2D<float> tamanho_input)
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

	void Fase1::criar_pedra(Vetor2D<float> posicao_input)
	{
		Entidades::Obstaculos::Pedra* pedra = new Entidades::Obstaculos::Pedra(gerenciador_grafico, "assets//pedra.png", posicao_input);
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
		Entidades::Personagens::Ninja* ninja = new Entidades::Personagens::Ninja(gerenciador_grafico, "assets//ninja.png", posicao_input, samurai);
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
		Entidades::Personagens::Kamikaze* kamikaze = new Entidades::Personagens::Kamikaze(gerenciador_grafico, "assets//kamikaze.png", posicao_input, samurai);
		if (!kamikaze)
		{
			std::cout << "Nao foi possivel criar kamikaze!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(kamikaze));
		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(kamikaze->get_shuriken()));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(kamikaze));
	}

	void Fase1::set_ganhou_fase(const bool ganhou_fase_input)
	{
		ganhou_fase = ganhou_fase_input;
	}

	const bool Fase1::get_ganhou_fase() const
	{
		return(ganhou_fase);
	}
}
