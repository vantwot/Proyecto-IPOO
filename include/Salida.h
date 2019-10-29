/*
  Archivo: Salida.h
  Autor: jaime.aza@correounivalle.edu.co
  Fecha creación: 2018-02-24
  Fecha última modificación: 2019-06-10
  Versión: 0.2
  Licencia: GPL
*/

/**
  @class: Salida
  @brief
  Relaciones: 
  Intención: 
*/

#ifndef SALIDA_H
#define SALIDA_H

#include <iostream>
#include "Objeto.h"

using namespace std;

class Salida : public Objeto
{
protected:

public:
  Salida(int fila, int columna, string nombre, bool obligatorio = false);
  /**
     * @brief el destructor no hace nada
     */
  virtual ~Salida();
  /**
     * @brief un objeto externo me pregunta si puedo quitarme de enmedio, para avanzar encima de mi
     * @param quienPregunta es el objeto externo que hace la pregunta
     * @return retorna 0 en el caso de que no se pueda quitar de enmedio (si es un Obstáculo o Puerta o Trinity (con respuesta equivocada) o Morfeo (con menos pastillas Rojas de las necesarias).
     * Y retorna el puntero al Objeto nuevo que se deja (casilla Salida), en el caso de que sí se pueda, para permitir avanzar, típicamente para Vacía o Llave o Roja o Trinity (si contestaste bien la pregunta) o Morfeo (si tienes suficientes pastillas Rojas).
     * Si no hay nadie que pregunte (o sea, quienPregunta es 0) entonces no se hacen preguntas, por lo que solo las casillas Salidas pueden quitarse de enmedio.
     */
  virtual Objeto *puedesQuitarteDeEnmedio(Objeto *quienPregunta = 0);
};

#else
class Salida; // Declaración adelantada
#endif
