#ifndef __CONTRATOSMEGAMEX_H_INCLUDED__
#define __CONTRATOSMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

int contratosDisp = 0;

/**
 * Declaracion de la clase principal.
 */
class contratos
{
  public :
    // Variables publicas de la clase contrato.
    int servicioContrato, clienteContrato, contratistaContrato,
    fechaContrato[3], numeroContrato;

    // Metodos publicos de la clase servicio.
    static void capturar();
    static void mostrar();
    static void buscar();
    static int menu();

    string servicioServido()
    {
      string service;

      for (int i = 0; i < serviciosDisp; ++i) {
        if (servicioContrato == sv[i].codigoServicio) {
          service = sv[i].tituloServicio;
          break;
        }

        else {
          continue;
        }
      }

      if (service.empty()) {
        service = "Servicio no disponible";
      }

      return service;
    };

    string clienteServido()
    {
      string client;

      for (int i = 0; i < clientesDisp; ++i) {
        if (clienteContrato == cl[i].numeroCliente) {
          client = cl[i].nombreCliente[0] + " " + cl[i].nombreCliente[1] + " " + cl[i].nombreCliente[3];
          break;
        }

        else {
          continue;
        }
      }

      if (client.empty()) {
        client = "Cliente no disponible";
      }

      return client;
    };

    string empleadoServidor()
    {
      string employee;

      for (int i = 0; i < empleadosDisp; ++i) {
        if (contratistaContrato == ep[i].codigoEmpleado) {
          employee = ep[i].nombreEmpleado[0] + " " + ep[i].nombreEmpleado[1] + " " + ep[i].nombreEmpleado[2];
        }

        else {
          continue;
        }
      }

      return employee;
    };

    int arreglarFechas(int fechas[])
    {
      // Revisamos dias introducidos para ver si superan el limite de dias en cada mes.
      switch (fechas[0]) {
        case 2:
          if ((fechas[1] > 28) && (isLeapYear(fechas[2]) == false)) {
            fechas[1] = 28;
          }
          if ((fechas[1] > 29) && (isLeapYear(fechas[2]) == true)) {
            fechas[1] = 29;
          }
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          if (fechas[1] > 30) {
            --fechas[1];
          }
          break;
      }

      return 0;
    };

    /**
     * Funcion para revisar si sucursal introducida es valida.
     */
    bool clienteValido(int client)
    {
      bool cliente = false;

      for (int i = 0; i < clientesDisp; ++i) {
        if (client == cl[i].numeroCliente) {
          cliente = true;
        }
      }

      return cliente;
    };

    bool empleadoValido(int employee)
    {
      bool empleado = false;

      for (int i = 0; i < empleadosDisp; ++i) {
        if ((employee == ep[i].codigoEmpleado) && (ep[i].puestoEmpleado == 7)) {
          empleado = true;
        }
      }

      return empleado;
    };
} ct[20];

/**
 * Recopilamos los de los contratos.
 */
void contratos::capturar()
{
  int opAnt, amountToRegister = 0, contador = 0;
  bool contratistaDisp = false;

  /**
   * Code for checking if a "Contratista" employee is available.
   */
  for (int i = 0; i < empleadosDisp; ++i) {
    if (ep[i].puestoEmpleado == 7) {
      contratistaDisp = true;
      break;
    }

    else {
      continue;
    }
  }

  if (empleadosDisp == 0 || contratistaDisp == false) {
    cout << "Imposible crear un contrato sin empleados disponibles";
    return;
  }

  if ((20 - contratosDisp) > 0) {
    cout << "Inserte el numero de contratos que desea capturar (Maximo " << (20 - contratosDisp) << "): ";
    cin >> amountToRegister;
    checkInputRange(amountToRegister, 1, (20 - contratosDisp));

    for (int i = 0; i < amountToRegister; ++i) {
      cout << "--INGRESE LOS DATOS DEL CONTRATO EFECTUADO--" << endl;

      // Limpiamos buffer de cualquier caracter indeseado.
      cin.sync();

      // @TODO: Check for a valid service number (that it exist).
      cout << "Ingrese el codigo del servicio que se prestara (Maximo 5 digitos): ";
      cin >> ct[i].servicioContrato;
      checkInputLength(ct[i].servicioContrato, 5);

      cout << "Ingrese el numero del cliente con el que se efectuo el contrato (Maximo 5 digitos): ";
      cin >> ct[i].clienteContrato;
      checkInputLength(ct[i].clienteContrato, 5);

      // @TODO: Implement a function to create a client from here if he doesn't exist.
      while ((ct[i].clienteValido(ct[i].clienteContrato)) == false) {
        ++contador;

        if (opAnt == ct[i].clienteContrato && contador > 1) {
          contador = 0;
          opAnt = 0;
          break;
        }

        if (opAnt != ct[i].clienteContrato) {
          opAnt = ct[i].clienteContrato;
        }

        cout << "Cliente inexistente, vuelva a ingresar el codigo para registrarlo. Ingrese cualquier otro codigo de no ser ese el caso." << endl;
        cout << "Numero: ";
        cin >> ct[i].clienteContrato;
        checkInputLength(ct[i].clienteContrato, 5);

        cout << endl;
      }

      cout << "Ingrese el codigo del empleado que efectuo el contrato (Maximo 5 digitos): ";
      cin >> ct[i].contratistaContrato;
      checkInputLength(ct[i].contratistaContrato, 5);

      while (ct[i].empleadoValido(ct[i].contratistaContrato) == false) {
        cout << "Lo sentimos, no existe ningun empleado con ese codigo.";

        cout << "Estos son los empleados disponibles para esta casilla: " << endl;

        for (int j = 0; j < empleadosDisp; ++i) {
          if (ep[j].puestoEmpleado == 7) {
            cout << (j + 1) << ".-";
            cout << "    Nombre: " << ep[j].nombreEmpleado[0] << " " << ep[j].nombreEmpleado[1] << " " << ep[j].nombreEmpleado[2] << endl;
            cout << "       Codigo: " << ep[j].codigoEmpleado << endl << endl;
          }

          else {
            continue;
          }
        }

        cout << "Codigo: ";
        cin >> ct[i].contratistaContrato;
        checkInputLength(ct[i].contratistaContrato, 5);

        cout << endl;
      }

      cout << "Ingrese la fecha en que el contrato se efectuo como se le indica a continuacion" << endl;

      for (int j = 0; j < 3; ++j) {
        switch (j) {
          case 0:
            cout << "  Mes: ";
            cin >> ct[i].fechaContrato[j];
            while (ct[i].fechaContrato[j] > 12 || ct[i].fechaContrato[j] < 1) {
              cout << endl << "  Mes inexistente" << endl;
              cout << "  Mes: ";
              cin >> ct[i].fechaContrato[j];
              cout << endl;
            }
            break;
          case 1:
            cout << "  Dia: ";
            cin >> ct[i].fechaContrato[j];
            while (ct[i].fechaContrato[j] > 31 || ct[i].fechaContrato[j] < 0) {
              cout << endl << "  Dia inexistente" << endl;
              cout << "  Dia: ";
              cin >> ct[i].fechaContrato[j];
              cout << endl;
            }
            break;
          case 2:
            cout << "  A\xA4o: ";
            cin >> ct[i].fechaContrato[j];
            while (ct[i].fechaContrato[j] > 2016 || ct[i].fechaContrato[j] < 1910) {
              cout << endl << "  A\xA4o no disponible" << endl;
              cout << "  A\xA4o: ";
              cin >> ct[i].fechaContrato[j];
              cout << endl;
            }
            break;
        }
      }
      ct[i].arreglarFechas(ct[i].fechaContrato);

      cout << "Ingrese el numero asignado al contrato (Maximo 5 digitos): ";
      cin >> ct[i].numeroContrato;
      checkInputLength(ct[i].numeroContrato, 5);

      cout << endl;
    }
  }
}

/**
 * Imprimimos los datos de los contratos registrados.
 */
void contratos::mostrar()
{
  for (int i = 0; i < contratosDisp; ++i) {
    cout << "-- DATOS DEL CONTRATO "<< (i + 1) <<" --" << endl;

    cout << "Servicio: " << ct[i].servicioServido() << endl;

    cout << "Cliente: " << ct[i].clienteServido() << endl;

    cout << "Contratista: " << ct[i].empleadoServidor() << endl;

    cout << "Fecha del contrato: ";
    for (int j = 0; j < 3; ++j) {
      cout << ct[i].fechaContrato[j];

      if (j < 2) {
         cout << "/";
      }
    }
    cout << endl;

    cout << "Numero de contrato: " << ct[i].numeroContrato << endl;
  }
}

/**
 * Imprimimos datos del contrato solicitado.
 */
void contratos::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Ingrese el numero del contrato que quiere ver (Maximo 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);

    for (int i = 0; i < contratosDisp; ++i) {
      if (ct[i].numeroContrato == codigo) {
        cout << "Servicio: " << ct[i].servicioServido() << endl;
        cout << "Ciente: " << ct[i].clienteServido() << endl;
        cout << "Contratista: " << ct[i].empleadoServidor() << endl;
        cout << "Fecha del contrato: ";

        for (int j = 0; j < 3; ++j) {
          cout << ct[i].fechaContrato[j];

          if (j < 2) {
            cout << "/";
          }
        }

        cout << endl << endl;
        break;
      }

      if (i == (contratosDisp - 1) || contratosDisp == 0) {
        cout << "Contrato inexistente" << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quiere buscar otro contrato?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

int contratos::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar contrato." << endl;
    cout << "  2.- Ver contrato." << endl;
    cout << "  3.- Buscar contrato." << endl;
    cout << "  4.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";

    cin >> eleccion;
    checkInputRange(eleccion, 1, 4);

    cout <<endl;

    switch (eleccion) {
      case 1:
        contratos::capturar();
        cout << endl;
        break;
      case 2:
        contratos::mostrar();
        cout << endl;
        break;
      case 3:
        contratos::buscar();
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
