#include"stdafx.h"
#include "ListaPersonagens.h"

ListaPersonagens::ListaPersonagens():
	list()
{

}

ListaPersonagens::~ListaPersonagens()
{

}

void ListaPersonagens::add_personagem(Personagem* personagem_)
{
	list.add_info(personagem_);
}

void ListaPersonagens::atualizar_personagens(float time)
{

}

void ListaPersonagens::desenhar_personagens(RenderWindow* window)
{

}

void ListaPersonagens::limpar_lista()
{
	list.limpar_lista();
}

void ListaPersonagens::destruir_personagens()
{

}
