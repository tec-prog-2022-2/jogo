#pragma once

#include"stdafx.h"
#include"Ente.h"

#define ID_PLATAFORMA 1
#define ID_ESPINHO 2
#define ID_PEDRA 3

#define ID_NINJA 4
#define ID_KAMIKAZE 5
#define ID_SHURIKEN 6
#define ID_IZANAMI 7

#define ID_SAMURAI 8

namespace Entidades
{
	class Entidade :public Ente
	{
	protected:
		Vetor2D<float> posicao;
		Vetor2D<float> velocidade;
		sf::RectangleShape corpo;
		int tipo_entidade;

	public:
		Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0, 200.0), int tipo_entidade_input = -1);
		virtual ~Entidade();
		void desenhar();
		void set_posicao(Vetor2D<float> posicao_input);
		const Vetor2D<float> get_posicao() const;
		sf::RectangleShape get_corpo();
		const int get_tipo_entidade() const;
		void set_velocidade(const Vetor2D<float> velocidade_input);
		const Vetor2D<float> get_velocidade() const;
		virtual void executar(float delta_t) = 0;
	};
}
