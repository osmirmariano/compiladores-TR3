#include <iostream>
#include <stack>
#include "Posfixa.cpp"
#include "Thompson.cpp"
#include "Automato.cpp"
#include "Subconjuntos.cpp"
#include "Afd.cpp"
using namespace std;

int main(int argc, char const *argv[]){
    int op;
    string expressao, posTho;
    Posfixa *pos = new Posfixa();
    Thompson *tho = new Thompson();
    Subconjuntos *subconj = new Subconjuntos();
    Afd *afd = new Afd();
    Automato automato;

    string estado;
    vector<string> conversao;   
    
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
                if(automato.getNumeroEstados() == 0){
                    cout << "---------------------------------------------------" << endl;
                    cout << "   É NECESSÁRIO PRIMEIRAMENTE GERAR O AFN-E." << endl;
                    cout << " \tPOR FAVOR, ESCOLHA A OPÇÃO 2" << endl;
                    cout << "---------------------------------------------------" << endl;
                }
                else{
                    for(int x = 0; x < automato.getNumeroEstados(); x++){
                        subconj->imprimirFechos(automato, automato.getEstado(x));
                        if(x == 0){
                            conversao = subconj->fechoEOficial(automato, automato.getEstado(x));
                        }
                    }
                }
                break;
                    
            case 4:
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DO AFD" << endl;
                cout << "---------------------------------------------------" << endl;
                //subconj->conversaoAFNE_AFD(automato, conversao);
                afd->mostrarEstruturaAutomato(automato, conversao);
                
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
        cout << endl << "  PARA VOLTAR AO MENU PRESSIONE ENTER" << endl;
        cin.ignore().get();//Comando para Pausa no terminal
        cout << "\e[H\e[2J";//Comando para limpar a tela
    }while(op != 0);
};
