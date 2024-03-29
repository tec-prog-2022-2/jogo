#pragma once

#include"stdafx.h"
#include"GerenciadorGrafico.h"
#include"Vetor2D.h"

class Ente
{
protected:
	static int id; 
	Gerenciadores::GerenciadorGrafico* gerenciador_grafico;
	const char* caminho_textura;
	sf::RectangleShape* corpo;
	bool menu;

public:
	Ente(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, bool menu_input=false);
	virtual ~Ente();
	sf::RectangleShape* get_corpo();
	static void set_id(const int id_input);
	virtual void desenhar() = 0;
};
