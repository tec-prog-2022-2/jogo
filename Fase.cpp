#include"Fase.h"

namespace Fases
{
	Fase::Fase(Gerenciadores::GerenciadorGrafico* gerenciador_grafico, const char* background, Entidades::Personagens::Samurai* samurai_input):
		Ente(gerenciador_grafico, background),
		lista_entidades{},
		vetor_personagens{},
		lista_obstaculos{},
		samurai{samurai_input},
		samurai_2{nullptr},
		gerenciador_colisao{ samurai, &vetor_personagens, &lista_obstaculos},
		bandeira{sf::Vector2f(100.0f, 100.0f)},
		fundo{}
	{
		gerenciador_grafico->carregar_textura("C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//bandeira.png");
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

	void Fase::desenhar()
	{
		desenhar(caminho_textura);
	}

	void Fase::desenhar(const char* caminho_textura_input)
	{
		gerenciador_grafico->desenhar(caminho_textura_input, &fundo);
	}

	void Fase::executar(float delta_t)
	{
		gerenciador_grafico->limpar();
		desenhar();
		lista_entidades.executar_entidades(delta_t);
		gerenciador_colisao.executar(delta_t);
		gerenciador_grafico->centralizar(samurai->get_posicao() + Vetor2D<float>(0.0f, -100.0f));
		lista_entidades.desenhar_entidades();
		gerenciador_grafico->desenhar("C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//bandeira.png", Vetor2D<float>(1050.0f * 4+100.0f, 610.0f), &bandeira);
		gerenciador_grafico->set_camera();
		gerenciador_grafico->mostrar();
	}

	void Fase::set_samurai(Vetor2D<float> posicao_input)
	{
		samurai->set_posicao(posicao_input.get_x(), posicao_input.get_y());
	}

	void Fase::set_samurai_2(Entidades::Personagens::Samurai* samurai_2_input, Vetor2D<float> posicao_input)
	{
		samurai_2 = samurai_2_input;
		samurai_2->set_posicao(posicao_input);
		lista_entidades.add_entidade(static_cast<Entidades::Entidade*>(samurai_2));
		vetor_personagens.push_back(static_cast<Entidades::Personagens::Personagem*>(samurai_2));
		gerenciador_colisao.add_samurai_2(samurai_2);
	}
}
