#ifndef APLICACION_H
#define APLICACION_H

#include <QMainWindow>
#include <QRegularExpression>
#include "nodo.h"

namespace Ui {
class Aplicacion;
}

class Aplicacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Aplicacion(QWidget *parent = 0);
    ~Aplicacion();

private:
    Ui::Aplicacion *ui;
    Nodo *nodoRaiz;
    QPixmap *lienzo;
    int numeroDeOperadores;
    int coordenaX;
    int coordenaY;
    int coordenaX2;
    int coordenaY2;
    int direccionDeDibujo;
    QString resultadoInOrden;

    //Datos para realizar la operacion
    double resultadoFinal;

    //Funciones para realizar la operacion

    //Funcion que da pauta a crear el arbol
    void realizarArbol(QString expresion);


    //Funciones para crear nodos a la izquierda o derecha y ler el arbol
    Nodo *obtenerUltimoNodoIzquierda(Nodo *raiz);
    Nodo* obtenerUltimoNodoDerecha(Nodo *raiz);
    void establecerNodoAlADerecha(QChar indice, QChar operando);
    void establecerNodoAlADerecha(QChar indice);
    //Recorridos
    void inOrden(Nodo *raiz);


    //Funciones para realizar la operacion
    int obtenerValorOperadores(QChar operador);

    //Funciones para dibujar
    void limpiarLienzo();
    void dibujarArbol(QChar valor);
};

#endif // APLICACION_H
