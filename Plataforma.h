#pragma once

#include "Obstaculo.h"

namespace Obstaculos
{
	class Plataforma : public Obstaculo
	{
	private:
		bool metade_tamanho;

	public:
		Plataforma(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0, 200.0), int tipo_entidade_input = ID_PLATAFORMA, bool obstaculo_danoso_input = false);
		~Plataforma();
		void executar(float delta_t);
	};
}
