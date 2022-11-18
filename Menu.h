#pragma once

#include "Ente.h"

class Menu : public Ente
{
public:
	Menu(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr);
	~Menu();
	void executar();
};
