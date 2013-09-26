#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H


#include <string>
#include <iostream>
using namespace std;

class TablaSimbolos
{
    public:
        TablaSimbolos();
        virtual ~TablaSimbolos();
        int validaUnSimbolo( char simbolo );
        bool validaDosSimbolo( char anterior , char actual  );
    protected:
    private:
        string simbolos_;
};

#endif // TABLASIMBOLOS_H
