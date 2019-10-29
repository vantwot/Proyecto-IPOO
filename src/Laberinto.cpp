/*
  Programa: Laberinto.cpp
  Autor: 
  Fecha creación: 2019-08-06
  Fecha última modificación: 2019-08-06
  Licencia: GNU-GPL
*/

#include "../include/Laberinto.h"

Laberinto::Laberinto(HallDeLaFama *hallDeLaFama,
                     DispositivoEntradaSalida *dispositivo,
                     int alto,
                     int ancho,
                     int gradoDificultad,
                     int numeroPuertas,
                     int numeroPastillasRojas,
                     int numeroTrinities)
    :                hallDeLaFama(hallDeLaFama),
                     dispositivo(dispositivo),
                     alto(alto),
                     ancho(ancho),
                     gradoDificultad(gradoDificultad),
                     numeroPuertas(numeroPuertas),
                     numeroPastillasRojas(numeroPastillasRojas),
                     numeroTrinities(numeroTrinities)

{

  for (int horizontal = 0; horizontal < alto; horizontal++)
  {
    for (int vertical = 0; vertical < ancho; vertical++)
    {
      tablero.push_back(new Obstaculo(horizontal,vertical,"]", false));          
    }    
  }

  int vertices = 0;

  switch (gradoDificultad)
  {
  case 1:
    numeroPuertas = 3;
    numeroPastillasRojas = 3;
    numeroTrinities = 3;
    vertices = 3;
    break;

  case 2:
    numeroPuertas = 5;
    numeroPastillasRojas = 5;
    numeroTrinities = 5;
    vertices = 10;
    break;

  default:
    break;
  }

  vector<pair<int, int>> caminoCorrecto;
  vector<pair<int, int>> caminoInconrrecto1;
  vector<pair<int, int>> caminoIncorrecto2;

  caminoCorrecto = crearCaminoAlAzar(rand() % alto - 1, 0, rand() % alto, ancho - 1, vertices);
  caminoInconrrecto1 = crearCaminoAlAzar(rand() % alto - 1, 2, rand() % alto, 35, 3);
  caminoIncorrecto2 = crearCaminoAlAzar(rand() % alto - 1, 5, rand() % alto, 45, 5);

  for (int i = 0; i < caminoCorrecto.size(); i++)
    tablero.push_back(new Vacia(caminoCorrecto[i].first, caminoCorrecto[i].second, " ", false));
  for (int i = 0; i < caminoInconrrecto1.size(); i++)
    tablero.push_back(new Vacia(caminoInconrrecto1[i].first, caminoInconrrecto1[i].second, " ", false));
  for (int i = 0; i < caminoIncorrecto2.size(); i++)
    tablero.push_back(new Vacia(caminoIncorrecto2[i].first, caminoIncorrecto2[i].second, " ", false));  

  tablero.push_back(new Salida(5, 49, "S", false));

  imprimir();
}

Laberinto::~Laberinto()
{
  // No hacolumna que hacer nada
}

bool Laberinto::jugar()
{
  return true;
}

Objeto* Laberinto:: queHayEnCasilla(int fila, int columna)
{
   return 0;
}

void Laberinto::avisaQueLlegoALaSalida(Objeto *objeto)
{
    
}

int Laberinto::puntaje()
{
    return 0;
}

void Laberinto::imprimir()
{
    for (int elemento = 0; elemento < tablero.size(); elemento++)
    {
      dispositivo->imprimirCasillaTablero(tablero[elemento]->get_fila(), tablero[elemento]->get_columna(),tablero[elemento]->comoTeLlamas());
    }
    
}

Objeto *Laberinto::borrarObjeto(Objeto *objeto)
{
    return objeto;   
}

vector<pair<int, int>> Laberinto::crearCaminoAlAzar(int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, int vertices)
{
  vector<pair<int, int>> camino;

  int aumentarColumna =(int)abs(columnaDestino - columnaOrigen)/vertices;
  int aumentarFila = abs(filaDestino - filaOrigen);

  if (aumentarFila == 0)
  {
    aumentarFila = rand() % alto + 1;
  }
  

  while (columnaOrigen < columnaDestino)
  {
    //cout << aumentarFila << endl;
    if (filaOrigen < alto)
    {
      for (int i = columnaOrigen; i < columnaOrigen + aumentarColumna; i++)
        camino.push_back(make_pair(filaOrigen, i));
      columnaOrigen += aumentarColumna;

      for (int i = filaOrigen; i < filaOrigen + aumentarFila; i++)
        camino.push_back(make_pair(i, columnaOrigen));
      filaOrigen += aumentarFila; 

      if (filaOrigen > alto )      
        filaOrigen = alto;

    }
     else
    {
      for (int i = columnaOrigen; i < columnaOrigen + aumentarColumna; i++)
        camino.push_back(make_pair(filaOrigen-1, i));
      columnaOrigen += aumentarColumna;

      for (int i = filaOrigen ; i > filaOrigen - aumentarFila; i--)
        camino.push_back(make_pair(i, columnaOrigen));
        
      filaOrigen -= aumentarFila;
      
    }     
  }

  camino.push_back(make_pair(filaDestino, columnaDestino));

  return camino;
}

void Laberinto::vaciarCamino(vector<pair<int,int>> coordenadas, bool contarlongitudCamino)
{

}

int Laberinto::ponerObjetoEnLaberinto(Objeto *objeto)
{

}

int Laberinto::buscarCasilla(int fila, int columna)
{

}

int Laberinto::buscarCasilla(Objeto *objeto)
{

}

pair<int, int> Laberinto::caminarAlAzar(int filaInicial, int columnaInicial, int numeroPasos)
{

}

void Laberinto:: ordenar(int&menor, int &macolumnaor, int &incremeto)
{

}