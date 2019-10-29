/*
  Archivo: DispositivoTerminal.h
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2018-03-01
  Fecha última modificación: 2019-06-01
  Versión: 0.3
  Licencia: GNU-GPL
*/

/*
  Clase: DispositivoTerminal
  Atributos:
    - estado interno del terminal en modo ANSI
    - número de letras visibles de un string impreso en una casilla
  Funcionalidades:
    - Imprimir un string en una casilla concreta del tablero
    - Imprimir un string en la ventana de mensajes del Usuario
    - Leer un string de la ventana de mensajes del Usuario
    - Leer las flechas (arriba, abajo, derecha, izquierda) pulsadas por el Usuario
    (Para hacer todo esto, usa códigos de escape ANSI en el terminal, que están documentados aquí: https://en.wikipedia.org/wiki/ANSI_escape_code, por
    si alguien quiere saber más sobre ello).
  Relaciones:
    - es un DispositivoDeEntradaSalida.
*/

#ifndef DISPOSITIVOTERMINAL_H
#define DISPOSITIVOTERMINAL_H

#include "DispositivoEntradaSalida.h"
#include <termios.h>    // struct termios, tcgetattr(), tcsetattr()
#include <stdio.h>      // perror(), stderr, stdin, fileno()
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;


class DispositivoTerminal : public DispositivoEntradaSalida
{
  protected:
    struct termios terminal_salvado;
    
  public:
    /**
        Construye un DispositivoTerminal, programándolo sin buffer y sin eco en pantalla.
        Antes de ello, salva el estado del terminal
        El objetivo es imprimir una cuadrìcula
    */
    DispositivoTerminal(
                         int filaInicialTablero,
                         int columnaInicialTablero,
                         int altoTablero,
                         int anchoTablero,
                         int filaMensajeUsuario,
                         int columnaMensajeUsuario,
                         int altoMensajeUsuario,
                         int anchoMensajeUsuario
                       );
    /**
        Restaura el terminal a su estado inicial.
    */
    virtual ~DispositivoTerminal();
    /**
        Lee el un mensaje del Usuario, del dispositivo fìsico (tìpicamente el teclado).
    */
    virtual string leerMensajeUsuario(int renglon);
    /**
        Lee una única tecla del teclado (espera hasta que haya alguna, de modo que esta función es bloqueante), y la retorna con el siguiente convenio
          return 0 si es la flecha hacia ARRIBA    ( 0x1b, 0x5b, 0x41 )
          return 1 si es la flecha hacia ABAJO     ( 0x1b, 0x5b, 0x42 )
          return 2 si es la flecha hacia DERECHA   ( 0x1b, 0x5b, 0x43 )
          return 3 si es la flecha hacia IZQUIERDA ( 0x1b, 0x5b, 0x44 )
          return 4 si es la tecla de FIN (END)     ( 0x1b, 0x5b, 0x46 )
          return -1 si es cualquier otra
    */
    virtual int leerDireccion();
    /**
        Imprime una única casilla del tablero dada por sus coordenadas (fila, columna) con un valor dado.
    */
    virtual void imprimirCasillaTablero(int fila, int columna, string valor);
    /**
     * @brief imprime un mensaje en la ventana del Usuario
     * @param mensaje
     */
    virtual void imprimirMensajeUsuario(string mensaje, int renglon=0);
    /**
     * @brief limpia el área dedicada a los mensaje de usuario, dejándola en blanco.
     * @param renglonInicial
     */
    virtual void limpiarMensajesUsuario(int renglonInicial, int renglonFinal);

  protected:
    virtual void imprimirSimbolo(int fila, int columna, string mensaje);
};

#else
class DispositivoTerminal; // Declaración adelantada
#endif




