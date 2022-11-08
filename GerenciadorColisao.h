#pragma once

#include"stdafx.h"
#include"Personagem.h"
#include"Obstaculo.h"

namespace Gerenciadores
{
	class GerenciadorColisao
	{
	private:
		std::vector<Entidades::Personagem*>* vetor_personagens;
		std::list<Obstaculos::Obstaculo*>* lista_obstaculos;

	public:
		GerenciadorColisao(std::vector<Entidades::Personagem*>* vetor_personagens_input = nullptr, std::list<Obstaculos::Obstaculo*>* lista_obstaculos_input = nullptr);
		~GerenciadorColisao();
		Vetor2D<float> calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2);
		void executar();
	};
}
