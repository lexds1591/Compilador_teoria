#include "../include/Sintactico.h"

Sintactico::Sintactico( void )
{
    //ctor
}

Sintactico::~Sintactico( void )
{
    //dtor
}
int Sintactico::analizar( Lexico lexico )
{
    return sentencia( &lexico );
}
int Sintactico::sentencia( Lexico *lexico )
{
    lexico->sigPalabra();
    if( lexico->getPalabra() == "" )
    {
        return EXITO;
    }
    else if( expresion( lexico ) == 0 )
    {
        if( lexico->getPalabra()  == ";" )
        {
            sentencia( lexico );
        }
        else
            return ERROR;
    }
    else
    {
        return ERROR;
    }

    return EXITO;

}
int Sintactico::expresion( Lexico *lexico )
{
    if( termino( lexico ) == 0 )
    {
        while( lexico->getTipo() == ADICION || lexico->getTipo() == MULTIPLICACION )
        {
            lexico->sigPalabra();
            if( termino( lexico ) == ERROR )
            {
                return ERROR;
            }
        }
    }
    else
        return ERROR;
    return EXITO;
}
int Sintactico::termino( Lexico *lexico )
{
    if( lexico->getPalabra() == "(" )
    {
        lexico->sigPalabra();
        if( expresion( lexico ) == ERROR )
        {
            return ERROR;
        }
        if( lexico->getPalabra() == ")" )
        {
            lexico->sigPalabra();
        }
        else
            return ERROR;
    }
    else if( lexico->getTipo() == ENTERO || lexico->getTipo() == IDENTIFICADOR )
    {
        lexico->sigPalabra();
    }
    else
        return ERROR;
    return EXITO;
}
