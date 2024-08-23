#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		int Jogador::cont = 1;

		Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam):
			Personagem(pos, tam), pontuacao(0), intervaloAtaque(500), 
			jogadorId(cont++), olhandoDireita(true),
			ataque(sf::Vector2f((corpo.getSize().x * 1.5f), corpo.getSize().y)) 
		{
			vidas = 100;
			dano = 10;
			velocidadeMax = 10;
			aceleracao = 1;
			ataque.setOrigin(ataque.getSize() / 2.f);
		}
		Jogador::~Jogador() {}

		void Jogador::executar() {
			if (vidas <= 0)
				vivo = false;
			mover();
			atacar();
			desenhar();
		}

		void Jogador::mover() {
			//Andar
			if (jogadorId == 1) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					if (velocidades.x <= velocidadeMax)
						velocidades.x += aceleracao;
					if (!olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = true;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					if (velocidades.x >= -velocidadeMax)
						velocidades.x -= aceleracao;
					if (olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = false;
					}
				}
				else {
					if (olhandoDireita) {
						if (velocidades.x >= 0)
							velocidades.x -= aceleracao * 2;
						else
							velocidades.x = 0;
					}
					else {
						if (velocidades.x <= 0)
							velocidades.x += aceleracao * 2;
						else
							velocidades.x = 0;
					}
				}
					
			}

			if (jogadorId == 2) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (velocidades.x <= velocidadeMax)
						velocidades.x += aceleracao;
					if (!olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = true;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (velocidades.x >= -velocidadeMax)
						velocidades.x -= aceleracao;
					if (olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = false;
					}
				}
				else {
					if (olhandoDireita) {
						if (velocidades.x > 0) {
							velocidades.x -= aceleracao * 2;
							if (velocidades.x < 0)
								velocidades.x = 0;
						}	
					}
					else {
						if (velocidades.x < 0) {
							velocidades.x += aceleracao * 2;
							if (velocidades.x > 0)
								velocidades.x = 0;
						}
					}
				}
			}

			//Queda
			if (!noAr)
				velocidades.y -= GRAVIDADE;
			//Pulo
			else {
				velocidades.y = 0;
				if (jogadorId == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
						velocidades.y -= 6;
				}
				if (jogadorId == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						velocidades.y -= 6;
				}
			}
			corpo.move(velocidades);
		}

		void Jogador::atacar() {
			if (intervaloAtaque <= 0) {
				atacando = true;
				intervaloAtaque = 500;

				if (jogadorId == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						if (olhandoDireita)
							ataque.setPosition(sf::Vector2f
							(corpo.getPosition().x + ataque.getSize().x,
								corpo.getPosition().y));
						else
							ataque.setPosition(sf::Vector2f
							(-(corpo.getPosition().x + ataque.getSize().x),
								corpo.getPosition().y));
					}
				}
				if (jogadorId == 2) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
						if (olhandoDireita)
							ataque.setPosition(sf::Vector2f
							(corpo.getPosition().x + ataque.getSize().x,
								corpo.getPosition().y));
						else
							ataque.setPosition(sf::Vector2f
							(-(corpo.getPosition().x + ataque.getSize().x),
								corpo.getPosition().y));
					}
				}
			}
		}

		void Jogador::desenhar() {
			if (vivo) {
				if (atacando)
					pGG->desenhar(&ataque);
			}
		}
		void Jogador::salvar() {}

		sf::Vector2f Jogador::getVelocidade() { return velocidades; }

		void Jogador::colidir(Entidade* e, sf::Vector2f intersecao)
		{

		}
	}
}