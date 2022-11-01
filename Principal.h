#pragma once

#include"stdafx.h"
#include"Lista.h"
#include"Desenhavel.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorGrafico.h"
#include"ListaDesenhaveis.h"

class Principal
{
private:
	Listas::ListaDesenhaveis lista_desenhaveis;
	GerenciadorGrafico gerenciador_grafico; 
	GerenciadorEventos gerenciador_eventos;
	Desenhavel p1; 
	Desenhavel p2;

public:
	Principal();
	~Principal();
	void executar();
};
