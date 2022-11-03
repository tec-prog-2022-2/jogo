#pragma once

#include"stdafx.h"
#include"Entidade.h"
#include"Samurai.h"
#include"Lista.h"
#include"GerenciadorGrafico.h"
#include"ListaEntidades.h"

class Principal
{
private:
	Listas::ListaEntidades lista_entidades;
	Gerenciadores::GerenciadorGrafico gerenciador_grafico; 
	Entidades::Samurai p1;

public:
	Principal();
	~Principal();
	void executar();
};
