#include "Pedra.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Pedra::Pedra(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
            Obstaculo{ gerenciador_grafico_input, caminho_textura_input, posicao_input },
            metade_altura{ false }
        {
            corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
            tipo_entidade = ID_PEDRA;
            obstaculo_danoso = false;

            srand(static_cast<unsigned int>(time(nullptr)));

            if (1 + rand() % 100 >= 50)
                metade_altura = true;

            get_corpo()->setSize(sf::Vector2f(get_corpo()->getSize().x, get_corpo()->getSize().y / 2));
        }

        Pedra::~Pedra()
        {
        }

        void Pedra::executar(float delta_t)
        {
            if(pode_executar)
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
