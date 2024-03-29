#include"GerenciadorColisao.h"

namespace Gerenciadores
{
	GerenciadorColisao::GerenciadorColisao(Entidades::Personagens::Samurai* samurai_input, std::vector<Entidades::Personagens::Personagem*>* vetor_personagens_input, std::list<Entidades::Obstaculos::Obstaculo*>* lista_obstaculos_input) :
		samurai{samurai_input},
		samurai_2{nullptr},
		vetor_personagens{ vetor_personagens_input },
		lista_obstaculos{ lista_obstaculos_input },
		lista_shurikens{}
	{
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
		samurai = nullptr;
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
		float dx = abs((entidade_1->get_posicao().get_x() + entidade_1->get_corpo()->getSize().x / 2) - (entidade_2->get_posicao().get_x() + entidade_2->get_corpo()->getSize().x / 2)) - (entidade_1->get_corpo()->getSize().x + entidade_2->get_corpo()->getSize().x) / 2;
		float dy = abs((entidade_1->get_posicao().get_y() + entidade_1->get_corpo()->getSize().y / 2) - (entidade_2->get_posicao().get_y() + entidade_2->get_corpo()->getSize().y / 2)) - (entidade_1->get_corpo()->getSize().y + entidade_2->get_corpo()->getSize().y) / 2;
		return(Vetor2D<float>(dx, dy));
	}

	void GerenciadorColisao::colisao_personagem_obstaculo(Entidades::Personagens::Personagem* personagem, Entidades::Obstaculos::Obstaculo* obstaculo, Vetor2D<float> ds)
	{
		Vetor2D<float> deslocamento = personagem->get_posicao();

		//Colis�o na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O personagem est� a esquerda do obst�culo 
			if (deslocamento.get_x() < obstaculo->get_posicao().get_x())
			{
				if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_danoso())
				{
					Entidades::Personagens::Samurai* samurai_aux = static_cast<Entidades::Personagens::Samurai*>(personagem);

					if(samurai_aux->get_jogador_principal())
						samurai->set_colisao_esq_espinho(true);

					else
						samurai_2->set_colisao_esq_espinho(true);
				}
					
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
			}

			//O personagem est� a direita do obst�culo
			else
			{
				if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_danoso())
				{
					Entidades::Personagens::Samurai* samurai_aux = static_cast<Entidades::Personagens::Samurai*>(personagem);

					if (samurai_aux->get_jogador_principal())
						samurai->set_colisao_dir_espinho(true);

					else
						samurai_2->set_colisao_dir_espinho(true);
				}

				deslocamento.set_x(deslocamento.get_x() - ds.get_x());
			}

			personagem->set_velocidade(Vetor2D<float>(0.0f, personagem->get_velocidade().get_y()));
		}

		//Colis�o na horizontal
		else
		{
			//O personagem est� acima do obst�culo
			if (personagem->get_posicao().get_y() < obstaculo->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y());

				if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_danoso())
				{
					Entidades::Personagens::Samurai* samurai_aux = static_cast<Entidades::Personagens::Samurai*>(personagem);

					if (samurai_aux->get_jogador_principal())
						samurai->set_colisao_cima_espinho(true);

					else
						samurai_2->set_colisao_cima_espinho(true);
				}
				
				else if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_tipo_entidade() == ID_PEDRA)
				{
					Entidades::Personagens::Samurai* samurai_aux = static_cast<Entidades::Personagens::Samurai*>(personagem);
					
					if (samurai_aux->get_jogador_principal())
						samurai->set_colisao_pedra(true);

					else
						samurai_2->set_colisao_pedra(true);
				}

				else if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_tipo_entidade() != ID_PEDRA)
				{
					Entidades::Personagens::Samurai* samurai_aux = static_cast<Entidades::Personagens::Samurai*>(personagem);

					if (samurai_aux->get_jogador_principal())
						samurai->set_colisao_pedra(false);

					else
						samurai_2->set_colisao_pedra(false);
				}
				
				if (personagem->get_tipo_entidade() == ID_SAMURAI)
				{
					Entidades::Personagens::Samurai* samurai_aux = static_cast<Entidades::Personagens::Samurai*>(personagem);

					if (samurai_aux->get_jogador_principal())
						samurai->set_pode_pular(true);

					else
						samurai_2->set_pode_pular(true);
				}
			}

			//O personagem est� abaixo do obst�culo
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y());
			}

			personagem->set_velocidade(Vetor2D<float>(personagem->get_velocidade().get_x(), 0.0f));
		}

		if (personagem->get_tipo_entidade() == ID_SAMURAI && obstaculo->get_danoso())
		{
			Entidades::Obstaculos::Espinho* espinho = static_cast<Entidades::Obstaculos::Espinho*>(obstaculo);

			Entidades::Personagens::Samurai* samurai_aux = static_cast<Entidades::Personagens::Samurai*>(personagem);

			if (samurai_aux->get_jogador_principal())
			{
				samurai->set_vidas(samurai->get_vidas() - espinho->get_dano());
				if (samurai->get_vidas() <= 0)
					samurai->set_vivo(false);
			}
		
			else
			{
				samurai_2->set_vidas(samurai_2->get_vidas() - espinho->get_dano());
				if (samurai_2->get_vidas() <= 0)
					samurai_2->set_vivo(false);
			}
		}

		personagem->set_posicao(deslocamento);
	}

	void GerenciadorColisao::colisao_samurai_inimigo(Entidades::Personagens::Samurai* samurai_input, Entidades::Personagens::Inimigo* inimigo, Vetor2D<float> ds, float delta_t)
	{
		Vetor2D<float> deslocamento = samurai_input->get_posicao();

		//Colis�o na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O samurai est� a esquerda do inimigo 
			if (deslocamento.get_x() < inimigo->get_posicao().get_x())
			{
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
				samurai_input->set_colisao_esq_inimigo(true);
			}

			//O samurai est� a direita do obst�culo
			else
			{
				deslocamento.set_x(deslocamento.get_x() - ds.get_x());
				samurai_input->set_colisao_dir_inimigo(true);
			}

			samurai_input->set_vidas(samurai_input->get_vidas() - inimigo->get_dano());
			samurai_input->set_velocidade(Vetor2D<float>(0.0f, samurai_input->get_velocidade().get_y()));
			inimigo->set_velocidade(Vetor2D<float>(0.0f, inimigo->get_velocidade().get_y()));
		}

		//Colis�o na horizontal
		else
		{
			//O samurai est� acima do inimigo
			if (samurai_input->get_posicao().get_y() < inimigo->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y());
				samurai_input->set_colisao_cima_inimigo(true);
				inimigo->set_vidas(inimigo->get_vidas() - 1);
			}

			//O samurai est� abaixo do inimigo
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y());
				samurai_input->set_vidas(samurai_input->get_vidas() - inimigo->get_dano());
			}

			samurai_input->set_velocidade(Vetor2D<float>(samurai_input->get_velocidade().get_x(), 0.0f));
			inimigo->set_velocidade(Vetor2D<float>(inimigo->get_velocidade().get_x(), 0.0f));
		}

		samurai_input->set_posicao(deslocamento);

		if (samurai_input->get_vidas() <= 0)
			samurai_input->set_vivo(false);

		if (inimigo->get_vidas() <= 0)
		{
			inimigo->set_vivo(false);
			if (inimigo->get_tipo_entidade() == ID_KAMIKAZE)
			{
				Entidades::Personagens::Kamikaze* kamikaze = static_cast<Entidades::Personagens::Kamikaze*>(inimigo);
				kamikaze->get_shuriken()->set_kamikaze_vivo(false);
			}

			if (inimigo->get_tipo_entidade() == ID_IZANAGI)
			{
				samurai->set_perto_izanagi(false);
				samurai_input->set_perto_izanagi(false);
			}
		}
	}

	void GerenciadorColisao::colisao_samurai_shuriken(Entidades::Personagens::Samurai* samurai_input, Entidades::Shuriken* shuriken, Vetor2D<float> ds)
	{
		Vetor2D<float> deslocamento = samurai_input->get_posicao();

		//Colis�o na vertical
		if (ds.get_x() > ds.get_y())
		{
			//O samurai est� a esquerda do shuriken 
			if (deslocamento.get_x() < shuriken->get_posicao().get_x())
			{
				deslocamento.set_x(deslocamento.get_x() + ds.get_x());
			}

			//O samurai est� a direita do shuriken
			else
			{
				deslocamento.set_x(deslocamento.get_x() - ds.get_x());
			}

			samurai_input->set_velocidade(Vetor2D<float>(0.0f, samurai_input->get_velocidade().get_y()));
		}

		//Colis�o na horizontal
		else
		{
			//O samurai est� acima do shuriken
			if (samurai_input->get_posicao().get_y() < samurai_input->get_posicao().get_y())
			{
				deslocamento.set_y(deslocamento.get_y() + ds.get_y());
			}

			//O samurai est� acima do shuriken
			else
			{
				deslocamento.set_y(deslocamento.get_y() - ds.get_y());
			}

			samurai_input->set_velocidade(Vetor2D<float>(samurai_input->get_velocidade().get_x(), 0.0f));
		}

		shuriken->set_pode_atirar(false);
		shuriken->set_atirou_direita(false);
		shuriken->set_atirou_esquerda(false);
		shuriken->set_posicao(shuriken->get_posicao_inicial());
		samurai_input->set_vidas(samurai_input->get_vidas() - 1);
		samurai_input->set_posicao(deslocamento);
		if (samurai_input->get_vidas() <= 0)
			samurai_input->set_vivo(false);
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
				if (*j)
				{
					Entidades::Personagens::Personagem* personagem = *j;
					Vetor2D<float> ds = calcula_colisao(obstaculo, personagem);

					//Houve colis�o
					if (ds.get_x() < 0 && ds.get_y() < 0)
					{
						colisao_personagem_obstaculo(personagem, obstaculo, ds);
					}
				}
			}
		}

		for (j = vetor_personagens->begin(); j != vetor_personagens->end(); j++)
		{
			if (*j)
			{
				if (*j != samurai && *j != samurai_2)
				{
					Entidades::Personagens::Inimigo* inimigo = static_cast<Entidades::Personagens::Inimigo*>(*j);
					Vetor2D<float> ds = calcula_colisao(inimigo, samurai);

					//Houve colis�o
					if (ds.get_x() < 0 && ds.get_y() < 0 && inimigo->get_vivo())
					{
						colisao_samurai_inimigo(samurai, inimigo, ds, delta_t);
					}
				}
			}
		}

		for (j = vetor_personagens->begin(); j != vetor_personagens->end(); j++)
		{
			if(*j)
			{
				if (*j != samurai && *j != samurai_2)
				{
					if (samurai_2)
					{
						Entidades::Personagens::Inimigo* inimigo = static_cast<Entidades::Personagens::Inimigo*>(*j);
						Vetor2D<float> ds = calcula_colisao(inimigo, samurai_2);

						//Houve colis�o
						if (ds.get_x() < 0 && ds.get_y() < 0 && inimigo->get_vivo())
						{
							colisao_samurai_inimigo(samurai_2, inimigo, ds, delta_t);
						}
					}
				}
			}
		}

		for (k = lista_shurikens.begin(); k != lista_shurikens.end(); k++)
		{
			Entidades::Shuriken* shuriken = *k;

			Vetor2D<float> ds = calcula_colisao(shuriken, samurai);

			//Houve colis�o
			if (ds.get_x() < 0 && ds.get_y() < 0 && shuriken->get_kamikaze_vivo())
			{
				colisao_samurai_shuriken(samurai, shuriken, ds);
			}
		}

		if (samurai_2)
		{
			for (k = lista_shurikens.begin(); k != lista_shurikens.end(); k++)
			{
				Entidades::Shuriken* shuriken = *k;

				Vetor2D<float> ds = calcula_colisao(shuriken, samurai_2);

				//Houve colis�o
				if (ds.get_x() < 0 && ds.get_y() < 0 && shuriken->get_kamikaze_vivo())
				{
					colisao_samurai_shuriken(samurai_2, shuriken, ds);
				}
			}
		}
	}

	void GerenciadorColisao::add_samurai_2(Entidades::Personagens::Samurai* samurai_2_input)
	{
		samurai_2 = samurai_2_input;
	}
}
