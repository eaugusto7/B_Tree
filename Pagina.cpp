/*  INSTITUTO FEDERAL DE MINAS GERAIS

    Trabalho 1 da Disciplina de Tecnicas de Programacao
    Nome: Eduardo Augusto
*/

#include "Pagina.h"

void Pagina::fromString(int valor[], string nome_arquivo)
{
    int r,i;
    fstream arq = fstream(nome_arquivo, ios_base::in | ios_base::out | ios_base::binary);

    if(!arq.is_open())
        arq.open(nome_arquivo, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);

    for(i=1; i<((2*3)) && arq.good(); i++){
        cout<<valor[i]<<endl;
        r = valor[i];
        arq.seekp((i-1)*sizeof(r));
        arq.write(reinterpret_cast<char*>(&r),sizeof(r));
    }

    if(arq.good())cout<<"Escrita Realizada \n";

    arq.clear();
    arq.close();
}

string Pagina::toString(string nome_arquivo,int i)
{
    int r;
    fstream arq = fstream(nome_arquivo, ios_base::in | ios_base::out | ios_base::binary);

    if(!arq.is_open())
        arq.open(nome_arquivo, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);

    arq.clear();
    arq.seekg(i*sizeof(r));
    arq.read(reinterpret_cast<char*>(&r),sizeof(r));
    cout<<r<<endl;
    arq.close();

    return std::to_string(r);
}
