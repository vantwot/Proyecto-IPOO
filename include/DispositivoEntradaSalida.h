/*
  Archivo: DispositivoEntradaSalida.h
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2018-03-01
  Fecha última modificación: 2019-06-01
  Versión: 0.3
  Licencia: GNU-GPL
*/

/*
  Clase: DispositivoEntradaSalida
  Atributos:
    - filaInicial, columnaInicial, ancho y alto de la ventana donde mostrar el tablero del juego
    - filaInicial, columnaInicial, ancho y alto de la ventana donde mostrar mensajes para el Usuario
  Funcionalidades:
    - Imprimir un string en una casilla concreta del tablero
    - Imprimir un string en la ventana de mensajes del Usuario
    - Leer un string de la ventana de mensajes del Usuario
    - Leer la dirección en que se quiere mover el Usuario (arriba, abajo, derecha, izquierda)
  Relaciones:
    - Ninguna. Es una clase abstracta que hay que derivar e implementar para poder acceder a dispositivos físicos concretos (terminal, qt, etc.)
*/

#ifndef DISPOSITIVOENTRADASALIDA_H
#define DISPOSITIVOENTRADASALIDA_H

#include <string>
using namespace std;


class DispositivoEntradaSalida
{
  protected:
    int filaInicialTablero;
    int columnaInicialTablero;
    int altoTablero;
    int anchoTablero;
    int filaMensajeUsuario;
    int columnaMensajeUsuario;
    int altoMensajeUsuario;
    int anchoMensajeUsuario;

  public:
    DispositivoEntradaSalida( int filaInicialTablero=2,
                              int columnaInicialTablero=2,
                              int altoTablero=8,
                              int anchoTablero=10,
                              int filaMensajeUsuario=8,
                              int columnaMensajeUsuario=20,
                              int altoMensajeUsuario=10,
                              int anchoMensajeUsuario=30
                            );
    virtual ~DispositivoEntradaSalida();
    virtual string leerMensajeUsuario(int renglon) = 0;
    virtual int leerDireccion() = 0;
    virtual void imprimirCasillaTablero(int fila, int columna, string valor) = 0;
    virtual void imprimirMensajeUsuario(string mensaje, int renglon=0) = 0;
    virtual void limpiarMensajesUsuario(int renglonInicial=0, int renglonFinal=-1) = 0;
};

#else
class DispositivoEntradaSalida; // Declaración adelantada
#endif




