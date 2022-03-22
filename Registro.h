/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED
#include "Serializable.h"

template<class T>
class Registro: public Serializable
{
private:
    T dados;
    bool apagado;
    unsigned long int prox;

public:
    Registro();
    Registro(T i);
    Registro(const Registro<T> &r);
    Registro<T> operator = (const Registro<T> &r);
    bool operator == (const Registro<T> &r);
    T info() const;
    void info(T i);
    unsigned long int proximo() const;
    void proximo(unsigned long int p);
    bool excluido() const;
    void excluir();
    string toCSV() {}
    string toJSON() {}
    string toXML() {}
    string toString() {}

    void fromCSV(string repr) {}
    void fromJSON(string repr) {}
    void fromXML(string repr) {}
    void fromString(string repr) {}
};

#endif // REGISTRO_H_INCLUDED
