#pragma once

#include"stdafx.h"
#include "Personagem.h"

namespace Entidades
{
	class Samurai : public Personagem
	{
	private:
		bool colisao_chao;

	public:
		Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0f, 200.0f), int tipo_entidade_input = 1, Vetor2D<float> velocidade_input = Vetor2D<float>(0.1f, 0.1f), int vidas_input = -1);
		~Samurai();
		void executar(sf::Clock);
		void set_colisao_chao(const bool colisao_chao_input);
	};
}
