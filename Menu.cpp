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
	texto_ganhou{},
	texto_perdeu{},
	tamanhos{}
{
	fonte = new sf::Font();
	fonte->loadFromFile(caminho_textura);
	
	opcoes = { "Samurai++", "Jogar Fase 1 com 1 Jogador", "Jogar Fase 1 com 2 Jogadores", "Jogar Fase 2 com 1 Jogador", "Jogar Fase 2 com 2 Jogadores", "Sair", "Ganhou!", "Perdeu!"};
	textos.resize(6);
	
	coordenadas = { {500, 40}, {500, 191}, {500, 282}, {500, 370}, {500, 440}, {500, 490}, {500, 550} };
	tamanhos = { 30, 24, 24, 24, 24, 24, 24 };

	texto_ganhou.resize(1);
	texto_ganhou[0].setFont(*fonte);
	texto_ganhou[0].setString(opcoes[6]);
	texto_ganhou[0].setCharacterSize(tamanhos[0]);
	texto_ganhou[0].setOutlineColor(sf::Color::Magenta);
	texto_ganhou[0].setPosition(coordenadas[0]);

	texto_perdeu.resize(1);
	texto_perdeu[0].setFont(*fonte);
	texto_perdeu[0].setString(opcoes[7]);
	texto_perdeu[0].setCharacterSize(tamanhos[0]);
	texto_perdeu[0].setOutlineColor(sf::Color::Magenta);
	texto_perdeu[0].setPosition(coordenadas[0]);

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
	
	for (i=0; i<6; i++)
	{
		gerenciador_grafico->get_janela()->draw(textos[i]);
	}

	gerenciador_grafico->mostrar();
}

void Menu::desenhar(const int menu)
{
	gerenciador_grafico->limpar();

	if(menu==1)
		gerenciador_grafico->get_janela()->draw(texto_ganhou[0]);

	else if(menu==2)
		gerenciador_grafico->get_janela()->draw(texto_perdeu[0]);

	gerenciador_grafico->mostrar();
}
