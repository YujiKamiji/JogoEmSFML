#pragma once
#include "Ente.h"

class Menu: public Ente {
public:
	Menu();
	~Menu();
	void executar(sf::Time deltaTime);
	void desenhar();
};
