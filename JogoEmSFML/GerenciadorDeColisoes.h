/* O critério que define se houve uma colisao ou nao foi retirado de um video de um ex aluno da disciplina*/
/* Link do video em questao: https://www.youtube.com/watch?v=mxZMK7ZqFtE&t=319s */

#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Obstaculo.h"
#include "Lista.h"

using namespace Entidades::Personagens;
using namespace Listas;	

namespace Gerenciadores {
	class GerenciadorDeColisoes {
	private:
		Lista<Entidades::Obstaculos::Obstaculo>* obstaculos;
		Lista<Entidades::Personagens::Personagem>* personagens;
	public:
		GerenciadorDeColisoes(Lista<Entidades::Obstaculos::Obstaculo>* obs, Lista<Entidades::Personagens::Personagem>* pers);
		~GerenciadorDeColisoes();
		void colidir();
	};
}
