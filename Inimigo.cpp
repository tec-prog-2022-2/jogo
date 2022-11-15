#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo::Inimigo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, int vidas_input, int dano_input, Personagens::Samurai* samurai_input) :
			Personagem{ gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, vidas_input },
			dano{ dano_input },
			vivo{true},
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

		void Inimigo::set_vivo(const bool vivo_input)
		{
			vivo = vivo_input;
		}

		const bool Inimigo::get_vivo() const
		{
			return(vivo);
		}
	}
}
