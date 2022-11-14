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

public:
	Ente(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr);
	virtual ~Ente();
	virtual void desenhar() = 0; 
	virtual void executar(float delta_t) = 0;
};
