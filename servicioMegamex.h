#include "utileriasAHM.h"

using namespace std;

/**
 * Declaracion de variables globales y clase principal.
 */
int fin = 1, eleccion;

class servicios
{
  public :
    // Variables publicas de la clase servicio.
    string tituloDeServicio, descripcionDeServicio;
    int tipoDeServicio, codigoDeServicio;
    float costoDeServicio, comisionDeEmpleado;
    
    // Metodos publicos de la clase servicio.
    void capturar();
    void mostrar();
    void buscar();
    void menu();
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
  getline(cin, sv.tituloDeServicio);

    // Implementacion de ejemplos para nombramiento de titulo.
    if (sv.tituloDeServicio == "help") {
      int i = 0;
      
      while (sv.tituloDeServicio == "help") {
         switch (i) {
           case 0:
           cout << "  p. ej. Paquete Televisivo Basico 1" << endl;
           break;
         case 1:
           cout << "  p. ej. Paquete Economico" << endl;
           break;
         case 2:
           cout << "p. ej. Megapaquete Cable/Internet/Telefono" << endl;
           i = -1;
           break;
        }
        
        i++;
        
        cout << endl << "Titulo de servicio: ";
        getline(cin, sv.tituloDeServicio);
     }
   }

  cout << endl << "Especifique el digito del tipo de servicio a ofrecer." << endl;
  cout << "  1.- Telefonia Digital." << endl;
  cout << "  2.- Television Digital." << endl;
  cout << "  3.- Television Satelital." << endl;
  cout << "  4.- Internet" << endl;
  cout << "  5.- Mixto (Especificar en descripcion del servicio)"  << endl;
  cout << endl <<  "  Tipo de Servicio: ";
  cin >> sv.tipoDeServicio;

  cout << endl << "  Ingrese el codigo de tu servicio: ";
  // @TODO: Revisar si codigo de servicio ingresado ya existe.
  cin >> sv.codigoDeServicio;

  cout << endl << "  Ingrese el costo del servicio:" << endl;
  cout << "    $ ";
  cin >> sv.costoDeServicio;

  cout << endl << "  Ingrese la comision del empleado por el servicio" << endl;
  cout << "    $ ";
  cin >> sv.comisionDeEmpleado;

  // Limpiamos buffer para poder registrar la descripcion del servicio.
  cin.ignore(1, '\n');

  cout << endl << "  Ingrese una breve descripcion del servicio: ";
  getline(cin, sv.descripcionDeServicio);

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

void servicios::buscar() {
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

void servicios::menu() {
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
