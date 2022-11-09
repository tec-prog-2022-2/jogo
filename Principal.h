#pragma once

#include"stdafx.h"
#include"Entidade.h"
#include"Samurai.h"
#include"Lista.h"
#include"ListaEntidades.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorColisao.h"

#define ID_OBSTACULO 0
#define ID_SAMURAI 1

class Principal
{
private:
	Listas::ListaEntidades lista_entidades;
	//std::vector<Entidades::Inimigo*> vetor_personagens;
	std::list<Obstaculos::Obstaculo*> lista_obstaculos;
	Gerenciadores::GerenciadorGrafico gerenciador_grafico; 
	Gerenciadores::GerenciadorColisao gerenciador_colisao;
	Entidades::Samurai p1;
	//Entidades::Obstaculo o1;
	sf::Clock relogio;
	
public:
	Principal();
	~Principal();
	void executar();
};
