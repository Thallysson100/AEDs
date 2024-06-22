/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Criar um projeto em C/C++ que insira valores inteiros num vetor de 1000 posições. 
 * Depois, apresente um menu de operações que podem ser realizadas no vetor quantas vezes forem desejadas pelo usuário. 
 * As operações devem ser:

   >buscar pela primeira ocorrência de um valor (retornar a posição);
   >busca para contar a quantidade de ocorrências que um valor aparece;
   >busca para contar a quantidade de ocorrências de valores de um intervalo;
   >inverter os valores de um vetor;
   >excluir um valor informado pelo usuário (se existir) deslocando os valores para à esquerda (“não deixar buracos”);
   >retirar todos os valores repetidos.
 * 
 * Autor: Thallysson Luis Teixeira Carvalho 2024.1.08.022
 */

#include <cstdlib>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int TAM=1000;   //tamanho do vetor
    int quant=TAM;        //quantidade de elementos do vetor
    int lista[TAM], aux, num, valor, limin, limsu, opcao;
    srand(time(NULL));
    
    for(int i=0;i<TAM;i++){
        num = 100+rand()%101;  //gera um número aleatório entre 100 e 200
        lista[i]=num;
    }
    
    do{
        int vezes=0, ultm=quant-1, encontrado=0, pos=0, repetido=0;      //reseta as atribuições destas variáveis para cada início da repetição
        
        cout<<"\nDigite a letra correspondente a qual operação você deseja fazer:"<<endl;
        cout<<"0 para sair"<<endl;
        cout<<"1 para informar se o número existe na lista de números aleatórios e qual a sua posição"<<endl;
        cout<<"2 para contar quantas vezes um número arbitrário aparece"<<endl;
        cout<<"3 para contar quantas vezes os valores de um intervalo aparece"<<endl;
        cout<<"4 para inverter a ordem dos elementos"<<endl;
        cout<<"5 para retirar um elemento arbitrário"<<endl;
        cout<<"6 para retirar os elementos repitidos"<<endl;
        cin>>opcao;
    
    
        switch(opcao){
            case 1:        //informa se o número existe no vetor de números aleatórios e qual a sua posição
                cout<<"Digite o valor"<<endl;
                cin>>valor;
                for(int i=0; i<quant && encontrado==0; i++){    //quando o valor for encontrado, a repetição cessa
                    if (valor==lista[i]){
                        encontrado=1;
                        pos=i+1;
                    }
                }    
                if (encontrado==1){
                    cout<<"Valor encontrado na posição "<<pos<<endl;
                    cout<<endl;
                    }
                else
                    cout<<"Valor não encontrado"<<endl;
                
                break;
                
            case 2:   //conta quantas vezes o número informado aparece
                cout<<"Digite o valor:"<<endl;
                cin>>valor;
                for(int i=0; i<quant; i++){
                    if (lista[i]==valor){
                        vezes++;
                        cout<<"Valor encontrado na posição "<<i+1<<endl;
                    }
                }
                cout<<"O valor foi encontrado "<<vezes<<" vezes"<<endl;
                cout<<endl;
                break;
                
            case 3:     //contar quantas vezes os valores de um intervalo aparece
                cout<<"Digite os limites do intervalo"<<endl;
                cin>>limin>>limsu;
                for(int i=0; i<quant; i++){
                    if (lista[i]>=limin && lista[i]<=limsu)
                       vezes++; 
                }
                cout<<"Existem "<<vezes<<" valores nesse intervalo"<<endl;
                cout<<endl;
                break;
                
            case 4:       //inverte a ordem dos elementos do vetor
                for (int i=0; i<quant && i<ultm; i++){    //os elementos são trocados até metade do vetor, por isso i<ultm
                     aux = lista[ultm];
                     lista[ultm] = lista[i];
                     lista[i] = aux;
                     ultm--;
                }
                cout<<"A lista invertida é:"<<endl;
                for (int i=0; i<quant; i++){
                    cout<<lista[i]<<" ";
                    if (i%40==39)    //quebra a linha a cada 40 elementos
                        cout<<endl;
                }
                cout<<endl;
                break;
                
            case 5:     //retira um elemento arbitrário do vetor
                cout<<"Digite um valor para retirá_lo da lista"<<endl;
                cin>>valor;
                for (int i=0; i<quant; i++){
                    if (lista[i]==valor){
                        for (int j=i; j<quant; j++){     //desloca todos os elementos a direira de lista[i] para esquerda para retirá_lo
                            lista[j]=lista[j+1];
                        }
                        quant--;
                        i--;  //para não ignorar o próximo elemento a direita após o vetor ser deslocado 
                    }
                }
                cout<<"Os elementos da lista resultante são:"<<endl;
                for (int i=0; i<quant; i++){
                    cout<<lista[i]<<" ";
                    if (i%40==39)
                        cout<<endl;
                }
                cout<<endl;
                cout<<"A lista resultante possui "<<quant<<" elementos"<<endl;
                break;
                
            case 6:   //para retirar os elementos repitidos do vetor
                for (int i=0; i<quant; i++){
                    for (int j=i+1; j<quant; j++){
                        if (lista[j]==lista[i]){
                            for (int k=j; k<quant; k++){   //retira o elemeto lista[j]
                                lista[k]=lista[k+1];
                            }
                            quant--;
                            i--;
                            
                        }
                    }
                    
                }
                    
                cout<<"Os elementos da lista resultante são:"<<endl;
                for (int i=0; i<quant; i++){
                    cout<<lista[i]<<" ";
                    if (i%40==39)
                        cout<<endl;
                }
                cout<<endl;
                cout<<"A lista resultante possui "<<quant<<" elementos"<<endl;
                break;        
        }
    }while (opcao!=0);
    return 0;
}

