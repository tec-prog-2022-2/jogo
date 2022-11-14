#include "GerenciadorGrafico.h"

namespace Gerenciadores
{
	GerenciadorGrafico::GerenciadorGrafico(Vetor2D<float> tamanho_janela, Vetor2D<float> posicao_camera) :
		janela{ nullptr },
		camera(sf::Vector2f(posicao_camera.get_x(), posicao_camera.get_y()), sf::Vector2f(tamanho_janela.get_x(), tamanho_janela.get_y())),
		mapa_texturas()
	{
		janela = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(tamanho_janela.get_x()), static_cast<unsigned int>(tamanho_janela.get_y())), "janela_do_joao");
		janela->setView(camera);
	}

	GerenciadorGrafico::~GerenciadorGrafico()
	{
		delete janela;
		janela = nullptr;

		std::map<const std::string, sf::Texture*>::const_iterator i = mapa_texturas.begin();

		for (i = mapa_texturas.begin(); i != mapa_texturas.end(); i++)
			delete i->second;
	}

	void GerenciadorGrafico::mostrar() const
	{
		janela->display();
	}

	void GerenciadorGrafico::limpar(int r, int g, int b)
	{
		janela->clear(sf::Color(r, g, b));
	}

	bool GerenciadorGrafico::carregar_textura(const std::string caminho_imagem)
	{
		if (mapa_texturas.count(caminho_imagem))
			return(true);

		else
		{
			sf::Texture* textura = new sf::Texture();
			if (textura->loadFromFile(caminho_imagem))
			{
				mapa_texturas.emplace(caminho_imagem, textura);
				return(true);
			}

			else
			{
				std::cout << "Nao foi possivel carregar a textura de " << caminho_imagem << std::endl;
				delete textura;
				return(false);
			}
		}
	}

	void GerenciadorGrafico::desenhar(const std::string caminho_imagem, const Vetor2D<float> posicao, sf::RectangleShape* corpo_input)
	{
		if (carregar_textura(caminho_imagem))
		{
			sf::Texture* textura = mapa_texturas[caminho_imagem];
			sf::RectangleShape* corpo = corpo_input;
			corpo->setTexture(textura);
			corpo->setOrigin(corpo->getSize() / 2.0f);
			corpo->setPosition(posicao.get_x(), posicao.get_y());
			janela->draw(*corpo);
		}

		else
			std::cout << "Nao foi desenhar a textura de " << caminho_imagem << std::endl;
	}

	void GerenciadorGrafico::centralizar(Vetor2D<float> posicao)
	{
		camera.setCenter(posicao.get_x(), posicao.get_y());
	}

	sf::RenderWindow* GerenciadorGrafico::get_janela() const
	{
		return(janela);
	}
}
