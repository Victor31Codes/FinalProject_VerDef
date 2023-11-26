#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template <class T>
struct nodo {
    T Dato;
    nodo<T>* sig;
};

template <class T>
class Lista {
private:
    nodo<T>* cab;
    nodo<T>* fin;
    int tam;

public:
    Lista() {
        cab = NULL;
        tam = 0;
        fin = NULL;
    }
    int getTam() { return tam; }
    bool lista_vacia() { return cab == NULL; }
    void insertar_pos(T dato, int pos);
    void insertar_final(T dato);
    void insertar_inicio(T dato);
    bool borrar(int pos);
    T buscar(int pos);
    bool modificar(T infoNueva, int pos);
    nodo<T>* obtener_cabecera() {return cab;}
};

template <class T>
void Lista<T>::insertar_pos(T dato, int pos) {
    if (pos < 1 || pos > tam + 1) {
        std::cout << "Posición inválida" << std::endl;
        return;
    }

    nodo<T>* nuevo = new nodo<T>;
    nuevo->Dato = dato;
    nuevo->sig = NULL;

    if (pos == 1) {
        nuevo->sig = cab;
        cab = nuevo;
        if (tam == 0) {
            fin = nuevo;
        }
    } else if (pos == tam + 1) {
        fin->sig = nuevo;
        fin = nuevo;
    } else {
        nodo<T>* actual = cab;
        for (int i = 1; i < pos - 1; i++) {
            actual = actual->sig;
        }
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
    }

    tam++;
}

template <class T>
void Lista<T>::insertar_final(T dato) {
    insertar_pos(dato, tam + 1);
}

template <class T>
void Lista<T>::insertar_inicio(T dato) {
    insertar_pos(dato, 1);
}
template <class T>
bool Lista<T>::borrar(int pos) {
    if (pos < 1 || pos > tam || lista_vacia()) {
        std::cout << "Posición inválida o lista vacía" << std::endl;
        return false;
    }

    nodo<T>* temp;
    if (pos == 1) {
        temp = cab;
        cab = cab->sig;
        delete temp;
        if (tam == 1) {
            fin = NULL;
        }
    } else {
        nodo<T>* actual = cab;
        for (int i = 1; i < pos - 1; i++) {
            actual = actual->sig;
        }
        temp = actual->sig;
        actual->sig = temp->sig;
        delete temp;
        if (pos == tam) {
            fin = actual;
        }
    }

    tam--;
    return true;
}

template <class T>
T Lista<T>::buscar(int pos) {
    if (pos < 1 || pos > tam || lista_vacia()) {
        std::cerr << "Posición inválida o lista vacía" << std::endl;
        //throw std::out_of_range("Posición inválida o lista vacía");
    }

    nodo<T>* actual = cab;
    for (int i = 1; i < pos; i++) {
        actual = actual->sig;
    }
    return actual->Dato;
}

template <class T>
bool Lista<T>::modificar(T infoNueva, int pos) {
    if (pos < 1 || pos > tam || lista_vacia()) {
        std::cout << "Posición inválida o lista vacía" << std::endl;
        return false;
    }

    nodo<T>* actual = cab;
    for (int i = 1; i < pos; i++) {
        actual = actual->sig;
    }
    actual->Dato = infoNueva;
    return true;
}

#endif


