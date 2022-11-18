#pragma once

#include"Entidade.h"

namespace Entidades
{
    class Shuriken : public Entidade
    {
    private:
        bool pode_atirar;
        Vetor2D<float> posicao_inicial;

    public:
        Shuriken(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input=nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f));
        ~Shuriken();
        void executar(float delta_t);
        void atirar_direita(float delta_t);
        void atirar_esquerda(float delta_t);
        void set_pode_atirar(const bool pode_atirar_input);
        const bool get_pode_atirar() const;
        void set_posicao_inicial(const Vetor2D<float> posicao_inicial_input);
        const Vetor2D<float> get_posicao_inicial() const;
    };
}
