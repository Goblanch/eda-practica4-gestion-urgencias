#pragma once
#include <memory>

template <typename T>
class Nodo {
private:
    T dato;
    std::shared_ptr<Nodo<T>> sig;

public:
    Nodo() : dato(), sig(nullptr) {}

    Nodo(const T& dato) : dato(dato), sig(nullptr) {}

    Nodo(const T& dato, std::shared_ptr<Nodo<T>> sig) : dato(dato), sig(sig) {}

    const T& getDato() const {
        return dato;
    }

    std::shared_ptr<Nodo<T>> getSig() const {
        return sig;
    }

    void setSig(std::shared_ptr<Nodo<T>> siguiente) {
        sig = siguiente;
    }
};