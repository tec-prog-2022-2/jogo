#include "Obstaculo.h"

namespace Obstaculos
{
	Obstaculo::Obstaculo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, bool obstaculo_danoso_input, int dano_input) :
		Entidade{gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input},
		obstaculo_danoso{obstaculo_danoso_input},
		dano{dano_input}
	{
	}

	Obstaculo::~Obstaculo()
	{
	}

	void Obstaculo::colisao_obstaculo(Entidades::Personagem* personagem_colidido, Vetor2D<float> ds)
	{
		Vetor2D<float> deslocamento = personagem_colidido->get_posicao();
		//O métdodo é chamado somente quando já sabe-se que há colisão entre um obstáculo e personagem

		//Colisão no eixo x
		if (ds.get_x() > ds.get_y())
		{
			//O personagem está a esquerda do obstáculo 
			if (deslocamento.get_x() < this->get_posicao().get_x())
				deslocamento += ds.get_x();

			//O personagem está a direita do obstáculo
			else
				deslocamento -= ds.get_x();
		}

		personagem_colidido->set_posicao(deslocamento);
	}
}
