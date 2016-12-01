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
    static void capturar();
    static void mostrar();
    static void buscar();
    static int menu();
} sc[10];

/**
 * Recopilamos los datos de las sucursales.
 */
void sucursales::capturar()
{
  int amountToRegister = 0;

  if ((10 - sucursalesDisp) > 0) {
    cout << "Inserte el numero de sucursales que desea capturar (Maximo " << (10 - sucursalesDisp) << "): ";
    cin >> amountToRegister;
    checkInputRange(amountToRegister, 1, (10 - sucursalesDisp));

    for (int i = 0; i < amountToRegister; ++i) {
      cout << " --INGRESE LOS DATOS DE LA SUCURSAL " << (i + 1) << " --" << endl;

      // Limpiamos buffer de cualquier caracter indeseado.
      cin.sync();

      // @TODO: Function to make sure that no invalid characters get introduced in the name.
      cout << "Ingrese el nombre de la sucursal: ";
      getline(cin, sc[i].nombreSucursal);

      cout << endl << "A continuacion se le pedira informacion referente a la direccion de"
      << " la sucursal" << endl;

      for (int j = 0; j < 4; ++j) {
        switch(j) {
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
        getline(cin, sc[i].direccionSucursal[j]);
      }

      cout << endl << "Introduzca el codigo identificador de la sucursal (asegurese que se "
      << "contenga solo 5 digitos porfavor): ";
      cin >> sc[i].codigoSucursal;
      checkInputLength(sc[i].codigoSucursal, 5);
      cout << endl;

      cout << "A continuacion se le pedira que introduzca los tres numeros de"
      << " telefono con los que su sucursal cuenta:" << endl;

      // @TODO: Function to check if inserted number is valid.
      for (int j = 0; j < 3; ++j) {
        cout << "  Telefono " << (j + 1) << ": ";
        cin >> sc[i].telefonosSucursal[j];
      }

      ++sucursalesDisp;
    }
  }

  else {
    cout << "Imposible agregar mas sucursales" << endl;
  }

  cout << endl;
}

/**
 * Imprimimos los datos de las sucursales.
 */
void sucursales::mostrar()
{
  for (int i = 0; i < sucursalesDisp; ++i) {
    cout << "-- DATOS DE LA SUCURSAL " << (i + 1) << " --" << endl;

    cout << "Nombre: " << sc[i].nombreSucursal << endl;

    cout << "Direccion: ";

    for (int j = 0; j < 4; ++j) {
      if (j == 3) {
        cout << sc[i].direccionSucursal[j] << endl;
      }
      else {
        cout << sc[i].direccionSucursal[j] << ", ";
      }
    }

    cout << "Codigo: " << sc[i].codigoSucursal << endl;

    cout << "Telefonos:" << endl;

    for (int j = 0; j < 3; ++j) {
      // @TODO: Format output of phone numbers to be formatted for the user.
      cout << "  " << (j + 1) << ".- " << sc[i].telefonosSucursal[j] << endl;
    }
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

    for (int i = 0; i < sucursalesDisp; ++i) {
      if (sc[i].codigoSucursal == codigo) {
        cout << endl << "Nombre de sucursal: ";
        cout << sc[i].nombreSucursal;

        cout << endl << "Ubicacion: ";

        for (int j = 0; j < 4; ++j) {
          if (j == 3) {
            cout << sc[i].direccionSucursal[j] << endl;
          }
          else {
            cout << " " << sc[i].direccionSucursal[j] << ", ";
          }
        }

        cout << "Telefonos: " << endl;
        for (int j = 0; j < 3; ++j) {
          cout << "  " << (j + 1) << ".- " << sc[i].telefonosSucursal[j] << endl;
        }
        cout << endl;

        break;
      }

      if (i == (sucursalesDisp - 1)) {
        cout << "Sucursal inexistente." << endl;
      }

      else {
        continue;
      }
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
        sucursales::capturar();
        cout << endl;
        break;
      case 2:
        sucursales::mostrar();
        cout << endl;
        break;
      case 3:
        sucursales::buscar();
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
