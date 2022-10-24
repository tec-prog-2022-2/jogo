#pragma once

#include"stdafx.h"
#include"Lista.h"
#include"Personagem.h"

class Principal
{
private:
	lista::Lista<Personagem> lista_personagens;
	sf::RenderWindow window; //janela principal do programa
	Personagem p1; //personagem p1
	Personagem p2;

public:
	Principal();
	~Principal();
	void executar();
};

