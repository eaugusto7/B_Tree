/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#include <iostream>
#include "btree.h"
#include "Serializable.h"
#include "Cabecalho.h"

using namespace std;

void Menu(){
    btree *ab = new btree();
    while(true){
        int i,k;
        cout<<endl<<"1. Inserir valor"<<endl;
        cout<<"2. Remover valor"<<endl;
        cout<<"3. Imprimir pagina"<<endl;
        cout<<"4. Buscar valor"<<endl;
        cout<<"5. Sair"<<endl;
        cout<<"Digite uma opcao : ";
        cin>>i;

        switch (i){
            case 1:
                cout<<endl<<"Digite a chave: ";
                cin>>k;
                ab->B_TREE_INSERT(&ab,k);
                break;

            case 2:
                cout<<endl<<"Digite a chave: ";
                cin>>k;
                ab->B_TREE_REMOVE(&ab,k);
                break;

            case 3:
                ab->B_TREE_PRINT(&ab,k);
                break;

            case 4:
                cout<<endl<<"Digite a chave: ";
                cin>>k;
                ab->B_TREE_SEARCH(&ab,k);
                break;

            case 5:
                break;
            default:
                break;
        }
        if(i == 5) break;
    }
}

int main ()
{
    Menu();
    return 0;
}
