#include "./libraries/utilities/utileriasAHM.h"
#include "./libraries/classes/serviciosMegamex.h"
#include "./libraries/classes/sucursalesMegamex.h"
#include "./libraries/classes/empleadosMegamex.h"
#include "./libraries/classes/clientesMegamex.h"
#include "./libraries/classes/contratosMegamex.h"
#include "./libraries/classes/productosMegamex.h"

using namespace std;

int main()
{
  do {
    cout << "Bienvenido al menu administrativo de Megamex. Que desea hacer?" << endl;
    cout << "  1.- Acceder a 'Servicios'." << endl;
    cout << "  2.- Acceder a 'Sucursales'." << endl;
    cout << "  3.- Acceder a 'Empleados'." << endl;
    cout << "  4.- Acceder a 'Clientes'." << endl;
    cout << "  5.- Acceder a 'Contratos'." << endl;
    cout << "  6.- Acceder a 'Productos'." << endl;
    cout << "  7.- Salir." << endl;

    cout << "Eleccion: ";
    cin >> eleccion;
    checkInputRange(eleccion, 1, 7);
    cout << endl;

    switch (eleccion) {
      case 1:
        servicios::menu();
        cout << endl;
        break;
      case 2:
        sucursales::menu();
        cout << endl;
        break;
      case 3:
        empleados::menu();
        cout << endl;
        break;
      case 4:
        clientes::menu();
    	cout << endl;
    	break;
      case 5:
        contratos::menu();
        cout << endl;
        break;
      case 6:
        productos::menu();
        cout << endl;
        break;
      case 7:
        cout << "Algo mas antes de irte?" << endl;
        cout << "  1.- Si." << endl;
        cout << "  2.- No." << endl;
        cout << "Eleccion: ";

        cin >> fin;
        checkInputRange(fin, 1, 2);

        cout << endl;

        if (fin == 1) {
          break;
        }
        else {
          pause();
          return 0;
        }
      default:
        cout << "Bajo construccion." << endl << endl;
        break;
    }
  } while (eleccion);
}
