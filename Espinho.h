#pragma once

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho : public Obstaculo
        {
        private:
            int dano;

        public:
            Espinho(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0, 0));
            ~Espinho();
            const int get_dano() const;
            void executar(float delta_t);
        };
    }
}
