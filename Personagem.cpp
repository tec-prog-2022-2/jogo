#include "Personagem.h"

namespace Entidades
{
	namespace Personagens
	{
		Personagem::Personagem(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
			Entidade{ gerenciador_grafico_input, caminho_textura_input, posicao_input},
			vidas{ -1 },
			vivo{ false }
		{
		}

		Personagem::~Personagem()
		{
		}

		void Personagem::set_vidas(const int vidas_input)
		{
			vidas = vidas_input;
		}

		const int Personagem::get_vidas() const
		{
			return(vidas);
		}

		void Personagem::set_vivo(const bool vivo_input)
		{
			vivo = vivo_input;
		}

		const bool Personagem::get_vivo() const
		{
			return(vivo);
		}
	}
}
