#pragma once

#include"Entidade.h"

namespace Entidades
{
    class Shuriken : public Entidade
    {
    private:
        bool pode_atirar;
        bool atirou_direita;
        bool atirou_esquerda;
        bool kamikaze_vivo;
        Vetor2D<float> posicao_inicial;

    public:
        Shuriken(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input = nullptr, const char* caminho_textura_input = nullptr, Vetor2D<float> posicao_input = Vetor2D<float>(0.0f, 0.0f));
        ~Shuriken();
        void executar(float delta_t);
        void atirar_direita(float delta_t);
        void atirar_esquerda(float delta_t);
        void set_pode_atirar(const bool pode_atirar_input);
        const bool get_pode_atirar() const;
        void set_atirou_esquerda(const bool atirou_input);
        const bool get_atirou_esquerda() const;
        void set_atirou_direita(const bool atirou_input);
        const bool get_atirou_direita() const;
        void set_posicao_inicial(const Vetor2D<float> posicao_inicial_input);
        const bool get_kamikaze_vivo() const;
        void set_kamikaze_vivo(const bool kamikaze_vivo_input);
        const Vetor2D<float> get_posicao_inicial() const;
    };
}
