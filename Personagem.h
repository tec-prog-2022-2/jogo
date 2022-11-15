#pragma once

#include"Entidade.h"

namespace Personagens
{
	class Personagem : public Entidades::Entidade
	{
	protected:
		int vidas;
		bool vivo;

	public:
		Personagem(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0f, 200.0f), int tipo_entidade_input = -1, int vidas_input = -1);
		virtual ~Personagem();
		void set_vidas(const int vidas_input);
		const int get_vidas() const;
		void set_vivo(const bool vivo_input);
		const bool get_vivo() const;
		virtual void executar(float delta_t) = 0;
	};
}
