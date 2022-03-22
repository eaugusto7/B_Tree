/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <iostream>
#include <sstream>
#include "Pagina.h"

class btree
{
    public:
        const int T = 3;
        int n;
        int leaf;

        Pagina pag;
        struct btree* children[2*3];

        btree();
        void B_TREE_SPLIT_CHILD(btree* x,int i);
        void B_TREE_INSERT_NONFULL(btree* x,int k);
        void B_TREE_INSERT(btree** root,int k);
        void B_TREE_REMOVE(btree** root,int k);
        void B_TREE_PRINT(btree** root,int k);
        void B_TREE_SEARCH(btree** root,int k);
};

#endif // BTREE_H_INCLUDED
