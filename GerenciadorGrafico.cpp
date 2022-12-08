#include "GerenciadorGrafico.h"

namespace Gerenciadores
{
	GerenciadorGrafico::GerenciadorGrafico(Vetor2D<float> tamanho_janela, Vetor2D<float> posicao_camera, Vetor2D<float> tamanho_camera) :
		janela{ nullptr },
		camera(sf::Vector2f(posicao_camera.get_x(), posicao_camera.get_y()), sf::Vector2f(tamanho_camera.get_x(), tamanho_camera.get_y())),
		camera_menu(),
		mapa_texturas(),
		altura_camera{tamanho_janela.get_y()}
	{
		janela = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(tamanho_janela.get_x()), static_cast<unsigned int>(tamanho_janela.get_y())), "Samurai++");
		janela->setView(camera);
		janela->setFramerateLimit(60);
	}

	GerenciadorGrafico::GerenciadorGrafico(Vetor2D<float> tamanho_janela, Vetor2D<float> tamanho_camera):
		janela{ nullptr },
		camera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(tamanho_camera.get_x(), tamanho_camera.get_y())),
		camera_menu(),
		mapa_texturas(),
		altura_camera{ tamanho_janela.get_y() }
	{
		janela = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(tamanho_janela.get_x()), static_cast<unsigned int>(tamanho_janela.get_y())), "Samurai++");
		janela->setView(camera);
		janela->setFramerateLimit(60);
	}

	GerenciadorGrafico::~GerenciadorGrafico()
	{
		delete janela;
		janela = nullptr;

		std::map<const std::string, sf::Texture*>::const_iterator i = mapa_texturas.begin();

		for (i = mapa_texturas.begin(); i != mapa_texturas.end(); i++)
		{
			delete i->second;
		}
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
			textura->setRepeated(true);
			sf::RectangleShape* corpo = corpo_input;
			corpo->setTexture(textura, true);
			corpo->setPosition(posicao.get_x(), posicao.get_y());
			janela->draw(*corpo);
		}

		else
			std::cout << "Nao foi desenhar a textura de " << caminho_imagem << std::endl;
	}

	void GerenciadorGrafico::desenhar(const std::string caminho_imagem, sf::Sprite* fundo_input)
	{
		if (caminho_imagem == "C://joao//utfpr//quarto_periodo//tec_prog//jogo_dev//jogo_visual_studio//jogo_visual_studio//assets//fase_1.png")
		{
			if (carregar_textura(caminho_imagem))
			{
				sf::Texture* textura = mapa_texturas[caminho_imagem];
				fundo_input->setTexture(*textura);
				fundo_input->setScale(sf::Vector2f(2.5f, 2.5f));
				fundo_input->setPosition(sf::Vector2f(0.0f, -200.0f));
				janela->draw(*fundo_input);
				fundo_input->setPosition(sf::Vector2f(1850.0f, -200.0f));
				janela->draw(*fundo_input);
				fundo_input->setPosition(sf::Vector2f(2 * 1850.0f, -200.0f));
				janela->draw(*fundo_input);
			}

			else
				std::cout << "Nao foi desenhar a textura de " << caminho_imagem << std::endl;
		}

		else
		{
			if (carregar_textura(caminho_imagem))
			{
				sf::Texture* textura = mapa_texturas[caminho_imagem];
				fundo_input->setTexture(*textura);
				fundo_input->setScale(sf::Vector2f(2.5f, 2.5f));
				fundo_input->setPosition(sf::Vector2f(0.0f, -200.0f));
				janela->draw(*fundo_input);
				fundo_input->setPosition(sf::Vector2f(1100.0f, -200.0f));
				janela->draw(*fundo_input);
				fundo_input->setPosition(sf::Vector2f(2 * 1100.0f, -200.0f));
				janela->draw(*fundo_input);
				fundo_input->setPosition(sf::Vector2f(3 * 1100.0f, -200.0f));
				janela->draw(*fundo_input);
				fundo_input->setPosition(sf::Vector2f(4 * 1100.0f, -200.0f));
				janela->draw(*fundo_input);
			}

			else
				std::cout << "Nao foi desenhar a textura de " << caminho_imagem << std::endl;
		}
	}

	void GerenciadorGrafico::centralizar(Vetor2D<float> posicao)
	{
		camera.setCenter(sf::Vector2f(posicao.get_x(), 300.0f));
	}

	void GerenciadorGrafico::centralizar_menu(Vetor2D<float> posicao)
	{
		camera_menu.setCenter(sf::Vector2f(posicao.get_x(), posicao.get_y()));
	}

	sf::RenderWindow* GerenciadorGrafico::get_janela() const
	{
		return(janela);
	}

	void GerenciadorGrafico::set_camera()
	{
		janela->setView(camera);
	}

	void GerenciadorGrafico::set_camera_menu()
	{
		janela->setView(camera_menu);
	}

	void GerenciadorGrafico::reajustar_camera()
	{
		float razao_tela = (static_cast<float>(janela->getSize().x)) / (static_cast<float>(janela->getSize().y));
		camera.setSize(altura_camera * razao_tela, altura_camera);
	}
}
