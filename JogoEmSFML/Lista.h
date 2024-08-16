#pragma once

#include "stdafx.h"

namespace Listas {
	template<class TL>
	class Lista {
	public:
		template<class TE>
		class Elemento {
		private:
			Elemento<TE>* pProx;
			TE* info;

		public:
			Elemento():
				pProx(NULL), info(NULL) {}
			~Elemento() {
				if (info)
					delete info;
				info = NULL;
			}
			TE* getInfo() { return info; }
			Elemento<TE>*  getProx() { return prox; }
			void setInfo(TE* i) { info = i; }
			void setProx(Elemento<TE>* p) { pProx = p; }
		};

	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;

	public:
		Lista():
		pPrimeiro(NULL), pUltimo(NULL) {}
		~Lista() {
			Elemento<TL>* aux = NULL;
			while (pPrimeiro) {
				aux = pPrimeiro;
				pPrimeiro = pPrimeiro->getProx();
				if (aux)
					delete aux;
			}
			pPrimeiro = nullptr;
		}

		void inserir(TL* e) {
			if (e) {
				Elemento<TL>* aux = new Elemento<TL>();
				aux->setInfo(e);
				aux->setProx(pPrimeiro);
				if (pPrimeiro == NULL)
					pUltimo = aux;
				pPrimeiro = aux;
			}
		}
	};
}
