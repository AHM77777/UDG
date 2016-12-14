#include "../libraries/utilities/utileriasAHM.h"

using namespace std;

int serviciosDisp = 0, sucursalesDisp = 0;

/**
 * Declaracion de las clases principales.
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
} sv[10];

class sucursales
{
  public :
    // Variables publicas de la clase sucursal.
    string nombreSucursal, direccionSucursal[4];
    int codigoSucursal, telefonosSucursal[3];

    // Metodos publicos de la clase sucursal.
    static void capturar();
    static void mostrar();
    static void buscar();
    static void modificar();
    static int menu();
} sc[10];

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
        int i = 0;

        while (sv[i].tituloServicio == "help") {
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
      // @TODO: Revisar si codigo de servicio ingresado ya existe.
      cin >> sv[i].codigoServicio;
      checkInputLength(sv[i].codigoServicio, 5);

      // @TODO: Revisar que cantidad ingresada sea valida.
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
int main()
{
  do {
    cout << "Bienvenido a Megamex" << endl;
    cout << "  1.- Ingresar a Servicios." << endl;
    cout << "  2.- Ingresar a Sucursales." << endl;
    cout << "  3.- Salir." << endl;
    cout << "Eleccion: ";
    cin >> eleccion;

    switch (eleccion) {
      case 1:
        servicios::menu();
        cout << endl;
        break;
      case 2:
        sucursales:: menu();
        cout << endl;
        break;
      case 3:
        pause();
        return 0;
    }
  } while (eleccion);
}
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

/**
 * Recopilamos los datos de las sucursales.
 */
void sucursales::capturar()
{
  int amountToRegister = 0;

  if ((10 - sucursalesDisp) > 0) {
    cout << "Inserte el numero de sucursales que desea capturar (Maximo " << (10 - sucursalesDisp) << "): ";
    cin >> amountToRegister;
    checkInputRange(amountToRegister, 1, (10 - sucursalesDisp));

    for (int i = 0; i < amountToRegister; ++i) {
      cout << " --INGRESE LOS DATOS DE LA SUCURSAL " << (i + 1) << " --" << endl;

      // Limpiamos buffer de cualquier caracter indeseado.
      cin.sync();

      // @TODO: Function to make sure that no invalid characters get introduced in the name.
      cout << "Ingrese el nombre de la sucursal: ";
      getline(cin, sc[i].nombreSucursal);

      cout << endl << "A continuacion se le pedira informacion referente a la direccion de"
      << " la sucursal" << endl;

      for (int j = 0; j < 4; ++j) {
        switch(j) {
          case 0:
            cout << "  Direccion (Calle, Numero, Colonia): ";
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

        // Limpiamos buffer para ingresar el string que introducira el usuario.
        cin.sync();
        getline(cin, sc[i].direccionSucursal[j]);
      }

      cout << endl << "Introduzca el codigo identificador de la sucursal (asegurese que se "
      << "contenga solo 5 digitos porfavor): ";
      cin >> sc[i].codigoSucursal;
      checkInputLength(sc[i].codigoSucursal, 5);
      cout << endl;

      cout << "A continuacion se le pedira que introduzca los tres numeros de"
      << " telefono con los que su sucursal cuenta:" << endl;

      // @TODO: Function to check if inserted number is valid.
      for (int j = 0; j < 3; ++j) {
        cout << "  Telefono " << (j + 1) << ": ";
        cin >> sc[i].telefonosSucursal[j];
      }

      ++sucursalesDisp;
    }
  }

  else {
    cout << "Imposible agregar mas sucursales" << endl;
  }

  cout << endl;
}

/**
 * Imprimimos los datos de las sucursales.
 */
void sucursales::mostrar()
{
  for (int i = 0; i < sucursalesDisp; ++i) {
    cout << "-- DATOS DE LA SUCURSAL " << (i + 1) << " --" << endl;

    cout << "Nombre: " << sc[i].nombreSucursal << endl;

    cout << "Direccion: ";

    for (int j = 0; j < 4; ++j) {
      if (j == 3) {
        cout << sc[i].direccionSucursal[j] << endl;
      }
      else {
        cout << sc[i].direccionSucursal[j] << ", ";
      }
    }

    cout << "Codigo: " << sc[i].codigoSucursal << endl;

    cout << "Telefonos:" << endl;

    for (int j = 0; j < 3; ++j) {
      // @TODO: Format output of phone numbers to be formatted for the user.
      cout << "  " << (j + 1) << ".- " << sc[i].telefonosSucursal[j] << endl;
    }
  }

  cout << endl;
}

/**
 * Imprimimos informacion de la sucursal solicitada.
 */
void sucursales::buscar()
{
  int codigo;

  while (fin == 1) {
    cout << "Inserte el codigo de la sucursal que busca (Asegurese de introducir"
    << " un maximo de 5 digitos): ";
    cin >> codigo;
    checkInputLength(codigo, 5);

    for (int i = 0; i < sucursalesDisp; ++i) {
      if (sc[i].codigoSucursal == codigo) {
        cout << endl << "Nombre de sucursal: ";
        cout << sc[i].nombreSucursal;

        cout << endl << "Ubicacion: ";

        for (int j = 0; j < 4; ++j) {
          if (j == 3) {
            cout << sc[i].direccionSucursal[j] << endl;
          }
          else {
            cout << " " << sc[i].direccionSucursal[j] << ", ";
          }
        }

        cout << "Telefonos: " << endl;
        for (int j = 0; j < 3; ++j) {
          cout << "  " << (j + 1) << ".- " << sc[i].telefonosSucursal[j] << endl;
        }
        cout << endl;

        break;
      }

      if (i == (sucursalesDisp - 1)) {
        cout << "Sucursal inexistente." << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quiere buscar otra sucursal?" << endl;
    cout << "  1.- Si" << endl;
    cout << "  2.- No" << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

void sucursales::modificar()
{
  int codigo;

  while (fin == 1) {
    cout << "Ingrese el codigo de la sucursal que desea modificar: ";
    cin >> codigo;
    checkInputLength(codigo, 5);
    cout << endl;

    for (int i = 0; i < sucursalesDisp; ++i) {
      if (sc[i].codigoSucursal == codigo) {

        while (eleccion == 1) {
          cout << "Nombre: ";
          cout << sc[i].nombreSucursal << endl;

          cout << "Direccion: ";
          for (int j = 0; j < 4; ++j) {
            if (j == 3) {
              cout << sc[i].direccionSucursal[j] << endl;
            }

            else {
              cout << sc[i].direccionSucursal[j] << ", ";
            }
          }

          cout << endl;

          cout << "Codigo: ";
          cout << sc[i].codigoSucursal << endl;

          cout << "Telefonos:" << endl;

          for (int j = 0; j < 3; ++j) {
            // @TODO: Format output of phone numbers to be formatted for the user.
            cout << "  " << (j + 1) << ".- " << sc[i].telefonosSucursal[j] << endl;
          }

          cout << endl << "Que deseas modificar?" << endl;
          cout << "  1.- Nombre." << endl;
          cout << "  2.- Direccion." << endl;
          cout << "  3.- Codigo." << endl;
          cout << "  4.- Telefonos." << endl;
          cout << "Eleccion: ";
          cin >> eleccion;
          checkInputRange(eleccion, 1, 4);
          cout << endl;

          switch (eleccion) {
            case 1:
              cout << "Nuevo nombre: ";
              cin >> sc[i].nombreSucursal;
              cout << endl;
              break;
            case 2:
              cout << endl << "A continuacion se le pedira informacion referente a la direccion de"
              << " la sucursal" << endl;

              for (int j = 0; j < 4; ++j) {
                switch(j) {
                  case 0:
                    cout << "  Direccion (Calle, Numero, Colonia): ";
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

                // Limpiamos buffer para ingresar el string que introducira el usuario.
                cin.sync();
                getline(cin, sc[i].direccionSucursal[j]);
              }

              cout << endl;
              break;
            case 3:
              cout << "Nuevo codigo: ";
              cin >> sc[i].codigoSucursal;
              cout << endl;
              break;
            case 4:
              cout << "A continuacion se le pedira que introduzca los tres numeros de"
              << " telefono con los que su sucursal cuenta:" << endl;

              // @TODO: Function to check if inserted number is valid.
              for (int j = 0; j < 3; ++j) {
                cout << "  Telefono " << (j + 1) << ": ";
               cin >> sc[i].telefonosSucursal[j];
              }

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

      if (i == (sucursalesDisp - 1)) {
        cout << "Empleado inexistente." << endl << endl;
      }

      else {
        continue;
      }
    }

    cout << "Quieres modificar otra sucursal?" << endl;
    cout << "  1.- Si." << endl;
    cout << "  2.- No." << endl;
    cout << "Eleccion: ";
    cin >> fin;
    checkInputRange(fin, 1, 2);
    cout << endl;
  }
}

int sucursales::menu()
{
  do {
    cout << "Que deseas hacer?" << endl;
    cout << "  1.- Capturar sucursal." << endl;
    cout << "  2.- Ver todas las sucursales." << endl;
    cout << "  3.- Buscar sucursales." << endl;
    cout << "  4.- Modificar sucursales." << endl;
    cout << "  5.- Regresar a menu principal." << endl;

    cout << "Eleccion: ";
    cin >> eleccion;
    checkInputRange(eleccion, 1, 5);
    cout << endl;

    switch (eleccion) {
      case 1:
        sucursales::capturar();
        cout << endl;
        break;
      case 2:
        sucursales::mostrar();
        cout << endl;
        break;
      case 3:
        sucursales::buscar();
        cout << endl;
        break;
      case 4:
        sucursales::modificar();
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

int main()
{
  do {
    cout << "Bienvenido a Megamex" << endl;
    cout << "  1.- Ingresar a Servicios." << endl;
    cout << "  2.- Ingresar a Sucursales." << endl;
    cout << "  3.- Salir." << endl;
    cout << "Eleccion: ";
    cin >> eleccion;
    checkInputRange(eleccion, 1, 3);

    switch (eleccion) {
      case 1:
        servicios::menu();
        cout << endl;
        break;
      case 2:
        sucursales:: menu();
        cout << endl;
        break;
      case 3:
        pause();
        return 0;
    }
  } while (eleccion);
}
