#ifndef LEXICO_H
#define LEXICO_H


#include <string>
#include <iostream>
#include <cctype>

#define ERROR         -1
#define EXITO          0
#define IDENTIFICADOR  1
#define ENTERO         2
#define REAL           3
#define CADENA         4
#define ADICION        5
#define MULTIPLICACION 6
#define ASIGNACION     7
#define RELACIONAL     8
#define LOGICO         9
#define PARENTESIS_IZQ 10
#define PARENTESIS_DER 11
#define LLAVE_IZQ      12
#define LLAVE_DER      13
#define DELIMITADOR    14

using namespace std;

class Lexico
{
    public:

        Lexico( int estado , string cadena );
        virtual ~Lexico( void );

        unsigned int getEstado( void )
        {
            return estado_;
        }
        void setEstado( unsigned int val )
        {
            estado_ = val;
        }
        int getTipo()
        {
            return tipo_;
        }
        string getPalabra( void )
        {
            return palabra_;
        }
        void setPalabra( string  palabra )
        {
            palabra_ = palabra;
        }
        void setTipo( int val )
        {
            tipo_ = val;
        }
        void sigPalabra( void );

        void analizar( string palabra );
    protected:
    private:
        unsigned int estado_;
        int tipo_;
        unsigned int posicion;
        string cadena_;
        string palabra_;

};

#endif // LEXICO_H
