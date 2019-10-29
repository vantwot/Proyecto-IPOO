/*
  Archivo: HallDeLaFama.cpp
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-05-25
  Versión: 0.2
  Licencia: GPL
*/

#include "../include/HallDeLaFama.h"

HallDeLaFama::HallDeLaFama(string nombreDelArchivo) : nombreDelArchivo(nombreDelArchivo)
{
  ifstream flujo;
  flujo.open(nombreDelArchivo.c_str());
  if(not flujo.is_open())
    return;

  string linea;
  while(not flujo.eof())
  {
    getline(flujo, linea);
    int posicionTabulador = linea.find("\t");
    if(posicionTabulador != string::npos)
    {
      string nombre = linea.substr(0, posicionTabulador);
      int puntos = stoi(linea.substr(posicionTabulador+1));
      ganadoresYPuntajes.push_back(make_pair(nombre, puntos));
    }
  }
  flujo.close();
  ordenar();
}


HallDeLaFama::~HallDeLaFama()
{
  // No hay que hacer nada
}


void HallDeLaFama::salvar()
{
  ofstream flujo;
  flujo.open(nombreDelArchivo.c_str());
  if(not flujo.is_open())
    cerr << "ERROR al tratar de abrir (para escribir) el archivo " << nombreDelArchivo << endl;
  else
  {
    flujo << listaDeGanadores();
    flujo.close();
  }
}


void HallDeLaFama::nuevoGanador(string nombreGanador, int puntaje)
{
  // Buscarlo y si existe, actualizarlo
  bool existe = false;
  for(int cual=0; cual<ganadoresYPuntajes.size(); cual++)
    if(ganadoresYPuntajes[cual].first == nombreGanador)
    {
      existe = true;
      if(ganadoresYPuntajes[cual].second < puntaje)
        ganadoresYPuntajes[cual].second = puntaje;
    }
      
  if(not existe)
  {
    ganadoresYPuntajes.push_back(make_pair(nombreGanador, puntaje));
    ordenar();
  }
}


// Esta función no es de HallDeLaFama, pero la requiere para comparar:
bool compararSecond(pair<string,int> uno, pair<string,int> otro)
{
  return uno.second>otro.second;
}


void HallDeLaFama::ordenar()
{
  sort(ganadoresYPuntajes.begin(), ganadoresYPuntajes.end(), compararSecond);
}


string HallDeLaFama::listaDeGanadores(int numeroDeMejores)
{
  string resultado = "";
  if(numeroDeMejores>ganadoresYPuntajes.size())
    numeroDeMejores = ganadoresYPuntajes.size();
  for(int cual=0; cual<numeroDeMejores; cual++)
    resultado += ganadoresYPuntajes[cual].first + "\t" + to_string(ganadoresYPuntajes[cual].second) + "\n";

  return resultado;
}

