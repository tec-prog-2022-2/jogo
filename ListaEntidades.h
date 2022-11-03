#pragma once

#include"Lista.h"
#include"Entidade.h" //#include"GerenciadorGrafico.h"

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidades::Entidade> lista_entidades;

	public:
		ListaEntidades();
		~ListaEntidades();
		void add_entidade(Entidades::Entidade* entidade_input);
		void executar_entidades(sf::Clock);
		void desenhar_entidades();
	};
}
