#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		int Jogador::cont = 1;

		Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam):
			Personagem(pos, tam), pontuacao(0), intervaloAtaque(500), 
			jogadorId(cont++), olhandoDireita(true),
			ataque()
		{
			vidas = 100;
			dano = 5;
			velocidadeMax = 10;
			aceleracao = 50;
		}
		Jogador::~Jogador() {}

		void Jogador::executar(sf::Time deltaTime) {
			if (vidas <= 0)
				vivo = false;
			mover(deltaTime);
			atacar(deltaTime);
			desenhar();
		}

		void Jogador::mover(sf::Time deltaTime) {
			//Andar
			if (jogadorId == 1) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					if (velocidades.x <= velocidadeMax)
						velocidades.x += (aceleracao * deltaTime.asSeconds());
					if (!olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = true;
					}
					
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					if (velocidades.x >= -velocidadeMax)
						velocidades.x -= (aceleracao * deltaTime.asSeconds());
					if (olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = false;
					}
				}
				else {
					if (olhandoDireita) {
						if (velocidades.x > 0)
							velocidades.x -= ((aceleracao * 2.5) * deltaTime.asSeconds());
						else
							velocidades.x = 0;
					}
					else {
						if (velocidades.x < 0)
							velocidades.x += ((aceleracao * 2.5) * deltaTime.asSeconds());
						else
							velocidades.x = 0;
					}
				}
					
			}

			if (jogadorId == 2) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (velocidades.x <= velocidadeMax)
						velocidades.x += aceleracao * deltaTime.asSeconds();
					if (!olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = true;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (velocidades.x >= -velocidadeMax)
						velocidades.x -= aceleracao * deltaTime.asSeconds();
					if (olhandoDireita)
					{
						//corpo.setTexture(pGG->load_textures(""));
						olhandoDireita = false;
					}
				}
				else {
					if (olhandoDireita) {
						if (velocidades.x > 0) {
							velocidades.x -= ((aceleracao * 2) * deltaTime.asSeconds());
							if (velocidades.x < 0)
								velocidades.x = 0;
						}	
					}
					else {
						if (velocidades.x < 0) {
							velocidades.x += ((aceleracao * 2) * deltaTime.asSeconds());
							if (velocidades.x > 0)
								velocidades.x = 0;
						}
					}
				}
			}

			//Força normal
			if (!noAr)
				velocidades.y -= GRAVIDADE * deltaTime.asSeconds();
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

		void Jogador::atacar(sf::Time deltaTime) {
			if (intervaloAtaque <= 0) {
				atacando = true;
				intervaloAtaque = 500;

				if (jogadorId == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						if (olhandoDireita) {
							atacando = true;
							ataque->Posicionar(sf::Vector2f
							(corpo.getPosition().x + 4, corpo.getPosition().y));
							ataque->setAmigavel(true);
							ataque->setAtivo(true);
							ataque->executar();
						}
						else
							atacando = true;
							ataque->Posicionar(sf::Vector2f
							(corpo.getPosition().x - 4, corpo.getPosition().y));
							ataque->setAmigavel(true);
							ataque->setAtivo(true);
							ataque->executar();
					}
				}
				if (jogadorId == 2) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
						if (olhandoDireita) {
							atacando = true;
							ataque->Posicionar(sf::Vector2f
							(corpo.getPosition().x + 4, corpo.getPosition().y));
							ataque->setAmigavel(true);
							ataque->setAtivo(true);
							ataque->executar();
						}
						else
							atacando = true;
							ataque->Posicionar(sf::Vector2f
							(corpo.getPosition().x - 4, corpo.getPosition().y));
							ataque->setAmigavel(true);
							ataque->setAtivo(true);
							ataque->executar();
					}
				}
			}
		}

		void Jogador::desenhar() {
			if (vivo) {
				if (atacando)
					ataque->desenhar();
			}
			pGG->desenhar(&corpo);
		}
		void Jogador::salvar() {}

		sf::Vector2f Jogador::getVelocidade() { return velocidades; }

		void Jogador::colidir(Entidade* e, sf::Vector2f intersecao)
		{

		}
	}
}