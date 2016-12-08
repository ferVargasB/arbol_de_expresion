#include "aplicacion.h"
#include "ui_aplicacion.h"
#include "nodo.h"
#include <QPainter>


Aplicacion::Aplicacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Aplicacion)
{
    ui->setupUi(this);
    resultadoInOrden = ""; //iniciar el resultado inorden en blanco
    direccionDeDibujo = 1; //indice el orden de como se van a dibujar los nodos
    coordenaX = 40; //inicar las coordenadas de las nodos a dibujar
    coordenaY = 70; //iniciar las coordenadas de los nodos
    coordenaX2 = coordenaX + 40; //inicia las coordenadas de los nodos que van como operandos
    coordenaY2 = coordenaY - 40; //inicia las coordenadas de los nodos que van como operandos
    lienzo = new QPixmap( ui->labelLienzo->width(), ui->labelLienzo->height()); //inicia el lienzo con la altura del label donde se va a colocar
    limpiarLienzo(); //inicia el linezo en blanco
    nodoRaiz = new Nodo('R'); //crea un nodo raiz para indicar donde empezar
    nodoRaiz->establecerNodoAlaIzquierda( new Nodo('I')); //coloca un nodo a al izquierda como prueba
    QString expresion{ "3x5-7/8+9^2-2" }; //la expresion que va a generar un arbol
    realizarArbol( expresion ); //funcion que realiza el arbol
    inOrden( nodoRaiz ); //manda a llamar al recorrido inorden con el apuntador a la raiz
    ui->labelPegarResultadoInOrden->setText( resultadoInOrden ); //pega el resultado del recorrido en un label
}

Aplicacion::~Aplicacion()
{
    delete ui;
}

void Aplicacion::realizarArbol(QString expresion)
{
    for ( auto indice = 0; indice < expresion.size(); indice++){ //itera a traves de la expresion
        if ( !expresion.at(indice).isDigit() ) //si el caracter no es un digito, entonces es un operador
            establecerNodoAlADerecha( expresion.at(indice), expresion.at(indice - 1) ); //si es un operador, lo coloca a al derecha del                                                                             //ultimo nodo
        else if ( indice == expresion.size() - 1) //si es el ultimo operando lo coloca a la derecha del ultimo nodo a la derecha
            establecerNodoAlADerecha( expresion.at(indice) );
    }
}

Nodo *Aplicacion::obtenerUltimoNodoIzquierda(Nodo *raiz) //Funcion recursiva para encontrar el Ultimo Nodo a la Izquierda
{
    if ( raiz->obtenerNodoAlaIzquierda()== nullptr ) //si la raiz ya no tiene nodo
        return raiz; //caso baso, detiene la funcion
    else
        return obtenerUltimoNodoIzquierda( raiz->obtenerNodoAlaIzquierda() ); //paso recursivo
}

Nodo *Aplicacion::obtenerUltimoNodoDerecha(Nodo *raiz) //Funcion recursiva para encontrar el Ultimo Nodo a la derecha
{
    if ( raiz->obtenerNodoAlaDerecha() == nullptr ) //si la raiz ya no tiene nodo
        return raiz; //caso baso, detiene la funcion
    else
        return obtenerUltimoNodoDerecha( raiz->obtenerNodoAlaDerecha() );  //paso recursivo
}

void Aplicacion::establecerNodoAlADerecha(QChar indice, QChar operando) //Funcion para crear nodo a al derecha
{
    Nodo *nodoActual = obtenerUltimoNodoDerecha( nodoRaiz ); //Procedimiento para crear nodo
    nodoActual->establecerNodoAlaDerecha( new Nodo(indice) ); //Crear nodo con el valor del indice
    nodoActual = obtenerUltimoNodoDerecha( nodoRaiz ); //obtiene la direccion del apuntador actual de nodo
    nodoActual->establecerNodoAlaIzquierda( new Nodo(operando) ); //Hasta aqui termina
}

void Aplicacion::establecerNodoAlADerecha(QChar indice) //Funcion para crear nodo a al derecha, es una sobrecarga
{
    Nodo *nodoActual = obtenerUltimoNodoDerecha( nodoRaiz ); //Procedimiento para crear nodo, pero si es el ultimo operador
    nodoActual->establecerNodoAlaDerecha( new Nodo(indice) ); //Procedimiento para crear nodo a la derecha
}

void Aplicacion::inOrden(Nodo* raiz) //Proceso de recorrer el arbol con Inorden
{
    if ( raiz != nullptr){ //caso base
        inOrden( raiz->obtenerNodoAlaIzquierda() ); //paso recursivo
        resultadoInOrden += " ";
        resultadoInOrden += raiz->obtenerItem();
        dibujarArbol( raiz->obtenerItem() ); //cada que lee un nodo lo dibuja
        inOrden( raiz->obtenerNodoAlaDerecha() ); //paso recursivo
    }
}


int Aplicacion::obtenerValorOperadores(QChar operador) //obtiene el valor de cada operador
{
    if ( operador == '+' | operador == '-') //menor valor
        return 1;
    else if( operador == 'x' | operador == '/') //siguiente valor
        return 2;
    else //si es potencia o raiz
        return 3;
}

void Aplicacion::limpiarLienzo(){ //Funcion para limpiear el lienzo, lo llena de color blanco
    lienzo->fill(Qt::white);
    ui->labelLienzo->setPixmap(*lienzo); //y lo establece en el label
}

void Aplicacion::dibujarArbol(QChar valor){ //Funcion para dibujar el arbol
    QPainter p(lienzo);
    p.setPen(Qt::black);
    if ( direccionDeDibujo == 1){ //Si es operando dibuja en diagonal al sector 1
        p.drawText(coordenaX, coordenaY,valor);
        coordenaX += 40; //aumenta las coordenadas
        coordenaY += 40; //de los operandos
        direccionDeDibujo = 2;
    }
    else if ( direccionDeDibujo == 2){ //Si es operador dibuja en diagonal al sector 4 con un circulo
        p.drawText(coordenaX2, coordenaY2, valor);
        p.drawEllipse(coordenaX2-5, coordenaY2-15, 30, 30);
        coordenaX2 = coordenaX + 40; //aumenta las coordenadas
        coordenaY2 = coordenaY - 40; //de los operadores
        direccionDeDibujo = 1;
    }

    ui->labelLienzo->setPixmap(*lienzo); //Y lo coloca en el label
}
