#pragma once
#include <memory>

template <typename T>
class Nodo {
private:
    T dato;
    std::shared_ptr<Nodo<T>> sig;

public:
    const T& getDato() const {
        return dato;
    }
};
