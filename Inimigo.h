#pragma once

#include "Personagem.h"
#include"Samurai.h"

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo : public Personagem
		{
		protected:
			int dano;
			Personagens::Samurai* samurai;

		public:
			Inimigo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Personagens::Samurai* samurai_input = nullptr);
			virtual ~Inimigo();
			const int get_dano() const;
			virtual void executar(float delta_t) = 0;
		};
	}
}
