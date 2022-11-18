#pragma once

#include"stdafx.h"
#include"Samurai.h"
#include"GerenciadorGrafico.h"
#include"Fase1.h"

class Principal
{
private:
	Gerenciadores::GerenciadorGrafico gerenciador_grafico;
	Entidades::Personagens::Samurai samurai;
	sf::Clock relogio;
	Fases::Fase1 fase1;

public:
	Principal();
	~Principal();
	void executar();
};











/*
#include"stdafx.h"
#include"GerenciadorGrafico.h"
#include"Fase1.h"

class Principal
{	
private:
	Gerenciadores::GerenciadorGrafico gerenciador_grafico;
	sf::Clock relogio;
	Fases::Fase1 fase1;

public:
	Principal();
	~Principal();
	void executar();
};
*/