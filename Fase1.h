#pragma once

#include"stdafx.h"
#include"Fase.h"

namespace Fases
{
	class Fase1 :public Fase
	{
	private:
		bool ganhou_fase;

	public:
		Fase1(Gerenciadores::GerenciadorGrafico* gerenciador_grafico = nullptr, const char* background = nullptr, Entidades::Personagens::Samurai* samurai_input = nullptr);
		~Fase1();
		void criar_mapa();
		void criar_plataforma(Vetor2D<float> posicao_input, Vetor2D<float> tamanho_input = Vetor2D<float>(200.0f, 20.f));
		void criar_espinho(Vetor2D<float> posicao_input);
		void criar_pedra(Vetor2D<float> posicao_input);
		void criar_ninja(Vetor2D<float> posicao_input);
		void criar_kamikaze(Vetor2D<float> posicao_input);
		void set_ganhou_fase(const bool ganhou_fase_input);
		const bool get_ganhou_fase() const;
	};
}
