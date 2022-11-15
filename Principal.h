#pragma once

#include"stdafx.h"
#include"Entidade.h"
#include"Samurai.h"
#include"Ninja.h"
#include"Kamikaze.h"
#include"Plataforma.h"
#include"Espinho.h"
#include"Lista.h"
#include"ListaEntidades.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorColisao.h"

class Principal
{
private:
	Listas::ListaEntidades lista_entidades;
	std::vector<Entidades::Personagens::Personagem*> vetor_personagens;
	std::list<Entidades::Obstaculos::Obstaculo*> lista_obstaculos;
	Gerenciadores::GerenciadorGrafico gerenciador_grafico; 
	Gerenciadores::GerenciadorColisao gerenciador_colisao;
	Entidades::Personagens::Samurai p1;
	//Entidades::Personagens::Ninja i1;
	Entidades::Personagens::Kamikaze k1;
	Entidades::Obstaculos::Plataforma plataforma_1;
	Entidades::Obstaculos::Espinho e1;
	sf::Clock relogio;
	
public:
	Principal();
	~Principal();
	void executar();
};
