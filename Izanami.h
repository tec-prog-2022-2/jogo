#pragma once

#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Izanami : public Inimigo
		{
		private:
			bool dobra_atributos;

		public:
			Izanami(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Personagens::Samurai* samurai_input = nullptr);
			~Izanami();
			void executar(float delta_t);
		};
	}
}
