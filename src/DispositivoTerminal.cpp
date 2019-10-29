/*
  Archivo: DispositivoTerminal.cpp
  Autor: Ángel García Baños <angel.garcia@correounivalle.edu.co>
  Fecha creación: 2018-03-01
  Fecha última modificación: 2019-08-02
  Versión: 0.3
  Licencia: GNU-GPL
*/

#include "../include/DispositivoTerminal.h"

DispositivoTerminal::DispositivoTerminal(
                                          int filaInicialTablero,
                                          int columnaInicialTablero,
                                          int altoTablero,
                                          int anchoTablero,
                                          int filaMensajeUsuario,
                                          int columnaMensajeUsuario,
                                          int altoMensajeUsuario,
                                          int anchoMensajeUsuario
                                        )
  : DispositivoEntradaSalida( filaInicialTablero,
                              columnaInicialTablero,
                              altoTablero,
                              anchoTablero,
                              filaMensajeUsuario,
                              columnaMensajeUsuario,
                              altoMensajeUsuario,
                              anchoMensajeUsuario
                            )
{
  system("clear");
  // Programa el terminal en modo de un solo caracter:
  struct termios terminal; 
  tcgetattr(fileno(stdin), &terminal);
  terminal_salvado = terminal;
  terminal.c_lflag &= (~ICANON & ~ECHO);
  terminal.c_cc[VTIME] = 0;
  terminal.c_cc[VMIN] = 1;
  if(tcsetattr(fileno(stdin), TCSANOW, &terminal) < 0)
    perror("Imposible programar el terminal en modo de un solo caracter");
    
  printf("%c[%dm", 0x1B, 5);  // Oculta el cursor
  setbuf(stdout, NULL); // Elimina el buffer, para que la información se muestre inmediatamente

  // Dibujar borde de tablero:
  for(int columna=columnaInicialTablero-1; columna<=columnaInicialTablero+anchoTablero; columna++)
  {
    imprimirSimbolo(filaInicialTablero-1, columna, "█");
    imprimirSimbolo(filaInicialTablero+altoTablero, columna, "█");
  }

  for(int fila=filaInicialTablero-1; fila<=filaInicialTablero+altoTablero; fila++)
  {
    imprimirSimbolo(fila, columnaInicialTablero-1, "█");
    imprimirSimbolo(fila, columnaInicialTablero+anchoTablero, "█");
  }
}


DispositivoTerminal::~DispositivoTerminal()
{
  // Restaura el estado anterior del terminal:
  if(tcsetattr(fileno(stdin), TCSANOW, &terminal_salvado) < 0)
    perror("Imposible restaurar el estado anterior del terminal");
  imprimirSimbolo(filaInicialTablero+altoTablero+1, 0, "");
}


string DispositivoTerminal::leerMensajeUsuario(int renglon)
{
  imprimirSimbolo(filaMensajeUsuario+renglon, columnaMensajeUsuario, "");
  streambuf *teclado = cin.rdbuf();
  string mensaje="";
  
  while(true)
  {
    char caracter = teclado->sbumpc();
    if(caracter == '\n' or caracter == '\r')
      break;
    if(caracter==0x1b)
    {
      teclado->sbumpc();
      teclado->sbumpc();
    }
    else if(caracter==0x08 or caracter==0x7f)
    {
      if(not mensaje.empty())
        mensaje.pop_back();
      imprimirMensajeUsuario(mensaje+" ", renglon);
    }
    else if(isprint(caracter))
    {
      mensaje += string(1, caracter);
      imprimirMensajeUsuario(mensaje, renglon);
    }
  }
  
  return mensaje;
}


int DispositivoTerminal::leerDireccion()
{
  streambuf *teclado = cin.rdbuf();
  int estado = 0;
  while(true)
  {
    char caracter = teclado->sbumpc();
    switch(estado)
    {
      case 0:
        if(caracter == 0x1b) 
          estado = 1;
      break;
      case 1:
        if(caracter == 0x5b) 
          estado = 2;
      break;
      case 2:
        if(caracter == 0x41) 
          return 0;
        if(caracter == 0x42) 
          return 1;
        if(caracter == 0x43) 
          return 2;
        if(caracter == 0x44) 
          return 3;
        if(caracter == 0x46)
          return 4;
      break;
    }
  }
  return -1;
}


void DispositivoTerminal::imprimirCasillaTablero(int fila, int columna, string valor)
{
  if(fila<0 or fila>=altoTablero or columna<0 or columna>=anchoTablero)
    return;
  imprimirSimbolo(filaInicialTablero+fila, columnaInicialTablero+columna, valor);
}


void DispositivoTerminal::imprimirMensajeUsuario(string mensaje,int renglon)
{
  string restoDeLinea;
  do
  {
    int finalLinea = mensaje.find('\n');
    if(finalLinea != string::npos)
    {
      restoDeLinea = mensaje.substr(finalLinea+1);
      mensaje = mensaje.substr(0,finalLinea);
    }
    else
      restoDeLinea = "";
    while(not mensaje.empty())
    {
       printf("%c[%d;%dH%s", 0x1B, (filaMensajeUsuario+renglon++), columnaMensajeUsuario, mensaje.substr(0,anchoMensajeUsuario).c_str());
      if(mensaje.size() > anchoMensajeUsuario)
        mensaje = mensaje.substr(anchoMensajeUsuario);
      else
        mensaje = "";
    }
    mensaje = restoDeLinea;
  }while(not restoDeLinea.empty());
}


void DispositivoTerminal::imprimirSimbolo(int fila, int columna, string mensaje)
{
  printf("%c[%d;%dH%s", 0x1B, fila, columna, mensaje.substr(0,1).c_str());
}


void DispositivoTerminal::limpiarMensajesUsuario(int renglonInicial, int renglonFinal)
{
  if(renglonFinal==-1)
    renglonFinal=altoMensajeUsuario;
  string lineaEnBlanco = "";
  for(int letra=0; letra<anchoMensajeUsuario; letra++)
    lineaEnBlanco += " ";
  for(int renglon=renglonInicial; renglon<=renglonFinal; renglon++)
    if(renglon<altoMensajeUsuario)
      printf("%c[%d;%dH%s", 0x1B, (filaMensajeUsuario+renglon), columnaMensajeUsuario, lineaEnBlanco.c_str());
}







