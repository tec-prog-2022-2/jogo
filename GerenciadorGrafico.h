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
		float altura_camera;

	public:
		GerenciadorGrafico(Vetor2D<float> tamanho_janela = Vetor2D<float>(1024.0f, 768.0f), Vetor2D<float> posicao_camera = Vetor2D<float>(0.0f, 0.0f));
		~GerenciadorGrafico();
		void mostrar() const;
		void limpar(int r = 0, int g = 0, int b = 0);
		bool carregar_textura(const std::string caminho_imagem);
		void desenhar(const std::string caminho_imagem, const Vetor2D<float> posicao, sf::RectangleShape* corpo_input);
		//void desenhar_fonte();
		void centralizar(Vetor2D<float> posicao);
		sf::RenderWindow* get_janela() const;
		void set_camera();
		void reajustar_camera();
	};
}
