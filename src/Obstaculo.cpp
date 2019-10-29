/*
  Archivo: HallDeLaFama.cpp
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-05-25
  Versión: 0.2
  Licencia: GPL
*/

#include "../include/Obstaculo.h"

Obstaculo::Obstaculo(int fila, int columna, string nombre, bool obligatorio) : Objeto(fila, columna, nombre, obligatorio)
{
}

Obstaculo::~Obstaculo()
{
  // No hay que hacer nada
}


Objeto *Obstaculo::puedesQuitarteDeEnmedio(Objeto *quienPregunta)
{
    return 0;
}
