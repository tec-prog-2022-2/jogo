#pragma once

#include"stdafx.h"
#include"Personagem.h"
#include"Samurai.h"
#include"Inimigo.h"
#include"Kamikaze.h"
#include"Izanagi.h"
#include"Shuriken.h"
#include"Espinho.h"
#include"Obstaculo.h"

namespace Gerenciadores
{
	class GerenciadorColisao
	{
	private:
		Entidades::Personagens::Samurai* samurai;
		Entidades::Personagens::Samurai* samurai_2;
		std::vector<Entidades::Personagens::Personagem*>* vetor_personagens;
		std::list<Entidades::Obstaculos::Obstaculo*>* lista_obstaculos;
		std::list<Entidades::Shuriken*> lista_shurikens;

	public:
		GerenciadorColisao(Entidades::Personagens::Samurai* samurai_input, std::vector<Entidades::Personagens::Personagem*>* vetor_personagens_input = nullptr, std::list<Entidades::Obstaculos::Obstaculo*>* lista_obstaculos_input = nullptr);
		~GerenciadorColisao();
		void inicializar_lista_shurikens();
		Vetor2D<float> calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2);
		void colisao_personagem_obstaculo(Entidades::Personagens::Personagem* personagem, Entidades::Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds);
		void colisao_samurai_inimigo(Entidades::Personagens::Samurai* samurai_input, Entidades::Personagens::Inimigo* inimigo, Vetor2D<float> ds, float delta_t);
		void colisao_samurai_shuriken(Entidades::Personagens::Samurai* samurai_input, Entidades::Shuriken* shuriken, Vetor2D<float> ds);
		void executar(float delta_t);
		void add_samurai_2(Entidades::Personagens::Samurai* samurai_2_input);
	};
}
