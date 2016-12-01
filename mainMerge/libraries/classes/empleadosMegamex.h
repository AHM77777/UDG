#ifndef __EMPLEADOSMEGAMEX_H_INCLUDED__
#define __EMPLEADOSSMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

int empleadosDisp = 0;

/**
 * Declaracion de la clase principal.
 */
class empleados
{
  public :
    // Variables publicas de la clase empleados.
    string nombreEmpleado[3];
    int sucursalEmpleado, codigoEmpleado, puestoEmpleado;

    // Metodos publicos de la clase empleados.
    static void capturar();
    static void mostrar();
    static void buscar();
    static void modificar();
    static int menu();

    string sucursalLaboral()
    {
      string nombreS;

      if (sucursalesDisp > 0) {
        for (int i = 0; i < sucursalesDisp; ++i) {
          if (sucursalEmpleado == sc[i].codigoSucursal) {
            nombreS = sc[i].nombreSucursal;
          }

          else {
            continue;
          }
        }
      }

      else {
        nombreS = "Ninguna (fuera de servicio)";
      }

      return nombreS;
    };

    /**
     * Funcion para revisar si sucursal introducida es valida.
     */
    bool sucursalValida(int sucursal)
    {
      bool sucursalValida = false;
      for (int i = 0; i < sucursalesDisp; ++i) {
        if (sucursal == sc[i].codigoSucursal) {
          sucursalValida = true;
        }
      }

      return sucursalValida;
    };
} ep[10];

/**
 * Recopilamos los datos del empleado.
 */
void empleados::capturar()
{
  int sucursalAnt, amountToRegister = 0, contador = 0;

  if (sucursalesDisp == 0) {
    cout << "Imposible registrar un empleado sin sucursales abiertas" << endl;
    return;
  }

  if ((10 - empleadosDisp) > 0) {
    cout << "Inserte el numero de empleados que desea capturar (Maximo " << (10 - empleadosDisp) << "): ";
    cin >> amountToRegister;
    checkInputRange(amountToRegister, 1, (10 - empleadosDisp));

    for (int i = 0; i < amountToRegister; ++i) {
      cout << "--INGRESE LOS DATOS DEL EMPLEADO--" << endl << endl;

      // Limpiamos buffer de cualquier caracter indeseado.
      cin.sync();

      // @TODO: Function to make sure that no invalid characters get introduced in the name.
      cout << "Ingrese el su(s) nombre(s) y apellidos como se le indicara a continuacion: " << endl;

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
        getline(cin, ep[i].nombreEmpleado[j]);
      }

      cout << endl << "Ingrese el codigo de la sucursal donde labora el empleado (Maximo de 5 digitos): ";
      cin >> ep[i].sucursalEmpleado;
      checkInputLength(ep[i].sucursalEmpleado, 5);
      sucursalAnt = ep[i].sucursalEmpleado;
      cout << endl;

      while (ep[i].sucursalValida(ep[i].sucursalEmpleado) == false) {
        ++contador;

        if (sucursalAnt == ep[i].sucursalEmpleado && contador > 1) {
          break;
        }

        if (sucursalAnt != ep[i].sucursalEmpleado) {
          sucursalAnt = ep[i].sucursalEmpleado;
        }

        cout << "Sucursal inexistente, vuelva a ingresar el codigo para registrarlo. Ingrese cualquier otro codigo de no ser ese el caso." << endl;
        cout << "Codigo: ";
        cin >> ep[i].sucursalEmpleado;
        checkInputLength(ep[i].sucursalEmpleado, 5);

        cout << endl;
      }

      cout << "Introduzca el codigo del empleado (Maximo de 5 digitos): ";
      cin >> ep[i].codigoEmpleado;
      checkInputLength(ep[i].codigoEmpleado, 5);
      cout << endl;

      cout << "Ingrese su puesto en base a las siguientes opciones:" << endl;
      cout << "  1.- Ventas." << endl;
      cout << "  2.- Administracion." << endl;
      cout << "  3.- IT." << endl;
      cout << "  4.- Tecnicos." << endl;
      cout << "  5.- Operadoras." << endl;
      cout << "  6.- Customer-Care" << endl;
      cout << "  7.- Contratista" << endl;

      cout << "Eleccion: ";
      cin >> ep[i].puestoEmpleado;
     checkInputRange(ep[i].puestoEmpleado, 1, 7);
    }

    ++empleadosDisp;
  }

  else {
    cout << "Imposible registrar mas empleados" << endl;
  }

  cout << endl;
}

/**
 * Imprimimos los datos de la sucursal.
 */
void empleados::mostrar()
{
  for (int i = 0; i < empleadosDisp; ++i) {
    cout << "-- DATOS DEL EMPLEADO " << (i + 1) << "--" << endl;

    cout << "Nombre: ";
    for (int j = 0; j < 3; ++j) {
      cout << ep[i].nombreEmpleado[j] << " ";
    }

    cout << endl;

    cout << "Sucursal donde laboral el empleado: " << ep[i].sucursalLaboral() << endl;

    cout << "Codigo del empleado: " << ep[i].codigoEmpleado << endl;

    cout << "Puesto del empleado: ";

    switch (ep[i].puestoEmpleado) {
      case 1:
        cout << "Ventas";
        break;
      case 2:
        cout << "Administracion";
        break;
      case 3:
        cout << "IT";
        break;
      case 4:
        cout << "Tecnicos";
        break;
      case 5:
        cout << "Operadoras";
        break;
      case 6:
        cout << "Customer-Care";
        break;
      case 7:
        cout << "Contratistas";
        break;
    }
  }

  cout << endl;
}

/**
 * Imprimimos informacion de la sucursal solicitada.
 */
void empleados::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Inserte el codigo del empleado que busca (Maximo 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);

    for (int i = 0; i < empleadosDisp; ++i) {
      if (ep[i].codigoEmpleado == codigo) {
        cout << endl << "Nombre: ";
        cout << ep[i].codigoEmpleado << endl;

        cout << "Sucursal donde labora: ";
        cout << ep[i].sucursalLaboral() << endl;

        cout << "Puesto: ";
        switch (ep[i].puestoEmpleado) {
          case 1:
            cout << "Ventas";
            break;
          case 2:
            cout << "Administracion";
            break;
          case 3:
            cout << "IT";
            break;
          case 4:
            cout << "Tecnicos";
            break;
          case 5:
            cout << "Operadoras";
            break;
          case 6:
            cout << "Customer-Care";
            break;
          case 7:
            cout << "Contratistas";
            break;
        }

        cout << endl;
        break;
      }

      if (i == (empleadosDisp - 1)) {
        cout << "Empleado inexistente" << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quiere buscar otro empleado?" << endl;
    cout << "  1.- Si" << endl;
    cout << "  2.- No" << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

int empleados::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar empleados." << endl;
    cout << "  2.- Ver todos los empleados." << endl;
    cout << "  3.- Buscar empleados." << endl;
    cout << "  4.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";
    cin >> eleccion;
    checkInputRange(eleccion, 1, 4);
    cout << endl;

    switch (eleccion) {
      case 1:
        empleados::capturar();
        cout << endl;
        break;
      case 2:
        empleados::mostrar();
        cout << endl;
        break;
      case 3:
        empleados::buscar();
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

