#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
			Entidade{ gerenciador_grafico_input, caminho_textura_input, posicao_input },
			obstaculo_danoso{false}
		{
		}

		Obstaculo::~Obstaculo()
		{
		}

		const bool Obstaculo::get_danoso() const
		{
			return(obstaculo_danoso);
		}
	}
}
