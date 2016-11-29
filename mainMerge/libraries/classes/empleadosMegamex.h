#ifndef __EMPLEADOSMEGAMEX_H_INCLUDED__
#define __EMPLEADOSSMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

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
    void capturar();
    void mostrar();
    void buscar();
    void modificar();
    int menu();

    string sucursalLaboral()
    {
      string nombreS;
      if (sucursalEmpleado == sc.codigoSucursal) {
        nombreS = sc.nombreSucursal;
      }

      if (sc.codigoSucursal == 0) {
        nombreS = "Ninguna (fuera de servicio).";
      }

      return nombreS;
    };
} ep;

/**
 * Recopilamos los datos del empleado.
 */
void empleados::capturar()
{
  int sucursalAnt, contador = 0;

  cout << "--INGRESE LOS DATOS DEL EMPLEADO--" << endl << endl;

  // Limpiamos buffer de cualquier caracter indeseado.
  cin.ignore(1, '\n');

  // @TODO: Function to make sure that no invalid characters get introduced in the name.
  cout << "Ingrese el su(s) nombre(s) y apellidos como se le indicara a continuacion: " << endl;

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
    getline(cin, ep.nombreEmpleado[i]);
  }

  cout << endl << "Ingrese el codigo de la sucursal donde labora el empleado (Maximo de 5 digitos): ";
  cin >> ep.sucursalEmpleado;
  checkInputLength(ep.sucursalEmpleado, 5);
  sucursalAnt = ep.sucursalEmpleado;
  cout << endl;

  while (ep.sucursalEmpleado != sc.codigoSucursal) {
    ++contador;

    if (sucursalAnt == ep.sucursalEmpleado && contador > 1) {
      break;
    }

    if (sucursalAnt != ep.sucursalEmpleado) {
      sucursalAnt = ep.sucursalEmpleado;
    }

    cout << "Sucursal inexistente, vuelva a ingresar el codigo para registrarlo. Ingrese cualquier otro codigo de no ser ese el caso." << endl;
    cout << "Codigo: ";
    cin >> ep.sucursalEmpleado;
    checkInputLength(ep.sucursalEmpleado, 5);

    cout << endl << endl;
  }

  cout << "Introduzca el codigo del empleado (Maximo de 5 digitos): ";
  cin >> ep.codigoEmpleado;
  checkInputLength(ep.codigoEmpleado, 5);
  cout << endl;

  cout << "Ingrese su puesto en base a las siguientes opciones:" << endl;
  cout << "  1.- Ventas." << endl;
  cout << "  2.- Administracion." << endl;
  cout << "  3.- IT." << endl;
  cout << "  4.- Tecnicos." << endl;
  cout << "  5.- Operadoras." << endl;
  cout << "  6.- Customer-Care" << endl;

  cout << "Eleccion: ";
  cin >> ep.puestoEmpleado;
  checkInputRange(ep.puestoEmpleado, 1, 6);
  cout << endl;
}

/**
 * Imprimimos los datos de la sucursal.
 */
void empleados::mostrar()
{
  cout << "--DATOS DEL EMPLEADO--" << endl << endl;

  cout << "Nombre: ";
  for (int i = 0; i < 3; ++i) {
    cout << ep.nombreEmpleado[i] << " ";
  }

  cout << endl;

  cout << "Sucursal donde laboral el empleado: " << empleados::sucursalLaboral() << endl;

  cout << "Codigo del empleado: " << ep.codigoEmpleado << endl;

  cout << "Puesto del empleado: ";

  switch (ep.puestoEmpleado) {
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
  }
  cout << endl << endl;
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

    if (ep.codigoEmpleado == codigo) {
      cout << endl << "Nombre: ";
      cout << ep.codigoEmpleado << endl;

      cout << "Sucursal donde labora: ";
      cout << empleados::sucursalLaboral() << endl;

      cout << "Puesto: ";
      switch (ep.puestoEmpleado) {
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
      }
      cout << endl;
    }
    else {
      cout << "Empleado inexistente." << endl << endl;
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
    cout << "  1.- Capturar empleado." << endl;
    cout << "  2.- Ver todos los empleados." << endl;
    cout << "  3.- Buscar empleados." << endl;
    cout << "  4.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";
    cin >> eleccion;
    checkInputRange(eleccion, 1, 4);
    cout << endl;

    switch (eleccion) {
      case 1:
        ep.capturar();
        cout << endl;
        break;
      case 2:
        ep.mostrar();
        cout << endl;
        break;
      case 3:
        ep.buscar();
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
