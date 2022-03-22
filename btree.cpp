/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#include "btree.h"

using namespace std;

btree::btree()
{
    int i;
    this->leaf = 1;
    this->n = 0;
    for (i=0; i<=2*T; i++) this->children[i] = NULL;
}

void btree::B_TREE_SPLIT_CHILD(btree* x,int i)
{
    int j;
    btree* z = new btree();
    btree* y = x->children[1];
    z->leaf = y->leaf;
    z->n = T-1;

    for (j=1; j<=T-1; j++) z->pag.keys[j] = y->pag.keys[j+T];

    if (!y->leaf)
    {
        for(j=1; j<=T; j++) z->children[j] = y->children[j+T];
        y->n = T-1;

        for (j=x->n+1; j>=i+1; j--) x->children[j+1] = x->children[j];
        x->children[i+1] = z;

        for (j=x->n; j>=i; j--)x->pag.keys[j+1] = x->pag.keys[j];
    }
    x->pag.keys[i] = x->pag.keys[T];
    x->n = x->n+1;
}

void btree::B_TREE_INSERT_NONFULL(btree* x,int k)
{
    int i=x->n;
    if (x->leaf)
    {
        while(i>=1 && k<x->pag.keys[i])
        {
            x->pag.keys[i+1] = x->pag.keys[i];
            i--;
        }
        x->pag.keys[i+1] = k;
        x->n = x->n+1;
        x->pag.fromString(x->pag.keys,"PaginaRaiz.dat");
    }
    else
    {
        while(i>=1 && k<x->pag.keys[i]) i--; i++;

        if (x->children[i]->n == 2*T - 1)
        {
            B_TREE_SPLIT_CHILD(x,i);
            if (k > x->pag.keys[i])i++;
            B_TREE_INSERT_NONFULL(x->children[i],k);
        }
    }
}

void btree::B_TREE_INSERT(btree** root,int k)
{
    btree* r = *root;

    if (r->n == (2*3)-1)
    {
        btree* s= new btree();
        *root=s;
        s->leaf = false;
        s->n = 0;
        s->children[1] = r;
        B_TREE_SPLIT_CHILD(s,1);
        B_TREE_INSERT_NONFULL(s,k);
    }
    else B_TREE_INSERT_NONFULL(r,k);
}

void btree::B_TREE_REMOVE(btree** root,int k){
    btree* r = *root;
    bool achou=false;
    int i;

    for(i=0; i<((2*r->T)-1);i++)if(r->pag.keys[i] == k) achou = true;

    if ((achou == k) &&  r->leaf){
        int vet[(2*r->T) - 1];
        for(i=0; i<((2*r->T)-1);i++){
            if(r->pag.keys[i] != k){
                vet[i] = r->pag.keys[i];
                r->pag.keys[i] = vet[i];
            }
        }
        r->pag.fromString(vet,"PaginaRaiz.dat");
    }
}

void btree::B_TREE_PRINT(btree** root,int k){
    int i;
    btree* r = *root;

    for(i=0; i<((r->T*2)-1);i++)r->pag.toString("PaginaRaiz.dat",i);
}

void btree::B_TREE_SEARCH(btree** root,int k){
    int i,valor;
    bool achou=false;
    btree* r = *root;

    for(i=0; i<((r->T*2)-1);i++){
        std::stringstream s_num(r->pag.toString("PaginaRaiz.dat",i));
        s_num>>valor;
        if(valor == k) achou=true;
    }

    if(achou)cout<<"Chave foi Encontrada"<<endl;
    else{cout<<"Chave nao Encontrada"<<endl;}
}
