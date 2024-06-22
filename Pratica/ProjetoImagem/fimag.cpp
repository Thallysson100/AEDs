#include <stdlib.h>
#include <time.h>
#include "fmagem.h"
//recebe a matriz da imagem e suas dimenções e muda o seu tom 
void muda_tom(Timagem img, int lin, int col, int fator){
    int aux;
    for (int i=0; i<lin; i++)
        for (int j=0; j<col; j++) {
            aux=img[i][j]+fator; // Aplica o fator ao tom do pixel
            if (aux>255) // Garante que o valor do pixel não ultrapasse 255
                aux=255;
            else if (aux<0) // Garante que o valor do pixel não seja menor que 0
                aux=0;
            img[i][j]=aux;
        }
}

//recebe a matriz da imagem e suas dimenções e torna ela negativa 
void negativa(Timagem img, int lin, int col){
    for (int i=0; i<lin; i++) 
        for (int j=0; j<col; j++) 
            img[i][j]=255-img[i][j]; // Aplica a negativa ao valor do pixel            
}

//recebe a matriz da imagem e suas dimenções e um fator para binarizala
void binarizar(Timagem img, int lin, int col, int fator){
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            if (img[i][j]<=fator) // Verifica se o valor do pixel é menor ou igual ao fator
                img[i][j]=0; // Transforma o pixel em preto
            else
                img[i][j]=255; // Transforma o pixel em branco
        }
    }
}

//recebe a matriz da imagem e os ponteiros de suas dimenções e iconiza ela atualizando suas dimenções 
void iconizar(Timagem img, int *lin, int *col){
    int temp[64][64];
    int soma=0;
    int plin=*lin/64, pcol=*col/64, div=plin*pcol;   
    for (int i=0, m=0; m<64; i+=plin, m++) 
        for (int j=0, n=0; n<64; j+=pcol, n++) {
            soma=0;
            // Calcula a média dos valores de cada bloco
            for (int k=i; k<i+plin; k++)
                for (int l=j; l<j+pcol; l++)
                    soma+=img[k][l];                            
            temp[m][n]=soma/div; // Armazena a média no array temporário
        }
    
    *lin=64; // Atualiza o número de linhas  e colunas da imagem para 64
    *col=64;
    
    // Copia os valores do array temporário de volta para a imagem original
    for (int i=0; i<64; i++) 
        for (int j=0; j<64; j++) 
            img[i][j]=temp[i][j];            
}

//recebe a matriz da imagem e suas dimenções e adiciona ruído
void ruido(Timagem img, int lin, int col){
    srand(time(NULL)); 
    for (int i=0; i<3000+rand()%10000; i++) 
        img[rand()%lin][rand()%col]=rand()%256; // Modifica um pixel aleatório com um valor aleatório entre 0 e 255
}

//recebe a matriz da imagem e suas dimenções e suaviza ela
void suavizar(Timagem img, int lin, int col){
    int soma;
    int **temp; // Matriz temporária para armazenar os valores suavizados
    temp = (int **)malloc(lin * sizeof(int *)); //se não utilizar o malloc, resuta em falha de segmentação
    for (int i = 0; i < lin; i++)
        temp[i] = (int *)malloc(col * sizeof(int)); 
        
    for (int i=1; i<lin; i++) 
        for (int j=1; j<col; j++) {
            soma=0;
            // Calcula a média dos valores dos pixels ao redor do pixel atual (filtro 3x3)
            for (int k=i-1; k<i+2 && k<lin; k++)
                for (int l=j-1; l<j+2 && l<col; l++)
                    soma+=img[k][l];                            
            temp[i][j]=soma/9;
        }      
    
    // Copia os valores da matriz temporária de volta para a imagem original (exceto bordas)
    for (int i=1; i<lin; i++) 
        for (int j=1; j<col; j++) 
            img[i][j]=temp[i][j];          
    
    // Libera a memória alocada para a matriz temporária
    for (int i = 0; i < lin; i++)
        free(temp[i]);    
    free(temp);
}
