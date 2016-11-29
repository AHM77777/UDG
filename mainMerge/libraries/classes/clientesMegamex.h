#ifndef __CLIENTESMEGAMEX_H_INCLUDED__
#define __CLIENTESMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

/**
 * Declaracion de la clase principal.
 */
class cliente
{
  public :
    // Variables publicas de la clase servicio.
    string nombreCliente[3], correoECliente, direccionCliente[4];
    int telefonoCliente, numeroCliente;

    // Metodos publicos de la clase servicio.
    void capturar();
    void mostrar();
    void buscar();
    int menu();
} cl;

/**
 * Recopilamos los datos del cliente.
 */
void cliente::capturar()
{
  cout << "--INGRESE DATOS LOS DATOS DEL CLIENTE--" << endl << endl;

  // Limpiamos buffer de cualquier caracter indeseado.
  cin.ignore(1, '\n');

  cout << "Ingrese el/los nombre(s) y apellidos del cliente como se le indicara a continuacion" << endl;

  for (int i = 0; i < 3; ++i) {
    switch (i) {
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
    getline(cin, cl.nombreCliente[i]);
  }

  cout << endl << "Ingrese la direcccion del cliente como se le indique a continuacion" << endl;

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
    getline(cin, cl.direccionCliente[i]);
  }

  cout << endl << "Ingrese el numero de telefono del cliente: ";
  cin >> cl.telefonoCliente;

  // @TODO: Check for valid email.
  cout << endl << "Ingrese el correo electronico del cliente: ";
  cin >> cl.correoECliente;

  cout << endl << "Ingrese el numero identificador del cliente (Maximo 5 digitos): ";
  cin >> cl.numeroCliente;
  checkInputLength(cl.numeroCliente, 5);

  cout << endl;
}

/**
 * Imprimimos los datos de los clientes registradis.
 */
void cliente::mostrar()
{
  cout << "--DATOS DEL CLIENTE--" << endl;

  cout << "Nombre: ";

  for (int i = 0; i < 3; ++i) {
    cout << cl.nombreCliente[i] << " ";
  }

  cout << endl;

  cout << "Direccion: ";

  for (int i = 0; i < 4; ++i) {
    if (i == 3) {
      cout << cl.direccionCliente[i] << endl;
    }
    else {
      cout << cl.direccionCliente[i] << ", ";
    }
  }

  cout << "Telefono: " << cl.telefonoCliente << endl;
  cout << "Correo Electronico: " << cl.correoECliente << endl;
  cout << "Numero de cliente: " << cl.numeroCliente << endl;
}

void cliente::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Ingrese el numero del cliente que quiere ver (Maximo 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);
    cout << endl;

    if (codigo == cl.numeroCliente) {
      cout << "Nombre de cliente: ";

      for (int i = 0; i < 3; ++i) {
        cout << cl.nombreCliente[i] << " ";
      }
      cout << endl;

      cout << "Telefono: " << cl.telefonoCliente << endl;
      cout << "Correo Electronico: " << cl.correoECliente << endl;
    }
    else {
      cout << "Cliente inexistente." << endl << endl;
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

int cliente::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar cliente." << endl;
    cout << "  2.- Ver cliente." << endl;
    cout << "  3.- Buscar cliente." << endl;
    cout << "  4.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";

    cin >> eleccion;
    checkInputRange(eleccion, 1, 4);

    cout <<endl;

    switch (eleccion) {
      case 1:
        cl.capturar();
        cout << endl;
        break;
      case 2:
        cl.mostrar();
        cout << endl;
        break;
      case 3:
        cl.buscar();
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
