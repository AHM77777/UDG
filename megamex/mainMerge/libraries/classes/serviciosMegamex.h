#ifndef __SERVICIOSMEGAMEX_H_INCLUDED__
#define __SERVICIOSMEGAMEX_H_INCLUDED__

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
    float costoServicio, comisionServicio;

    // Metodos publicos de la clase servicio.
    static void capturar();
    static void mostrar();
    static void buscar();
    static void modificar();
    static int menu();

    bool validarServicio() {
      bool servicio = true;

      for (int i = 0; i < servicioDisp; ++i) {
        if (codigoServicio == sv[i].codigoServicio) {
	  servicio = false;
	}
      }

      return servicio;
    };
      
} sv[10];

/**
 * Recopilamos los datos del servicio.
 */
void servicios::capturar()
{
  int amountToRegister = 0;

  if ((10 - serviciosDisp) > 0) {
    cout << "Inserte el numero de servicios que desea capturar (Maximo " << (10 - serviciosDisp) << "): ";
    cin >> amountToRegister;
    checkInputRange(amountToRegister, 1, (10 - serviciosDisp));

    for (int i = 0; i < amountToRegister; ++i) {
      cout << "-- INGRESE LOS DATOS DEL SERVICIO " << (i + 1) << " --" << endl;

      // Limpiamos buffer de cualquier caracter indeseado.
      cin.sync();

      cout << "Ingresa el titulo de su servicio (Inserta 'help' para ejemplos de posibles titulos): ";
      getline(cin, sv[i].tituloServicio);

      // Implementacion de ejemplos para nombramiento de titulo.
      if (sv[i].tituloServicio == "help") {
        int k = 0;

        while (sv[i].tituloServicio == "help") {
          switch (k) {
            case 0:
              cout << "  p. ej. Paquete Televisivo Basico 1." << endl;
              break;
            case 1:
             cout << "  p. ej. Paquete Economico." << endl;
             break;
            case 2:
             cout << "p. ej. Megapaquete Cable/Internet/Telefono." << endl;
             k = -1;
             break;
          }

          k++;

          cout << endl << "Titulo de servicio: ";
          getline(cin, sv[i].tituloServicio);
        }
      }

      cout << endl << "Especifique el digito del tipo de servicio a ofrecer." << endl;
      cout << "  1.- Telefonia Digital." << endl;
      cout << "  2.- Television Digital." << endl;
      cout << "  3.- Television Satelital." << endl;
      cout << "  4.- Internet" << endl;
      cout << "  5.- Mixto (Especificar en descripcion del servicio)."  << endl;
      cout << endl <<  "  Tipo de Servicio: ";
      cin >> sv[i].tipoServicio;
      checkInputRange(sv[i].tipoServicio, 1, 5);

      cout << endl << "Ingrese el codigo de tu servicio (Asegurate de que el codigo"
      << " tenga un maximo de 5 digitos): ";
      
      cin >> sv[i].codigoServicio;
      checkInputLength(sv[i].codigoServicio, 5);

      // Checamos que el codigo de servicio ingresado sea nuevo.
      while (sv[i].validarServicio() == false) {
        cout << "Codigo de servicio ya existente, porfavor ingreselo nuevamente: ";
	cin >> sv[i].codigoServicio;
	cout << endl;
      }
      
      cout << endl << "Ingrese el costo del servicio:" << endl;
      cout << "  $ ";
      cin >> sv[i].costoServicio;

      cout << endl << "Ingrese la comision del empleado por el servicio:" << endl;
      cout << "  $ ";
      cin >> sv[i].comisionServicio;;

      // Limpiamos buffer para poder registrar la descripcion del servicio.
      cin.ignore(1, '\n');

      cout << endl << "Ingrese una breve descripcion del servicio: ";
      getline(cin, sv[i].descripcionServicio);

      ++serviciosDisp;
    }
  }

  else {
    cout << "Imposible agregar mas servicios" << endl;
    return;
  }

  cout << endl;
}

/**
 * Imprimimos los datos del servicio solicitado.
 */
void servicios::mostrar()
{
  for (int i = 0; i < serviciosDisp; ++i) {
    cout << "-- DATOS DEL SERVICIO " << (i + 1) << " --" << endl;

    cout << "Titulo: " << sv[i].tituloServicio << endl;

    cout << "Tipo: ";
    switch (sv[i].tipoServicio) {
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

    cout << "Codigo: " << sv[i].codigoServicio << endl;
    cout << "Costo: $" << sv[i].costoServicio << endl;
    cout << "Comision de empleado: $" << sv[i].comisionServicio << endl;
    cout << "Descripcion: " << sv[i].descripcionServicio << endl << endl;
  }
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

    for (int i = 0; i < serviciosDisp; ++i) {
      if (sv[i].codigoServicio == codigo) {
        cout << "Titulo de servicio: ";
        cout << sv[i].tituloServicio << endl;

        cout << "Costo de servicio: ";
        cout << sv[i].costoServicio << endl ;

        cout << "Comision a empleado: ";
        cout << sv[i].comisionServicio << endl << endl;

        break;
      }

      if (i == (serviciosDisp - 1)) {
        cout << "Servicio inexistente." << endl;
      }

      else {
        continue;
      }
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

void servicios::modificar()
{
  int codigo;

  while (fin == 1) {
    cout << "Ingrese el codigo del servicio que desea modificar: ";
    cin >> codigo;
    checkInputLength(codigo, 5);
    cout << endl;

    for (int i = 0; i < serviciosDisp; ++i) {
      if (sv[i].codigoServicio == codigo) {

        while (eleccion == 1) {
          cout << "Titulo de servicio: ";
          cout << sv[i].tituloServicio << endl;

          cout << "Tipo de servicio: ";
          cout << sv[i].tipoServicio << endl;

          cout << "Costo de servicio: ";
          cout << sv[i].costoServicio << endl;

          cout << "Codigo de servicio: ";
          cout << sv[i].codigoServicio << endl;

          cout << "Comision a empleado: ";
          cout << sv[i].comisionServicio << endl;

          cout << "Descripcion de servicio: ";
          cout << sv[i].descripcionServicio << endl;

          cout << endl << "Que deseas modificar?" << endl;
          cout << "  1.- Titulo." << endl;
          cout << "  2.- Tipo." << endl;
          cout << "  3.- Costo." << endl;
          cout << "  4.- Codigo." << endl;
          cout << "  5.- Comision." << endl;
          cout << "  6.- Descripcion." << endl;
          cout << "Eleccion: ";
          cin >> eleccion;
          checkInputRange(eleccion, 1, 6);
          cout << endl;

          switch (eleccion) {
            case 1:
              cout << "Nuevo titulo: ";
              cin >> sv[i].tituloServicio;
              cout << endl;
              break;
            case 2:
              cout << endl << "Especifique el digito del tipo de servicio a ofrecer." << endl;
              cout << "  1.- Telefonia Digital." << endl;
              cout << "  2.- Television Digital." << endl;
              cout << "  3.- Television Satelital." << endl;
              cout << "  4.- Internet" << endl;
              cout << "  5.- Mixto (Especificar en descripcion del servicio)."  << endl;

              cout << "Nuevo tipo: ";
              cin >> sv[i].tipoServicio;
              cout << endl;
              break;
            case 3:
              cout << "Nuevo costo: ";
              cin >> sv[i].costoServicio;
              cout << endl;
              break;
            case 4:
              cout << "Nuevo codigo: ";
              cin >> sv[i].codigoServicio;
              cout << endl;
              break;
            case 5:
              cout << "Nueva comision: ";
              cin >> sv[i].comisionServicio;
              cout << endl;
              break;
            case 6:
              cout << "Nueva descripcion: ";
              cin >> sv[i].tituloServicio;
              cout << endl;
              break;
          }

          cout << "Desea modificar algo mas?" << endl;
          cout << "  1.- Si." << endl;
          cout << "  2.- No." << endl;
          cout << "Eleccion: ";
          cin >> eleccion;
          cout << endl;
        }

        break;
      }

      if (i == (serviciosDisp - 1)) {
        cout << "Servicio inexistente." << endl << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quieres modificar otro servicio?" << endl;
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
    cout << "  2.- Ver todos los servicios." << endl;
    cout << "  3.- Buscar servicios." << endl;
    cout << "  4.- Modificar servicios." << endl;
    cout << "  5.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";

    cin >> eleccion;
    checkInputRange(eleccion, 1, 5);

    cout <<endl;

    switch (eleccion) {
      case 1:
        servicios::capturar();
        cout << endl;
        break;
      case 2:
        servicios::mostrar();
        cout << endl;
        break;
      case 3:
        servicios::buscar();
        cout << endl;
        break;
      case 4:
        servicios::modificar();
        cout << endl;
        break;
      case 5:
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
