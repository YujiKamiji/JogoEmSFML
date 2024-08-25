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
                pProx(nullptr), info(nullptr) {}
            ~Elemento() {
                delete info;
                info = nullptr;
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
                if (atual)
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
            void operator=(const Iterador<TE>& i) { atual = i.atual; }

            TE* operator*() { return atual->getInfo(); }
            const Elemento<TE>* getAtual() const { return atual; }
        };

    private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;

    public:
        Lista() :
            pPrimeiro(nullptr), pUltimo(nullptr) {}
        ~Lista() {
            Elemento<TL>* aux = nullptr;
            while (pPrimeiro) {
                aux = pPrimeiro;
                pPrimeiro = pPrimeiro->getProx();
                delete aux;
            }
            pPrimeiro = nullptr;
            pUltimo = nullptr;
        }

        void inserir(TL* e) {
            if (e) {
                Elemento<TL>* aux = new Elemento<TL>();
                aux->setInfo(e);
                aux->setProx(pPrimeiro);
                if (pPrimeiro == nullptr)
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
                aux->setProx(nullptr);

                if (pUltimo) {
                    pUltimo->setProx(aux);
                }
                else {
                    pPrimeiro = aux;
                }

                pUltimo = aux;
            }
        }

        int getTamanho() const {
            int tam = 0;
            Elemento<TL>* aux = pPrimeiro;
            while (aux) {
                tam++;
                aux = aux->getProx();
            }
            return tam;
        }

        Iterador<TL> inicio() const { return Iterador<TL>(pPrimeiro); }
        Iterador<TL> fim() const { return Iterador<TL>(nullptr); }
    };
}
