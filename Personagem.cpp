#include "Personagem.h"

namespace Entidades
{
	Personagem::Personagem(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, Vetor2D<float> velocidade_input, int vidas_input) :
		Entidade{ gerenciador_grafico_input,caminho_textura_input, posicao_input,  tamanho_corpo, tipo_entidade_input},
		velocidade{ velocidade_input },
		vidas{ vidas_input }
	{
	}

	Personagem::~Personagem()
	{
	}

	void Personagem::set_vidas(const int vidas_input)
	{
		vidas = vidas_input;
	}

	const int Personagem::get_vidas() const
	{
		return(vidas);
	}
}
