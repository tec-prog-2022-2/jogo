#pragma once

#include"stdafx.h"
#include "Personagem.h"

namespace Entidades
{
	namespace Personagens
	{
		class Samurai : public Personagem
		{
		private:
			bool jogador_principal;
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
			bool colisao_pedra;
			bool perto_izanagi;

		public:
			Samurai(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f));
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
			void set_jogador_principal(const bool jogador_principal_input);
			const bool get_jogador_principal() const;
			void set_colisao_pedra(const bool colisao_pedra_input);
			void set_perto_izanagi(const bool perto_izanagi_input);
		};
	}
}
