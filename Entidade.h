#pragma once

#include"stdafx.h"
#include"Ente.h"

namespace Entidades
{
	class Entidade :public Ente
	{
	protected:
		Vetor2D<float> posicao;
		sf::RectangleShape corpo;

	public:
		Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0, 200.0));
		virtual ~Entidade();
		void desenhar();
		const Vetor2D<float> get_posicao();
		const sf::RectangleShape get_corpo();
		virtual void executar(sf::Clock) = 0;
	};
}