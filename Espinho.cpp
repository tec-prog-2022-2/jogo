#include "Espinho.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input, Vetor2D<float> tamanho_corpo, int tipo_entidade_input, bool obstaculo_danoso_input) :
            Obstaculo{ gerenciador_grafico_input, caminho_textura_input, posicao_input, tamanho_corpo, tipo_entidade_input, obstaculo_danoso_input },
            dano{ 1 }
        {
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
            //Efeito gravitacional
            velocidade.set_y(velocidade.get_y() + 981000000.0f * delta_t);
            velocidade.set_y(velocidade.get_y() - 981000000.0f * delta_t);
        }
    }
}
