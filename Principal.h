#pragma once

#include"stdafx.h"
#include"Lista.h"
#include"Personagem.h"
#include"GerenciadorGrafico.h"

class Principal
{
private:
	Listas::Lista<Personagem> lista_personagens;
	GerenciadorGrafico gerenciador_grafico; 
	Personagem p1; 
	Personagem p2;

public:
	Principal();
	~Principal();
	void executar();
};

