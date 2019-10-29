/*
  Archivo: DispositivoEntradaSalida.cpp
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2018-03-01
  Fecha última modificación: 2019-05-25
  Versión: 0.2
  Licencia: GNU-GPL
*/


#include "../include/DispositivoEntradaSalida.h"

DispositivoEntradaSalida::DispositivoEntradaSalida(int filaInicialTablero,
                                                   int columnaInicialTablero,
                                                   int altoTablero,
                                                   int anchoTablero,
                                                   int filaMensajeUsuario,
                                                   int columnaMensajeUsuario,
                                                   int altoMensajeUsuario,
                                                   int anchoMensajeUsuario
                                                  )
  : filaInicialTablero(filaInicialTablero),
    columnaInicialTablero(columnaInicialTablero),
    altoTablero(altoTablero),
    anchoTablero(anchoTablero),
    filaMensajeUsuario(filaMensajeUsuario),
    columnaMensajeUsuario(columnaMensajeUsuario),
    altoMensajeUsuario(altoMensajeUsuario),
    anchoMensajeUsuario(anchoMensajeUsuario)
{
  // No hay que hacer nada
}


DispositivoEntradaSalida::~DispositivoEntradaSalida()
{
}





