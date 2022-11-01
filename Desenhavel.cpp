#include"Desenhavel.h"

Desenhavel::Desenhavel(Vetor2D<float> posicao_input, Vetor2D<float> velocidade_input, const char* caminho_textura_input):
	posicao{posicao_input},
	velocidade{velocidade_input},
	caminho_textura{caminho_textura_input}
{
}

Desenhavel::~Desenhavel()
{
}

void Desenhavel::inicializar(GerenciadorGrafico* gerenciador_grafico_input, GerenciadorEventos* gerenciador_eventos_input)
{
	if (gerenciador_grafico_input->carregar_textura(caminho_textura))
		std::cout << "Textura de personagem inicializada com sucesso!" << std::endl;

	else
		std::cout << "Textura de personagem nao inicializada com sucesso!" << std::endl;
}

void Desenhavel::atualizar(float tempo_input)
{
	posicao += velocidade * tempo_input;

}

void Desenhavel::desenhar(GerenciadorGrafico* gerenciador_grafico_input)
{
	gerenciador_grafico_input->desenhar(caminho_textura, posicao); 
}
