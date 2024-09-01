#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam):
			Personagem(pos, tam), p1(NULL), p2(NULL) {}

		Inimigo::~Inimigo() {}

		//Jogador* Inimigo::p1 = nullptr;
		//Jogador* Inimigo::p2 = nullptr;

		void Inimigo::setP1(Jogador* p)
		{
			if (p1 == nullptr)
				p1 = p;
			else
				cout << "Jogador 1 ja foi setado" << endl;
		}

		void Inimigo::setP2(Jogador* p)
		{
			if (p2 == nullptr)
				p2 = p;
			else
				cout << "Jogador 2 ja foi setado" << endl;
		}

		Jogador* Inimigo::getP1()
		{
			if (p1 != nullptr)
				return p1;
			else
				return nullptr;			
		}

		Jogador* Inimigo::getP2()
		{
			if (p2 != nullptr)
				return p2;
			else
				return nullptr;
		}

		void Inimigo::verificarJogadores() {
			if (!p1->getVivo())
				p1 = p2;
			else if (!p2->getVivo())
				p2 = p1;
		}

	}
}