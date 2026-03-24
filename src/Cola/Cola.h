#pragma once
#include <memory>
#include <stdexcept>
#include <iostream>
#include "Cola/Nodo.h"

template <typename T>
class Cola {
private:
    std::shared_ptr<Nodo<T>> primero;
    std::shared_ptr<Nodo<T>> ultimo;
    std::size_t numElementos;

    void copy(const Cola<T>& other) {
        primero = nullptr;
        ultimo = nullptr;
        numElementos = 0;

        std::shared_ptr<Nodo<T>> actual = other.primero;
        while (actual != nullptr) {
            push(actual->getDato());
            actual = actual->getSig();
        }
    }

public:
    Cola() : primero(nullptr), ultimo(nullptr), numElementos(0) {}

    Cola(const Cola<T>& other) : primero(nullptr), ultimo(nullptr), numElementos(0) {
        copy(other);
    }

    Cola<T>& operator=(const Cola<T>& other) {
        if (this != &other) {
            copy(other);
        }
        return *this;
    }

    std::shared_ptr<Nodo<T>>& getPrimero() const {
        return primero;
    }

    std::shared_ptr<Nodo<T>>& getUltimo() const {
        return ultimo;
    }

    void push(const T& value) {
        std::shared_ptr<Nodo<T>> nuevoNodo = std::make_shared<Nodo<T>>(value);

        if (empty()) {
            primero = ultimo = nuevoNodo;
        } else {
            ultimo->setSig(nuevoNodo);
            ultimo = nuevoNodo;
        }

        ++numElementos;
    }

    void push_front(const T& value) {
        std::shared_ptr<Nodo<T>> nuevoNodo = std::make_shared<Nodo<T>>(value);

        if (empty()) {
            primero = ultimo = nuevoNodo;
        } else {
            nuevoNodo->setSig(primero);
            primero = nuevoNodo;
        }

        ++numElementos;
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("La cola está vacía.");
        }

        primero = primero->getSig();
        --numElementos;

        if (primero == nullptr) {
            ultimo = nullptr;
        }
    }

    bool exists(const T& dato) const {
        std::shared_ptr<Nodo<T>> actual = primero;

        while (actual != nullptr) {
            if (actual->getDato() == dato) {
                return true;
            }
            actual = actual->getSig();
        }

        return false;
    }

    bool remove(const T& valor) {
        if (empty()) {
            return false;
        }

        // Si es el primero...
        if (primero->getDato() == valor) {
            pop();
            return true;
        }

        std::shared_ptr<Nodo<T>> anterior = primero;
        std::shared_ptr<Nodo<T>> actual = primero->getSig();

        while (actual != nullptr) {
            if (actual->getDato() == valor) {
                anterior->setSig(actual->getSig());

                if (actual == ultimo) {
                    ultimo = anterior;
                }

                --numElementos;
                return true;
            }

            anterior = actual;
            actual = actual->getSig();
        }

        return false;
    }

    const T& front() const {
        if (empty()) {
            throw std::underflow_error("La cola está vacía.");
        }

        return primero->getDato();
    }

    bool empty() const {
        return primero == nullptr;
    }

    std::size_t size() const {
        return numElementos;
    }

    void print() const {
        std::shared_ptr<Nodo<T>> actual = primero;

        while (actual != nullptr) {
            std::cout << actual->getDato() << " ";
            actual = actual->getSig();
        }

        std::cout << std::endl;
    }
};