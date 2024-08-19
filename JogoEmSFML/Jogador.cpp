#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		int Jogador::cont = 1;

		Jogador::Jogador(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0)):
			Personagem(pos, tam), pontuacao(0), dano(10), intervaloAtaque(500), jogadorId(cont++),
			olhandoDireita(true), atacando(false), velocidadeMax(10), aceleracao(1),
			ataque(sf::Vector2f((corpo.getSize().x * 1.5f), corpo.getSize().y)) 
		{
			vivo = true;
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
				pGG->desenhar(&corpo);
			}
		}
		void Jogador::salvar() {}

		sf::Vector2f Jogador::getVelocidade() { return velocidades; }
	}
}