#pragma once

#include"stdafx.h"

namespace Listas
{
	template<class TL>
	class Lista
	{

	//Classe aninhada Elemento
	private:
		template<class TE>
		class Elemento;

	//Classe aninhada Iterador
	public:
		class Iterador;

	private:
		Elemento<TL>* primeiro_elemento;
		Elemento<TL>* ultimo_elemento;

	public:
		Lista();
		~Lista();
		Elemento<TL>* comeco() const;
		Elemento<TL>* fim() const;
		Elemento<TL>* rcomeco() const;
		Elemento<TL>* rfim() const;
		void set_primeiro_elemento(Elemento<TL>* elemento_input);
		Elemento<TL>* get_primeiro_elemento() const;
		void set_ultimo_elemento(Elemento<TL>* elemento_input);
		Elemento<TL>* get_ultimo_elemento() const;
		void add_info(TL* info_input);
		void limpar_lista();
	};

	#include"Elemento.h"
	#include"Iterador.h"
	#include"ListaImplementacao.h"
}
