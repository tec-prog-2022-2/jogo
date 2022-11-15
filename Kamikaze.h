#pragma once

#include "Inimigo.h"
#include"Shuriken.h"

namespace Personagens
{
	class Kamikaze : public Inimigo
	{
	private:
		Entidades::Shuriken* shuriken;
		bool samurai_direita;
		bool samurai_esquerda;
		int temporizador_atirar;

	public:
		Kamikaze(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0f, 200.0f), int tipo_entidade_input = ID_KAMIKAZE, int vidas_input = -1, int dano_input = 0, Personagens::Samurai* samurai_input = nullptr);
		~Kamikaze();
		void executar(float delta_t);
		Entidades::Shuriken* get_shuriken() const;
	};
}
