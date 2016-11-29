#ifndef __CONTRATOSMEGAMEX_H_INCLUDED__
#define __CONTRATOSMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

/**
 * Declaracion de la clase principal.
 */
class contrato
{
  public :
    // Variables publicas de la clase contrato.
    int servicioContrato, clienteContrato, contratistaContrato,
    fechaContrato[3], numeroContrato;

    // Metodos publicos de la clase servicio.
    void capturar();
    void mostrar();
    void buscar();
    int menu();

    string servicioPrestado() {
      string servicio;

      if (ct.servicioContrato == sv.codigoServicio) {
        servicio = sv.tituloServicio;
      }

      return servicio;
    }

    int arreglarFechas() {
      // Revisamos dias introducidos para ver si superan el limite de dias en cada mes.
      switch (fechaContrato[0]) {
        case 2:
          if ((fechaContrato[1] > 28) && (isLeapYear(fechaContrato[2]) == false)) {
            fechaContrato[1] = 28;
          }
          if ((fechaContrato[1] > 29) && (isLeapYear(fechaContrato[2]) == true)) {
            fechaContrato[1] = 29;
          }
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          if (fechaContrato[1] > 30) {
            --fechaContrato;
          }
          break;
      }

      return fechaContrato;
    }
} ct;

/**
 * Recopilamos los del contrato.
 */
void contrato::capturar()
{
  int clienteAnt, contador = 0;

  cout << "--INGRESE DATOS LOS DATOS DEL CONTRATO EFECTUADO--" << endl << endl;

  // Limpiamos buffer de cualquier caracter indeseado.
  cin.ignore(1, '\n');

  cout << "Ingrese el codigo del servicio que se prestara (Maximo 5 digitos): ";
  cin >> ct.servicioContrato;

  cout << "Ingrese el numero del cliente con el que se efectuo el contrato (Maximo 5 digitos): ";
  cin >> ct.clienteContrato;
  checkInputLength(ct.clienteContrato, 5);

  // @TODO: Implement a function to create a client from here if he doesn't exist.
  while (cl.numeroCliente != ct.clienteContrato) {
    ++contador;

    if (clienteAnt == ct.clienteContrato && contador > 1) {
      break;
    }

    if (clienteAnt != ct.clienteContrato) {
      clienteAnt = ct.clienteContrato;
    }

    cout << "Cliente inexistente, vuelva a ingresar el codigo para registrarlo. Ingrese cualquier otro codigo de no ser ese el caso." << endl;
    cout << "Numero: ";
    cin >> ct.clienteContrato;
    checkInputLength(ct.clienteContrato, 5);

    cout << endl;
  }

  cout << "Ingrese el codigo del empleado que efectuo el contrato (Maximo 5 digitos): ";
  cin >> ct.contratistaContrato;
  checkInputLength(ct.contratistaContrato, 5);

  // @TODO: Add check for instances of "Empleados" which are 'Contratistas' to be printed out for the user (There should always be one available), otherwise leave empty and CANCEL contract.
  while (ct.contratistaContrato != em.codigoEmpleado) {
    cout << "Lo sentimos, el empleado ingresado no existe. Vuelva a ingresar el codigo de un empleado actual" << endl;

    cout << "Estos son los empleados disponibles para esta casilla: " << endl;
    cout << "1.-  ";
    cout << "    Nombre: " << em.nombreEmpleado << endl;
    cout << "    Codigo: " << em.codigoEmpleado << endl;
    cout << "Codigo: ";
    cin >> ct.contratistaContrato;
    checkInputLength(ct.contratistaContrato, 5);

    cout << endl;
  }

  cout << "Ingrese la fecha en que el contrato se efectuo como se le indica a continuacion" << endl;

  for (int i = 0; i < 3; ++i) {
    switch (i) {
      case 0:
        cout << "  Mes: ";
        cin >> ct.fechaContrato[i];
        while (ct.fechaContrato[i] > 12 || ct.fechaContrato[i] < 1) {
          cout << endl << "  Mes inexistente" << endl;
          cout << "  Mes: "
          cin >> ct.fechaContrato[i];
          cout << endl;
        }
        break;
      case 1:
        cout << "  Dia: ";
        cin >> ct.fechaContrato[i];
        while (ct.fechaContrato[i] > 31 || ct.fechaContrato[i] < 0) {
          cout << endl << "  Dia inexistente" << endl;
          cout << "  Dia: "
          cin >> ct.fechaContrato[i];
          cout << endl;
        }
        break;
      case 2:
        cout << "  A\xA4o: ";
        cin >> ct.fechaContrato[i];
        while (ct.fechaContrato[i] > 2016 || ct.fechaContrato[i] < 1910) {
          cout << endl << "  A\xA4o no disponible" << endl;
          cout << "  A\xA4o: "
          cin >> ct.fechaContrato[i];
          cout << endl;
        }
        break;
    }
  }

  cout << endl;
}

/**
 * Imprimimos los datos de los clientes registradis.
 */
void cliente::mostrar()
{
  cout << "--DATOS DEL CLIENTE--" << endl;

  cout << "Nombre: " << cl.nombreCliente << endl;

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

    if (codigo == cl.numeroCliente) {
      cout << "Nombre de cliente: " << cl.nombreCliente << endl;
      cout << "Telefono: " << cl.telefonoCliente << endl;
      cout << "Correo Electronico: " << cl.correoECliente << endl;
    }
    else {
      cout << "Cliente inexistente." << endl;
    }

    cout << "Quiere buscar otro cliente?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
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
