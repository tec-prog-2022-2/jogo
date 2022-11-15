#include"GerenciadorColisao.h"

namespace Gerenciadores
{
	GerenciadorColisao::GerenciadorColisao(Entidades::Personagens::Samurai* samurai_input, std::vector<Entidades::Personagens::Personagem*>* vetor_personagens_input, std::list<Entidades::Obstaculos::Obstaculo*>* lista_obstaculos_input) :
		samurai{samurai_input},
		vetor_personagens{ vetor_personagens_input },
		lista_obstaculos{ lista_obstaculos_input },
		lista_shurikens{}
	{
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
		lista_shurikens.clear();
		vetor_personagens = nullptr;
		lista_obstaculos = nullptr;
	}

	void GerenciadorColisao::inicializar_lista_shurikens()
	{
		std::vector<Entidades::Personagens::Personagem*>::const_iterator a = vetor_personagens->begin();
		for (a = vetor_personagens->begin(); a != vetor_personagens->end(); a++)
		{
			Entidades::Personagens::Personagem* personagem = *a;
			if (personagem->get_tipo_entidade() == ID_KAMIKAZE)
			{
				Entidades::Personagens::Kamikaze* kamikaze = static_cast<Entidades::Personagens::Kamikaze*>(personagem);
				lista_shurikens.push_back(kamikaze->get_shuriken());
			}
		}
	}

	Vetor2D<float> GerenciadorColisao::calcula_colisao(Entidades::Entidade* entidade_1, Entidades::Entidade* entidade_2)
	{
		float dx = abs((entidade_1->get_posicao().get_x() + entidade_1->get_corpo().getSize().x / 2) - (entidade_2->get_posicao().get_x() + entidade_2->get_corpo().getSize().x / 2)) - (entidade_1->get_corpo().getSize().x + entidade_2->get_corpo().getSize().x) / 2;
		float dy = abs((entidade_1->get_posicao().get_y() + entidade_1->get_corpo().getSize().y / 2) - (entidade_2->get_posicao().get_y() + entidade_2->get_corpo().getSize().y / 2)) - (entidade_1->get_corpo().getSize().y + entidade_2->get_corpo().getSize().y) / 2;
		return(Vetor2D<float>(dx, dy));
	}

	void GerenciadorColisao::colisao_personagem_obstaculo(Entidades::Personagens::Personagem* personagem, Entidades::Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds)
	{
		Vetor2D<float> deslocamento = personagem->get_posicao();

		//Colisão na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O personagem está a esquerda do obstáculo 
			if (deslocamento.get_x() < obstaculo->get_posicao().get_x())
			{
				if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_tipo_entidade() == ID_ESPINHO)
					samurai->set_colisao_esq_espinho(true);
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
			}

			//O personagem está a direita do obstáculo
			else
			{
				if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_tipo_entidade() == ID_ESPINHO)
					samurai->set_colisao_dir_espinho(true);

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

				if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_tipo_entidade() == ID_ESPINHO)
					samurai->set_colisao_cima_espinho(true);
				
				else if (personagem->get_tipo_entidade() == ID_SAMURAI)
				{
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

		if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_tipo_entidade() == ID_ESPINHO)
		{
			Entidades::Obstaculos::Espinho* espinho = static_cast<Entidades::Obstaculos::Espinho*>(obstaculo);
			samurai->set_vidas(samurai->get_vidas() - espinho->get_dano());

			if (samurai->get_vidas() <= 0)
				samurai->set_vivo(false);
		}

		personagem->set_posicao(deslocamento);
	}

	void GerenciadorColisao::colisao_samurai_inimigo(Entidades::Personagens::Inimigo* inimigo, Vetor2D<float> ds, float delta_t)
	{
		Vetor2D<float> deslocamento = samurai->get_posicao();

		//Colisão na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O samurai está a esquerda do inimigo 
			if (deslocamento.get_x() < inimigo->get_posicao().get_x())
			{
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
				samurai->set_colisao_esq_inimigo(true);
			}

			//O samurai está a direita do obstáculo
			else
			{
				deslocamento.set_x(deslocamento.get_x() - ds.get_x());
				samurai->set_colisao_dir_inimigo(true);
			}

			samurai->set_vidas(samurai->get_vidas() - inimigo->get_dano());
			samurai->set_velocidade(Vetor2D<float>(0.0f, samurai->get_velocidade().get_y()));
			inimigo->set_velocidade(Vetor2D<float>(0.0f, inimigo->get_velocidade().get_y()));
		}

		//Colisão na horizontal
		else
		{
			//O samurai está acima do inimigo
			if (samurai->get_posicao().get_y() < inimigo->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y());
				samurai->set_colisao_cima_inimigo(true);
				inimigo->set_vidas(inimigo->get_vidas() - 1);
			}

			//O samurai está abaixo do inimigo
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y());
				samurai->set_vidas(samurai->get_vidas() - inimigo->get_dano());
			}

			samurai->set_velocidade(Vetor2D<float>(samurai->get_velocidade().get_x(), 0.0f));
			inimigo->set_velocidade(Vetor2D<float>(inimigo->get_velocidade().get_x(), 0.0f));
		}

		samurai->set_posicao(deslocamento);

		if (samurai->get_vidas() <= 0)
			samurai->set_vivo(false);

		if (inimigo->get_vidas() <= 0)
			inimigo->set_vivo(false);
	}

	void GerenciadorColisao::colisao_samurai_shuriken(Entidades::Shuriken* shuriken, Vetor2D<float> ds)
	{
		Vetor2D<float> deslocamento = samurai->get_posicao();

		//Colisão na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O samurai está a esquerda do shuriken 
			if (deslocamento.get_x() < shuriken->get_posicao().get_x())
			{
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
			}

			//O samurai está a direita do shuriken
			else
			{
				deslocamento.set_x(deslocamento.get_x() - ds.get_x());
			}

			samurai->set_velocidade(Vetor2D<float>(0.0f, samurai->get_velocidade().get_y()));
		}

		//Colisão na horizontal
		else
		{
			//O samurai está acima do shuriken
			if (samurai->get_posicao().get_y() < samurai->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y());
			}

			//O samurai está acima do shuriken
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y());
			}

			samurai->set_velocidade(Vetor2D<float>(samurai->get_velocidade().get_x(), 0.0f));
		}

		shuriken->set_pode_atirar(false);
		shuriken->set_posicao(shuriken->get_posicao_inicial());
		samurai->set_vidas(samurai->get_vidas() - 1);
		if (samurai->get_vidas() <= 0)
			samurai->set_vivo(false);
		samurai->set_posicao(deslocamento);
	}

	void GerenciadorColisao::executar(float delta_t)
	{
		std::list<Entidades::Obstaculos::Obstaculo*>::const_iterator i;
		std::vector<Entidades::Personagens::Personagem*>::const_iterator j;
		std::list<Entidades::Shuriken*>::const_iterator k;

		for (i = lista_obstaculos->begin(); i != lista_obstaculos->end(); i++)
		{
			Entidades::Obstaculos::Obstaculo* obstaculo = *i;
			for (j = vetor_personagens->begin(); j != vetor_personagens->end(); j++)
			{
				Entidades::Personagens::Personagem* personagem = *j;
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
				Entidades::Personagens::Inimigo* inimigo = static_cast<Entidades::Personagens::Inimigo*>(*j);
				Vetor2D<float> ds = calcula_colisao(inimigo, samurai);

				//Houve colisão
				if (ds.get_x() < 0 && ds.get_y() < 0)
				{
					colisao_samurai_inimigo(inimigo, ds, delta_t);
				}
			}
		}

		for (k = lista_shurikens.begin(); k != lista_shurikens.end(); k++)
		{
			Entidades::Shuriken* shuriken = *k;

			Vetor2D<float> ds = calcula_colisao(shuriken, samurai);

			//Houve colisão
			if (ds.get_x() < 0 && ds.get_y() < 0)
			{
				std::cout << "colisao";
				colisao_samurai_shuriken(shuriken, ds);
			}
		}
	}
}
