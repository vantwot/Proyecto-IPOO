/*
  Archivo: Test_Laberinto.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2019-08-02
  Fecha última modificación: 2019-08-02
  Versión: 0.1
  Licencia: GPL
*/


/*
  Utilidad: Un juego de salir de un laberinto.
  Historia: solo se va a probar el constructor y el destructor del Laberinto.
*/

#include "../include/Laberinto.h"
#include "../include/HallDeLaFama.h"
#include "../include/DispositivoTerminal.h"
#include <stdlib.h>
#include <vector>

int main(int numeroArgumentos, char *argumentos[])
{
  srand(time(0));
  
  int alto = 15;
  int ancho = 50;
  int gradoDeDificultad = 2;
  HallDeLaFama hallDeLaFama;
  DispositivoEntradaSalida *dispositivo = new DispositivoTerminal(2, 2, alto, ancho, 2, 2+2+ancho, 12, 75);
  Laberinto laberinto(&hallDeLaFama, dispositivo, alto, ancho, gradoDeDificultad);

  delete dispositivo;
  dispositivo = 0;
  return 0;
}

