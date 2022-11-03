#include "Ente.h"

int Ente::id{ 0 };

Ente::Ente(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input) :
	gerenciador_grafico{gerenciador_grafico_input},
	caminho_textura{caminho_textura_input}
{
	if (gerenciador_grafico->carregar_textura(caminho_textura))
		std::cout << "Textura de ente carregada com sucesso!" << std::endl;
	
	else
		std::cout << "Textura de ente nao carregada com sucesso!" << std::endl;
	
	id++;
}

Ente::~Ente()
{
	gerenciador_grafico = nullptr;
	caminho_textura = nullptr;
}