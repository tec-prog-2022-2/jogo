#pragma once

#include"Personagem.h"

namespace Obstaculos
{
	class Obstaculo : public Entidades::Entidade
	{
	protected:
		bool obstaculo_danoso;

	public:
		Obstaculo(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0), Vetor2D<float> tamanho_corpo = Vetor2D<float>(200.0, 200.0), int tipo_entidade_input = 0, bool obstaculo_danoso_input = false);
		virtual ~Obstaculo();
		const bool get_danoso() const;
		void executar(sf::Clock relogio) = 0;
	};
}
