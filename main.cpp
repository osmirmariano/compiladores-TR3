#include <iostream>
#include <stack>
#include "Posfixa.cpp"
#include "Thompson.cpp"
#include "Automato.cpp"
#include "Subconjuntos.cpp"
using namespace std;

int main(int argc, char const *argv[]){
    int op;
    string expressao, posTho;
    Posfixa *pos = new Posfixa();
    Thompson *tho = new Thompson();
    Subconjuntos *subconj = new Subconjuntos();
    Automato automato;
    string estado;

    
    do{
        cout << "---------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÃO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 -- INSERIR EXPRESSÃO (INFIXA)" << endl;
        cout << " 2 -- VISUALIZAÇÃO DO AUTÔMATO DE THOMPSON " << endl;
        cout << " 3 -- VISUALIZAÇÃO DOS FECHO-E" << endl;
        cout << " 4 -- VISUALIZAÇÃO DO AFD" << endl;
        cout << " 5 -- AFD MÍNIMO" << endl;
        cout << " 6 -- PARA TESTE, VISUALIZAÇÃO DO AUTÔMATO ESTRUTURADO" << endl;
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
                break;
            case 2:
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DO AUTÔMATO DE THOMPSON" << endl;
                cout << "---------------------------------------------------" << endl;
                posTho = pos->retorno();
                automato = tho->montadorAutomato(posTho);
                break;
            case 3: 
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DOS FECHO-E" << endl;
                cout << "---------------------------------------------------" << endl;
                subconj->fechoE(automato);
                break;
            case 4:
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DO AFD" << endl;
                cout << "---------------------------------------------------" << endl;
                //CHAMAR FUNÇÃO AQUI PARA MOSTRAR O AUTOMATO FINITO DETERMINÍSTICO
                break;
            case 5:
                cout << "---------------------------------------------------" << endl;
                cout << "\t AUTÔMATO MÍNIMO" << endl;
                cout << "---------------------------------------------------" << endl;
                //CHAMA A FUNÇÃO MINIMIZAÇÃO
                break;
            case 6: 
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DO AUTÔMATO ESTRUTURADO" << endl;
                cout << "---------------------------------------------------" << endl;
                //posTho = pos->retorno();
                subconj->mostrarEstruturaAutomato(automato);
                //tho->recebeAutomato(posTho);
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
