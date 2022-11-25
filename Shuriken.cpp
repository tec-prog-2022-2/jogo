#include "Shuriken.h"

namespace Entidades
{
    Shuriken::Shuriken(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
        Entidade{gerenciador_grafico_input, caminho_textura_input, posicao_input},
        pode_atirar{ true },
        atirou_direita{false},
        atirou_esquerda{false},
        kamikaze_vivo{true},
        posicao_inicial{Vetor2D<float>(0.0f, 0.0f)}
    {
        velocidade = Vetor2D<float>(0.0f, 0.0f);
        corpo = new sf::RectangleShape(sf::Vector2f(30.0f, 30.f));
        tipo_entidade = ID_SHURIKEN;
    }

    Shuriken::~Shuriken()
    {
    }

    void Shuriken::executar(float delta_t)
    {
        if (pode_executar)
        {
            velocidade.set_x(0.0f);

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

    void Shuriken::atirar_direita(float delta_t)
    {
        velocidade.set_x(0.0f);
        velocidade.set_x(velocidade.get_x() + 50.0f);
        posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y());
    }

    void Shuriken::atirar_esquerda(float delta_t)
    {
        velocidade.set_x(0.0f);
        velocidade.set_x(velocidade.get_x() - 50.0f);
        posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y());
    }

    void Shuriken::set_pode_atirar(const bool pode_atirar_input)
    {
        pode_atirar = pode_atirar_input;
    }

    const bool Shuriken::get_pode_atirar() const
    {
        return(pode_atirar);
    }

    void Shuriken::set_posicao_inicial(const Vetor2D<float> posicao_inicial_input)
    {
        posicao_inicial = posicao_inicial_input;
    }

    const Vetor2D<float> Shuriken::get_posicao_inicial() const
    {
        return(posicao_inicial);
    }

    void Shuriken::set_atirou_esquerda(const bool atirou_input)
    {
        atirou_esquerda = atirou_input;
    }

    const bool Shuriken::get_atirou_esquerda() const
    {
        return(atirou_esquerda);
    }

    void Shuriken::set_atirou_direita(const bool atirou_input)
    {
        atirou_direita = atirou_input;
    }

    const bool Shuriken::get_atirou_direita() const
    {
        return(atirou_direita);
    }

    const bool Shuriken::get_kamikaze_vivo() const
    {
        return(kamikaze_vivo);
    }

    void Shuriken::set_kamikaze_vivo(const bool kamikaze_vivo_input)
    {
        kamikaze_vivo = kamikaze_vivo_input;
    }
}
