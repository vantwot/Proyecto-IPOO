/*
  Archivo: Objeto.h
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2019-05-20
  Fecha última modificación: 2019-06-01
  Licencia: GNU-GPL
*/

/*
  Clase: Objeto
  Atributos:
    - sus coordenadas dentro del Laberinto
    - su nombre
    - si es obligatorio o no cogerlo, para poder salir
  Funcionalidades:
    - Neo puedo intentar avanzar. Dependiendo del Objeto, quizás
      se pueda o quizás no, o quizás le hagan una pregunta, quizás deba recoger otro Objeto.
  Relaciones:
    - Es una clase abstracta que hay que heredar e implementar.
*/

#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include<iostream>  // PARA DEPURAR
using namespace std;

class Objeto
{
  protected:
    int fila;
    int columna;
    string nombre;
    bool obligatorio;

public:
    /**
     * @brief construye un Objeto con un cierto nombre en unas coordenadas dadas y diciendo si es obligatorio cogerlo para poder salir (por defecto, no lo es)
     * @param fila
     * @param columna
     * @param nombre
     * @param obligatorio
     */
    Objeto(int fila, int columna, string nombre, bool obligatorio=false);
    /**
     * @brief ~Objeto no hace nada especial
     */
    virtual ~Objeto();
    /**
     * @brief comoTeLlamas
     * @return el nombre
     */
    virtual string comoTeLlamas() const;
    /**
     * @brief esObligatorioParaSalir
     * @return true si es obligatorio cogerlo para poder salir (típicamente pastillas Rojas y Trinities); y false en caso contrario (Puertas, Llaves...)
     */
    virtual bool esObligatorioParaSalir() const;
    /**
     * @brief get_fila
     * @return fila
     */
    virtual int get_fila() const;
    /**
     * @brief get_columna
     * @return columna
     */
    virtual int get_columna() const;
    /**
     * @brief incrementa las coordenadas del objeto, añadiendo los valores proporcionados.
     * @param incrementoFila
     * @param incrementoColumna
     */
    virtual void incrementaCoordenadas(int incrementoFila, int incrementoColumna);
    /**
     * @brief mira a ver si se puede mover en la direccion dada por un incremento en fila y columna
     * @param incrementoFila
     * @param incrementoColumna
     * @return 0 si no puedo moverme en esa dirección. En caso contrario, un puntero al Objeto que está en esa casilla donde me voy a mover. En la clase Objeto, siempre retorna 0, y es deber de las clases derivadas reimplementar esta función.
     */
    virtual Objeto *puedesMoverteEnDireccion(int incrementoFila, int incrementoColumna);
    /**
     * @brief un objeto externo me pregunta si puedo quitarme de enmedio, para avanzar encima de mi
     * @param quienPregunta es el objeto externo que hace la pregunta
     * @return retorna 0 en el caso de que no se pueda quitar de enmedio (si es un Obstáculo o Puerta o Trinity (con respuesta equivocada) o Morfeo (con menos pastillas Rojas de las necesarias).
     * Y retorna el puntero al Objeto nuevo que se deja (casilla Vacia), en el caso de que sí se pueda, para permitir avanzar, típicamente para Vacía o Llave o Roja o Trinity (si contestaste bien la pregunta) o Morfeo (si tienes suficientes pastillas Rojas).
     * Si no hay nadie que pregunte (o sea, quienPregunta es 0) entonces no se hacen preguntas, por lo que solo las casillas Vacias pueden quitarse de enmedio.
     */
    virtual Objeto *puedesQuitarteDeEnmedio(Objeto *quienPregunta=0) = 0;
    /**
     * @brief coge el Objeto especificado
     * @param objetoACoger
     * @return El nuevo Objeto (típicamente Vacia) que queda en su lugar. Y 0 si no se pudo coger. Esta función retorna 0 (pues la mayoría de objetos no pueden coger otros objetos), y deberá sobreescribirse si se desea otra cosa.
     */
    virtual Objeto *cogeObjeto(Objeto *objetoACoger);
    /**
     * @brief se le pregunta si tiene un cierto objeto. Típicamente, la Puerta pregunta a Gandalf si tiene la Llave correspondiente.
     * @param objetoRequerido
     * @return true en caso afirmativo; false en caso negativo. La mayoría de los objetos no tienen nada, por lo que aquí retorna false. Las clases derivadas pueden sobreescribir esta función.
     */
    virtual bool tienesObjeto(Objeto *objetoRequerido);
    /**
     * @brief recibe una pregunta y retorna una respuesta
     * @param pregunta
     * @param esperarRespuesta si es false, solo imprime el mensaje; si es true, además espera una respuesta
     * @return la respuesta. Por defecto es "" y cada clase puede reimplementar esta función.
     */
    virtual string hacerPregunta(string pregunta, bool esperarRespuesta=true);
    /**
     * @brief aDondeQuieresMoverte hace esa pregunta al usuario real, por medio del DispositivoEntradaSalida. Pero no todos los objetos pueden hacer esa pregunta, sino solo los controlados por el usuario real, en este caso, Neo. En los demás casos no hace nada y retorna -1.
     * @return 0,1,2,3 para indicar ARRIBA, ABAJO, DERECHA o IZQUIERDA, respectivamente. Y -1 para cualquier otra posibilidad.
     */
    virtual int aDondeQuieresMoverte();
};

#else
class Objeto;  // Declaración adelantada
#endif
