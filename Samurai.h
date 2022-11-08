#pragma once

#include"stdafx.h"
#include "Personagem.h"

namespace Entidades
{
	class Samurai : public Personagem
	{
	public:
		Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> velocidade_input = Vetor2D<float>(0.1f, 0.1f), int vidas_input = -1);
		~Samurai();
		void executar(sf::Clock);
	};
}
