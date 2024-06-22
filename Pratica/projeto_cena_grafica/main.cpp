/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Descrição: criar um arquivo-texto (‘cenagrafica.txt’) onde cada linha terá o nome de um objeto geométrico 2D 
 * (quadrado, retângulo, triângulo, …) ou 3D (cubo, paralelepípedo, cilindro, cone, esfera, …), seguido de seus parâmetros, 
 * a última linha deverá ter a palavra ‘fim’. Calcule e escreva na tela a área total e o volume total da cena para 
 * qualquer quantidade e variedade de objetos 2D ou 3D. 
 * 
 * Autor: Thallysson Luis Teixeira Carvalho 2024.1.08.022
 */

#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>
#define pi 3.14159265359 

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string obj;
    float lado, area, vol, l1, l2, l3, altura, raio, base, soma_area=0, soma_vol=0;
    
    ifstream arq("cenagrafica.txt");      //declara o conteúdo da cenagráfica como a variável arq
    if (!arq.is_open()){
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    arq >> obj;                          //declara um objeto antes da condição de repetição ser testada
    
    while (obj != "fim") {               //quando o objeto for fim, a repetição para
        
        if (obj == "cubo"){
            arq >> lado;
            area = 6*lado*lado;
            vol = lado*lado*lado;
        }
        else if (obj == "esfera"){       //utilizando a indentação else if para  melhor organização
            arq >> raio;
            area = 4*pi*raio*raio;
            vol = 4/3.0*pi*raio*raio*raio;
        }
        else if (obj == "quadrado"){     
            arq >> lado;
            area = lado*lado;
        }
        else if (obj == "circulo"){       //sem acento para facilitar na escrita
            arq >> raio;
            area = pi*raio*raio;
        }
        else if (obj == "retangulo"){     
            arq >> l1;
            arq >> l2;
            area = l1*l2;
        }
        else if (obj == "paralelepipedo"){
            arq >> l1;
            arq >> l2;
            arq >> l3;
            area = 2*(l1*l2 + l1*l3 + l2*l3);
            vol = l1*l2*l3;
        }
        else if (obj == "cilindro"){
            arq >> raio;
            arq >> altura;
            area = 2*pi*raio*(raio+altura);
            vol = pi*raio*raio*altura;
        }
        else if (obj == "cone"){
            arq >> raio;
            arq >> altura;
            area = pi*raio*(raio + sqrt(raio*raio + altura*altura)); //pi*r*(r+g)
            vol = 1/3.0*pi*raio*raio*altura;
        }
        else if (obj == "triangulo"){
            arq >> base;
            arq >> altura;
            area = base*altura/2.0;             
        }
        
        soma_area = soma_area + area;
        
        soma_vol = soma_vol + vol;
    
        arq >> obj;            //declara um novo objeto antes de recomeçar a repetição
       
    }        //fim while
    
    cout << "A soma total das áreas de todas as figuras é: " << soma_area << endl;
    cout << "A soma total dos volumes de todas as figuras é: " << soma_vol << endl;
    
    
    
    return 0;
}

