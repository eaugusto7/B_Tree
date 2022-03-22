/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#ifndef PAGINA_H_INCLUDED
#define PAGINA_H_INCLUDED

#include "Cabecalho.h"

class Pagina
{
public:
    int keys[(2*3)-1];
    Pagina(){for(int i=0; i<((2*3)-1);i++)keys[i] = NULL;};

    string toString(string,int);
    void fromString(int[],string);
};

#endif // PAGINA_H_INCLUDED
