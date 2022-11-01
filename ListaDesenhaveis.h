#pragma once

#include"Lista.h"
#include"Desenhavel.h"

namespace Listas
{

	class ListaDesenhaveis
	{
	private:
		Lista<Desenhavel> lista_desenhaveis;

	public:
		ListaDesenhaveis();
		~ListaDesenhaveis();
		void add_desenhavel(Desenhavel* desenhavel_input);
		void inicializar_desenhaveis(GerenciadorGrafico* gerenciador_grafico_input, GerenciadorEventos* gerenciador_eventos_input);
		void atualizar_desenhaveis(float tempo = 1.0);
		void desenhar_desenhaveis(GerenciadorGrafico* gerenciador_grafico_input);
		void limpar_lista();
	};
}