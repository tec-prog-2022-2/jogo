#pragma once

#include "Inimigo.h"

namespace Personagens
{
	class Ninja : public Inimigo
	{
	private:
		bool dobrar_velocidade;

	public:
		Ninja(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0f, 200.0f), int tipo_entidade_input = ID_NINJA, int vidas_input = -1, int dano_input = 10, Personagens::Samurai* samurai_input = nullptr);
		~Ninja();
		void executar(float delta_t);
	};
}
