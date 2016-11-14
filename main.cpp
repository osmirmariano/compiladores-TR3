#include <iostream>
#include <stack>
#include <sstream>
#include "Posfixa.cpp"
#include "Thompson.cpp"
#include "Automato.cpp"
#include "Subconjuntos.cpp"
#include "Afd.cpp"
//#include "ConversaoAFD.cpp"
using namespace std;

int main(int argc, char const *argv[]){
    int op;
    string expressao, posTho, dados;
    Posfixa *pos = new Posfixa();
    Thompson *tho = new Thompson();
    Subconjuntos *subconj = new Subconjuntos();
    Afd *afd = new Afd();
    //ConversaoAFD *afd = new ConversaoAFD();
    Automato automato, automato2, automatoAFD;

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
                //automato = subconj->renomearEstados(automato2);
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
                    }
                }
                cout << "---------------------------------------------------" << endl;

                break;
                    
            case 4:
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DO AFD" << endl;
                cout << "---------------------------------------------------" << endl;
                conversao = subconj->fechoEOficial(automato, automato.getEstado(0));  
                afd->gerandoEstadosAFD(automato, conversao);
                //afd->imprimirAutomatoAFD(automato, conversao);
                //afd->gerando(automato, conversao);
                //afd->removerEstadosRepetidos(automato);

                break;
            case 5:
                cout << "---------------------------------------------------" << endl;
                cout << "\t AUTÔMATO MÍNIMO" << endl;
                cout << "---------------------------------------------------" << endl;
                //CHAMA A FUNÇÃO MINIMIZAÇÃO
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

