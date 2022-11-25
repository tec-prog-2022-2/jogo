#include "Menu.h"

Menu::Menu(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, bool menu) :
	Ente{ gerenciador_grafico_input, caminho_textura_input , menu},
	posicao{0},
	pressionado{false},
	selecionado{false},
	fonte{nullptr},
	opcoes{},
	coordenadas{},
	textos{},
	tamanhos{}
{
	fonte = new sf::Font();
	fonte->loadFromFile(caminho_textura);
	opcoes = { "Samurai++", "Jogar Fase 1 com 1 Jogador", "Jogar Fase 1 com 2 Jogadores", "Jogar Fase 2 com 1 Jogador", "Jogar Fase 2 com 2 Jogadores", "Pontuação Jogador 1: ", "Pontuação Jogador 2: "};
	textos.resize(7);
	coordenadas = { {500, 40}, {500, 191}, {500, 282}, {500, 370}, {500, 440}, {500, 480}, {500, 550} };
	tamanhos = { 30, 28, 24, 24, 24, 24, 24 };

	for (std::size_t i{}; i < textos.size(); ++i)
	{
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize(tamanhos[i]);
		textos[i].setOutlineColor(sf::Color::Magenta);
		textos[i].setPosition(coordenadas[i]);
	}

	textos[1].setOutlineThickness(7);
	posicao = 1;
}

Menu::~Menu()
{
	delete fonte;
}

void Menu::desenhar()
{
	gerenciador_grafico->limpar();

	int i = 0;
	
	for (i=0; i<5; i++)
	{
		gerenciador_grafico->get_janela()->draw(textos[i]);
	}

	gerenciador_grafico->mostrar();
}

void Menu::desenhar(const bool menu_final)
{
	gerenciador_grafico->limpar();

	for (auto t : textos)
	{
		gerenciador_grafico->get_janela()->draw(t);
	}
}
