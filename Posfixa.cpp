#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
/*----------------------- DECLARAÇÃO DA ESTRUTURA-------------------------*/
typedef struct PILHA{
	string armazena;
    struct PILHA *prox;
}PILHA;

/*----------------------- DECLARAÇÃO DA CLASSE POSFIXA---------------------*/
class Posfixa{
	public:
        int opcao, opction;
        string posfixaThompson;
	public:
        //CONSTRUTOR
		Posfixa(){
            void empilhar(PILHA **topo);
            void desempilhar(PILHA **topo);
            void listar(PILHA *topo);
            int precedenciasPilha(PILHA *topo);
            int precedenciasExpr(string expressao, int x);
            void infixaParaPosfixa(string expressao);
            string preencherExpressao(string expressao);
            int verificaParentese(string expressao);
            void operadoresBinariosVerificacao(string expressao);
		};
		~Posfixa();
        
        /*--------------------- FUNÇÃO LISTAR PARA TESTES------------------------*/
        void listar(PILHA *topo){
            PILHA *aux;
            if(topo == NULL)
                cout << "PILHA VAZIA" << endl;
            else{
                aux = topo;
                while(aux != NULL){
                    cout << " EMPILHADO: " << aux->armazena << endl;
                    aux = aux->prox;
                }
           }
        };

        /*----------------------- FUNÇÃO EMPILHAR-----------------------------*/
        void empilhar(PILHA **topo, string recebe){
            PILHA *novo;
            novo = new PILHA;
            if(novo == NULL)
                cout << "NÃO ALOCADO" << endl;
            else{
                novo->armazena = recebe;
                novo->prox = (*topo);
                (*topo) = novo;
            }
        };

        /*----------------------- FUNÇÃO DESEMPILHAR-----------------------------*/
        void desempilhar(PILHA **topo){
            PILHA *aux;
            if(aux == NULL)
                cout << "NÃO EXISTE NENHUM ELEMENTO NA PILHA" << endl;
            else{ 
                aux = (*topo); 
                (*topo) = (*topo)->prox; 
                delete aux; 
            }
        };
                

        /*--------------------- FUNÇÃO PRECENDENCIA PILHA------------------------*/
        int precedenciasPilha(PILHA *topo){
            if(topo == NULL){
                opction = 0;
            }
            else{
                if(topo->armazena == "*"){
                    opction = 4;
                }
                else if(topo->armazena == "."){
                    opction = 3;
                }
                else if(topo->armazena == "+"){
                    opction = 2;
                }
                else if(topo->armazena == "(")
                    opction = 1;
            }            
            return opction;
        };

        /*--------------------- FUNÇÃO PRECENDENCIA EXPRESSAO-----------------------*/
        int precedenciasExpr(string novaExpressao, int x){
            
            if(novaExpressao[x] == '*')
                opcao = 4;
            else if(novaExpressao[x] == '.')
                opcao = 3;
            else if(novaExpressao[x] == '+')
                opcao = 2;
            else if(novaExpressao[x] == '(')
                opcao = 1;
            return opcao;
        };

        /*--------------------- FUNÇÃO PREENCHER EXPRESSAO COM . -------------------*/
        string preencherExpressao(string expressao){
            string novaExpr;
            int cont = 0;
            for(int x = 0; x < expressao.length(); x++){
                novaExpr += expressao[x];
                //Tratando para caso seja * A e * (
                if((expressao[x] == '*' && expressao[x+1] != ')') && 
                    (expressao[x] == '*' && expressao[x+1] != '.') && 
                    (expressao[x] == '*' && expressao[x+1] != '+')){
                    if(x+1 == expressao.length()){
                        break;
                    }
                    else{
                        novaExpr += '.';
                    }
                }

                else{
                    //Tratamento para caso seja A B
                    if((expressao[x] != '+' && expressao[x+1] != '*') && 
                        (expressao[x] != '+' && expressao[x+1] != ' ') &&
                        (expressao[x] != '+' && expressao[x+1] != ')') &&
                        (expressao[x] != '+' && expressao[x+1] != '(') &&
                        (expressao[x] != '+' && expressao[x+1] != '.') &&

                        (expressao[x] != '(' && expressao[x+1] != '+') && 
                        (expressao[x] != '(' && expressao[x+1] != ' ') &&
                        (expressao[x] != '(' && expressao[x+1] != '*') &&
                        (expressao[x] != '(' && expressao[x+1] != ')') &&
                        (expressao[x] != '(' && expressao[x+1] != '.') &&

                        (expressao[x] != '.' && expressao[x+1] != '+') && 
                        (expressao[x] != '.' && expressao[x+1] != ' ') &&
                        (expressao[x] != '.' && expressao[x+1] != '*') &&
                        (expressao[x] != '.' && expressao[x+1] != ')') &&
                        (expressao[x] != '.' && expressao[x+1] != '(') &&

                        (expressao[x] != ')' && expressao[x+1] != '+') && 
                        (expressao[x] != ')' && expressao[x+1] != '.') && 
                        (expressao[x] != ')' && expressao[x+1] != ' ') &&
                        (expressao[x] != ')' && expressao[x+1] != '*') &&
                        (expressao[x] != ')' && expressao[x+1] != '(')){
                        if(x+1 == expressao.length()){
                            break;
                        }
                        else{
                            novaExpr += '.';
                        }
                    }
                    else{
                        if((expressao[x] != '+' && expressao[x+1] == '(') &&
                            (expressao[x] != '*' && expressao[x+1] == '(') &&
                            (expressao[x] != ')' && expressao[x+1] == '(') &&
                            (expressao[x] != '.' && expressao[x+1] == '(') &&
                            (expressao[x] != '(' && expressao[x+1] == '(')){
                            novaExpr += '.';
                        }
                        else{
                            if((expressao[x] == ')' && expressao[x+1] != '*') &&
                                (expressao[x] == ')' && expressao[x+1] != '+') &&
                                (expressao[x] == ')' && expressao[x+1] != '.') &&
                                (expressao[x] == ')' && expressao[x+1] != '(')){
                                if(x+1 == expressao.length()){
                                    break;
                                }
                                else{
                                    novaExpr += '.';
                                }
                            }
                            else{
                                if((expressao[x] == ')' && expressao[x+1] == '(')){
                                    novaExpr += '.';
                                }
                            }
                        }
                    }
                }
            }
            return novaExpr;
        };

        /*-----------------------FUNÇÃO VERIFICA PARENTESES----------------------*/
        int verificaParentese(string expressao){
            int cont1 = 0, cont2 = 0;
            for(int x = 0; x < expressao.length(); x++){
                if(expressao[x] == '('){
                    cont1++;
                }
                if(expressao[x] == ')'){
                    cont2++;
                }
            }

            if(cont1 == cont2)
                return 1;
            else
                return 0;
        }

        /*-----------------------FUNÇÃO VERIFICA OPERADORES----------------------*/
        void operadoresBinariosVerificacao(string expressao){
            int verifica1 = 0, verifica2 = 0;
            for(int x = 0; x < expressao.length(); x++){
                if(expressao[x] == '+' || expressao[x] == '.'){
                    if(expressao[x-1] != '(' && expressao[x-1] != '.' && expressao[x-1] != '+' &&
                        expressao[x+1] != ')' && expressao[x+1] != '.' && expressao[x+1] != '+' && 
                        expressao[x+1] != '*' && x+1 != expressao.length() && x-1 != -1){
                        verifica1 = 1;
                    }
                    else{
                        verifica2 = 2;
                    }
                }
            }
            if(verifica2 == 2){
                cout << endl << "      ERRO: EXISTE UM OPERADOR BINÁRIO '+ OU '.' " << endl;
                cout << " \tQUE NÃO POSSUI SEU CORRESPONDENTE" << endl;
            }

            else
                infixaParaPosfixa(expressao);
        };

        /*-----------------------FUNÇÃO INFIXAPARAPOSFIXA---------------------*/
        void infixaParaPosfixa(string expressao){
            string posfixa, recebe, novaExpressao;

            if(verificaParentese(expressao) == 1){
                PILHA *topo = NULL;
                preencherExpressao(expressao);
                novaExpressao = preencherExpressao(expressao);
                //cout << " CORRESPONDENTE: " << novaExpressao << endl << endl;

                for(int x = 0; x < novaExpressao.length(); x++){
                    //Tratamento de ser "(", então empilha -> SITUAÇÃO OK
                    if(novaExpressao[x] == '('){
                        recebe =  novaExpressao[x];
                        empilhar(&topo, recebe);//Empilhar tá OK
                    }

                    else{
                        //Tratamento para caso seja ")", então enquanto o topo = "(" desempilha -> SITUAÇÃO OK
                        if(novaExpressao[x] == ')'){ 
                            while(topo->armazena != "(" && topo != NULL){
                                posfixa += topo->armazena;
                                desempilhar(&topo);//Desempilha
                            }
                            //Desempilhar e descartar o "(" -> SITUAÇÃO OK
                            if(topo->armazena == "("){
                                desempilhar(&topo);
                            }
                        }
                        else{
                            //Para caso de ser operador
                            if(novaExpressao[x] == '*' || novaExpressao[x] == '.' || novaExpressao[x] == '+') {                                
                                while(precedenciasPilha(topo) >= precedenciasExpr(novaExpressao, x)){
                                    posfixa += topo->armazena;
                                    desempilhar(&topo); 
                                }
                                recebe = novaExpressao[x];
                                empilhar(&topo, recebe);
                            }
                            else{
                                posfixa += novaExpressao[x];
                            }
                        }
                    }
                    //Quando novaExpressao não tiver mais elementos e topo tiver
                    if(x+1 == novaExpressao.length()){
                        while(topo != NULL){
                            posfixa += topo->armazena;
                            desempilhar(&topo);
                        }
                    }
                }
                posfixaThompson = posfixa;
                cout << "----------------------------------------------------------------------" << endl;
                cout << " \t A CONVERSÃO DE INFIXA PARA POSFIXA" << endl;
                cout << " INFIXA: " << novaExpressao << endl;
                cout << " POSFIXA: " << posfixa << endl;
                cout << "----------------------------------------------------------------------" << endl << endl;
                topo = NULL;
            }
            else{
                cout << endl << "\t ERRO! FALTANDO PARENTESES" << endl << endl;
            }
            
        };

        /*-----------------------FUNÇÃO RETORNA POSIFXA---------------------*/
        string retorno(){
            return posfixaThompson;
        }
};

                                    
