#pragma once

#include"Lista.h"
#include"Entidade.h" 
#include"Personagem.h"

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
		void executar_entidades(float delta_t);
		void desenhar_entidades();
	};
}
