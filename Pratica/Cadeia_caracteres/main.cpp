/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Tema: cadeia de caracteres.

Objetivo: compreender e manipular caracteres num vetor de caracteres.

Roteiro:
    >iniciar os vetores ‘nome’ e ‘sobrenome’ com as letras do seu próprio nome, e não se esqueça do ‘\0’ no final;
    >construir o vetor ‘nomecompleto’ copiando as letras dos vetores nome e sobrenome utilizando repetições com índices;
    >colocar os caracteres do nome completo em maiusculas;
    >agora, colocar os caracteres em minúsculas, menos as primeiras letras do nome completo;
    >retirar os espaços de um nome completo;
    >procurar se um nome está dentro de um nome completo.
 * 
 * Autor:Thallysson Luis Teixeira Carvalho 20214.1.08.022
 */

#include <cstdlib>
#include <stdio.h>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char nome[31], sobrenome[31], nomecompleto[61], busca[31];
    int i, j;
    nome[0]='T';
    nome[1]='h';
    nome[2]='a';
    nome[3]='l';
    nome[4]='l';
    nome[5]='y';
    nome[6]='s';
    nome[7]='s';
    nome[8]='o';
    nome[9]='n';
    nome[10]='\0';
    
    printf("\n Nome: %s!\n", nome);
    
    sobrenome[0]='L';
    sobrenome[1]='u';
    sobrenome[2]='i';
    sobrenome[3]='s';
    sobrenome[4]=' ';
    sobrenome[5]='T';
    sobrenome[6]='e';
    sobrenome[7]='i';
    sobrenome[8]='x';
    sobrenome[9]='e';
    sobrenome[10]='i';
    sobrenome[11]='r';
    sobrenome[12]='a';
    sobrenome[13]=' ';
    sobrenome[14]='C';
    sobrenome[15]='a';
    sobrenome[16]='r';
    sobrenome[17]='v';
    sobrenome[18]='a';
    sobrenome[19]='l';
    sobrenome[20]='h';
    sobrenome[21]='o';
    sobrenome[22]='\0';
    
    printf("\n Sobrenome: %s!\n", sobrenome);
    
    i=0;
    while (nome[i]!='\0') {
        nomecompleto[i]=nome[i];
        i++;
    } 
    nomecompleto[i]=' ';
    
    j=i+1;
    i=0;
    while (sobrenome[i]!='\0') {      //começa de onde parou o nome para completar com o sobrenome
       nomecompleto[j]=sobrenome[i];
       j++;
       i++;
    } 
    nomecompleto[j]='\0';

    
    printf("\n Nome Completo: %s!\n", nomecompleto);
    
    //transforma nome completo em maiúsculo
    for (int i=0; nomecompleto[i]!='\0'; i++){    
        if (nomecompleto[i] >= 'a' && nomecompleto[i] <= 'z'){    //testa se o caracter é minúsculo
            nomecompleto[i]=nomecompleto[i]-32;
        }
    }
 
    printf("\n Nome Completo em maiúsculo: %s!\n", nomecompleto);
    
    //transforma nome completo em minúsculo
    for (int i=1; nomecompleto[i]!='\0'; i++){
        if (nomecompleto[i]!=' ' && nomecompleto[i-1]!=' '){    //reconhece quando começa um nome (após um espaço)
            nomecompleto[i]=nomecompleto[i]+32;
        }
    }
    
    printf("\n Nome Completo em minúsculo (menos as iniciais): %s!\n", nomecompleto);
     
    //tira os espaços
    for (int i=0; nomecompleto[i]!='\0'; i++){    
        if (nomecompleto[i]==' '){
            for (int j=i; nomecompleto[j]!='\0'; j++){
                 nomecompleto[j]=nomecompleto[j+1];
            }
        }
    }
     
    printf("\n Nome Completo: %s!\n", nomecompleto);
    
    
    printf("\nDigite o nome que deseja buscar (sem espaço):\n");
    scanf("%30[^\n]", &busca);
    
    int encontrado=-1;
    for (int i=0; nomecompleto[i]!='\0' && encontrado!=1;i++){
        if (nomecompleto[i]==busca[0]){    //busca o primeiro caracter de busca em nomecompleto
            j=0;
            encontrado=-1; 
            while (busca[j]!='\0' && encontrado!=0){       //loop que testa se todos os caracteres de busca estão em nomecompleto
                if (busca[j]!=nomecompleto[i+j])   //se encontrar uma desigualdade antes de acabar o vetor busca, então busca não foi encontrado nessa sessão
                    encontrado=0;
                j++;
            }
            if (busca[j]=='\0' && encontrado!=0)      //se chegou no final do loop sem encontrar uma desigualdade, então busca foi encontrado
                encontrado=1;
        }
    }
    if (encontrado==1)
        printf("Nome %s encontrado no nome completo", busca);
    if (encontrado==0)
        printf("Nome %s  não encontrado no nome completo", busca); 
    
    return 0;
    
   
}

