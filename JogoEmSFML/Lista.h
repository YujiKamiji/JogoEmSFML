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
			Elemento() :
				pProx(NULL), info(NULL) {}
			~Elemento() {
				if (info)
					delete info;
				info = NULL;
			}
			TE* getInfo() { return info; }
			Elemento<TE>* getProx() { return pProx; }
			void setInfo(TE* i) { info = i; }
			void setProx(Elemento<TE>* p) { pProx = p; }
		};

		template<class TE>
		class Iterador {
		private:
			Elemento<TE>* atual;

		public:
			Iterador(Elemento<TE>* a = nullptr) :
				atual(a) {}
			~Iterador() {}

			Iterador& operator++() {
				atual = atual->getProx();
				return *this;
			}
			Iterador operator++(int) {
				Iterador<TE> temp = *this;
				++(*this);
				return temp;
			}
			bool operator==(const Elemento<TE>* e) const { return atual == e; }
			bool operator==(const Iterador<TE>& i) const { return atual == i.atual; }
			bool operator!=(const Elemento<TE>* e) const { return !(atual == e); }
			bool operator!=(const Iterador<TE>& i) const { return !(atual == i.atual); }	
			void operator=(const Elemento<TE>* e) { atual = e; }
			TE* operator*() { return atual->getInfo(); }
			const Elemento<TE>* getAtual() const { return atual; }
		};

	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;

	public:
		Lista() :
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

		void remover(TL* e) {
			if (!e || !pPrimeiro) return;

			Elemento<TL>* atual = pPrimeiro;
			Elemento<TL>* anterior = nullptr;

			while (atual) {
				if (atual->getInfo() == e) {
					if (anterior) {
						anterior->setProx(atual->getProx());
					}
					else {
						pPrimeiro = atual->getProx();
					}

					if (atual == pUltimo) {
						pUltimo = anterior;
					}

					delete atual;
					return;
				}

				anterior = atual;
				atual = atual->getProx();
			}
		}

		void inserirNoFinal(TL* e) {
			if (e) {
				Elemento<TL>* aux = new Elemento<TL>();
				aux->setInfo(e);
				aux->setProx(NULL);

				if (pUltimo) {
					pUltimo->setProx(aux);
				}
				else {
					pPrimeiro = aux;
				}

				pUltimo = aux;
			}
		}

		Iterador<TL> inicio() { return Iterador<TL>(pPrimeiro); }
		Iterador<TL> fim() { return Iterador<TL>(NULL); }
	};
}
