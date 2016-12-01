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
    int categoriaProducto, cantidadProducto, codigoProducto;
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
    int tipoProductoEl;

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
      cout << endl;

      cout << "Inserte el codigo identificador del producto (Maximo 5 digitos): ";
      cin >> pd[i].codigoProducto;
      cout << endl;

      cout << "Ingrese el costo base del producto: ";
      cin >> pd[i].costoProducto;
      cout << endl;

      if (pd[i].categoriaProducto == 1) {
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
 * Imprimimos los datos de los productos registrados.
 */
void productos::mostrar()
{
  for (int i = 0; i < productosDisp; ++i) {
    cout << "-- DATOS DEL PRODUCTO "<< (i + 1) <<" --" << endl;

    cout << "Nombre: " << pd[i].nombreProducto << endl;

    cout << "Categoria: " << pd[i].categoriaProducto << endl;

    cout << "Costo: " << pd[i].costoProducto << endl;
  }
}

/**
 * Imprimimos los datos del producto solicitado.
 */
void productos::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Ingrese el numero del producto que quiere ver (Maximo 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);

    for (int i = 0; i < productosDisp; ++i) {
      if (pd[i].codigoProducto == codigo) {
        cout << "Nombre: " << pd[i].nombreProducto << endl;
        cout << "Categoria: " << pd[i].categoriaProducto << endl;
        cout << "Costo: " << pd[i].costoProducto << endl;
        break;
      }

      if (i == (productosDisp - 1) || productosDisp == 0) {
        cout << "Producto inexistente" << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quiere buscar otro producto?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

int productos::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar un producto." << endl;
    cout << "  2.- Ver todos los productos." << endl;
    cout << "  3.- Buscar productos." << endl;
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
