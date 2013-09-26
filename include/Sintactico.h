#ifndef SINTACTICO_H
#define SINTACTICO_H

#include <iostream>
#include <string>
#include "../include/Lexico.h"

using namespace std;

class Sintactico
{
    public:
        Sintactico( void );
        virtual ~Sintactico( void );
        int analizar( Lexico lexico );
    protected:
    private:
        int sentencia( Lexico *lexico );
        int expresion( Lexico *lexico );
        int termino( Lexico *lexico );
};

#endif // SINTACTICO_H
