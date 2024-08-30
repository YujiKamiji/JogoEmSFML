#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		int Jogador::cont = 1;

		Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam):
			Personagem(pos, tam), pontuacao(0), intervaloAtaque(500), 
			jogadorId(cont++), olhandoDireita(true),
			ataque(new AtaqueCorte(sf::Vector2f(0,0), sf::Vector2f(50,50))),
			id(JOGADOR)
		{
			vidas = VIDAMAX;
			dano = 100;
			velocidadeMax = 10;
			aceleracao = 50;
			ataque->setAmigavel(true);
		}
		Jogador::~Jogador() 
		{ 
			delete ataque; 
			ataque = nullptr;
		}

		void Jogador::executar(sf::Time deltaTime) {
			if (vidas <= 0)
				vivo = false;
			mover(deltaTime);

			//cout << "vidas:" << vidas << endl;
			if(olhandoDireita)
				ataque->Posicionar(sf::Vector2f(corpo.getPosition().x + 50, corpo.getPosition().y));
			else
				ataque->Posicionar(sf::Vector2f(corpo.getPosition().x - 50, corpo.getPosition().y));
			atacar(deltaTime);
			
			if (intervaloAtaque > 0) //esta no intervalo de ataque
			{
				intervaloAtaque -= deltaTime.asMilliseconds();
				atacando = false;
			}
			//cout << "vidas: " << vidas << endl;	
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

			//Pulo
			if(!noAr) {
				velocidades.y = 0;
				if (jogadorId == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
						velocidades.y -= 15;
				}
				if (jogadorId == 2) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						velocidades.y -= 15;
				}
				noAr = true;
			}
			
			gravidade(deltaTime);
			corpo.move(velocidades);
			
		}

		void Jogador::atacar(sf::Time deltaTime) {
			if (intervaloAtaque <= 0) {
				

				if (jogadorId == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						if (olhandoDireita) {
							atacando = true;
							
							ataque->Posicionar(sf::Vector2f(corpo.getPosition().x + 50, corpo.getPosition().y));							
							ataque->setAtivo(true);
							ataque->setOlhandoDireita(true);
							ataque->executar(deltaTime);
							
							intervaloAtaque = 500;
						}
						else {
							atacando = true;
							
							ataque->Posicionar(sf::Vector2f(corpo.getPosition().x -50, corpo.getPosition().y)); 							 
							ataque->setAtivo(true);
							ataque->setOlhandoDireita(false);
							ataque->executar(deltaTime); 
							
							intervaloAtaque = 500;
						}
					}
				}
				if (jogadorId == 2) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
						if (olhandoDireita) {
							atacando = true;
							
							ataque->Posicionar(sf::Vector2f(corpo.getPosition().x + 50, corpo.getPosition().y));
							ataque->setAtivo(true);
							ataque->setOlhandoDireita(true);
							ataque->executar(deltaTime);

							intervaloAtaque = 500;
						}
						else {
							atacando = true;
							
							ataque->Posicionar(sf::Vector2f(corpo.getPosition().x - 50, corpo.getPosition().y));
							ataque->setAtivo(true);
							ataque->setOlhandoDireita(false);
							ataque->executar(deltaTime);

							intervaloAtaque = 500;
						}

					}
				}
			}
		}

		void Jogador::desenhar() {
			if (vivo) {
				pGG->desenhar(&corpo); 
			}
			
		}
		void Jogador::salvar() {}

		sf::Vector2f Jogador::getVelocidade() { return velocidades; }

		AtaqueCorte* Jogador::getAtaque()
		{
			if(ataque)
				return ataque;
			cout << "ponteiro nulo" << endl;
			return nullptr;
		}

		ID Jogador::getId() const
		{
			return ID(id);
		}

		void Jogador::colidir(Entidade* e, sf::Vector2f intersecao)
		{
			sf::Vector2f posOutro = e->getPosicao();

			

			
			if (e->getId() != PROJETIL)
			{
				//colisao em x
				if (intersecao.x > intersecao.y)
				{
					if (getPosicao().x < posOutro.x)
						corpo.move(intersecao.x, 0);
					else
						corpo.move(-intersecao.x, 0);
					velocidades.x = 0;
				}
				//colisao em y
				else 
				{
					if (getPosicao().y < posOutro.y) 
						corpo.move(0, intersecao.y);
					else
						corpo.move(0, -intersecao.y); 
					velocidades.y = 0; 
					if (e->getId() == CHAO || e->getId() == PLATAFORMA || e->getId() == CAIXOTE || e->getId() == ESPINHOS)
					{
						if (getPosicao().y < posOutro.y)
							noAr = false;
					}
																						
						
				}

			}
			
			if (e->getId() == CURA)
			{
				recuperarVida(static_cast<Entidades::Consumiveis::Cura*>(e)->getCura()); 
			}

			if (e->getId() == ESPINHOS)
			{
				receberDano(e->getDano());
				cout << "tomou dano dos espinhos" << endl;
			}

			if (e->getId() == NINJA_GARRAS || e->getId() == SHOGUN) 
			{
				receberDano(e->getDano());
				cout << "tomou dano do ninja garras" << endl;
			}

			if (e->getId() == PROJETIL)
			{
				if (static_cast<Projetil*>(e)->getAmigavel() == false)
				{
					receberDano(e->getDano()); 
					cout << "tomou dano da shuriken" << endl; 
				}
				
			}
				

		}
		void Jogador::recuperarVida(int Cura)
		{
			//cout << "vida antes: " << vidas << endl;
			if (vidas < VIDAMAX)
				vidas += Cura;
			else
				vidas = VIDAMAX;
			//cout << "recuperou vida, vida agr: " << vidas << endl;
			
		}
	}
}