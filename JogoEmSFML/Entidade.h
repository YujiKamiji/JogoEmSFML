#pragma once
#include "stdafx.h"
#include "Ente.h"

namespace Entidades {
	class Entidade: public Ente {
	protected:
		int x;
		int y;

	public:
		Entidade();
		virtual ~Entidade();
		virtual void executar() = 0;
		virtual void salvar() = 0;
	};
}
