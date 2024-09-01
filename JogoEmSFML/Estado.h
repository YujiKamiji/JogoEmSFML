#pragma once
#include "stdafx.h"

namespace Gerenciadores
{
	class GerenciadorDeEstados;
}

namespace Estados
{
    class Estado
    {
    protected:
        idEstado id_estado;
        Gerenciadores::GerenciadorDeEstados* pGE;
    public:
        Estado(idEstado ID);
        Estado();
        virtual ~Estado();

        idEstado getIdEstado() const;
        virtual void executar() = 0; // Método virtual puro para ser implementado nas subclasses

    };
}
