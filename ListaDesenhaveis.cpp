#include "ListaDesenhaveis.h"

namespace Listas
{
	ListaDesenhaveis::ListaDesenhaveis():
		lista_desenhaveis()
	{
	}

	ListaDesenhaveis::~ListaDesenhaveis()
	{
		limpar_lista();
	}

	void ListaDesenhaveis::add_desenhavel(Desenhavel* desenhavel_input)
	{
		if (desenhavel_input)
			lista_desenhaveis.add_info(desenhavel_input);

		else
			std::cout << "desenhavel_input era nullptr" << std::endl;
	}

	void ListaDesenhaveis::inicializar_desenhaveis(GerenciadorGrafico* gerenciador_grafico_input, GerenciadorEventos* gerenciador_eventos_input)
	{
		Listas::Lista<Desenhavel>::Iterador i;

		for (i = lista_desenhaveis.comeco(); i != lista_desenhaveis.fim(); ++i)
		{
			Desenhavel* desenhavel = *i;
			desenhavel->inicializar(gerenciador_grafico_input, gerenciador_eventos_input);
		}
	}

	void ListaDesenhaveis::atualizar_desenhaveis(float tempo)
	{
		Listas::Lista<Desenhavel>::Iterador i;

		for (i = lista_desenhaveis.comeco(); i != lista_desenhaveis.fim(); ++i)
		{
			Desenhavel* desenhavel = *i;
			desenhavel->atualizar(tempo);
		}
	}

	void ListaDesenhaveis::desenhar_desenhaveis(GerenciadorGrafico* gerenciador_grafico_input)
	{
		Listas::Lista<Desenhavel>::Iterador i;

		for (i = lista_desenhaveis.comeco(); i != lista_desenhaveis.fim(); ++i)
		{
			Desenhavel* desenhavel = *i;
			desenhavel->desenhar(gerenciador_grafico_input);
		}
	}

	void ListaDesenhaveis::limpar_lista()
	{
		lista_desenhaveis.limpar_lista();
	}
}
