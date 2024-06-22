/*
 * Autores:
 * Thalysson Luis Teixeira Carvalho   Matrícula: 2024.1.08.022
 * Thyago Pereira de Carvalho         Matrícula: 2024.1.08.039
 * 
 * Este projeto possibilita a realização em uma determinada imagem com extenção pgm as
 * Seguintes operações: clarear ou escurecer, tornar negativa, binarizar, iconizar para 
 * uma imagem 64x64 e suavizar. Cada operação só pode ser realizada uma vez,
 * gerará um arquivo modificado e a próxima operação será baseada no arquivo modificado."
 *   
 *  
 */
#include <iostream>
#include <fstream>
#include "fmagem.h" //incluindo a biblioteca refenente as funções feitas no projeto
using namespace std;

/*
 *
 */
int main(){
   
    ifstream arq1 ("stanford.pgm");
    if (!arq1.is_open()){
        cout<<"\nErro, arquivo não encontrado\n";
        return 1;
    }        
    string aux;
    int col, lin;
    Timagem img;
    char op;
    arq1>>aux;
    if (aux!="P2"){ //se a imagem não for do tipo pgm
        cout<<"\nErro, arquivo não é do formato pgm\n";
        return 1;
    }
    arq1>>col>>lin;
    arq1>>aux;
    for (int i=0; i<lin; i++)
        for (int j=0; j<col; j++)
            arq1>>img[i][j];        
    arq1.close();


    //cada vez que o programa é executado, os aquivos de saída são resetados
    ofstream arq2 ("stanford_tom_modificado.pgm");
    ofstream arq3 ("stanford_negativa.pgm");
    ofstream arq4 ("stanford_binarizada.pgm");
    ofstream arq5 ("stanford_iconizada.pgm");
    ofstream arq6 ("stanford_com_ruido.pgm");
    ofstream arq7 ("stanford_suavizada.pgm");


    do{
        cout<<"Digite de acordo com a operação desejada"<<endl
            <<"*Obs.: Cada operação só pode ser realizada uma vez, "
            <<"gerará um arquivo modificado e a próxima operação será baseada no arquivo modificado"<<endl
            <<"0-Sair"<<endl
            <<"1-Clarear ou escurecer"<<endl
            <<"2-Tornar negativa"<<endl
            <<"3-Binarizar"<<endl
            <<"4-Iconizar"<<endl
            <<"5-Adicionar ruido"<<endl
            <<"6-Suavizar"<<endl;
        cin>>op;
        switch(op){
            case '1':   //escurece ou clareia a imagem
                int fator;
                cout<<"Digite o fator para escurecer ou clarear a imagem "
                    <<"(negativo para escurecer, positivo para clarear):"<<endl;
                cin>>fator;
                muda_tom(img, lin, col, fator);            
                arq2<<"P2"<<endl<<col<<" "<<lin<<endl<<"255"<<endl;
                for (int i=0; i<lin; i++)
                    for (int j=0; j<col;){
                        for (int k=0; k<40 && j<col; k++, j++) //a cada 40 elementos, quebra a linha
                            arq2<<img[i][j]<<" ";
                        arq2<<endl;
                    }
                arq2.close();
                break;
           
            case '2':     //torna a imagem negativa
                negativa(img, lin, col);            
                arq3<<"P2"<<endl<<col<<" "<<lin<<endl<<"255"<<endl;
                for (int i=0; i<lin; i++)
                    for (int j=0; j<col;){
                        for (int k=0; k<40 && j<col; k++, j++)
                            arq3<<img[i][j]<<" ";
                        arq3<<endl;
                    }
                arq3.close();                    
                break;
           
            case '3':   //binariza a imagem
                cout<<"Digite o fator para binarizar a imagem"<<endl;
                cin>>fator;
                binarizar(img, lin, col, fator);                            
                arq4<<"P2"<<endl<<col<<" "<<lin<<endl<<"255"<<endl;
                for (int i=0; i<lin; i++)
                    for (int j=0; j<col;){
                        for (int k=0; k<40 && j<col; k++, j++)
                            arq4<<img[i][j]<<" ";
                        arq4<<endl;
                    }
                arq4.close();
                break;
           
            case '4':   //iconiza a imagem         
                iconizar(img, &lin, &col);
                arq5<<"P2"<<endl<<col<<" "<<lin<<endl<<"255"<<endl;
                for (int i=0; i<lin; i++)
                    for (int j=0; j<col;){
                        for (int k=0; k<40 && j<col; k++, j++)
                            arq5<<img[i][j]<<" ";
                        arq5<<endl;
                    }
                arq5.close();
                break;
           
            case '5':   //adiciona ruido na imagem
                ruido(img, lin, col);
                arq6<<"P2"<<endl<<col<<" "<<lin<<endl<<"255"<<endl;
                for (int i=0; i<lin; i++)
                    for (int j=0; j<col;){
                        for (int k=0; k<40 && j<col; k++, j++)
                            arq6<<img[i][j]<<" ";
                        arq6<<endl;
                    }
                arq6.close();
                break;                          
           
            case '6':    //suaviza a imagem
                suavizar(img, lin, col);
                arq7<<"P2"<<endl<<col<<" "<<lin<<endl<<"255"<<endl;
                for (int i=0; i<lin; i++)
                    for (int j=0; j<col;){
                        for (int k=0; k<40 && j<col; k++, j++)
                            arq7<<img[i][j]<<" ";
                        arq7<<endl;
                    }
                arq7.close();            
                break;
        }    
    }while (op!='0');
    return 0;
}