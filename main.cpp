/*@Practica #2
 *Alejandro Duarte S�nchez
 *Seccion:D02
 */

/*************************** TO DO *********************************************
*                                                                              *
*    1.-Realizar pruebas                                                       *
*                                                                              *
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "include/Lexico.h"
#include "include/Sintactico.h"
#include "include/ArchivoIO.h"

using namespace std;

int main()
{
    string cadena;
    int estado = 0;
    string palabra;
    char ruta[] = "archivo.txt";
    char rutaSalida[]="salida.txt";
    char permisos[] = "r";

    cadena = leerArchivo( ruta ,permisos );//se obtiene toda la cadena del archivo

    Lexico lexico( estado , cadena );
    Sintactico sintactico;

    if( sintactico.analizar( lexico ) == EXITO )//se realiza analisis sintactico
    {
        escribeSalida( rutaSalida , 1 );
    }
    else
    {
        escribeSalida( rutaSalida , 0 );
        cout << "************** SE ENCONTRARON ERRORES **************" << endl;
    }
    #ifdef _WIN32
            system("pause");
    #endif
    return EXIT_SUCCESS;
}
