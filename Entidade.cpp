#include"Entidade.h"

namespace Entidades
{
	Entidade::Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input) :
		Ente{ gerenciador_grafico_input, caminho_textura_input },
		posicao{ posicao_input },
		velocidade{Vetor2D<float>(0.0f, 0.0f)},
		corpo{ sf::Vector2f{tamanho_corpo.get_x(), tamanho_corpo.get_y()} },
		tipo_entidade{tipo_entidade_input}
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

	void Entidade::set_posicao(Vetor2D<float> posicao_input)
	{
		posicao = posicao_input;
	}

	const Vetor2D<float> Entidade::get_posicao() const
	{
		return(posicao);
	}

	sf::RectangleShape Entidade::get_corpo()
	{
		return(corpo);
	}

	const int Entidade::get_tipo_entidade() const
	{
		return(tipo_entidade);
	}

	void Entidade::set_velocidade(const Vetor2D<float> velocidade_input)
	{
		velocidade = velocidade_input;
	}

	const Vetor2D<float> Entidade::get_velocidade() const
	{
		return(velocidade);
	}
}
