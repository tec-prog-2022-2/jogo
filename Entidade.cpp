#include"Entidade.h"

namespace Entidades
{
	Entidade::Entidade(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
		Ente{ gerenciador_grafico_input, caminho_textura_input},
		posicao{ posicao_input },
		velocidade{Vetor2D<float>(0.0f, 0.0f)},
		tipo_entidade{-1}
	{
	}

	Entidade::~Entidade()
	{
		caminho_textura = nullptr;
		
		if (corpo)
			delete corpo;

		corpo = nullptr;
	}

	void Entidade::desenhar()
	{
		gerenciador_grafico->desenhar(caminho_textura, posicao, corpo);
	}

	void Entidade::set_posicao(Vetor2D<float> posicao_input)
	{
		posicao = posicao_input;
	}

	void Entidade::set_posicao(float x_input, float y_input)
	{
		posicao.set_x(x_input);
		posicao.set_y(y_input);
	}

	Vetor2D<float> Entidade::get_posicao() const
	{
		return(posicao);
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
