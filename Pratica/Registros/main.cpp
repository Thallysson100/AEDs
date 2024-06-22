/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Gerencie uma agenda de amigos, onde cada amigo possui os campos nome, celular, cidade e email. 
 *Além desses campos, o projeto deve considerar no registro um campo de flag que indique se o registro é válido ou não, assim, 
 *para excluir um registro, basta atribuir Falso para este campo. O projeto deve ler no início um arquivo de dados dos amigos, realizar as operações e, 
 *no final, reescrever o arquivo inicial.
 *
 *As operações podem ser realizadas pelo usuário quantas vezes forem necessárias e devem ser:
 *
 *  busca pelo nome do amigo;
 *  excluir um amigo;
 *  inserir um amigo.
 * 
 * Nome: Thallysson Luis Teixeira Carvalho
 * Matrícula: 2024.1.08.022
 * 
 */

#include <cstdlib>
#include <iostream>
#include <fstream>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream arq1("agenda.txt");
    if (!arq1.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    const int TAM = 100;

    typedef struct {
        string nome;
        string celular;
        string cidade;
        string email;
        bool valido;
    } Pessoa;

    Pessoa agenda[TAM];
    int qtd = 0, op2, aux2;
    string aux1, pqz1, mud;


    arq1>>aux1;
    for (qtd = 0; aux1 != "fim" && qtd < TAM; qtd++) {    //lê a lista sem ler o fim
        agenda[qtd].nome = aux1;
        arq1 >> agenda[qtd].celular >> agenda[qtd].cidade >> agenda[qtd].email;
        agenda[qtd].valido=true;
        arq1>>aux1;
    }


    char opcao, op3;
    do {
        cout<<"Agenda de contatos"<<endl;
        cout<<endl;
        for (int i = 0; i < qtd; i++) {
            if (agenda[i].valido)
                cout << agenda[i].nome << " " << agenda[i].celular << " " << agenda[i].cidade << " " << agenda[i].email <<" "<<endl;
        }
        cout << "---------------------------------------------------------" << endl;
        

        cout << "Digite de acordo com as opções de operação na agenda" << endl;
        cout << "0)Sair" << endl;
        cout << "1)Adiconar contato" << endl;
        cout << "2)Retirar contato" << endl;
        cout << "3)Alterar contato" << endl;
        cout << "4)buscar contato" << endl;
        cin>>opcao;
        cout<<endl;

        switch (opcao) {
            case '1':     //adiciona um contato
                cout << "Digite o contato para adicionar (nome, celular, cidade, email):" << endl;
                aux2=qtd;    //aux2 determina o endereço de onde vai ser adicionado o contato
                
                for (int i=0; i<qtd; i++){
                    if (agenda[i].valido==false){
                        aux2=i;
                        i=qtd;    //substitui o break
                    }
                }
                
                cin >> agenda[aux2].nome >> agenda[aux2].celular >> agenda[aux2].cidade >> agenda[aux2].email;
                agenda[aux2].valido=true;
                
                if (aux2==qtd)    //se o contato foi adicionado no final da lista, aumenta a quantidade de elementos
                    qtd++;
                
                break;

            case '2':          //retira um contato
                cout << "Digite o nome do contado para retirar" << endl;
                cin>>pqz1;

                for (int i = 0; i < qtd; i++)
                    if (agenda[i].nome == pqz1){ 
                        cout << agenda[i].nome << " " << agenda[i].celular << " " << agenda[i].cidade << " " << agenda[i].email << endl;
                        cout<<"Deseja retira esse contato? (s para sim n para não)";
                        cin>>op3;
                        if (op3=='s')
                            agenda[i].valido=false;
                    }
                break;

            case '3':     //edita um determinado contato
                cout << "Digite o nome do contato que deseja fazer a alteração" << endl;
                cin>>pqz1;

                for (int i = 0; i < qtd; i++) {
                    if (agenda[i].nome == pqz1 && agenda[i].valido) {
                        do {
                            cout << agenda[i].nome << " " << agenda[i].celular << " " << agenda[i].cidade << " " << agenda[i].email << endl;
                            cout << "O que deseja alterar nesse contato?" << endl;
                            cout << "0)nada ou fim" << endl;
                            cout << "1)nome" << endl;
                            cout << "2)número" << endl;
                            cout << "3)cidade" << endl;
                            cout << "4)email" << endl;
                            cin>>op3;

                            switch (op3) {
                                case '1':
                                    cout << "Digite o nome" << endl;
                                    cin>>mud;
                                    agenda[i].nome = mud;
                                    break;

                                case '2':
                                    cout << "Digite o celular" << endl;
                                    cin>>mud;
                                    agenda[i].celular = mud;
                                    break;

                                case '3':
                                    cout << "Digite a cidade" << endl;
                                    cin>>mud;
                                    agenda[i].cidade = mud;
                                    break;

                                case '4':
                                    cout << "Digite o email" << endl;
                                    cin>>mud;
                                    agenda[i].email = mud;
                                    break;
                            }

                        } while (op3 != '0');
                    }
                }
                break;

            case '4':     //Busca um contato
                cout << "Digite o nome do contato que dejesa buscar:" << endl;
                cin>>pqz1;
                
                for (int i=0; i<qtd; i++)
                    if (agenda[i].nome==pqz1 && agenda[i].valido)
                        cout << agenda[i].nome << " " << agenda[i].celular << " " << agenda[i].cidade << " " << agenda[i].email << endl;
                break;
                
        }
       
    } while (opcao != '0');
    
    arq1.close();
    
    ofstream arq2("agenda.txt");
    
    for (int i=0; i<qtd; i++)    //rescreve no arquivo apenas os contatos válidos
        if (agenda[i].valido)
            arq2 << agenda[i].nome << " " << agenda[i].celular << " " << agenda[i].cidade << " " << agenda[i].email << endl;
    arq2<<"fim";
    
    arq2.close();
    return 0;
}

