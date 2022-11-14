#include "Plataforma.h"

namespace Obstaculos
{
	Plataforma::Plataforma(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, bool movimenta_input, bool obstaculo_danoso_input):
		Obstaculo{gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, obstaculo_danoso_input},
		movimenta{movimenta_input},
		velocidade_movimento{Vetor2D<float>(0.0f, 0.0f)}
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		if (1 + rand() % 100 >= 75)
		{
			movimenta = true;
			velocidade_movimento = Vetor2D<float>(20.0f, 20.0f);
		}
	}

	Plataforma::~Plataforma()
	{

	}

	void Plataforma::executar(float delta_t)
	{
		
	}
}
