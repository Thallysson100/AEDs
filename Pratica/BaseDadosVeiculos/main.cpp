/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
  O aplicativo desenvolvido no projeto deve ler os dados de um arquivo-texto no início 
  da execução e escrever neste mesmo arquivo-texto no final da execução. 
  Os dados do arquivo-texto devem ser armazenados num vetor de registros na ordem de entrada, 
  com no máximo 100 registros. 
  Cada linha do arquivo de entrada tem informações de apenas um veículo, 
  conforme o modelo apresentado no arquivo-texto de exemplo “BD_veiculos.txt”. 
  Durante a execução, o aplicativo deverá exibir um menu de opções ao usuário, 
  conforme as operações abaixo. 
  Cada registro do vetor deverá ter um campo booleano que indica se o registro é válido ou não.
    >inclusão de um novo veículo na base de dados;
    >busca de um veículo pela placa, com opção de exclusão da base de dados;
    >busca de veículos pelo tipo;
    >busca de veículos pelo câmbio;
    >busca de veículos por uma faixa de valores;
    >relatório do banco de dados:
        >porcentagens de veículos nas categorias de tipo;
        >porcentagens de veículos pelo combustível;
        >placa e valor do veículo mais barato entre os veículos com potência do motor 1.0, e ainda, valor da prestação 
        do financiamento em 60 meses com taxa de juros atuais (consulte na internet);
        >placa e valor do veículo mais caro com direção hidráulica e câmbio automático, e ainda, valor do 
        seguro estimado (porcentagem estimada sobre o valor do veículo);
        >quantidade e média de quilometragem dos veículos com 5 anos ou mais (2019).
  
  Nome: Thallysson Luis Teixeira Carvalho
  Matrícula: 2024.1.08.022
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream arq1("BD_veiculos.txt");
    if (!arq1.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }
    
    const int TAM=100;
    
    typedef struct {
        string modelo;
        string marca;
        string tipo;
        int ano;
        int quilom;
        string poten;
        string combus;
        string cambio;
        string direc;
        string cor;
        string portas;
        string placa;
        float valor;
        bool valido;
    }Veiculo;
    
    Veiculo lista[TAM];
    string aux1;
    char op1, op2;
    int qtd, i, aux2, qtdv;
    float li, ls;
    
    //lê o arquivo e salva em lista (para em fim)
    arq1>>aux1;
    for (qtd=0; aux1 != "fim" && qtd<TAM; qtd++){
        lista[qtd].modelo = aux1;
        arq1 >> lista[qtd].marca >> lista[qtd].tipo >> lista[qtd].ano
             >> lista[qtd].quilom >> lista[qtd].poten >> lista[qtd].combus
             >> lista[qtd].cambio >> lista[qtd].direc >> lista[qtd].cor
             >> lista[qtd].portas >> lista[qtd].placa >> lista[qtd].valor;
        lista[qtd].valido=true;
        arq1 >> aux1;   
    }
    qtdv=qtd;   //quantidade de veículos válidos (necessário para o calculo de porcentagem)
    
    do{ 
        cout<<"Digite de acordo para realizar a operação desejada no banco de dados:"<<endl;
        cout<<"0: sair"<<endl;
        cout<<"1: para incluir um novo veículo"<<endl;
        cout<<"2: para buscar um veículo pela placa (com opção de exclusão)"<<endl;
        cout<<"3: para buscar veículos pelo tipo"<<endl;
        cout<<"4: para buscar veículos pelo câmbio"<<endl;
        cout<<"5: para buscar veículos dentro de uma faixa de preço"<<endl;
        cout<<"6: para mostrar o relatório do banco de dados"<<endl;
        cin>>op1;
        
        
        if (op1=='1'){      //adiciona um novo veículo
            
            aux2=qtd;

            for (i=0; i<qtd; i++){         //procura a posição a ser adicionado o novo veículo
                if (not lista[i].valido){
                    aux2=i;
                    i=qtd;    //quebra o loop
                }
            }
            cout<<"Escolha o tipo de acordo com as opções abaixo"<<endl;   //para não ocorrer o risco do usuário digitar errado (é necessário para o relatório)
            cout<<"1)Hatch\n2)SUV\n3)Pick-up\n4)Sedã\n5)Van\nQualquer outro)Outro\n"<<endl;
            cin>>op2;
            if (op2=='1'){lista[aux2].tipo="Hatch";}
            else if (op2=='2'){lista[aux2].tipo="SUV";}
            else if (op2=='3'){lista[aux2].tipo="Pick-up";}
            else if (op2=='4'){lista[aux2].tipo="Sedã";}
            else if (op2=='5'){lista[aux2].tipo="Van";}
            else {cout<<"Digite o modelo"<<endl; cin>>lista[aux2].tipo;}
            
            cout<<"Escolha o combustível de acordo com as opções abaixo"<<endl;
            cout<<"1)Diesel\n2)Gasolina\n3)Flex\nQualquer outro)Outro\n";
            cin>>op2;
            if (op2=='1'){lista[aux2].combus="Diesel";}
            else if (op2=='2'){lista[aux2].combus="Gasolina";}
            else if (op2=='3'){lista[aux2].combus="Flex";}
            else {cout<<"Digite o combustível"<<endl; cin>>lista[aux2].combus;}
            
            cout<<"Escolha a direção de acordo com as opções abaixo"<<endl;
            cout<<"1)Hidráulica\nQualquer outro)Elétrica\n";
            cin>>op2;
            if (op2=='1'){lista[aux2].direc="Hidráulica";}
            else {lista[aux2].direc="Elétrica";}
            
            cout<<"Escolha o câmbio de acordo com as opções abaixo"<<endl;
            cout<<"1)Manual\nQualquer outro)Automático\n";
            cin>>op2;
            if (op2=='1'){lista[aux2].cambio="Manual";}
            else {lista[aux2].cambio="Automático";}
            
            cout<<"Digite o modelo"<<endl;
            cin>>lista[aux2].modelo;
            cout<<"Digite a marca"<<endl;
            cin>>lista[aux2].marca;  
            cout<<"Digite o ano"<<endl;
            cin>>lista[aux2].ano;
            cout<<"Digite a quilometragem"<<endl;
            cin>>lista[aux2].quilom;
            cout<<"Digite a litragem do motor"<<endl;
            cin>>lista[aux2].poten;
            cout<<"Digite a cor"<<endl;
            cin>>lista[aux2].cor;
            cout<<"Digite o número de portas"<<endl;
            cin>>lista[aux2].portas;
            cout<<"Digite a placa"<<endl;
            cin>>lista[aux2].placa;
            cout<<"Digite o valor"<<endl;
            cin>>lista[aux2].valor;
            lista[aux2].valido=true;
            
            qtdv++;
            if (aux2==qtd){qtd++;}        //aumenta a quantidade se o novo veículo foi adicionado no final da lista
        }

        else if (op1=='2'){    //busca pela placa
            cout<<"Digite a placa"<<endl;
            cin>>aux1;
            int achou=0;
            for (i=0; i<qtd; i++){
                if (lista[i].valido){
                    if (lista[i].placa==aux1){
                        achou=1;
                        cout<<lista[i].modelo<<" "<<lista[i].marca<<" "<<lista[i].tipo<<" "
                            <<lista[i].ano<<" "<<lista[i].quilom<<" "<<lista[i].poten<<" "
                            <<lista[i].combus<<" "<<lista[i].cambio<<" "<<lista[i].direc<<" "
                            <<lista[i].cor<<" "<<lista[i].portas<<" "<<lista[i].placa<<" "
                            <<lista[i].valor<<" "<<lista[i].valido<<endl;
                        cout<<"Deseja excluir? (1 para sim, qualquer outro para não)"<<endl;
                        cin>>op2;
                        if (op2=='1'){
                            lista[i].valido=false;
                            qtdv--;
                        }
                        i=qtd;
                    }
                }
            }
            if (achou==0){cout<<"Veículo não encontrado"<<endl;}
        }


        else if (op1=='3'){    //busca pelo tipo
            cout<<"Digite o tipo"<<endl;
            cin>>aux1;
            for (i=0; i<qtd; i++){
                if (lista[i].valido){
                    if (lista[i].tipo==aux1){
                        cout<<lista[i].modelo<<" "<<lista[i].marca<<" "<<lista[i].tipo<<" "
                            <<lista[i].ano<<" "<<lista[i].quilom<<" "<<lista[i].poten<<" "
                            <<lista[i].combus<<" "<<lista[i].cambio<<" "<<lista[i].direc<<" "
                            <<lista[i].cor<<" "<<lista[i].portas<<" "<<lista[i].placa<<" "
                            <<lista[i].valor<<" "<<lista[i].valido<<endl;
                    }
                }
            }
        }

        else if (op1=='4'){    //busca pelo câmbio
            cout<<"Digite o câmbio"<<endl;
            cin>>aux1;
            for (i=0; i<qtd; i++){
                if (lista[i].valido){
                    if (lista[i].cambio==aux1){
                        cout<<lista[i].modelo<<" "<<lista[i].marca<<" "<<lista[i].tipo<<" "
                            <<lista[i].ano<<" "<<lista[i].quilom<<" "<<lista[i].poten<<" "
                            <<lista[i].combus<<" "<<lista[i].cambio<<" "<<lista[i].direc<<" "
                            <<lista[i].cor<<" "<<lista[i].portas<<" "<<lista[i].placa<<" "
                            <<lista[i].valor<<" "<<lista[i].valido<<endl;
                    }
                }
            }
        }


        else if (op1=='5'){   //busca pela faixa de valores
            cout<<"Digite a faixa de valores"<<endl;
            cin>>li>>ls;
            if (li>ls){    //troca se lim inferior > lim superior
                aux2=li;
                li=ls;
                ls=aux2;
            }
            for (i=0; i<qtd; i++){
                if (lista[i].valido){
                    if (lista[i].valor>li && lista[i].valor<ls){
                        cout<<lista[i].modelo<<" "<<lista[i].marca<<" "<<lista[i].tipo<<" "
                            <<lista[i].ano<<" "<<lista[i].quilom<<" "<<lista[i].poten<<" "
                            <<lista[i].combus<<" "<<lista[i].cambio<<" "<<lista[i].direc<<" "
                            <<lista[i].cor<<" "<<lista[i].portas<<" "<<lista[i].placa<<" "
                            <<lista[i].valor<<" "<<lista[i].valido<<endl;
                    }
                }
            }
        }

        else if (op1=='6'){     //escreve o relatório   
            int qhatch=0, qsuv=0, qpickup=0, qseda=0, qvan=0, qdiesel=0, qgasol=0, qflex=0, q2019=0, somaquil=0;
            float mbarato=lista[0].valor, mcaro=0;
            string placabarato, placacaro;
            for (i=0; i<qtd; i++){
                if (lista[i].valido){
                    if (lista[i].tipo=="Hatch")
                        qhatch++;
                    if (lista[i].tipo=="SUV")
                        qsuv++;
                    if (lista[i].tipo=="Pick-up")
                        qpickup++;
                    if (lista[i].tipo=="Sedã")
                        qseda++;
                    if (lista[i].tipo=="Van")
                        qvan++;
                    if (lista[i].combus=="Diesel")
                        qdiesel++;
                    if (lista[i].combus=="Gasolina")
                        qgasol++;
                    if (lista[i].combus=="Flex")
                        qflex++;
                    if (lista[i].poten=="1.0")
                        if (lista[i].valor<mbarato){
                            mbarato=lista[i].valor;
                            placabarato=lista[i].placa;
                        }
                    if (lista[i].cambio=="Automático" && lista[i].direc=="Hidráulica")
                        if (lista[i].valor>mcaro){
                            mcaro=lista[i].valor;
                            placacaro=lista[i].placa;
                        }
                    if (lista[i].ano<=2019){
                        q2019++;
                        somaquil=somaquil+lista[i].quilom;
                    }
                }
            }
            cout<<"Porcentagem de carros do tipo Hatch: "<<(float) qhatch/qtdv*100<<endl;   //divide apenas pela quantidade de veículos válidos
            cout<<"Porcentagem de carros do tipo SUV: "<<(float) qsuv/qtdv*100<<endl;
            cout<<"Porcentagem de carros do tipo Pick up: "<<(float) qpickup/qtdv*100<<endl;
            cout<<"Porcentagem de carros do tipo Sedã: "<<(float) qseda/qtdv*100<<endl;
            cout<<"Porcentagem de carros do tipo Van: "<<(float) qvan/qtdv*100<<endl;
            cout<<"Porcentagem de carros a diesel: "<<(float) qdiesel/qtdv*100<<endl;
            cout<<"Porcentagem de carros a gasolina: "<<(float) qgasol/qtdv*100<<endl;
            cout<<"Porcentagem de carros flex: "<<(float) qflex/qtdv*100<<endl;
            cout<<"O veículo com motor 1.0 mais barato possui a placa "<<placabarato
                <<", seu preço é "<<mbarato<<" e sua prestação de financiamento em 60 meses é "
                <<0.0262496566*mbarato<<endl;      //constante obtida do cálculo da parcela do financiamento a taxa de 1.63% a.m em 60 meses
            
            cout<<"O veículo com direção hidráulica e com câmbio automático mais caro possui a placa "
                <<placacaro<<", seu valor é "<<mcaro<<" e seu seguro estimado vale "<<0.066*mcaro<<endl;
            cout<<"A quantidade de veículos com 5 anos ou mais é "<<q2019
                <<", e a média de quilometragem desses veículos é "<<(float) somaquil/q2019<<endl;
        }
        cout<<endl;
    
    }while (op1!='0');
    
    arq1.close();
    
    ofstream arq2("BD_veiculos.txt");    //Escreve o novo bancos de dados no arquivo
    for (i=0; i<qtd; i++){
        if (lista[i].valido){
            arq2<<lista[i].modelo<<" "<<lista[i].marca<<" "<<lista[i].tipo<<" "
                <<lista[i].ano<<" "<<lista[i].quilom<<" "<<lista[i].poten<<" "
                <<lista[i].combus<<" "<<lista[i].cambio<<" "<<lista[i].direc<<" "
                <<lista[i].cor<<" "<<lista[i].portas<<" "<<lista[i].placa<<" "
                <<lista[i].valor<<endl;
        }
    }
    arq2<<"fim";
    
    arq2.close();
    
    return 0;
}

