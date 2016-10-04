#include <iostream>
#include <stack>
#include "Posfixa.cpp"
#include "Thompson.cpp"
using namespace std;

int main(int argc, char const *argv[]){
    int op;
    string expressao, posTho;
    Posfixa *pos = new Posfixa();
    Thompson *tho = new Thompson();
    
    do{
        cout << "---------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÃO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 -- INSERIR EXPRESSÃO (INFIXA)" << endl;
        cout << " 2 -- VISUALIZAÇÃO DO AUTÔMATO DE THOMPSON " << endl;
        cout << " 0 -- SAIR" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " OPÇÃO: ";
        cin >> op;
        cout << "---------------------------------------------------" << endl;

        switch(op){
            case 1:
                cout << "---------------------------------------------------" << endl;
                cout << "\t INSERÇÃO DA EXPRESSÃO REGULAR" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << " EXPRESSÃO: ";
                cin >> expressao;
                pos->operadoresBinariosVerificacao(expressao);
                // posTho = pos->retorno();
                // tho->montadorAutomato(posTho);
                //cout << "TESTE " <<  posTho << endl;
                //tho->testandoExpressao(posTho); // Testando, depois remover
                break;
            case 2:
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DO AUTÔMATO DE THOMPSON" << endl;
                cout << "---------------------------------------------------" << endl;
                posTho = pos->retorno();
                tho->montadorAutomato(posTho);
                break;
            case 0:
                cout << "\tAPLICAÇÃO ENCERRADA COM SUCESSO!" << endl << endl;
                break;
            default:
                cout << "\tOPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA" << endl;
        }
        cout << endl << "  PARA VOLTAR AO MENU PRESSIONE 0 E CONFIRME COM UM ENTER" << endl;
        cin.ignore().get();//Comando para Pausa no terminal
        cout << "\e[H\e[2J";//Comando para limpar a tela
    }while(op != 0);
};
