#pragma once

#include "Ente.h"


//Canal do doidao
class Menu : public Ente
{
public:
	int posicao;
	bool pressionado;
	bool selecionado;
	sf::Font* fonte;
	std::vector<const char*> opcoes;
	std::vector<sf::Vector2f> coordenadas;
	std::vector<sf::Text> textos;
	std::vector<std::size_t> tamanhos;

public:
	Menu(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, bool menu=true);
	~Menu();
	void desenhar();
	void desenhar(const bool menu_final);
};
