#include "Obstaculo.h"

namespace Obstaculos
{
	Obstaculo::Obstaculo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, bool obstaculo_danoso_input) :
		Entidade{gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input},
		obstaculo_danoso{obstaculo_danoso_input}
	{
	}

	Obstaculo::~Obstaculo()
	{
	}

	const bool Obstaculo::get_danoso() const
	{
		return(obstaculo_danoso);
	}
}
