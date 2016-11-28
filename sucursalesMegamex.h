#include "utileriasAHM.h"

using namespace std;

/**
 * Declaracion de variables globales y clase principal.
 */
int fin = 1, eleccion;

class sucursales
{
  public :
    // Variables publicas de la clase sucursal.
    string nombreDeSucursal, direccionDeSucursal[4];
    int codigoDeSucursal, telefonosDeSucursal[3];
    
    // Metodos publicos de la clase sucursal.
    void capturar();
    void mostrar();
    void buscar();
    void menu();
} sc;

/**
 * Recopilamos los datos de la sucursal.
 */
void sucursales::capturar()
{
  cout << "--INGRESE DATOS DE LA SUCURSAL--" << endl << endl;

  // Limpiamos buffer de cualquier caracter indeseado.
  cin.ignore(1, '\n');

  cout << "Ingrese el nombre de la sucursal: ";
  getline(cin, sc.nombreDeSucursal);

  cout << "A continuacion se le pedira informacion referente a la direccion de"
  << " la sucursal" << endl;
  
  for (int i = 0; i < 4; ++i) {
    switch(i) {
      case 0:
        cout << "  Direccion (calle, numero, colonia): ";
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
    
    cin.ignore(1, '\n');
    getline(cin, sc.direccionDeSucursal[i]);
    cout << endl;
  }
  
  cout << "Introduzca el codigo identificador de la sucursal: ";
  cin >> sc.codigoDeSucursal;
  cout << endl;
  
  cout << "A continuacion se le pedira que introduzca los tres numeros de"
  << " telefono con los que su sucursal cuenta" << endl;
  
  // @TODO: Have the numbers separated by a hyphen for user to see formatted number.
  for (int i = 0; i < 3; ++i) {
    cout << "Telefono " << (i + 1) << ": ";
    cin >> sc.telefonosDeSucursal[i];
  }
  
  cout << endl;
}

/**
 * Imprimimos los datos del servicio solicitado.
 */
void servicios::mostrar() 
{
  cout << "--DATOS DEL SERVICIO--" << endl;

  cout << "  Titulo: " << sv.tituloDeServicio << endl;

  cout << "  Tipo: ";
  switch(sv.tipoDeServicio) {
    case 1:
      cout << "Telefonia Digital";
      break;
    case 2:
      cout << "Television Digital";
      break;
    case 3:
      cout << "Television Satelital";
      break;
    case 4:
      cout << "Internet";
      break;
    case 5:
      cout << "Mixto";
      break;
  }
  cout << endl;

  cout << "  Codigo: " << sv.codigoDeServicio << endl;
  cout << "  Costo: $" << sv.costoDeServicio << endl;
  cout << "  Comision de empleado: $" << sv.comisionDeEmpleado << endl;
  cout << "  Descripcion: " << sv.descripcionDeServicio << endl;
}

void servicios::buscar()
{
  int codigo;
     
  while (fin == 1) {
    cout << "Inserte el codigo del servicio que desea ver: ";
    cin >> codigo;
    
    if (sv.codigoDeServicio == codigo) {
      cout << endl << "Titulo de servicio: ";
      cout << sv.tituloDeServicio;
      
      cout << "Costo de servicio: ";
      cout << sv.costoDeServicio << endl ;
      
      cout << "Comision de empleado: ";
      cout << sv.comisionDeEmpleado << endl ;
    }
    else {
      cout << "Servicio solicitado inexistente" << endl;
    }
    
    cout << "Quieres revisar otro producto?" << endl;
    cout << "  1.- Si" << endl << "  2.- No" << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInput(fin, 1, 2);
  }
}

void servicios::menu()
{
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar servicio." << endl;
    cout << "  2.- Ver servicios." << endl;
    cout << "  3.- Buscar servicio." << endl;
    cout << "  4.- Salir." << endl;
  
    cout << "Eleccion: ";
    cin >> eleccion;
    checkInput(eleccion, 1, 4);
    
    switch(eleccion) {
      case 1:
        sv.capturar();
        cout << endl;
        break;
      case 2:
        sv.mostrar();
        cout << endl;
        break;
      case 3:
        sv.buscar();
        cout << endl;
        break;
      case 4:
        pause();
        return 0;
    }
    
    cout << "Deseas hacer algo mas?" << endl;
    cout << "  1.- Si." << endl << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInput(fin, 1, 2);
    
  } while (fin == 1);
}
int main()
{
  sc.capturar();
  
  pause();
  return 0;
}
