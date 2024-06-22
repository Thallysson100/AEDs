/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * >criar 2 vetores de 10 números inteiros, com valores repetidos em cada um;
   >remover os valores repetidos de cada um deles;
   >implementar a operação de união entre eles;
   >implementar a operação de intersecção entre eles;
   >melhorar as operações acima para que elas sejam o mais simples e rápido possível.
 * 
 * Nome:Thallysson Luis Teixeira Carvalho 2024.1.08.022
 */

#include <cstdlib>
#include <iostream>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int conjunto1[10] = {5, 4, 2, 5, 3, 2, 4, 8, 2, 9};
    int conjunto2[10] = {7, 1, 12, 10, 9, 2, 8, 1, 2, 7};
    
    int tam1=10, tam2=10;
    
    //retira os elementos repetidos do conjunto 1
    for (int i=0; i<tam1; i++){
        for (int j=i+1; j<tam1; j++){
            if (conjunto1[j]==conjunto1[i]){
                for (int k=j; k<tam1; k++)   
                    conjunto1[k]=conjunto1[k+1];
                tam1--;
                i--;     //nesse caso, não precisa, porém este caso é especial
            }
        }   
    }
    
    cout<<"conjunto 1:"<<endl;
    for (int i=0; i<tam1; i++)
        cout<<conjunto1[i]<<" ";
    cout<<"\n\n";
    
    //retira os elementos repetidos do conjunto 2
    for (int i=0; i<tam2; i++){
        for (int j=i+1; j<tam2; j++){
            if (conjunto2[j]==conjunto2[i]){
                for (int k=j; k<tam2; k++)   
                    conjunto2[k]=conjunto2[k+1];
                tam2--; 
                i--;
            }
        }   
    }
    
    cout<<"Conjunto 2:"<<endl;
    for (int i=0; i<tam2; i++)
        cout<<conjunto2[i]<<" ";
    cout<<"\n\n";
    
    int uniao[20];
    int tamun=tam1;   //primeiramente, o número de elementos de uniao será igual a número de elementos de conjunto 1
    
    //adiciona conjunto 1 a uniao
    for (int i=0; i<tam1; i++){
        uniao[i]=conjunto1[i];
    }
    
    //adiciona conjunto 2 a uniao sem repetir elemento
    int ja_exis;
    for (int i=0; i<tam2; i++){
        ja_exis=0;
        for (int j=0; j<tam1 && ja_exis==0; j++){  //verifica se o elemento conjunto2[i] já existe em uniao
            if (conjunto2[i]==uniao[j])
                ja_exis=1;
        }
        if (ja_exis==0){
            uniao[i+tam1]=conjunto2[i];
            tamun++;
        }
    }
    
    cout<<"A união dos dois conjuntos é:"<<endl;
    for (int i=0; i<tamun; i++)
        cout<<uniao[i]<<" ";
    cout<<"\n\n";
    
    int interseccao[20];
    int tamin=0, parar;
    
    for(int i=0; i<tam1; i++){
        parar=0;
        for(int j=0; j<tam2 && parar==0; j++){
            if (conjunto1[i]==conjunto2[j]){    //verifica se o elemento conjunto1[i] repete em conjunto2
                interseccao[tamin]=conjunto1[i];
                tamin++;
                parar=1;   //substitui o break
            }       
        }
    }
    
    cout<<"A intersecção dos dois conjuntos é:"<<endl;
    for (int i=0; i<tamin; i++)
        cout<<interseccao[i]<<" ";
    cout<<"\n\n";

    return 0;
}

