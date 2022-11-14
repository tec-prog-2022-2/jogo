#include "Inimigo.h"

namespace Personagens
{
	Inimigo::Inimigo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, Vetor2D<float> velocidade_input, int vidas_input, int dano_input, Personagens::Samurai* samurai_input):
		Personagem{ gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, velocidade_input, vidas_input },
		dano{dano_input},
		samurai{samurai_input}
	{
	}

	Inimigo::~Inimigo()
	{
	}

	void Inimigo::executar(float delta_t)
	{
		velocidade.set_x(0.0f);
		velocidade.set_y(velocidade.get_y() + 981000000.0f * delta_t);
		posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
	}
}
