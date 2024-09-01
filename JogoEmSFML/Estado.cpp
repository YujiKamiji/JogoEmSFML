#include "Estado.h"
#include "GerenciadorDeEstados.h"

namespace Estados
{
    Estado::Estado(idEstado ID) :
        id_estado(ID), pGE(pGE->getInstancia())
    {
    }

    Estado::Estado()
	{
		pGE = pGE->getInstancia();
    }

    
    Estado::~Estado()
    {
    }

    idEstado Estado::getIdEstado() const
    {
        return idEstado(id_estado);
    }
    void Estado::executarEstado()
    {
    }
}
