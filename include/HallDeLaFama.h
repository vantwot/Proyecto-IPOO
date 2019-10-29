/*
  Archivo: HallDeLaFama.h
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2018-02-24
  Fecha última modificación: 2019-06-10
  Versión: 0.2
  Licencia: GPL
*/

/**
  @class: HallDeLaFama
  @brief
  Relaciones: ninguna
  Intención: mantiene una lista de ganadores, formada por parejas de nombres con su correspondiente puntaje. La lista está ordenada, de mayor a menor puntaje. La lista se recupera y vuelve a guardar en un archivo. La lista se puede actualizar, añadiendo un nuevo ganador con su puntaje. Hay una función para ordenar la lista.
*/

#ifndef HALLDELAFAMA_H
#define HALLDELAFAMA_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


class HallDeLaFama
{
  protected:
    string nombreDelArchivo;
    vector< pair<string, int> > ganadoresYPuntajes;
    
  public:
    /**
     * @brief Lee un archivo (por defecto, "LosGanadores.txt") si ya existe, conteniendo los ganadores, y después los ordena, usando una función protected. 
     * Si no existe el archivo, crea uno vacío.
     * El formato del archivo es una línea con cada ganador, ordenado de mayor a menor puntos. 
     * Cada línea es:   nombre del ganador\tpuntos\n
     * Es decir, hay un tabulador que separa el nombre del ganador de su puntaje.
     * Veremos más adelante que esta clase es hackeable. Y después veremos como evitar el hackeo.
     * @param nombre del archivo
     */
    HallDeLaFama(string nombreDelArchivo="LosGanadores.txt");
    /**
     * @brief el destructor no hace nada
     */
    virtual ~HallDeLaFama();
    /**
     * @brief añade un nuevo nombre del ganador con su puntaje y luego ordena la lista.
     * Si el ganador ya existe, simplemente actualiza su puntaje en caso de que el nuevo puntaje sea mejor.
     * @param nombreGanador
     * @param puntaje
     */
    virtual void nuevoGanador(string nombreGanador, int puntaje);
    /**
     * @brief salva la lista de ganadores en el archivo
     */
    virtual void salvar();
    /**
     * @brief pide la lista de ganadores
     * @param numeroDeMejores
     * @return un string con la lista de ganadores, con un ganador por línea. Y para cada ganador se especifica su nombre, un carácter tabulador y su puntaje, y luego el salto de línea. Solo considera los mejores, por defecto, 10.
     */
    virtual string listaDeGanadores(int numeroDeMejores=10);

protected:
    /**
     * @brief Ordena los ganadores de mayor a menor puntaje.
     */
    virtual void ordenar();
};

#else
class HallDeLaFama; // Declaración adelantada
#endif

