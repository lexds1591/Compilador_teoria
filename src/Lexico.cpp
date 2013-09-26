#include "../include/Lexico.h"
#include "../include/Funciones.h"

Lexico::Lexico( int estado , string cadena )
{
    estado_ = estado;
    posicion = 0;
    cadena_ = cadena;
}

Lexico::~Lexico( void )
{
    //dtor
}

void Lexico::analizar( string palabra )
{
    for( unsigned int i = 0 ; i < palabra.length() && estado_ !=  24 ; i++ )
    {
        switch( estado_ )
        {
            case 0: //inicio
                    if( isalpha( palabra[i] ) || palabra[i] == '_' )
                    {
                        estado_ = 1;
                    }
                    else if( palabra[i] == '+'  || palabra[i] == '-' )
                    {
                        estado_ = 2;
                    }
                        else if ( isdigit( palabra[i] ) )
                        {
                            estado_ = 3;
                        }
                            else if ( palabra[i] == '"' )
                            {
                                estado_ = 6;
                            }
                                else if ( palabra[i] == '*'  || palabra[i] == '/' )
                                {
                                    estado_ = 9;
                                }
                                    else if ( palabra[i] == '>' || palabra[i] == '<' )
                                    {
                                        estado_ = 10;
                                    }
                                        else if ( palabra[i] == '!' )
                                        {
                                            estado_ = 12;
                                        }
                                            else if ( palabra[i] == '&' )
                                            {
                                                estado_ = 14;
                                            }
                                                else if ( palabra[i] == '|' )
                                                {
                                                    estado_ = 16;
                                                }
                                                    else if ( palabra[i] == '(' )
                                                    {
                                                        estado_ = 18;
                                                    }
                                                        else if ( palabra[i] == ')'  )
                                                        {
                                                            estado_ = 19;
                                                        }
                                                            else if ( palabra[i] == '{' )
                                                            {
                                                                estado_ = 20;
                                                            }
                                                                else if( palabra[i] == '}' )
                                                                {
                                                                    estado_ = 21;
                                                                }
                                                                    else if( palabra[i] == '=' )
                                                                    {
                                                                        estado_ = 22;
                                                                    }
                                                                        else if( palabra[i] == ',' || palabra[i] == ';' )
                                                                        {
                                                                            estado_ = 23;
                                                                        }
                                                                            else
                                                                            {
                                                                                estado_ = 24;
                                                                            }
                break;
            case 1://terminal
                    if( ( isalpha( palabra[i] ) || palabra[i] == '_' )||
                       isdigit( palabra[i] ) )
                    {
                        estado_ = 1;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 2://terminal
                    break;
            case 3://terminal
                    if( isdigit( palabra[i] ) )
                    {
                        estado_ = 3;
                    }
                    else if( palabra[i] == '.' )
                    {
                        estado_ = 4;
                    }
                        else
                        {
                            estado_ = 24;
                        }
                    break;
            case 4:
                    if ( isdigit( palabra[i] ) )
                    {
                        estado_ = 5;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 5://terminal
                    if( isdigit( palabra[i] ) )
                    {
                        estado_ = 5;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 6:
                    if( palabra[i] == '"' )
                    {
                        estado_ = 7;
                    }
                        else if( isascii( palabra[i] ) )
                        {
                            estado_ = 6;
                        }
                            else
                            {
                                estado_ = 24;
                            }
                    break;
            case 7://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            ///estado 8 eliminado por implementacion ""
            case 9://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 10://terminal
                    if( palabra[i] == '=' )
                    {
                        estado_ = 11;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 11://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 12://terminal
                    if( palabra[i] == '=' )
                    {
                        estado_ = 13;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 13://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 14:
                    if( palabra[i] == '&' )
                    {
                        estado_ = 15;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 15://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 16:
                    if( palabra[i] == '|' )
                    {
                        estado_ = 17;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 17://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 18://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 19://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 20://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 21://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 22://terminal
                    if( palabra[i] == '=' )
                    {
                        estado_ = 11;
                    }
                    else
                    {
                        estado_ = 24;
                    }
                    break;
            case 23://terminal
                    if( palabra[i] != '\0' )
                        estado_ = 24;
                    break;
            case 24://error
                    break;
            default:
                    cout << "No debe entrar en esta opcion!(Lexico_1)" << endl;
                    break;
        }

    }

    //Definir el tipo mediante el estado terminal que finalizo
    switch( estado_ )
    {
        case 1:
                tipo_ = IDENTIFICADOR;
                break;
        case 2:
                tipo_ = ADICION;
                break;
        case 3:
                tipo_ = ENTERO;
                break;
        case 5:
                tipo_ = REAL;
                break;
        case 7:
                tipo_ = CADENA;
                break;
        case 9:
                tipo_ = MULTIPLICACION;
                break;
        case 10:
                tipo_ = RELACIONAL;
                break;
        case 11:
                tipo_ = RELACIONAL;
                break;
        case 12:
                tipo_ = LOGICO;
                break;
        case 13:
                tipo_ = RELACIONAL;
                break;
        case 15:
                tipo_ = LOGICO;
                break;
        case 17:
                tipo_ = LOGICO;
                break;
        case 18:
                tipo_ = PARENTESIS_IZQ;
                break;
        case 19:
                tipo_ = PARENTESIS_DER;
                break;
        case 20:
                tipo_ = LLAVE_IZQ;
                break;
        case 21:
                tipo_ = LLAVE_DER;
                break;
        case 22:
                tipo_ = ASIGNACION;
                break;
        case 23:
                tipo_ = DELIMITADOR;
                break;
        case 24:
                tipo_ = ERROR;
                break;
        default:
                tipo_ = ERROR;
                break;
    }
}
void Lexico::sigPalabra( void )
{
    setEstado( 0 );
    setPalabra( producirPalabra( cadena_ , & posicion) );
    analizar( palabra_ );
}
