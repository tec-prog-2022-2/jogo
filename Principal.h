#pragma once

#include"stdafx.h"
#include"Entidade.h"
#include"Samurai.h"
#include"Inimigo.h"
#include"Plataforma.h"
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
	Personagens::Inimigo i1;
	Obstaculos::Plataforma plataforma_1;
	sf::Clock relogio;
	
public:
	Principal();
	~Principal();
	void executar();
};
