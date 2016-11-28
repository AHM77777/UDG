/**
 * Header para cargar librerias default y funciones customizadas para programas.
 */
#ifndef __UTILERIASAHM_H_INCLUDED__
#define __UTILERIASAHM_H_INCLUDED__

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Funciones de utileria para acortar trabajo.
 */

// Pausa sistema.
void pause()
{
  cin.sync(); // Sincronizamos buffer para limpiarlo de cualquier valor residual.
  cout << endl << "Presiona cualquier tecla para continuar...";
  cin.ignore(); // Pausamos sistema.
}

// Revisa opcion ingresada en buffer de entrada.
int checkInput(int &input, int lowerBracket, int upperBracket)
{ 
  while (input < lowerBracket || input > upperBracket) {
    cout << "Opcion inexistente, intente de nuevo por favor" << endl;
    cout << "Eleccion: ";
    cin >> input;
    cout << endl;
  }

  return input;
}

#endif
