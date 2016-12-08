#include "nodo.h"

Nodo::Nodo(QChar valor)
{
    nodoIzquierdo = nullptr;
    nodoDerecho = nullptr;
    item = valor;
}

void Nodo::establecerNodoRaiz(QChar valor)
{
    item = valor;
}

void Nodo::establecerNodoAlaIzquierda(Nodo *ptr)
{
    nodoIzquierdo = ptr;
}

void Nodo::establecerNodoAlaDerecha(Nodo *ptr)
{
    nodoDerecho = ptr;
}

Nodo *Nodo::obtenerNodoAlaDerecha()
{
    return nodoDerecho;
}

Nodo *Nodo::obtenerNodoAlaIzquierda()
{
    return nodoIzquierdo;
}

QChar Nodo::obtenerItem()
{
    return item;
}
