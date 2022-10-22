#include "Principal.h"

Principal::Principal():
	window{ VideoMode(800, 600), "jogo do joao" },

	//inicializando o personagem na posição (0, 0)
	//passamos também o caminho para o arquivo png que será usado como textura
	p1{ 0, 0, "../png-clipart-bamboo-bamboo.png" } 
{
	executar();
}

Principal::~Principal()
{

}

void Principal::executar()
{
	while (true)
	{
		window.clear(); //limpa a janela
		p1.atualizar(); //atualizamos a posição do personagem p1
		p1.desenhar(&window); //desenhamos na janela principal (que é passada por referência à função o personagem p1
		window.display(); //necessário
	}
}
