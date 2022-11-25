#pragma once

#include"stdafx.h"
#include"Ente.h"

#define GRAVIDADE 30

#define ID_PLATAFORMA 1
#define ID_ESPINHO 2
#define ID_PEDRA 3

#define ID_SHURIKEN 4

#define ID_NINJA 5
#define ID_KAMIKAZE 6
#define ID_IZANAMI 7
#define ID_SAMURAI 8

namespace Entidades
{
	class Entidade :public Ente
	{
	protected:
		Vetor2D<float> posicao;
		Vetor2D<float> velocidade;
		int tipo_entidade;
		bool pode_executar;
		int temporizador_pode_executar;

	public:
		Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f));
		virtual ~Entidade();
		void desenhar();
		void set_posicao(Vetor2D<float> posicao_input);
		void set_posicao(float x_input, float y_input);
		Vetor2D<float> get_posicao() const;
		const int get_tipo_entidade() const;
		void set_velocidade(const Vetor2D<float> velocidade_input);
		const Vetor2D<float> get_velocidade() const;
		virtual void executar(float delta_t) = 0;
		void set_pode_executar(const bool e);
		const bool get_pode_executar() const;
	};
}
