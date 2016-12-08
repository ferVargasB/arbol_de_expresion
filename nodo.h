#ifndef NODO_H
#define NODO_H
#include <QString>

class Nodo
{
public:
    Nodo(QChar valor);
    void establecerNodoRaiz(QChar valor);//establece el item
    void establecerNodoAlaIzquierda(Nodo *ptr);//coloca el apuntador del parametro
    void establecerNodoAlaDerecha(Nodo *ptr);//coloca el apuntador del parametro
    Nodo* obtenerNodoAlaDerecha();//regresa un aputador del nodo solicitado
    Nodo* obtenerNodoAlaIzquierda();//regresa un aputador del nodo solicitado
    QChar obtenerItem();
private:
    QChar item; //valor para identificar el nodo
    Nodo *nodoIzquierdo;
    Nodo *nodoDerecho;
};
#endif // NODO_H
