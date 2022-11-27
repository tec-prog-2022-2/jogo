#pragma once

#include"stdafx.h"
#include"Samurai.h"
#include"GerenciadorGrafico.h"
#include"Fase1.h"
#include"Fase2.h"
#include"Menu.h"

class Jogo
{
private:
	Gerenciadores::GerenciadorGrafico gerenciador_grafico;
	Entidades::Personagens::Samurai samurai;
	Entidades::Personagens::Samurai* samurai_2;
	sf::Clock relogio;
	Fases::Fase1 fase1;
	Fases::Fase2 fase2;
	Menu menu;
	bool menu_inicial;
	bool menu_ganhou;
	bool menu_perdeu;
	bool fase_1_1_jog;
	bool fase_1_2_jog;
	bool fase_2_1_jog;
	bool fase_2_2_jog;
	bool criar_fase_1;
	bool criar_fase_2;

public:
	Jogo();
	~Jogo();
	void executar();
};
