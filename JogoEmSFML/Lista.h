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
			Elemento<TE>*  getProx() { return pProx; }
			void setInfo(TE* i) { info = i; }
			void setProx(Elemento<TE>* p) { pProx = p; }
		};

		template<class TE>
		class Iterador {
		private:
			Elemento<TE>* atual;

		public:
			Iterador(Elemento<TE>* a = nullptr):
			atual(a) {}
			~Iterador() {}

			Iterador& operator++() {
				pAtual = atual->getProx();
				return *this;
			}
			Iterador operator++(int) {
				Iterator temp = *this;
				++(*this);
				return temp;
			}
			bool operator==(const Elemento<TE>* e) const { return atual == e; }
			bool operator!=(const Elemento<TE>* e) const { return !(atual == e); }
			void operator=(const Elemento<TE>* e) { atual = e; }
			TE* operator*() { return atual->getInfo(); }
			const Elemento<TE>* getAtual() const { return atual; }
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

		Iterador<TL> inicio() { return Iterador<TL>(pPrimeiro) };
		Iterador<TL> fim() { return Iterador<TL>(pUltimo->getProx) }
	};
}
