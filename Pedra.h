#pragma once

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Pedra : public Obstaculo
        {
        private:
            bool metade_altura;

        public:
            Pedra(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f));
            ~Pedra();
            void executar(float delta_t);
        };
    }
}
