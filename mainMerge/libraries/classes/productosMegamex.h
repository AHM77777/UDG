#ifndef __PRODUCTOSMEGAMEX_H_INCLUDED__
#define __PRODUCTOSMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

int productosDisp = 0;

/**
 * Declaracion de la clase principal.
 */
class productos
{
  public :
    // Variables publicas de la clase contrato.
    string nombreProducto;
    int tipoProducto, cantidadProducto, codigoProducto;
    float costoProducto;

    // Metodos publicos de la clase servicio.
    static void capturar();
    static void mostrar();
    static void buscar();
    static int menu();
};

class productosElectronica : public productos
{
  public :
    // Variables publicas de clase productosElectronica.
    int tipoProductoEl,

} pd[30];

/**
 * Recopilamos los de los productos a registrar.
 */
void productos::capturar()
{
  int opAnt, amountToRegister = 0, contador = 0;

  if ((30 - productosDisp) > 0) {
    cout << "Inserte el numero de productos que desea capturar (Maximo " << (30 - productosDisp) << "): ";
    cin >> amountToRegister;
    checkInputRange(amountToRegister, 1, (30 - productosDisp));

    for (int i = 0; i < amountToRegister; ++i) {
      cout << "--INGRESE LOS DATOS DEL PRODUCTO A REGISTRAR--" << endl;

      // Limpiamos buffer de cualquier caracter indeseado.
      cin.sync();

      cout << "Inserte el nombre del producto a registrar: ";
      getline(cin, pd[i].nombreProducto);
      cout << endl;

      cout << "Inserte la cantidad de este producto que va a introducir: ";
      cin >> pd[i].cantidadProducto;
      cout << endl

      cout << "Inserte el codigo identificador del producto (Maximo 5 digitos): ";
      cin >> pd[i].codigoProducto;
      cout << endl;

      cout << "Ingrese el costo base del producto: ";
      cin >> pd[i].costoProducto;
      cout << endl

      if (pd[i].tipoProducto == 1) {
        cout << "Ingrese el tipo de electronico que añadira" << endl;
        cout << "  1.- Laptop" << endl;
        cout << "  2.- Computadora de escritorio" << endl;
        cout << "  3.- Videojuegos" << endl;
        cout << "Eleccion: ";
        cin >> pd[i].tipoProductoEl;
        cout << endl;
      }

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
