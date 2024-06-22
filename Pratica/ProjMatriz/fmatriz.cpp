#include <iostream>
#include "fmatriz.h"
using namespace std;

/*Função que toma como entrada uma matriz e suas dimenções e
escreve ela na tela*/
void mostrar(matriz m, int l, int c){
    for (int i=0; i<l; i++){
        for (int j=0; j<c; j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

/*Função que toma como entrada uma matriz e suas dimenções
e armazena a transposta em outra matriz e determina suas dimenções*/
void transp(matriz m1, int l1, int c1,
                matriz m2, int *l2, int *c2){
    for (int i=0; i<l1; i++)
        for (int j=0; j<c1; j++)
            m2[j][i]=m1[i][j];
    *l2=c1;
    *c2=l1;
}

/*Função que toma como entrada duas matrizes e suas respectivas dimenções, uma terceira
matriz e dois ponteiros. Armazena a soma das duas primeiras matrizes na terceira
e armazena suas dimenções nos ponteiros. Retorna 1 se a operação for impossível*/
int soma(matriz m1, int l1, int c1,
        matriz m2, int l2, int c2,
        matriz m3, int *l3, int *c3){


    if (l1!=l2 || c1!=c2) //testa se não é possível realizar a soma
        return 1;
    for (int i=0; i<l1; i++)
        for (int j=0; j<c1; j++)
            m3[i][j]=m1[i][j]+m2[i][j];
    *l3=l1;
    *c3=c1;
    return 0;
}

/*Função que toma como entrada duas matrizes e suas respectivas dimenções, uma terceira
matriz e dois ponteiros. Armazena a multiplicação das duas primeiras matrizes na terceira
e armazena suas dimenções nos ponteiros. Retorna 1 se a operação for impossível*/
int multpl(matriz m1, int l1, int c1,
        matriz m2, int l2, int c2,
        matriz m3, int *l3, int *c3){
    if (c1!=l2)  //testa se não é possível realizar a multiplicação
        return 1;
    int soma;
    for (int i=0; i<l1; i++)
        for (int j=0; j<c2; j++){
            soma=0;
            for (int k=0; k<c1; k++)
                soma+=m1[i][k]*m2[k][j];
            m3[i][j]=soma;
        }
    *l3=l1;
    *c3=c2;
    return 0;
}

/*Função que toma como entrada uma matriz, suas
dimenções e um ponteiro e armazena a média de seus valores no ponteiro*/
void media(matriz m, int l, int c, float *med){
    int soma=0;
    for (int i=0; i<l; i++)
        for (int j=0; j<c; j++)
            soma+=m[i][j];
    *med=(float) soma/(l*c);
}