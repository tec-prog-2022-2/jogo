#include"Entidade.h"

namespace Entidades
{
	Entidade::Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
		Ente{ gerenciador_grafico_input, caminho_textura_input },
		posicao{ posicao_input }
	{
	}

	Entidade::~Entidade()
	{
		caminho_textura = nullptr;
	}

	void Entidade::desenhar()
	{
		gerenciador_grafico->desenhar(caminho_textura, posicao);
	}
}