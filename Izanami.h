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
			Izanami(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0f, 200.0f), int tipo_entidade_input = ID_IZANAMI, int vidas_input = 15, int dano_input = 2, Personagens::Samurai* samurai_input = nullptr);
			~Izanami();
			void executar(float delta_t);
		};
	}
}
