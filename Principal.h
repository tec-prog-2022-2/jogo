#pragma once

#include"stdafx.h"
#include"Samurai.h"
#include"GerenciadorGrafico.h"
#include"Fase1.h"
#include"Fase2.h"
#include"Menu.h"

class Principal
{
private:
	Gerenciadores::GerenciadorGrafico gerenciador_grafico;
	Entidades::Personagens::Samurai samurai;
	sf::Clock relogio;
	Fases::Fase1 fase1;
	Fases::Fase2 fase2;
	Menu menu;

public:
	Principal();
	~Principal();
	void executar();
};
