#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo::Inimigo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Personagens::Samurai* samurai_input) :
			Personagem{ gerenciador_grafico_input, caminho_textura_input, posicao_input},
			dano{-1},
			samurai{ samurai_input }
		{
		}

		Inimigo::~Inimigo()
		{
		}

		const int Inimigo::get_dano() const
		{
			return(dano);
		}
	}
}
