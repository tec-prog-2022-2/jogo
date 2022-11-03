#include "Personagem.h"

namespace Entidades
{
	Personagem::Personagem(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, int vidas_input) :
		Entidade{ gerenciador_grafico_input, caminho_textura_input, posicao_input },
		vidas{ vidas_input }
	{
	}

	Personagem::~Personagem()
	{
	}
}
