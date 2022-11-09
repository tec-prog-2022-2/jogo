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
		//O m�tdodo � chamado somente quando j� sabe-se que h� colis�o entre um obst�culo e personagem

		//Colis�o no eixo x
		if (ds.get_x() > ds.get_y())
		{
			//O personagem est� a esquerda do obst�culo 
			if (deslocamento.get_x() < this->get_posicao().get_x())
				deslocamento += ds.get_x();

			//O personagem est� a direita do obst�culo
			else
				deslocamento -= ds.get_x();
		}

		personagem_colidido->set_posicao(deslocamento);
	}
}
