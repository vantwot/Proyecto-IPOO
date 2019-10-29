/*
  Archivo: Vacia.h
  Autor: jaime.aza@correounivalle.edu.co
  Fecha creación: 2019-08-06
  Fecha última modificación: 2019-08-06
  Versión: 0.2
  Licencia: GPL
*/

/**
  @class: Vacia
  @brief
  Relaciones: 
  Intención: 
*/

#ifndef VACIA_H
#define VACIA_H

#include <iostream>
#include "Objeto.h"

using namespace std;

class Vacia : public Objeto
{
protected:

public:
  Vacia(int fila, int columna, string nombre, bool obligatorio = false);
  /**
     * @brief el destructor no hace nada
     */
  virtual ~Vacia();
  /**
     * @brief un objeto externo me pregunta si puedo quitarme de enmedio, para avanzar encima de mi
     * @param quienPregunta es el objeto externo que hace la pregunta
     * @return retorna 0 en el caso de que no se pueda quitar de enmedio (si es un Obstáculo o Puerta o Trinity (con respuesta equivocada) o Morfeo (con menos pastillas Rojas de las necesarias).
     * Y retorna el puntero al Objeto nuevo que se deja (casilla Vacia), en el caso de que sí se pueda, para permitir avanzar, típicamente para Vacía o Llave o Roja o Trinity (si contestaste bien la pregunta) o Morfeo (si tienes suficientes pastillas Rojas).
     * Si no hay nadie que pregunte (o sea, quienPregunta es 0) entonces no se hacen preguntas, por lo que solo las casillas Vacias pueden quitarse de enmedio.
     */
  virtual Objeto *puedesQuitarteDeEnmedio(Objeto *quienPregunta = 0);
};

#else
class Vacia; // Declaración adelantada
#endif
