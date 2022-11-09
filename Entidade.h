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
		int tipo_entidade;

	public:
		Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0, 200.0), int tipo_entidade_input = -1);
		virtual ~Entidade();
		void desenhar();
		void set_posicao(Vetor2D<float> posicao_input);
		const Vetor2D<float> get_posicao() const;
		const sf::RectangleShape get_corpo() const;
		const int get_tipo_entidade() const;
		virtual void executar(sf::Clock) = 0;
		virtual void colisao(Entidades::Entidade* entidade_colidida, Vetor2D<float> ds = Vetor2D<float>(0.0f, 0.0f)) = 0;
	};
}
