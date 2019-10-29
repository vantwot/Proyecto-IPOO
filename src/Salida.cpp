/*
  Archivo: Salida.cpp
  Autor:
  Fecha creación: 2018-08-06
  Fecha última modificación: 2019-08-06
  Versión: 0.2
  Licencia: GPL
*/

#include "../include/Salida.h"

Salida::Salida(int fila, int columna, string nombre, bool obligatorio) : Objeto(fila, columna, nombre, obligatorio)
{
}

Salida::~Salida()
{
  // No hay que hacer nada
}

Objeto *Salida::puedesQuitarteDeEnmedio(Objeto *quienPregunta)
{
    return this;
}
