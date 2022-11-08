#include"Entidade.h"

namespace Entidades
{
	Entidade::Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo) :
		Ente{ gerenciador_grafico_input, caminho_textura_input },
		posicao{ posicao_input },
		corpo{ sf::Vector2f{tamanho_corpo.get_x(), tamanho_corpo.get_y()} }
	{
	}

	Entidade::~Entidade()
	{
		caminho_textura = nullptr;
	}

	void Entidade::desenhar()
	{
		gerenciador_grafico->desenhar(caminho_textura, posicao, &corpo);
	}

	const Vetor2D<float> Entidade::get_posicao()
	{
		return(posicao);
	}

	const sf::RectangleShape Entidade::get_corpo()
	{
		return(corpo);
	}
}