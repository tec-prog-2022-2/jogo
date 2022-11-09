#include "GerenciadorColisao.h"

namespace Gerenciadores
{
	GerenciadorColisao::GerenciadorColisao(std::vector<Entidades::Personagem*>* vetor_personagens_input, std::list<Obstaculos::Obstaculo*>* lista_obstaculos_input):
		vetor_personagens{vetor_personagens_input},
		lista_obstaculos{lista_obstaculos_input}
	{
	}

	GerenciadorColisao::~GerenciadorColisao() 
	{
		vetor_personagens = nullptr;
		lista_obstaculos = nullptr;
	}

	Vetor2D<float> GerenciadorColisao::calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2)
	{
		float dx = abs((entidade_1->get_posicao().get_x() + entidade_1->get_corpo().getSize().x / 2) - (entidade_2->get_posicao().get_x() + entidade_2->get_corpo().getSize().x / 2)) - (entidade_1->get_corpo().getSize().x+entidade_2->get_corpo().getSize().x) / 2;
		float dy = abs((entidade_1->get_posicao().get_y() + entidade_1->get_corpo().getSize().y / 2) - (entidade_2->get_posicao().get_y() + entidade_2->get_corpo().getSize().y / 2)) - (entidade_1->get_corpo().getSize().y + entidade_2->get_corpo().getSize().y) / 2;
		return(Vetor2D<float>(dx, dy));
	}

	void GerenciadorColisao::executar()
	{
		std::list<Obstaculos::Obstaculo*>::iterator i;
		std::vector<Entidades::Personagem*>::const_iterator j;

		for (i = lista_obstaculos->begin(); i != lista_obstaculos->end(); i++)
		{
			Obstaculos::Obstaculo* obstaculo = *i;
			for (j = vetor_personagens->begin(); j != vetor_personagens->end(); j++)
			{
				Entidades::Personagem* personagem = *j;
				Vetor2D<float> ds = calcula_colisao(obstaculo, personagem);
				if (ds.get_x() < 0 && ds.get_y() < 0)
				{

				}
			}
		}
	}
}
