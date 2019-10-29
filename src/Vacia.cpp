/*
  Archivo: Vacia.cpp
  Autor: 
  Fecha creación: 2019-08-06
  Fecha última modificación: 2019-08-06
  Versión: 0.2
  Licencia: GPL
*/

#include "../include/Vacia.h"

Vacia::Vacia(int fila, int columna, string nombre, bool obligatorio) : 
Objeto(fila,columna,nombre,obligatorio)
{
}

Vacia::~Vacia()
{
  // No hay que hacer nada
}

Objeto *Vacia::puedesQuitarteDeEnmedio(Objeto *quienPregunta)
{
    return this;
}

