/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Crie um projeto em C/C++ que gere aleatoriamente 1000 valores de alturas de
 * pessoas entre 1.5 e 2.3 metros, calcule a média, o desvio-padrão, encontre a
 * maior altura, encontre amenor altura e encontre a porcentagem de pessoas maiores 
 * que 2,0 metros.
 * 
 * Autor: Thallysson Luis Teixeira Carvalho 2024.1.08.022
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    srand(time(NULL));
    
    float soma = 0, soma_quad = 0, maior_alt = 0, menor_alt = 2.3, altura;
    int i = 0, maior_que2 = 0;
    
    while (i <= 1000){
        
        altura = (150+rand()%81)/100.0;    /*Gera um número natural aleatório entre 150 e 150+80=230, depois divide por 100
                                             para gerar um número entre 1.5 e 2.3 de duas casas decimais*/
        soma = soma + altura;
        
        soma_quad = soma_quad + pow(altura,2);   /*A1²+A2²+A3²+...*/
        
        if (altura > maior_alt)
            maior_alt = altura;     /*Atualiza a maior altura caso a altura for maior que a atual maior altura */
        
        if (altura < menor_alt)     
            menor_alt = altura;     /*Atualiza a menor altura caso a altura for menor que a menor altura atual (começa com 2.3)*/
        
        if (altura >= 2)
            maior_que2++;           /*Conta quantos indivíduos tem altura maior ou igual a 2 metros*/
        
        i++;
    }
    
    cout << "A média as alturas é: "<< soma/1000.0 <<endl;
    
    cout << "A maior altura é "<< maior_alt <<endl;
    
    cout << "A menor altura é "<< menor_alt <<endl;
    
    cout << "A porcentagem de indivíduos com 2 metros ou mais é: " << maior_que2/10.0 <<endl; /*(maior_que2/1000)x100*/
    
    cout << "O desvio padrão da amostra é: " << pow((soma_quad - pow(soma,2)/1000.0)/999,0.5);
    /*Nesse caso, eu rearranjei a fómula do desvio padrão da amostra para depender apenas
      de variáveis acumulativas, assim não sendo nessesário armazenar o valor de cada altura individualmente
     * 
     OBS.: eu dividi por n-1 (nesse caso, 999) por considerar esse conjunto de dados apenas uma amostra de uma 
     *determinada população, não a população em si*/
    
    return 0;
}

