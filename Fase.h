#pragma once

#include"stdafx.h"
#include"Entidade.h"
#include"Samurai.h"
#include"Ninja.h"
#include"Kamikaze.h"
#include"Izanagi.h"
#include"Plataforma.h"
#include"Espinho.h"
#include"Pedra.h"
#include"Lista.h"
#include"ListaEntidades.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorColisao.h"

namespace Fases
{
	class Fase :public Ente
	{
	protected:
		bool passou_fase;
		Listas::ListaEntidades lista_entidades;
		std::vector<Entidades::Personagens::Personagem*> vetor_personagens;
		std::list<Entidades::Obstaculos::Obstaculo*> lista_obstaculos;
		Entidades::Personagens::Samurai* samurai;
		Entidades::Personagens::Samurai* samurai_2;
		Gerenciadores::GerenciadorColisao gerenciador_colisao;

	public:
		Fase(Gerenciadores::GerenciadorGrafico* gerenciador_grafico = nullptr, const char* background = nullptr, Entidades::Personagens::Samurai* samurai_input=nullptr);
		virtual ~Fase();
		void desenhar() {}; 
		void executar(float delta_t);
		void set_samurai(Vetor2D<float> posicao_input);
		void set_samurai_2(Entidades::Personagens::Samurai* samurai_2_input, Vetor2D<float> posicao_input);
	};
}

/*#pragma once

#include"stdafx.h"
#include"Entidade.h"
#include"Samurai.h"
#include"Ninja.h"
#include"Kamikaze.h"
#include"Izanami.h"
#include"Plataforma.h"
#include"Espinho.h"
#include"Pedra.h"
#include"Lista.h"
#include"ListaEntidades.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorColisao.h"

namespace Fases
{
	class Fase:public Ente
	{
	protected:
		Listas::ListaEntidades lista_entidades;
		std::vector<Entidades::Personagens::Personagem*> vetor_personagens;
		std::list<Entidades::Obstaculos::Obstaculo*> lista_obstaculos;
		Gerenciadores::GerenciadorColisao gerenciador_colisao;
		Entidades::Personagens::Samurai samurai;

	public:
		Fase(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr);
		virtual ~Fase();
		void criar_plataforma(Vetor2D<float> posicao_input);
		void criar_espinho(Vetor2D<float> posicao_input);
		void criar_pedra(Vetor2D<float> posicao_input);
		void criar_ninja(Vetor2D<float> posicao_input);
		void criar_kamikaze(Vetor2D<float> posicao_input);
		void criar_izanami(Vetor2D<float> posicao_input);
		void setar_samurai(Vetor2D<float> posicao_input);
		void desenhar();
		void executar(float delta_t);
		virtual void criar_fase() = 0;
	};
}*/