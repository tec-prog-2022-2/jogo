#pragma once

#include"stdafx.h"
#include "Personagem.h"

namespace Personagens
{
	class Samurai : public Personagem
	{
	private:
		int pontos;
		float altura_maxima;
		bool pode_pular;
		int temporizador_movimento;
		bool colisao_dir_inimigo;
		bool colisao_esq_inimigo;
		bool colisao_cima_inimigo;
		bool colisao_dir_espinho;
		bool colisao_esq_espinho;
		bool colisao_cima_espinho;

	public:
		Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0f, 200.0f), int tipo_entidade_input = ID_SAMURAI, Vetor2D<float> velocidade_input = Vetor2D<float>(0.1f, 0.1f), int vidas_input = 15);
		~Samurai();
		void executar(float delta_t);
		void set_pode_pular(const bool pode_pular_input);
		void set_colisao_dir_inimigo(const bool colisao);
		void set_colisao_esq_inimigo(const bool colisao);
		void set_colisao_cima_inimigo(const bool colisao);
		void set_colisao_dir_espinho(const bool colisao);
		void set_colisao_esq_espinho(const bool colisao);
		void set_colisao_cima_espinho(const bool colisao);
		void set_pontos(const int pontos_input);
		const int get_pontos() const;
	};
}
