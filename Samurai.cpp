#include "Samurai.h"

namespace Entidades
{
	Samurai::Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, int vidas_input) :
		Personagem{gerenciador_grafico_input, caminho_textura_input, posicao_input, vidas_input}
	{
	}

	Samurai::~Samurai()
	{
	}

	void Samurai::executar(sf::Clock)
	{
		posicao += 0.1;
	}
}
