#include "Ninja.h"

namespace Personagens
{
	Ninja::Ninja(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, int vidas_input, int dano_input, Personagens::Samurai* samurai_input) :
		Inimigo{gerenciador_grafico_input, caminho_textura_input,posicao_input, tamanho_corpo, tipo_entidade_input, vidas_input, dano_input, samurai_input}
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		if (1 + rand() % 100 >= 80)
			dobrar_velocidade = true;

		else
			dobrar_velocidade = false;
	}

	Ninja::~Ninja()
	{
	}

	void Ninja::executar(float delta_t)
	{
		velocidade.set_x(0.0f);
		velocidade.set_y(velocidade.get_y() + 981000000.0f * delta_t);

		if(this->posicao.get_x()<samurai->get_posicao().get_x())
			velocidade.set_x(velocidade.get_x() + 10000.0f);

		else if(this->posicao.get_x() > samurai->get_posicao().get_x())
			velocidade.set_x(velocidade.get_x() - 10000.0f);

		if(dobrar_velocidade)
			posicao = Vetor2D<float>(posicao.get_x() + 2*velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);

		else
			posicao = Vetor2D<float>(posicao.get_x() + 2 * velocidade.get_x() * delta_t, posicao.get_y() + velocidade.get_y() * delta_t);
	}
}
