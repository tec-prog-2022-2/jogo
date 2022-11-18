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

	void ListaEntidades::executar_entidades(float delta_t)
	{
		Listas::Lista<Entidades::Entidade>::Iterador i;

		for (i = lista_entidades.comeco(); i != lista_entidades.fim(); ++i)
		{
			Entidades::Entidade* entidade = *i;

			if (entidade->get_tipo_entidade() >= 5 && entidade->get_tipo_entidade() <= 8)
			{
				Entidades::Personagens::Personagem* personagem = static_cast<Entidades::Personagens::Personagem*>(*i);
				if (personagem->get_vivo())
					personagem->executar(delta_t);
			}

			else
				entidade->executar(delta_t);
		}
	}

	void ListaEntidades::desenhar_entidades()
	{
		Listas::Lista<Entidades::Entidade>::Iterador i;

		for (i = lista_entidades.comeco(); i != lista_entidades.fim(); ++i)
		{
			Entidades::Entidade* entidade = *i;

			if (entidade->get_tipo_entidade() >= 5 && entidade->get_tipo_entidade() <= 8)
			{
				Entidades::Personagens::Personagem* personagem = static_cast<Entidades::Personagens::Personagem*>(*i);
				if (personagem->get_vivo())
					personagem->desenhar();
			}

			else
				entidade->desenhar();
		}
	}
}
