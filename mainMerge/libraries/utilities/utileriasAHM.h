/**
 * Header para cargar librerias default, funciones customizadas para programas
 * y variables globales.
 */
#ifndef __UTILERIASAHM_H_INCLUDED__
#define __UTILERIASAHM_H_INCLUDED__

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Variables globales.
 */
int fin = 1, eleccion;

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

// Revisa rango de la opcion ingresada por usuario en buffer.
int checkInputRange(int &input, int lowerBracket, int upperBracket)
{
  while (input < lowerBracket || input > upperBracket) {
    cout << "Opcion inexistente, intente de nuevo por favor" << endl;
    cout << "Eleccion: ";
    cin >> input;
    cout << endl;
  }

  return input;
}

// Revisa que la longitud del input del usuario sea el requerido.
int checkInputLength(int &input, int length)
{
  int numDigits;
  float inputNum;

  do {
    numDigits = 0;
    inputNum = input;

    while (inputNum > 1) {
      ++numDigits;
      inputNum /= 10;
    }

    if (numDigits > length) {
      cout << "El codigo tiene mas de 5 digitos, vuelvalo a introducir porfavor." << endl;
      cout << "Codigo: ";
      cin >> input;
      cout << endl;
    }
  } while (numDigits > length);

  return input;
}

bool isLeapYear(int year) {
  bool isLeap = false;

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    isLeap = true;
  }

  return isLeap;
}
#endif
