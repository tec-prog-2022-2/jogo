#pragma once

#include"stdafx.h"
#include"Personagem.h"

class Principal
{
private:
	RenderWindow window; //janela principal do programa
	Personagem p1; //personagem p1

public:
	Principal();
	~Principal();
	void executar();
};

