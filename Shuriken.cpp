#include "Shuriken.h"

namespace Entidades
{
    Shuriken::Shuriken(Gerenciadores::GerenciadorGrafico* gerenciador_grafico_input, const char* caminho_textura_input, Vetor2D<float> posicao_input) :
        Entidade{gerenciador_grafico_input, caminho_textura_input, posicao_input},
        pode_atirar{ true },
        posicao_inicial{Vetor2D<float>(0.0f, 0.0f)}
    {
        velocidade = Vetor2D<float>(0.0f, 0.0f);
        corpo = new sf::RectangleShape(sf::Vector2f(50.0f, 90.f));
        tipo_entidade = ID_SHURIKEN;
    }

    Shuriken::~Shuriken()
    {
    }

    void Shuriken::executar(float delta_t)
    {
        velocidade.set_x(0.0f);

        //Efeito gravitacional
        velocidade.set_y(velocidade.get_y() + 981000000.0f * delta_t);
        velocidade.set_y(velocidade.get_y() - 981000000.0f * delta_t);
    }

    void Shuriken::atirar_direita(float delta_t)
    {
        velocidade.set_x(velocidade.get_x() + 10000.0f);
        posicao = Vetor2D<float>(posicao.get_x() + velocidade.get_x() * delta_t, posicao.get_y());
    }

    void Shuriken::atirar_esquerda(float delta_t)
    {
        velocidade.set_x(velocidade.get_x() - 10000.0f);
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
}
