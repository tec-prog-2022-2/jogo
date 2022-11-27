#pragma once

#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Izanagi : public Inimigo
		{
		private:
			bool mais_vidas;

		public:
			Izanagi(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Personagens::Samurai* samurai_input = nullptr);
			~Izanagi();
			void executar(float delta_t);
			void set_ressucitar(const int ressucitar_input);
			const int get_ressucitar() const;
		};
	}
}
