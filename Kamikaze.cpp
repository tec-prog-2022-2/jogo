#include "Kamikaze.h"

namespace Personagens
{
	Kamikaze::Kamikaze(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, int vidas_input, int dano_input, Personagens::Samurai* samurai_input) :
		Inimigo{gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, vidas_input, dano_input, samurai_input},
		samurai_direita{false},
		samurai_esquerda{false},
		temporizador_atirar{0}
	{
		shuriken = new Entidades::Shuriken(gerenciador_grafico_input, caminho_textura_input, posicao_input, Vetor2D<float>(20.0f, 20.0f), ID_SHURIKEN);
		shuriken->set_posicao_inicial(posicao_input);
	}

	Kamikaze::~Kamikaze()
	{
		delete shuriken;
		shuriken = nullptr;
	}

	void Kamikaze::executar(float delta_t)
	{
		if (shuriken->get_pode_atirar())
		{
			if (this->posicao.get_x() < samurai->get_posicao().get_x())
			{
				shuriken->atirar_direita(delta_t);
			}

			else
			{
				shuriken->atirar_esquerda(delta_t);
			}
		}

		else
		{
			temporizador_atirar++;
			if (temporizador_atirar == 200)
			{
				shuriken->set_pode_atirar(true);
				temporizador_atirar = 0;
			}
		}
	}

	Entidades::Shuriken* Kamikaze::get_shuriken() const
	{
		return(shuriken);
	}
}
