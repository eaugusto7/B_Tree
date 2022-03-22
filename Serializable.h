/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#ifndef SERIALIZABLE_H_INCLUDED
#define SERIALIZABLE_H_INCLUDED

#include<string>
#include<cstring>
#include<fstream>

using namespace std;

class Serializable{
    public:
            Serializable(){}
            virtual string toString() = 0;
            virtual string toJSON() = 0;
            virtual string toXML() = 0;
            virtual string toCSV() = 0;

            virtual void fromString(string repr) = 0;
            virtual void fromJSON(string repr) = 0;
            virtual void fromXML(string repr) = 0;
            virtual void fromCSV(string repr) = 0;
};

#endif // SERIALIZABLE_H_INCLUDED
