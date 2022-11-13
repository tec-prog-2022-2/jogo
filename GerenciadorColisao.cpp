#include"GerenciadorColisao.h"

namespace Gerenciadores
{
	GerenciadorColisao::GerenciadorColisao(Entidades::Samurai* samurai_input, std::vector<Entidades::Personagem*>* vetor_personagens_input, std::list<Obstaculos::Obstaculo*>* lista_obstaculos_input) :
		samurai{samurai_input},
		vetor_personagens{ vetor_personagens_input },
		lista_obstaculos{ lista_obstaculos_input }
	{
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
		samurai = nullptr;
		vetor_personagens = nullptr;
		lista_obstaculos = nullptr;
	}

	Vetor2D<float> GerenciadorColisao::calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2)
	{
		float dx = abs((entidade_1->get_posicao().get_x() + entidade_1->get_corpo().getSize().x / 2) - (entidade_2->get_posicao().get_x() + entidade_2->get_corpo().getSize().x / 2)) - (entidade_1->get_corpo().getSize().x + entidade_2->get_corpo().getSize().x) / 2;
		float dy = abs((entidade_1->get_posicao().get_y() + entidade_1->get_corpo().getSize().y / 2) - (entidade_2->get_posicao().get_y() + entidade_2->get_corpo().getSize().y / 2)) - (entidade_1->get_corpo().getSize().y + entidade_2->get_corpo().getSize().y) / 2;
		return(Vetor2D<float>(dx, dy));
	}

	void GerenciadorColisao::colisao_samurai_obstaculo(Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds)
	{
		Vetor2D<float> deslocamento = samurai->get_posicao();
		
		//Colis�o na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O personagem est� a esquerda do obst�culo 
			if (deslocamento.get_x() < obstaculo->get_posicao().get_x())
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());

			//O personagem est� a direita do obst�culo
			else
				deslocamento.set_x(deslocamento.get_x() - ds.get_x());

			samurai->set_colisao_chao(false);
		}

		//Colis�o na horizontal
		else
		{
			//O personagem est� acima do obst�culo
			if (samurai->get_posicao().get_y() < obstaculo->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y()+0.000001f);
				samurai->set_colisao_chao(true);
			}

			//O personagem est� abaixo do obst�culo
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y());
			}
		}
		samurai->set_posicao(deslocamento);
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

				//Houve colis�o
				if ((ds.get_x() < 0 && ds.get_y() < 0) && personagem->get_tipo_entidade() == ID_SAMURAI)
				{
					colisao_samurai_obstaculo(obstaculo, ds);
				}

				else if (personagem->get_tipo_entidade() == ID_SAMURAI)
				{
					samurai->set_colisao_chao(false);
				}
			}
		}
	}
}
