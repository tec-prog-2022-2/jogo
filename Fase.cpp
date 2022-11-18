#include"Fase.h"

namespace Fases
{
	Fase::Fase(Gerenciadores::GerenciadorGrafico* gerenciador_grafico, const char* background, Entidades::Personagens::Samurai* samurai_input):
		Ente(gerenciador_grafico, background),
		passou_fase{false},
		lista_entidades{},
		vetor_personagens{},
		lista_obstaculos{},
		samurai{samurai_input},
		gerenciador_colisao{ samurai, &vetor_personagens, &lista_obstaculos}
	{
		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(samurai));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(samurai));
	}

	Fase::~Fase()
	{
		std::vector<Entidades::Personagens::Personagem*>::iterator iterador_personagens;
		std::list<Entidades::Obstaculos::Obstaculo*>::iterator iterador_obstaculos;

		for (iterador_personagens = vetor_personagens.begin(); iterador_personagens != vetor_personagens.end(); iterador_personagens++)
		{
			Entidades::Personagens::Personagem* personagem= static_cast<Entidades::Personagens::Personagem*>(*iterador_personagens);

			if (personagem && personagem->get_tipo_entidade()!=ID_SAMURAI)
				delete personagem;

			personagem = nullptr;
		}

		for (iterador_obstaculos = lista_obstaculos.begin(); iterador_obstaculos != lista_obstaculos.end(); iterador_obstaculos++)
		{
			if (*iterador_obstaculos)
				delete* iterador_obstaculos;

			*iterador_obstaculos = nullptr;
		}
	}

	void Fase::executar(float delta_t)
	{
		gerenciador_grafico->limpar();
		lista_entidades.executar_entidades(delta_t);
		gerenciador_colisao.executar(delta_t);
		gerenciador_grafico->centralizar(samurai->get_posicao() + Vetor2D<float>(0.0f, -100.0f));
		lista_entidades.desenhar_entidades();
		gerenciador_grafico->set_camera();
		gerenciador_grafico->mostrar();
	}

	void Fase::set_samurai(Vetor2D<float> posicao_input)
	{
		samurai->get_corpo()->setPosition(sf::Vector2f(posicao_input.get_x(), posicao_input.get_y()));
	}
}

/*#include "Fase.h"

namespace Fases
{
	Fase::Fase(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input):
		Ente(gerenciador_grafico_input, caminho_textura_input),
		lista_entidades(),
		lista_obstaculos(),
		gerenciador_colisao{ &samurai, &vetor_personagens, &lista_obstaculos },
		samurai{ gerenciador_grafico_input, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", Vetor2D<float>(0.0f,0.0f)}
	{
		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(&samurai));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(&samurai));
	}

	Fase::~Fase()
	{

	}

	void Fase::criar_plataforma(Vetor2D<float> posicao_input)
	{
		Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input);
		if (!plataforma)
		{
			std::cout << "Nao foi possivel criar plataforma!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(plataforma));
		lista_obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(plataforma));
	}

	void Fase::criar_espinho(Vetor2D<float> posicao_input)
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

	void Fase::criar_pedra(Vetor2D<float> posicao_input)
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

	void Fase::criar_ninja(Vetor2D<float> posicao_input)
	{
		Entidades::Personagens::Ninja* ninja = new Entidades::Personagens::Ninja(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input);
		if (!ninja)
		{
			std::cout << "Nao foi possivel criar ninja!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(ninja));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(ninja));
	}

	void Fase::criar_kamikaze(Vetor2D<float> posicao_input)
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

	void Fase::criar_izanami(Vetor2D<float> posicao_input)
	{
		Entidades::Personagens::Izanami* izanami = new Entidades::Personagens::Izanami(gerenciador_grafico, "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//Bamboo-Free-PNG.png", posicao_input);
		if (!izanami)
		{
			std::cout << "Nao foi possivel criar izanami!" << std::endl;
			exit(1);
		}

		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(izanami));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(izanami));
	}

	void Fase::setar_samurai(Vetor2D<float> posicao_input)
	{
		samurai.set_posicao(posicao_input);
	}

	void Fase::desenhar()
	{

	}

	void Fase::executar(float delta_t)
	{
		gerenciador_grafico->limpar();
		lista_entidades.executar_entidades(delta_t);
		gerenciador_colisao.executar(delta_t);
		gerenciador_grafico->centralizar(samurai.get_posicao());
		lista_entidades.desenhar_entidades();
		gerenciador_grafico->set_camera();
		gerenciador_grafico->mostrar();
	}
}
*/
