#pragma once
#include "Ente.h"
#include "Estado.h"

class Menu: public Ente, public Estados::Estado {
public:
	Menu(idEstado ID_ESTADO);
	~Menu();
	void executar(sf::Time deltaTime);
	void desenhar();
};
