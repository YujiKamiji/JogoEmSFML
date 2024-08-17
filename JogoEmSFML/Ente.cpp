#include "Ente.h"

Gerenciador_Grafico* Ente::pGG = Gerenciador_Grafico::getInstancia();
int Ente::cont = 0;

Ente::Ente():
id(cont++), textura(NULL) {}

Ente::~Ente() {}

const int Ente::getId() { return id; }