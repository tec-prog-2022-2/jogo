#include"GerenciadorColisao.h"

namespace Gerenciadores
{
	GerenciadorColisao::GerenciadorColisao(Personagens::Samurai* samurai_input, std::vector<Personagens::Personagem*>* vetor_personagens_input, std::list<Obstaculos::Obstaculo*>* lista_obstaculos_input) :
		samurai{samurai_input},
		vetor_personagens{ vetor_personagens_input },
		lista_obstaculos{ lista_obstaculos_input }
	{
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
		vetor_personagens = nullptr;
		lista_obstaculos = nullptr;
	}

	Vetor2D<float> GerenciadorColisao::calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2)
	{
		float dx = abs((entidade_1->get_posicao().get_x() + entidade_1->get_corpo().getSize().x / 2) - (entidade_2->get_posicao().get_x() + entidade_2->get_corpo().getSize().x / 2)) - (entidade_1->get_corpo().getSize().x + entidade_2->get_corpo().getSize().x) / 2;
		float dy = abs((entidade_1->get_posicao().get_y() + entidade_1->get_corpo().getSize().y / 2) - (entidade_2->get_posicao().get_y() + entidade_2->get_corpo().getSize().y / 2)) - (entidade_1->get_corpo().getSize().y + entidade_2->get_corpo().getSize().y) / 2;
		return(Vetor2D<float>(dx, dy));
	}

	void GerenciadorColisao::colisao_personagem_obstaculo(Personagens::Personagem* personagem, Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds)
	{
		Vetor2D<float> deslocamento = personagem->get_posicao();

		//Colisão na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O personagem está a esquerda do obstáculo 
			if (deslocamento.get_x() < obstaculo->get_posicao().get_x())
			{
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
			}

			//O personagem está a direita do obstáculo
			else
			{
				deslocamento.set_x(deslocamento.get_x() - ds.get_x());
			}

			personagem->set_velocidade(Vetor2D<float>(0.0f, personagem->get_velocidade().get_y()));
		}

		//Colisão na horizontal
		else
		{
			//O personagem está acima do obstáculo
			if (personagem->get_posicao().get_y() < obstaculo->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y());

				if (personagem->get_tipo_entidade() == ID_SAMURAI)
				{
					Personagens::Samurai* samurai = static_cast<Personagens::Samurai*>(personagem);
					samurai->set_pode_pular(true);
				}
			}

			//O personagem está abaixo do obstáculo
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y());
			}

			personagem->set_velocidade(Vetor2D<float>(personagem->get_velocidade().get_x(), 0.0f));
		}

		personagem->set_posicao(deslocamento);
	}

	void GerenciadorColisao::colisao_samurai_inimigo(Personagens::Inimigo* inimigo, Vetor2D<float> ds, float delta_t)
	{
		Vetor2D<float> deslocamento = samurai->get_posicao();

		//Colisão na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O samurai está a esquerda do inimigo 
			if (deslocamento.get_x() < inimigo->get_posicao().get_x())
			{
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
				samurai->set_velocidade(Vetor2D<float>(samurai->get_velocidade().get_x() - 100000.0f, samurai->get_velocidade().get_y()));
			}

			//O samurai está a direita do obstáculo
			else
			{
				deslocamento.set_x(deslocamento.get_x() - ds.get_x());
				samurai->set_velocidade(Vetor2D<float>(samurai->get_velocidade().get_x() - 100000.0f, samurai->get_velocidade().get_y()));
			}

			samurai->set_velocidade(Vetor2D<float>(0.0f, samurai->get_velocidade().get_y()));
			inimigo->set_velocidade(Vetor2D<float>(0.0f, inimigo->get_velocidade().get_y()));
		}

		//Colisão na horizontal
		else
		{
			//O samurai está acima do inimigo
			if (samurai->get_posicao().get_y() < inimigo->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y()-1.0f);
			}

			//O samurai está abaixo do inimigo
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y()+1.0f);
			}

			samurai->set_velocidade(Vetor2D<float>(samurai->get_velocidade().get_x(), 0.0f));
			inimigo->set_velocidade(Vetor2D<float>(inimigo->get_velocidade().get_x(), 0.0f));
		}

		samurai->set_posicao(deslocamento);
	}

	void GerenciadorColisao::executar(float delta_t)
	{
		std::list<Obstaculos::Obstaculo*>::iterator i;
		std::vector<Personagens::Personagem*>::const_iterator j;

		for (i = lista_obstaculos->begin(); i != lista_obstaculos->end(); i++)
		{
			Obstaculos::Obstaculo* obstaculo = *i;
			for (j = vetor_personagens->begin(); j != vetor_personagens->end(); j++)
			{
				Personagens::Personagem* personagem = *j;
				Vetor2D<float> ds = calcula_colisao(obstaculo, personagem);

				//Houve colisão
				if (ds.get_x() < 0 && ds.get_y() < 0)
				{
					colisao_personagem_obstaculo(personagem, obstaculo, ds);
				}
			}
		}

		for (j = vetor_personagens->begin(); j != vetor_personagens->end(); j++)
		{
			if (*j != samurai)
			{
				Personagens::Inimigo* inimigo = static_cast<Personagens::Inimigo*>(*j);
				Vetor2D<float> ds = calcula_colisao(inimigo, samurai);

				//Houve colisão
				if (ds.get_x() < 0 && ds.get_y() < 0)
				{
					colisao_samurai_inimigo(inimigo, ds, delta_t);
				}
			}
		}
	}
}
