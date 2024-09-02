#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade():
		Ente(), velocidades(0, 0), noAr(true) {}

	Entidade::~Entidade() {}

	void Entidade::mover(sf::Time deltaTime)
	{
		cout << "entidade sem metodo mover proprio!!!" << endl;
	}

	void Entidade::setNoAr(bool b) { noAr = b; }

	void Entidade::executar(sf::Time deltaTime)
	{
		//cout << "entidade sem metodo executar proprio!!!" << endl;
	}

	void Entidade::gravidade(sf::Time deltaTime)
	{
		if (velocidades.y <= VEL_TERMINAL)
			velocidades.y += GRAVIDADE * deltaTime.asSeconds();
		else
			velocidades.y = VEL_TERMINAL;
	}
	int Entidade::getDano()
	{
		cout << "entidade sem parametro dano nela!!!" << endl;
		return 0;
	}
}

