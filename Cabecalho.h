/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#include <string>
#include <type_traits>
#include <iostream>
#include "Serializable.h"

using namespace std;

class Cabecalho: public Serializable
{
public:
    Cabecalho();
    Cabecalho(const string t, const int v);
    Cabecalho(const Cabecalho &c);
    Cabecalho operator = (const Cabecalho &c);
    unsigned long int primeiroExcluido() const;
    void primeiroExcluido(unsigned long int r);
    unsigned long int primeiroValido() const;
    void primeiroValido(unsigned long int r);

    string tipoArquivo() const;
    void tipoArquivo(string t);
    int versao() const;
    void versao(int v);

    string toCSV(){return "";}
    string toXML(){return "";}
    string toJSON(){return "";}

    string toString()
    {
        int r,i=0;
        fstream arq = fstream("Pagina.dat", ios_base::in | ios_base::out | ios_base::binary);

        if(!arq.is_open())
            arq.open("Pagina.dat", ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);

        arq.clear();
        arq.seekg(i*sizeof(r));
        arq.read(reinterpret_cast<char*>(&r),sizeof(r));
        cout<<r<<endl;
        arq.close();

        return std::to_string(r);
    }

    void fromCSV(string repr) {}
    void fromXML(string repr) {}
    void fromJSON(string repr) {}

    void fromString(string repr){
        int r,i;
        fstream arq = fstream("Pagina.dat", ios_base::in | ios_base::out | ios_base::binary);

        if(!arq.is_open())
            arq.open("Pagina.dat", ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);

        for(i=0; i<(2*3) && arq.good(); i++){
            r = std::stoi(repr);
            arq.seekp(i*sizeof(r));
            arq.write(reinterpret_cast<char*>(&r),sizeof(r));
        }
        arq.close();
    }

protected:
    string tipo;
    int ver;
    unsigned long int primExcluido;
    unsigned long int primValido;
};

#endif // CABECALHO_H_INCLUDED
