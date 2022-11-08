#include "Obstaculo.h"

namespace Obstaculos
{
	Obstaculo::Obstaculo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, bool obstaculo_danoso_input, int dano_input) :
		Entidade{gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo},
		obstaculo_danoso{obstaculo_danoso_input},
		dano{dano_input}
	{
	}

	Obstaculo::~Obstaculo()
	{
	}
}
