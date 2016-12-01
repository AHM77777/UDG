#ifndef __CLIENTESMEGAMEX_H_INCLUDED__
#define __CLIENTESMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

int clientesDisp = 0;

/**
 * Declaracion de la clase principal.
 */
class clientes
{
  public :
    // Variables publicas de la clase servicio.
    string nombreCliente[3], correoECliente, direccionCliente[4];
    int telefonoCliente, numeroCliente;

    // Metodos publicos de la clase servicio.
    static void capturar();
    static void mostrar();
    static void buscar();
    static void modificar();
    static int menu();
} cl[30];

/**
 * Recopilamos datos de los clientes.
 */
void clientes::capturar()
{
  int amountToRegister = 0;

  if ((30 - clientesDisp) > 0) {
    cout << "Inserte el numero de clientes que desea capturar (Maximo " << (30 - sucursalesDisp) << "): ";
    cin >> amountToRegister;
    checkInputRange(amountToRegister, 1, (30 - clientesDisp));

    for (int i = 0; i < amountToRegister; ++i) {
      cout << "-- INGRESE LOS DATOS DEL CLIENTE " << (i + 1) << "--" << endl << endl;

      // Limpiamos buffer de cualquier caracter indeseado.
      cin.sync();

      cout << "Ingrese el/los nombre(s) y apellidos del cliente como se le indicara a continuacion" << endl;

      for (int j = 0; j < 3; ++j) {
        switch (j) {
          case 0:
            cout << "  Nombre(s): ";
            break;
          case 1:
            cout << "  Apellido Paterno: ";
            break;
          case 2:
            cout << "  Apellido Materno: ";
            break;
        }

        cin.sync(); // Limpiamos buffer de caracteres indeseados paea registrar nombres.
        getline(cin, cl[i].nombreCliente[j]);
      }

      cout << endl << "Ingrese la direcccion del cliente como se le indique a continuacion" << endl;

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
        getline(cin, cl[i].direccionCliente[j]);
      }

      cout << endl << "Ingrese el numero de telefono del cliente: ";
      cin >> cl[i].telefonoCliente;

      // @TODO: Check for valid email.
      cout << endl << "Ingrese el correo electronico del cliente: ";
      cin >> cl[i].correoECliente;

      cout << endl << "Ingrese el numero identificador del cliente (Maximo 5 digitos): ";
      cin >> cl[i].numeroCliente;
      checkInputLength(cl[i].numeroCliente, 5);

      ++clientesDisp;
      }
    }

    else {
      cout << "Imposible agregar mas clientes." << endl;
    }

  cout << endl;
}

/**
 * Imprimimos los datos de los clientes registradis.
 */
void clientes::mostrar()
{
  for (int i = 0; i < clientesDisp; ++i) {
    cout << "--DATOS DEL CLIENTE " << (i + 1) << "--" << endl;

    cout << "Nombre: ";

    for (int j = 0; j < 3; ++j) {
      cout << cl[i].nombreCliente[j] << " ";
    }

    cout << endl;

    cout << "Direccion: ";

    for (int j = 0; j < 4; ++j) {
      if (j == 3) {
        cout << cl[i].direccionCliente[j] << endl;
      }
      else {
        cout << cl[i].direccionCliente[j] << ", ";
      }
    }

    cout << "Telefono: " << cl[i].telefonoCliente << endl;
    cout << "Correo Electronico: " << cl[i].correoECliente << endl;
    cout << "Numero de cliente: " << cl[i].numeroCliente << endl << endl;
  }

  cout << endl;
}

void clientes::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Ingrese el numero del cliente que quiere ver (Maximo 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);
    cout << endl;

    for (int i = 0; i < clientesDisp; ++i) {
      if (cl[i].numeroCliente == codigo) {
        cout << "Nombre de cliente: ";

        for (int j = 0; j < 3; ++j) {
          cout << cl[i].nombreCliente[j] << " ";
        }

        cout << endl;

        cout << "Telefono: " << cl[i].telefonoCliente << endl;
        cout << "Correo Electronico: " << cl[i].correoECliente << endl;
        break;
      }

      if (i == (clientesDisp - 1)) {
        cout << "Cliente inexistente." << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quiere buscar otro cliente?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl << endl;
  }
}

void clientes::modificar()
{
  int codigo;

  while (fin == 1) {
    cout << "Ingrese el codigo del cliente que desea modificar: ";
    cin >> codigo;
    checkInputLength(codigo, 5);
    cout << endl;

    for (int i = 0; i < clientesDisp; ++i) {
      if (cl[i].numeroCliente == codigo) {

        while (eleccion == 1) {
          cout << "Nombre: ";

          for (int j = 0; j < 3; ++j) {
            cout << cl[i].nombreCliente[j] << " ";
          }

          cout << endl;

          cout << "Direccion: ";
          for (int j = 0; j < 4; ++j) {
            if (j == 3) {
              cout << cl[i].direccionCliente[j] << endl;
            }

            else {
              cout << cl[i].direccionCliente[j] << ", ";
            }
          }

          cout << endl;

          cout << "Telefono: ";
          cout << cl[i].telefonoCliente << endl;

          cout << "Correo Electronico: ";
          cout << cl[i].correoECliente << endl;

          cout << "Numero de cliente: ";
          cout << cl[i].numeroCliente << endl;

          cout << endl << "Que deseas modificar?" << endl;
          cout << "  1.- Nombre." << endl;
          cout << "  2.- Direccion." << endl;
          cout << "  3.- Telefono." << endl;
          cout << "  4.- Correo Electronico." << endl;
          cout << "  5.- Numero de cliente." << endl;
          cout << "Eleccion: ";
          cin >> eleccion;
          checkInputRange(eleccion, 1, 4);
          cout << endl;

          switch (eleccion) {
            case 1:
              cout << "Ingrese el/los nombre(s) y apellidos del cliente como se le indicara a continuacion" << endl;

              for (int j = 0; j < 3; ++j) {
                switch (j) {
                  case 0:
                    cout << "  Nombre(s): ";
                    break;
                  case 1:
                    cout << "  Apellido Paterno: ";
                    break;
                  case 2:
                    cout << "  Apellido Materno: ";
                    break;
                }

                cin.sync(); // Limpiamos buffer de caracteres indeseados paea registrar nombres.
                getline(cin, cl[i].nombreCliente[j]);
              }

              cout << endl;
              break;
            case 2:
              cout << endl << "Ingrese la direcccion del cliente como se le indique a continuacion" << endl;

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
                getline(cin, cl[i].direccionCliente[j]);
              }
              cout << endl;
              break;
            case 3:
              cout << "Nuevo telefono: ";
              cin >> cl[i].telefonoCliente;
              cout << endl;
              break;
            case 4:
              cout << "Nuevo correo electronico: ";
              cin >> cl[i].correoECliente;
              cout << endl;
              break;
            case 5:
              cout << "Nuevo numero de cliente: ";
              cin >> cl[i].numeroCliente;
              cout << endl;
              break;
          }

          cout << "Desea modificar algo mas?" << endl;
          cout << "  1.- Si." << endl;
          cout << "  2.- No." << endl;
          cout << "Eleccion: ";
          cin >> eleccion;
          cout << endl;
        }

        break;
      }

      if (i == (clientesDisp - 1)) {
        cout << "Cliente inexistente." << endl << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quieres modificar otra sucursal?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

int clientes::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar un cliente." << endl;
    cout << "  2.- Ver todos los clientes." << endl;
    cout << "  3.- Buscar clientes." << endl;
    cout << "  4.- Modificar clientes." << endl;
    cout << "  5.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";

    cin >> eleccion;
    checkInputRange(eleccion, 1, 5);

    cout << endl;

    switch (eleccion) {
      case 1:
        clientes::capturar();
        cout << endl;
        break;
      case 2:
        clientes::mostrar();
        cout << endl;
        break;
      case 3:
        clientes::buscar();
        cout << endl;
        break;
      case 4:
        clientes::modificar();
        cout << endl;
        break;
      case 5:
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
