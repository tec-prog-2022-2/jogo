#pragma once

#include"Lista.h"
#include"Personagem.h"

class ListaPersonagens
{
private:
	Lista<Personagem> list;

public:
	ListaPersonagens();
	~ListaPersonagens();
	void add_personagem(Personagem* personagem_);
	void atualizar_personagens(float time = 1);
	void desenhar_personagens(RenderWindow* window);
	void limpar_lista();
	void destruir_personagens();
};
