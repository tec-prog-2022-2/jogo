#pragma once

#include"Entidade.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo : public Entidades::Entidade
		{
		protected:
			bool obstaculo_danoso;

		public:
			Obstaculo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f));
			virtual ~Obstaculo();
			const bool get_danoso() const;
			virtual void executar(float delta_t) = 0;
		};
	}
}
