/* O critério que define se houve uma colisao ou nao foi retirado de um video de um ex aluno da disciplina*/
/* Link do video em questao: https://www.youtube.com/watch?v=mxZMK7ZqFtE&t=319s */

#pragma once
#include "Plataforma.h"
#include "stdafx.h"
#include "Personagem.h"
#include "Obstaculo.h"
#include "Consumiveis.h"
#include "Lista.h"
#include "Entidade.h"

using namespace Entidades::Personagens;

using namespace Listas;	

namespace Gerenciadores {
	class GerenciadorDeColisoes {
	private:
	
		Lista<Entidades::Obstaculos::Obstaculo>* obstaculos;
		Lista<Entidades::Personagens::Personagem>* personagens;
		Lista<Entidades::Projetil>* projeteis;
		Lista<Entidades::Consumiveis::Consumivel>* consumiveis;
	public:
		GerenciadorDeColisoes(Lista<Entidades::Obstaculos::Obstaculo>* obs, Lista<Entidades::Personagens::Personagem>* pers, Lista<Entidades::Projetil>* proj, Lista<Entidades::Consumiveis::Consumivel>* consu);
		~GerenciadorDeColisoes();
		sf::Vector2f criterioDeColisao(Entidades::Entidade* e1, Entidades::Entidade* e2);
		void colidir();
		void plataformasMoveis(Entidades::Obstaculos::Plataforma * plat);
	};
}
