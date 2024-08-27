#include "Jogo.h"

Jogo::Jogo() {
	fase1 = new Floresta();
	executar();
}

Jogo::~Jogo() {}

void Jogo::executar() { fase1->executar(); }