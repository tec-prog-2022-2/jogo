#include "Espinho.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
            Obstaculo{ gerenciador_grafico_input, caminho_textura_input, posicao_input},
            dano{ 1 }
        {
            corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
            tipo_entidade = ID_ESPINHO;
            obstaculo_danoso = true;
        }

        Espinho::~Espinho()
        {
        }

        const int Espinho::get_dano() const
        {
            return(dano);
        }

        void Espinho::executar(float delta_t)
        {
            if (pode_executar)
            {
                //Efeito gravitacional
                velocidade.set_y(velocidade.get_y() + GRAVIDADE * delta_t);
                velocidade.set_y(velocidade.get_y() - GRAVIDADE * delta_t);
            }

            else
            {
                temporizador_pode_executar++;

                if (temporizador_pode_executar >= 5)
                    this->set_pode_executar(true);
            }
        }
    }
}
