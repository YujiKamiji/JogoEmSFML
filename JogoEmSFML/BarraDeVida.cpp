#include "BarraDeVida.h"

BarraDeVida::BarraDeVida(sf::Vector2f TamFundo, int vida_max):
	Ente(), vida(vida_max), vidaMaxima(vida_max)
{
	fundo.setSize(TamFundo);
	fundo.setOrigin(TamFundo / 2.f);
	fundo.setFillColor(sf::Color::Black);
	fundo.setOutlineColor(sf::Color::White);
	fundo.setOutlineThickness(1.f);

	sf::Vector2f TamBarra = sf::Vector2f(TamFundo.x - 10.f, TamFundo.y - 10.f);
	barra.setSize(TamBarra);
	barra.setOrigin(TamBarra / 2.f);
	barra.setFillColor(sf::Color::Red);
}

BarraDeVida::~BarraDeVida()
{
}

void BarraDeVida::setPosicao(sf::Vector2f pos)
{
	fundo.setPosition(pos);
	barra.setPosition(pos);
}

void BarraDeVida::setVida(int v)
{
	
	// Calcula a nova largura da barra de vida com base na porcentagem de vida restante
	float largura = (fundo.getSize().x - 10.f) * (static_cast<float>(v) / static_cast<float>(vidaMaxima));

	// Define o novo tamanho da barra de vida
	barra.setSize(sf::Vector2f(largura, fundo.getSize().y - 10.f)); 

	// Ajusta a posição da barra para que diminua apenas de um lado
	barra.setPosition(fundo.getPosition().x, fundo.getPosition().y);
}

void BarraDeVida::setCor(sf::Color cor)
{
	barra.setFillColor(cor);
}

void BarraDeVida::desenhar()
{
	pGG->desenhar(&fundo);
	pGG->desenhar(&barra);
}

void BarraDeVida::executar(sf::Time deltaTime)
{
}

