#pragma once

#include"Entidade.h"

namespace Entidades
{
	class Personagem : public Entidade
	{
	protected:
		Vetor2D<float> velocidade;
		int vidas;

	public:
		Personagem(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0f, 200.0f), int tipo_entidade_input = -1, Vetor2D<float> velocidade_input = Vetor2D<float>(0.1f, 0.1f), int vidas_input = -1);
		virtual ~Personagem();
		virtual void executar(sf::Clock) = 0;
		virtual void colisao(Entidades::Entidade* entidade_colidida, Vetor2D<float> ds = Vetor2D<float>(0.0f, 0.0f)) = 0;
	};
}
