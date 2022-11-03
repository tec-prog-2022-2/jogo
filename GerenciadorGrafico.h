#pragma once

#include"stdafx.h"
#include"Vetor2D.h"

namespace Gerenciadores
{
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* janela;
		sf::View camera;
		std::map<const std::string, sf::Texture*> mapa_texturas;

	public:
		GerenciadorGrafico(Vetor2D<float> tamanho_janela = Vetor2D<float>(800, 600), Vetor2D<float> posicao_camera = Vetor2D<float>(400, 300));
		~GerenciadorGrafico();
		void mostrar() const;
		void limpar(int r = 0, int g = 0, int b = 0);
		bool carregar_textura(const std::string caminho_imagem);
		void desenhar(const std::string caminho_imagem, const Vetor2D<float> posicao);
		void centralizar(Vetor2D<float> posicao);
		sf::RenderWindow* get_janela() const;
	};
}
