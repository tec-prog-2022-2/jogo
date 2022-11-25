#pragma once

#include"stdafx.h"
#include"GerenciadorGrafico.h"
#include"Vetor2D.h"

class Ente
{
protected:
	static int id; //salvar objetos
	Gerenciadores::GerenciadorGrafico* gerenciador_grafico;
	const char* caminho_textura;
	sf::RectangleShape* corpo;
	bool menu;

public:
	Ente(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, bool menu_input=false);
	virtual ~Ente();
	const int get_id() const;
	sf::RectangleShape* get_corpo();
	virtual void desenhar() = 0;
};
