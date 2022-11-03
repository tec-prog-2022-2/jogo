#pragma once

#include"Entidade.h"

namespace Entidades
{
	class Personagem : public Entidade
	{
	protected:
		int vidas;

	public:
		Personagem(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), int vidas_input = -1);
		virtual ~Personagem();
		virtual void executar(sf::Clock) = 0;
	};
}