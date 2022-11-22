#pragma once

#include "Inimigo.h"
#include"Shuriken.h"

namespace Entidades
{
	namespace Personagens
	{
		class Kamikaze : public Inimigo
		{
		private:
			Entidades::Shuriken* shuriken;
			bool samurai_direita;
			bool samurai_esquerda;
			int temporizador_atirar;
			int duracao_tiro;

		public:
			Kamikaze(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Personagens::Samurai* samurai_input = nullptr);
			~Kamikaze();
			void executar(float delta_t);
			Entidades::Shuriken* get_shuriken() const;
			const int get_duracao_tiro() const;
		};
	}
}
