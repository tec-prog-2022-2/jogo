#include "Pedra.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Pedra::Pedra(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, bool obstaculo_danoso_input) :
            Obstaculo{ gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, obstaculo_danoso_input },
            metade_altura{ false }
        {
            srand(static_cast<unsigned int>(time(nullptr)));

            if (1 + rand() % 100 >= 50)
                metade_altura = true;

            get_corpo().setSize(sf::Vector2f(get_corpo().getSize().x, get_corpo().getSize().y / 2));
        }

        Pedra::~Pedra()
        {
        }

        void Pedra::executar(float delta_t)
        {
            //Efeito gravitacional
            velocidade.set_y(velocidade.get_y() + 981000000.0f * delta_t);
            velocidade.set_y(velocidade.get_y() - 981000000.0f * delta_t);
        }
    }
}
