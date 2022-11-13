#pragma once

#include"stdafx.h"
#include"Personagem.h"
#include"Samurai.h"
#include"Obstaculo.h"

namespace Gerenciadores
{
	class GerenciadorColisao
	{
	private:
		Entidades::Samurai* samurai;
		std::vector<Entidades::Personagem*>* vetor_personagens;
		std::list<Obstaculos::Obstaculo*>* lista_obstaculos;

	public:
		GerenciadorColisao(Entidades::Samurai* samurai_input, std::vector<Entidades::Personagem*>* vetor_personagens_input = nullptr, std::list<Obstaculos::Obstaculo*>* lista_obstaculos_input = nullptr);
		~GerenciadorColisao();
		Vetor2D<float> calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2);
		void colisao_samurai_obstaculo(Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds);
		void colisao_personagem_obstaculo(Entidades::Personagem* personagem, Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds);
		void executar();
	};
}
