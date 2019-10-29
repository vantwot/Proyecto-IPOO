/*
  Programa: Objeto.cpp
  Autor: 
  Fecha creación: 2019-08-06
  Fecha última modificación: 2019-08-06
  Licencia: GNU-GPL
*/

#include "../include/Objeto.h"

Objeto::Objeto(int fila, int columna, string nombre, bool obligatorio) : fila(fila), columna(columna), nombre(nombre), obligatorio(obligatorio)
{
  // No hay que hacer nada
}


Objeto::~Objeto()
{
  // No hay que hacer nada
}


string Objeto::comoTeLlamas() const
{
  return nombre;
}


bool Objeto::esObligatorioParaSalir() const
{
  return obligatorio;
}


int Objeto::get_fila() const
{
  return fila;
}


int Objeto::get_columna() const
{
  return columna;
}


void Objeto::incrementaCoordenadas(int incrementoFila, int incrementoColumna)
{
  fila += incrementoFila;
  columna += incrementoColumna;
}


Objeto *Objeto::puedesMoverteEnDireccion(int incrementoFila, int incrementoColumna)
{
  return 0;
}


Objeto *Objeto::cogeObjeto(Objeto *objetoACoger)
{
  return 0;
}


bool Objeto::tienesObjeto(Objeto *objetoRequerido)
{
  return false;
}


string Objeto::hacerPregunta(string pregunta, bool esperarRespuesta)
{
  return "";
}


int Objeto::aDondeQuieresMoverte()
{
  return -1;
}
