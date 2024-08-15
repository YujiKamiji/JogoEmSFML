#include "Ente.h"

Gerenciador_Grafico* Ente::pGG = Gerenciador_Grafico::getInstancia();

Ente::Ente():
id(0) {}

Ente::~Ente() {}