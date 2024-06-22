/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Author:  Thallysson Luis Teixeira Carvalho 2024.1.08.022
 * 
 * 
 *  Crie um projeto em C/C++ para informar ao usuário qual o tipo de
 * triângulo formado a partir das dimensões dos lados de um triângulo. 
 * O projeto deve informar: quando não forma triângulo, triângulo equilátero, 
 * triângulo isósceles, triângulo escaleno e triângulo-retângulo.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float a, b, c;
    
    cout << "Informe os lados do triângulo" <<endl; 
    
    cout << "a:";
    cin >> a;
    
    while (a < 0){                  /*testa se o valor a é definido*/
        cout << "Valor a indefinido, digite novamente";
        cin >> a;      
    }
    
    cout << "b:";
    cin >> b;
    
    while (b < 0){                  /*testa se o valor b é definido*/
        cout << "Valor b indefinido, digite novamente";
        cin >> b;          
    }
    
    cout << "c:";
    cin >> c;
    
    while (c < 0){               /*testa se o valor c é definido*/
        cout << "Valor c indefinido, digite novamente";
        cin >> c;        
    }
    
    if (a+b<=c or a+c<=b or b+c<=a )          /*testa se é possível formar triângulo*/
        cout << "Não forma triângulo";
    else{
        if (a==b and b==c)                    /*testa se o triângulo é equilátero*/
            cout << "Triângulo equilátero";
        else{
            if (a==b or a==c or b==c)         /*testa se o triângulo é isóceles*/
                cout << "Triângulo isóceles";
            else                              /*se o triângulo não for equilátero ou isóceles, é escaleno*/
                cout << "Triângulo escaleno"; 
           }
        if (a*a==b*b+c*c or b*b==a*a+c*c or c*c==a*a+b*b) /*testa se o triângulo é retângulo, pode ser isóceles ou escaleno também*/
            cout << " e retângulo";
    }
    return 0;
}

