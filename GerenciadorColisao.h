#pragma once

#include"stdafx.h"
#include"Personagem.h"
#include"Samurai.h"
#include"Inimigo.h"
#include"Obstaculo.h"

namespace Gerenciadores
{
	class GerenciadorColisao
	{
	private:
		Personagens::Samurai* samurai;
		std::vector<Personagens::Personagem*>* vetor_personagens;
		std::list<Obstaculos::Obstaculo*>* lista_obstaculos;

	public:
		GerenciadorColisao(Personagens::Samurai* samurai_input, std::vector<Personagens::Personagem*>* vetor_personagens_input = nullptr, std::list<Obstaculos::Obstaculo*>* lista_obstaculos_input = nullptr);
		~GerenciadorColisao();
		Vetor2D<float> calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2);
		void colisao_personagem_obstaculo(Personagens::Personagem* personagem, Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds);
		void colisao_samurai_inimigo(Personagens::Inimigo* inimigo, Vetor2D<float> ds, float delta_t);
		void executar(float delta_t);
	};
}
