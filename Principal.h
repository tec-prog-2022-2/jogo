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
	std::vector<Personagens::Personagem*> vetor_personagens;
	std::list<Obstaculos::Obstaculo*> lista_obstaculos;
	Gerenciadores::GerenciadorGrafico gerenciador_grafico; 
	Gerenciadores::GerenciadorColisao gerenciador_colisao;
	Personagens::Samurai p1;
	//Personagens::Ninja i1;
	Personagens::Kamikaze k1;
	Obstaculos::Plataforma plataforma_1;
	Obstaculos::Espinho e1;
	sf::Clock relogio;
	
public:
	Principal();
	~Principal();
	void executar();
};
