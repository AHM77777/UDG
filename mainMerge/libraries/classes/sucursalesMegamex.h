#ifndef __SUCURSALESMEGAMEX_H_INCLUDED__
#define __SUCURSALESMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

int sucursalesDisp = 0;

/**
 * Declaracion de la clase principal.
 */
class sucursales
{
  public :
    // Variables publicas de la clase sucursal.
    string nombreSucursal, direccionSucursal[4];
    int codigoSucursal, telefonosSucursal[3];

    // Metodos publicos de la clase sucursal.
    void capturar();
    void mostrar();
    void buscar();
    int menu();
} sc;

/**
 * Recopilamos los datos de la sucursal.
 */
void sucursales::capturar()
{
  cout << "--INGRESE DATOS DE LA SUCURSAL--" << endl << endl;

  // Limpiamos buffer de cualquier caracter indeseado.
  cin.ignore(1, '\n');

  // @TODO: Function to make sure that no invalid characters get introduced in the name.
  cout << "Ingrese el nombre de la sucursal: ";
  getline(cin, sc.nombreSucursal);

  cout << endl << "A continuacion se le pedira informacion referente a la direccion de"
  << " la sucursal" << endl;

  for (int i = 0; i < 4; ++i) {
    switch(i) {
      case 0:
        cout << "  Direccion (Calle, Numero, Colonia): ";
        break;
      case 1:
        cout << "  Ciudad: ";
        break;
      case 2:
        cout << "  Estado: ";
        break;
      case 3:
        cout << "  Codigo Postal: ";
        break;
    }

    // Limpiamos buffer para ingresar el string que introducira el usuario.
    cin.sync();
    getline(cin, sc.direccionSucursal[i]);
  }

  cout << endl << "Introduzca el codigo identificador de la sucursal (asegurese que se "
  << "contenga solo 5 digitos porfavor): ";
  cin >> sc.codigoSucursal;
  checkInputLength(sc.codigoSucursal, 5);
  cout << endl;

  cout << "A continuacion se le pedira que introduzca los tres numeros de"
  << " telefono con los que su sucursal cuenta:" << endl;

  // @TODO: Function to check if inserted number is valid.
  for (int i = 0; i < 3; ++i) {
    cout << "  Telefono " << (i + 1) << ": ";
    cin >> sc.telefonosSucursal[i];
  }

  cout << endl;
}

/**
 * Imprimimos los datos de la sucursal.
 */
void sucursales::mostrar()
{
  cout << "--DATOS DE LA SUCURSAL--" << endl;

  cout << "Nombre: " << sc.nombreSucursal << endl;

  cout << "Direccion: ";

  for (int i = 0; i < 4; ++i) {
    if (i == 3) {
      cout << sc.direccionSucursal[i] << endl;
    }
    else {
      cout << sc.direccionSucursal[i] << ", ";
    }
  }

  cout << "Codigo: " << sc.codigoSucursal << endl;

  cout << "Telefonos:" << endl;

  for (int i = 0; i < 3; ++i) {
    // @TODO: Format output of phone numbers to be formatted for the user.
    cout << "  " << (i + 1) << ".- " << sc.telefonosSucursal[i] << endl;
  }
  cout << endl;
}

/**
 * Imprimimos informacion de la sucursal solicitada.
 */
void sucursales::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Inserte el codigo de la sucursal que busca (Asegurese de introducir"
    << " un maximo de 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);

    if (sc.codigoSucursal == codigo) {
      cout << endl << "Nombre de sucursal: ";
      cout << sc.nombreSucursal;

      cout << endl << "Ubicacion: ";

      for (int i = 0; i < 4; ++i) {
        if (i == 3) {
          cout << sc.direccionSucursal[i] << endl;
        }
        else {
          cout << " " << sc.direccionSucursal[i] << ", ";
        }
      }

      cout << "Telefonos: " << endl;
      for (int i = 0; i < 3; ++i) {
        cout << "  " << (i + 1) << ".- " << sc.telefonosSucursal[i] << endl;
      }
      cout << endl;
    }
    else {
      cout << "Sucursal inexistente" << endl << endl;
    }

    cout << "Quiere buscar otra sucursal?" << endl;
    cout << "  1.- Si" << endl;
    cout << "  2.- No" << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

int sucursales::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar sucursal." << endl;
    cout << "  2.- Ver sucursales." << endl;
    cout << "  3.- Buscar sucursales." << endl;
    cout << "  4.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";
    cin >> eleccion;
    checkInputRange(eleccion, 1, 4);
    cout << endl;

    switch (eleccion) {
      case 1:
        sc.capturar();
        cout << endl;
        break;
      case 2:
        sc.mostrar();
        cout << endl;
        break;
      case 3:
        sc.buscar();
        cout << endl;
        break;
      case 4:
        return 0;
    }

    cout << "Deseas hacer algo mas?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";

    cin >> fin;
    checkInputRange(fin, 1, 2);

    cout << endl;
  } while (fin == 1);
}
#endif
