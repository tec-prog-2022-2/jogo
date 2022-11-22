#pragma once

#include "Fase.h"

namespace Fases
{
	class Fase2 : public Fase
	{
	private:
		bool ganhou_jogo;

	public:
		Fase2(Gerenciadores::GerenciadorGrafico* gerenciador_grafico = nullptr, const char* background = nullptr, Entidades::Personagens::Samurai* samurai_input = nullptr);
		~Fase2();
		void criar_mapa();
		void criar_plataforma(Vetor2D<float> posicao_input, Vetor2D<float> tamanho_input = Vetor2D<float>(200.0f, 20.f));
		void criar_espinho(Vetor2D<float> posicao_input);
		void criar_ninja(Vetor2D<float> posicao_input);
		void criar_izanami(Vetor2D<float> posicao_input);
		void set_ganhou_jogo(const bool ganhou_jogo_input);
		const bool get_ganhou_jogo() const;
	};
}
