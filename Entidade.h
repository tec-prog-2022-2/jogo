#pragma once

#include"stdafx.h"
#include"Ente.h"

namespace Entidades
{
	class Entidade :public Ente
	{
	protected:
		Vetor2D<float> posicao;

	public:
		Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0));
		virtual ~Entidade();
		void desenhar();
		virtual void executar(sf::Clock) = 0;
	};
}