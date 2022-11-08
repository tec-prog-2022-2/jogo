#include "ListaEntidades.h"

namespace Listas
{
	ListaEntidades::ListaEntidades():
		lista_entidades()
	{
	}

	ListaEntidades::~ListaEntidades()
	{
	}

	void ListaEntidades::add_entidade(Entidades::Entidade* entidade_input)
	{
		if (entidade_input)
			lista_entidades.add_info(entidade_input);

		else
			std::cout << "entidade_input era nullptr" << std::endl;
	}

	void ListaEntidades::executar_entidades(sf::Clock relogio)
	{
		Listas::Lista<Entidades::Entidade>::Iterador i;

		for (i = lista_entidades.comeco(); i != lista_entidades.fim(); ++i)
		{
			Entidades::Entidade* entidade = *i;
			entidade->executar(relogio);
		}
	}

	void ListaEntidades::desenhar_entidades()
	{
		Listas::Lista<Entidades::Entidade>::Iterador i;

		for (i = lista_entidades.comeco(); i != lista_entidades.fim(); ++i)
		{
			Entidades::Entidade* entidade = *i;
			entidade->desenhar();
		}
	}
}
