#pragma once

#include "Ente.h"

class Menu : public Ente
{
private:
	int item_selecionado;
	sf::Font fonte;
	sf::Text tela_inicial[4];
	sf::Text tela_jogar[2];
	sf::Text tela_fase[2];
	sf::Text tela_fase_1_completa[3];
	sf::Text tela_fase_2_completa[2];
	sf::Text tela_rank[1];
	sf::Text tela_salvar[1];
	sf::Text tela_pausa[3];

public:
	Menu(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr);
	~Menu();
	void desenhar();
	void mover_cima();
	void mover_baixo();
	void menu_inicial();
	void menu_fases();
	void menu_selecionar_jogadores();
	void menu_fase_1_completa();
	void menu_fase_2_completa();
	void menu_salvar();
	void menu_rank();
	void menu_pausa();
};
