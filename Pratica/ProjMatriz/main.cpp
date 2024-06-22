

/*
Autor: Thallysson Luis Teixeira Carvalho
Matricula: 2024.1.08.022
Este projeto cria 2 matrizes com valores entre 0 e 9
e posibilita as seguntes operações entre elas: transposta, soma,
multiplicação e médias de seus valores.
 */


#include <iostream>
#include <time.h>
#include <iostream>
#include "fmatriz.h" //biblioteca local das funções relacionas ao projeto
using namespace std;

int main(int argc, char** argv) {
    int l1, c1, l2, c2, l3, c3;
    matriz m1, m2, m3;
    cout<<"Digite o números de linhas da primeira matriz (max 100):"<<endl;
    cin>>l1;
    cout<<"Digite o números de colunas da primeira matriz (max 100):"<<endl;
    cin>>c1;
    cout<<"Digite o números de linhas da segunda matriz (max 100):"<<endl;
    cin>>l2;
    cout<<"Digite o números de colunas da segunda matriz (max 100):"<<endl;
    cin>>c2;
   
    srand(time(NULL));  
    //inicializa as matrizes com valores entre 0 e 9
    for (int i=0; i<l1; i++)
        for (int j=0; j<c1; j++)
            m1[i][j]=rand()%10;
    for (int i=0; i<l2; i++)
        for (int j=0; j<c2; j++)
            m2[i][j]=rand()%10;
    mostrar(m1, l1, c1);
    mostrar(m2, l2, c2);

    char op;
    do{
        cout<<"Digite a opção de acordo com a operação desejada:"<<endl;
        cout<<"0-Sair"<<endl;
        cout<<"1-Encontrar a transposta de cada matriz"<<endl;
        cout<<"2-Somar as duas matrizes"<<endl;
        cout<<"3-Multiplicar as duas matrizes"<<endl;
        cout<<"4-Calcular a média entre os valores de cada matriz"<<endl;
        cin>>op;
        switch(op){
            case '1':
                cout<<"Transposta da primeira matriz:"<<endl;
                transp(m1, l1, c1, m3, &l3, &c3);
                mostrar(m3, l3, c3);
                cout<<"Transposta da segunda matriz:"<<endl;
                transp(m2, l2, c2, m3, &l3, &c3);
                mostrar(m3, l3, c3);
                break;

            case '2':
                if (soma(m1, l1, c1, m2, l2, c2, m3, &l3, &c3))
                    cout<<"Não é possível realizar a soma"<<endl<<endl;
                else
                    mostrar(m3, l3, c3);
                break;

            case '3':
                if (multpl(m1, l1, c1, m2, l2, c2, m3, &l3, &c3))
                    cout<<"Não é possível realizar a multiplicação"<<endl<<endl;
                else
                    mostrar(m3, l3, c3);
                break;

            case '4':
                float med;
                media(m1, l1, c1, &med);
                cout<<"Média dos valores da primeira matriz: "<<med<<endl;
                media(m2, l2, c2, &med);
                cout<<"Média dos valores da segunda matriz: "<<med<<endl<<endl;
                break;               
        }
    }while (op!='0');
    return 0;
}









