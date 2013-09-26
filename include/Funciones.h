#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <cstring>
#include <fstream>
#include <sstream>
#include "TablaSimbolos.h"

string producirPalabra( string cadena , unsigned int *posicion );
bool validaEspacio( char espacio );

string producirPalabra( string cadena , unsigned int *posicion )
{
    char palabra[40];
    int contPalabra = 0;
    TablaSimbolos simbolos;
    int valor;

    while( validaEspacio( cadena[*posicion] ) )
    {
        (*posicion)++;
    }

    valor = simbolos.validaUnSimbolo( cadena[*posicion] );

    if( valor != -1 )
    {
        palabra[contPalabra] = cadena[*posicion];
        contPalabra++;
        (*posicion)++;

        if( valor >= 0 && valor <= 5 )
        {

            if( simbolos.validaDosSimbolo( cadena[*posicion-1] , cadena[*posicion] ) )
            {
                palabra[contPalabra] = cadena[*posicion];
                contPalabra++;
                (*posicion)++;
            }
        }
    }

    else
    {

        do
        {

            palabra[contPalabra] = cadena[*posicion];
            contPalabra++;
            (*posicion)++;

        }while( simbolos.validaUnSimbolo( cadena[*posicion] ) == -1  &&
               !validaEspacio( cadena[*posicion] )&& (*posicion) < cadena.length() );

        if( validaEspacio( cadena[*posicion] ) )
           (*posicion)++;
    }


    palabra[contPalabra]='\0';

    return (string)palabra;
}

bool validaEspacio( char espacio )
{
    if( espacio == ' ' || espacio == '\t' || espacio == '\n')
        return true;
    return false;
}

#endif // FUNCIONES_H_INCLUDED
