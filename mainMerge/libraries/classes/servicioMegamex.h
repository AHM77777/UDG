#ifndef __SERVICIOMEGAMEX_H_INCLUDED__
#define __SERVICIOMEGAMEX_H_INCLUDED__

#include "../utilities/utileriasAHM.h"

using namespace std;

int serviciosDisp = 0;

/**
 * Declaracion de la clase principal.
 */
class servicios
{
  public :
    // Variables publicas de la clase servicio.
    string tituloServicio, descripcionServicio;
    int tipoServicio, codigoServicio;
    float costoServicio, comisionEmpleado;

    // Metodos publicos de la clase servicio.
    void capturar();
    void mostrar();
    void buscar();
    int menu();
} sv;

/**
 * Recopilamos los datos del servicio.
 */
void servicios::capturar()
{
  cout << "--INGRESE DATOS DEL SERVICIO--" << endl << endl;

  // Limpiamos bufferde cualquier caracter indeseado.
  cin.ignore(1, '\n');

  cout << "Ingresa el titulo de su servicio (Inserta 'help' para ejemplos de posibles titulos): ";
  getline(cin, sv.tituloServicio);

    // Implementacion de ejemplos para nombramiento de titulo.
    if (sv.tituloServicio == "help") {
      int i = 0;

      while (sv.tituloServicio == "help") {
         switch (i) {
           case 0:
           cout << "  p. ej. Paquete Televisivo Basico 1." << endl;
           break;
         case 1:
           cout << "  p. ej. Paquete Economico." << endl;
           break;
         case 2:
           cout << "p. ej. Megapaquete Cable/Internet/Telefono." << endl;
           i = -1;
           break;
        }

        i++;

        cout << endl << "Titulo de servicio: ";
        getline(cin, sv.tituloServicio);
     }
   }

  cout << endl << "Especifique el digito del tipo de servicio a ofrecer." << endl;
  cout << "  1.- Telefonia Digital." << endl;
  cout << "  2.- Television Digital." << endl;
  cout << "  3.- Television Satelital." << endl;
  cout << "  4.- Internet" << endl;
  cout << "  5.- Mixto (Especificar en descripcion del servicio)."  << endl;
  cout << endl <<  "  Tipo de Servicio: ";
  cin >> sv.tipoServicio;
  checkInputRange(sv.tipoServicio, 1, 5);

  cout << endl << "Ingrese el codigo de tu servicio (Asegurate de que el codigo"
  << " tenga un maximo de 5 digitos): ";
  // @TODO: Revisar si codigo de servicio ingresado ya existe.
  cin >> sv.codigoServicio;
  checkInputLength(sv.codigoServicio, 5);

  // @TODO: Revisar que cantidad ingresada sea valida.
  cout << endl << "Ingrese el costo del servicio:" << endl;
  cout << "  $ ";
  cin >> sv.costoServicio;

  cout << endl << "Ingrese la comision del empleado por el servicio:" << endl;
  cout << "  $ ";
  cin >> sv.comisionEmpleado;

  // Limpiamos buffer para poder registrar la descripcion del servicio.
  cin.ignore(1, '\n');

  cout << endl << "Ingrese una breve descripcion del servicio: ";
  getline(cin, sv.descripcionServicio);

  cout << endl;
}

/**
 * Imprimimos los datos del servicio solicitado.
 */
void servicios::mostrar()
{
  cout << "--DATOS DEL SERVICIO--" << endl;

  cout << "Titulo: " << sv.tituloServicio << endl;

  cout << "Tipo: ";
  switch (sv.tipoServicio) {
    case 1:
      cout << "Telefonia Digital.";
      break;
    case 2:
      cout << "Television Digital.";
      break;
    case 3:
      cout << "Television Satelital.";
      break;
    case 4:
      cout << "Internet.";
      break;
    case 5:
      cout << "Mixto.";
      break;
  }
  cout << endl;

  cout << "Codigo: " << sv.codigoServicio << endl;
  cout << "Costo: $" << sv.costoServicio << endl;
  cout << "Comision de empleado: $" << sv.comisionEmpleado << endl;
  cout << "Descripcion: " << sv.descripcionServicio << endl;
}

void servicios::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Inserte el codigo del servicio que desea ver (Asegurese que como"
    << " maximo contega 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);
    cout << endl;

    if (sv.codigoServicio == codigo) {
      cout << "Titulo de servicio: ";
      cout << sv.tituloServicio << endl;

      cout << "Costo de servicio: ";
      cout << sv.costoServicio << endl ;

      cout << "Comision a empleado: ";
      cout << sv.comisionEmpleado << endl ;
    }
    else {
      cout << "Servicio solicitado inexistente." << endl << endl;
    }

    cout << "Quieres revisar otro producto?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

int servicios::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar servicio." << endl;
    cout << "  2.- Ver servicios." << endl;
    cout << "  3.- Buscar servicio." << endl;
    cout << "  4.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";

    cin >> eleccion;
    checkInputRange(eleccion, 1, 4);

    cout <<endl;

    switch (eleccion) {
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
