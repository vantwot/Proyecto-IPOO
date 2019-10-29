/*
  Archivo: Laberinto.h
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2019-05-20
  Fecha última modificación: 2019-08-02
  Licencia: GNU-GPL
*/

/*
  Clase: Laberinto
  Atributos:
    - un dispositivo de entrada/salida para comunicarse con el usuario (por ejemplo, teclado/pantalla).
    - alto x ancho del laberinto
    - gradoDeDificultad del Laberinto, que influye en cuantas esquinas tiene el camino hacia la salida.
    - número de Puertas, Trinities y pastillas Rojas. Cada Llave abre una Puerta, por lo que el número de Puertas es igual al número de Llaves. Cada Trinity hace una pregunta. Si la aciertas, te dá una pastilla Roja y desaparece.
    - longitudCamino que lleva desde la entrada hasta la salida. Sirve para calcular la puntuación del usuario.
    - numeroDeMovimientos que ha realizado el usuario. Sirve para calcular su puntuación. Cuantos más movimientos, peor.
    - casillaNeo. El índice en tablero donde está situado Gandalf en cada momento.
    - elJuegoContinua se pone a false únicamente cuando Gandalf alcanza la salida; y true en los demás casos.
  Funcionalidades:
    - Puedo pedirle que juegue.
    - Puedo pedirle que me diga que Objeto en una cierta casilla.
    - Puedo avisarle de que un Objeto llegó a la Salida
    - Puedo preguntarle el puntaje del jugador.
    - Puedo perirle que se imprima en el DispositivoEntradaSalida
  Relaciones:
    - Conoce un HallDeLaFama
    - Conoce un DispositivoEntradaSalida
    - Posee un tablero, que es una lista de Objetos (Obstaculo, Vacia, Salida, Neo, Morfeo, Trinity, Llave, Puerta, Roja). Cada Objeto sabe sus propias coordenadas en el laberinto.
    - Posee la lista de las esquinas del camino que conduce a la salida. Cada elemento de la lista es un par <fila, columna>
*/

#ifndef LABERINTO_H
#define LABERINTO_H

#include "DispositivoEntradaSalida.h"
#include "Objeto.h"
#include "Obstaculo.h"
#include "Salida.h"
#include "Vacia.h"
#include "HallDeLaFama.h"
#include <vector>
#include <utility>
#include<iostream>  // PARA DEPURAR
using namespace std;


class Laberinto
{
  protected:
    HallDeLaFama *hallDeLaFama;    // No toma propiedad
    DispositivoEntradaSalida *dispositivo;     // No toma propiedad
    int alto;
    int ancho;
    int gradoDificultad;
    int numeroPuertas;
    int numeroPastillasRojas;
    int numeroTrinities;
    vector<Objeto*> tablero;  // Toma propiedad de los Objetos a los que apunta
    vector< pair<int,int> > esquinasDelCamino;
    int longitudCamino;
    int numeroDeMovimientos;
    int casillaNeo;
    bool elJuegoContinua;
    bool teRendiste;

  public:
    /**
     * @brief Construye un laberinto con un cierto alto y ancho, y un cierto grado de dificultad.
     * Usa un DispositivoEntradaSalida para comunicarse con el usuario (imprimir el Laberinto).
     * Usa un HallDeLaFama para mantener la lista de nombres y puntajes ganadores.
     * Se puede especificar el número de Puertas (con una LLave por Puerta), pastillas Rojas y Trinities
     */
    Laberinto(HallDeLaFama *hallDeLaFama, DispositivoEntradaSalida *dispositivo, int alto=20, int ancho=40, int gradoDificultad=4, int numeroPuertas=2, int numeroPastillasRojas=3, int numeroTrinities=2); // No toma propiedad del DispositivoEntradaSalida ni del HallDeLaFama ni del Usuario
    /**
     * @brief Guarda el nomnbre del Usuario y su puntaje en el HallDeLaFama. Destruye todos los objetos internos.
     */
    virtual ~Laberinto();
    /**
     * @brief comienza el juego. Le pide al usuario que haga un movimiento, en caso de que sea legal, lo lleva a cabo, imprime el tablero.
     * @return false si con ello el juego terminó; y true si el juego continua.
     */
    virtual bool jugar();
    /**
     * @brief queHayEnCasilla
     * @param fila
     * @param columna
     * @return un puntero al Objeto que hay en la casilla especificada. Y 0 si no hay nada.
     */
    virtual Objeto* queHayEnCasilla(int fila, int columna);
    /**
     * @brief llegoALaSalida avisa que el objeto especificado llegó a la salida
     * @param objeto
     */
    virtual void avisaQueLlegoALaSalida(Objeto *objeto);
    /**
     * @brief puntaje
     * @return el puntaje del jugador, medido como el número de casillas vacías, menos el número de movimientos. Si sale negativo, se retorna 0.
     */
    virtual int puntaje();
    /**
     * @brief se imprime el tablero del Laberinto en el DispositivoEntradaSalida
     */
    virtual void imprimir();
    /**
     * @brief borra el objeto indicado del Laberinto, cediendo su propiedad (no lo elimina de memoria).
     * Si hace falta eliminarlo de la memoria, el programa llamante debe encargarse de hacerlo.
     * @param objeto
     * @return el nuevo Objeto Vacia que deja en lugar del objeto cogido. Si retorna 0, hay un error interno.
     */
    virtual Objeto *borrarObjeto(Objeto *objeto);

  protected:
    /**
     * @brief crea un camino al azar desde el origen hasta el destino, usando el número de vértices especificado.
     * @return la lista de esquinas <fila,columna> por donde pasa el camino incluyendo la entrada y la salida
     */
    virtual vector< pair<int,int> > crearCaminoAlAzar(int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, int vertices);
    /**
     * @brief borra (delete) los objetos que haya en el camino, añadiendo en su lugar Objetos Vacia.
     * @param si contarlongitudCamino es true, entonces cuenta el número de casillas que tiene el camino, guardándolas en longitudCamino
     * @param lista de coordenadas por donde pasa el camino, incluyendo las iniciales y finales
     */
    virtual void vaciarCamino(vector< pair<int,int> > coordenadas, bool contarlongitudCamino);
    /**
     * @brief pone un objeto en las coordenadas especificadas.
     * Si hay algo allí, lo borra (delete) primero.
     * Toma propiedad del nuevo objeto.
     * @return el índice de la casilla donde se puso ese objeto.
     */
    virtual int ponerObjetoEnLaberinto(Objeto *objeto);
    /**
     * @brief busca la casilla del tablero con las coordenadas dadas.
     * @return el número de la casilla en el tablero donde está el objeto con esas coordenadas. O -1 si no existe.
     */
    virtual int buscarCasilla(int fila, int columna);
    /**
     * @brief busca la casilla donde está un objeto en el tablero
     * @param objeto
     * @return el número de la casilla en el tablero donde está el objeto. O -1 si no existe.
     */
    virtual int buscarCasilla(Objeto *objeto);
    /**
     * @brief camina al azar desde (filaInicial,columnaInicial) durante un número de pasos dado (por defecto, 100).
     * Obviamente, termina en un punto accesible del Laberinto.
     * @param filaInicial
     * @param columnaInicial
     * @param numeroPasos
     * @return un par que contiene la fila y la columna donde dejó de caminar
     */
    virtual pair <int, int> caminarAlAzar(int filaInicial, int columnaInicial, int numeroPasos=100);
    /**
     * @brief ordena el menor y el mayor, intercambiándolos si estna al revés
     * @param menor
     * @param mayor
     * @param incremento lo pone 0 si son iguales y 1 en caso contrario
     */
    virtual void ordenar(int &menor, int &mayor, int &incremento);
};

#else
class Laberinto;  // Declaración adelantada
#endif
