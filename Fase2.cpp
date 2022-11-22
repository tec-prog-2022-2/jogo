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
	}

	void Fase2::criar_mapa()
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		set_samurai(Vetor2D<float>(600.0f, 0.0f));

		//Criando o chão
		criar_plataforma(Vetor2D<float>(0.0f, 700.0f), Vetor2D<float>(4000.0f, 300.0f));

		//Criando plataformas
		int i = 0;
		int aleatorio = 3 + rand() % 1;
		float delta_x = 600.0f;
		for (i = 0; i < aleatorio; i++)
		{
			criar_plataforma(Vetor2D<float>(delta_x, 550.0f));
			delta_x += 750.0f;
		}

		aleatorio = 3 + rand() % 2;
		delta_x = 1000.0f;
		for (i = 0; i < aleatorio; i++)
		{
			criar_ninja(Vetor2D<float>(delta_x, 450.0f));
			delta_x += 750.0f;
		}
	}


	//Criacao inspirada no gege++
	void Fase2::criar_plataforma(Vetor2D<float> posicao_input, Vetor2D<float> tamanho_input)
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

	void Fase2::criar_espinho(Vetor2D<float> posicao_input)
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

	void Fase2::criar_ninja(Vetor2D<float> posicao_input)
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

	void Fase2::criar_izanami(Vetor2D<float> posicao_input)
	{
		Entidades::Personagens::Izanami* izanami = new Entidades::Personagens::Izanami(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input, samurai);
		if (!izanami)
		{
			std::cout << "Nao foi possivel criar izanami!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(izanami));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(izanami));
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
