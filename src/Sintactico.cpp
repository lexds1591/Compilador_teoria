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
    lexico.sigPalabra();
    return sentencia( &lexico );
}
int Sintactico::sentencia( Lexico *lexico )
{


    if( lexico->getTipo() == ERROR )
    {
        cout << "ERROR LEXICO  << ";
        return ERROR;
    }
    else
    {
        if( lexico->getPalabra() == "" )
        {
            return EXITO;
        }
        else if( expresion( lexico ) == 0 )
        {
            if( lexico->getPalabra()  == ";" )
            {
                lexico->sigPalabra();
                if( lexico->getPalabra() != "" )
                {
                    return sentencia( lexico );
                }


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


}
int Sintactico::expresion( Lexico *lexico )
{
    if( termino( lexico ) == 0 )
    {
       while( lexico->getTipo() == ADICION || lexico->getTipo() == MULTIPLICACION )
        {
            lexico->sigPalabra();
            if ( lexico->getTipo() == ERROR )
            {
                cout << "ERROR LEXICO  << ";
                return ERROR;
            }
            else if( termino( lexico ) == ERROR )
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

        if( lexico->getTipo() == ERROR )
        {
            cout << "ERROR LEXICO  << ";
            return ERROR;
        }
        else if( expresion( lexico ) == ERROR )
        {
            return ERROR;
        }

        if( lexico->getPalabra() == ")" )
        {
            lexico->sigPalabra();

            if( lexico->getTipo() == ERROR )
            {
                cout << "ERROR LEXICO  << ";
                return ERROR;
            }
        }
        else
            return ERROR;
    }
    else if( lexico->getPalabra() == "+" )
    {
        lexico->sigPalabra();
        return expresion(lexico);
    }
    else if( lexico->getTipo() == ENTERO || lexico->getTipo() == IDENTIFICADOR )
    {
        lexico->sigPalabra();
        if( lexico->getTipo() == ERROR )
        {
            cout << "ERROR LEXICO  << ";
            return ERROR;
        }
    }
    else
        return ERROR;
    return EXITO;
}
