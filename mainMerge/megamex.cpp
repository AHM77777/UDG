#include "./libraries/utilities/utileriasAHM.h"
#include "./libraries/classes/servicioMegamex.h"
#include "./libraries/classes/sucursalesMegamex.h"

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
    cout << "  6.- Salir." << endl;
  
    cout << "Eleccion: ";
    cin >> eleccion;
    checkInputRange(eleccion, 1, 4);
    cout << endl;
    
    switch (eleccion) {
      case 1:
        sv.menu();
        cout << endl;
        break;
      case 2:
        sc.menu();
        cout << endl;
        break;
      case 6:
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
          return 0;
        }
      default:
        cout << "Bajo construccion." << endl;
        break;
    }
  } while (eleccion);
}
