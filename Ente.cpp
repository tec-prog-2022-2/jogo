#include "Ente.h"

int Ente::id{ 0 };

Ente::Ente(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, bool menu_input) :
	gerenciador_grafico{gerenciador_grafico_input},
	caminho_textura{caminho_textura_input},
	corpo{nullptr},
	menu{menu_input}
{
	if (caminho_textura && !menu)
	{
		if (gerenciador_grafico->carregar_textura(caminho_textura))
			std::cout << "Textura de ente carregada com sucesso!" << std::endl;

		else
			std::cout << "Textura de ente nao carregada com sucesso!" << std::endl;
	}
	
	id++;
}

Ente::~Ente()
{
	gerenciador_grafico = nullptr;
	caminho_textura = nullptr;
}

sf::RectangleShape* Ente::get_corpo()
{
	return(corpo);
}

void Ente::set_id(const int id_input)
{
	id = id_input;
}
