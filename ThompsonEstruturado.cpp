#include <iostream>
#include <cstdlib>
//#include <stack>
#include <sstream>

using namespace std;

typedef struct {
	int *estados;
	int qtEstados;
}TRANSICOES;

typedef struct no{
	TRANSICOES **transicoes;
	string alfabeto;
    string *estados;
    int qtEstados;
    int estadoInicial;
    int *estadosFinais;
    int qtEstFinais;
    struct no *deslocamento;
}AUTOMATO;

typedef struct PILHAAUTOMATO{
	AUTOMATO *automato;
    struct PILHAAUTOMATO *prox;
}PILHAAUTOMATO;

class Thompson{
    public:
    	string posTho, simbolo;
    public:
        //CONSTRUTOR
    	Thompson(){
    		AUTOMATO *Base(string simbolo);
    		AUTOMATO *Concatenacao(AUTOMATO *a, AUTOMATO *b);
    		AUTOMATO *Uniao(AUTOMATO *a, AUTOMATO *b);
    		void montadorAutomato(string posTho);
    		string uneAlfabetos(string a, string b);
    		void montadorAutomato(string posTho);
            string *unirEstados(AUTOMATO *estados1, AUTOMATO *estados2);
            string *renomearEstados(AUTOMATO *nome);
            string *unirEstadosFecho(AUTOMATO *estados1);
    	};

        ~Thompson();

        /*------------------------- FUNÇÃO EMPILHAR AUTOMATO-------------------------------*/
        void empilhar(PILHAAUTOMATO **topo, AUTOMATO *recebe){
            PILHAAUTOMATO *novo;
            novo = new PILHAAUTOMATO;
            if(novo == NULL)
                cout << "NÃO ALOCADO" << endl;
            else{
                novo->automato = recebe;
                novo->prox = (*topo);
                (*topo) = novo;
            }
        };

        /*------------------------- FUNÇÃO DESEMPILHAR AUTOMATO-----------------------------*/
        void desempilhar(PILHAAUTOMATO **topo){
            PILHAAUTOMATO *aux;
            if(aux == NULL)
                cout << "NÃO EXISTE NENHUM ELEMENTO NA PILHA" << endl;
            else{
                aux = (*topo);
                (*topo) = (*topo)->prox;
                delete aux;
            }
        };

         /*---------------------------- FUNÇÃO LISTAR AUTOMATO-------------------------------*/
        void listar(PILHAAUTOMATO *topo){
            PILHAAUTOMATO *aux;
            if(topo == NULL)
                cout << "PILHA VAZIA" << endl;
            else{
                aux = topo;
                while(aux != NULL){
                    cout << "-----------------------------------------------" << endl;
                    cout << " ALFABETO: " << aux->automato->alfabeto << endl;
                    cout << " ESTADO INCIAL: " << aux->automato->estadoInicial << endl;
                    cout << " CONJUNTO DE ESTADOS: ";
                    for(int x = 0; x < aux->automato->qtEstados+2; x++){
                        cout << " " << aux->automato->estados[x];
                    }
                    cout << endl << " ESTADO FINAL: ";
                    for(int x = 0; x < aux->automato->qtEstFinais; x++){
                        cout << " " << aux->automato->estadosFinais[x];
                    }
                    cout << endl << " QUANTIDADE ESTADOS: " << aux->automato->qtEstados+2 << endl;
                    cout << " QUANTIDADE ESTADOS FINAIS: " << aux->automato->qtEstFinais<< endl;
                    for(int x = 0; x < aux->automato->qtEstados-1; x++){
                        for(int y = 0; y < aux->automato->alfabeto.size(); y++){
                            cout << " ENTRANDO: '" << aux->automato->alfabeto << "' NO ESTADO: '" << aux->automato->estados[x] << "' VAI PARA O ESTADO: ";
                            cout << " '" << aux->automato->transicoes[x][y].estados[x] << "'";
                        }
                    }
                    cout << "-----------------------------------------------" << endl << endl;
                    aux = aux->prox;
                }
           }
        };

        /*----------------------- FUNÇÃO PARA RENOMEAR ESTADOS------------------------------*/
        string *renomearEstados(AUTOMATO *nome){
            stringstream conversao;
            string *nomeNovo;
            for(int x = 0; x < nome->qtEstados; x++){
                conversao << x;
                nome->estados[x] = conversao.str();
                conversao.str("");
            }
            nomeNovo = nome->estados;
            return nomeNovo;
        };

        /*----------------------- FUNÇÃO PARA UNIR ALFABETOS--------------------------------*/
        string unirAlfabetos(string alfabeto1, string alfabeto2) {
            string alfabeto;
            alfabeto = alfabeto1;
            for (int x = 0; x < alfabeto2.size(); x++) {
                alfabeto += alfabeto2[x];
            }
            return alfabeto;
        };

        /*----------------------- FUNÇÃO PARA UNIR ESTADOS---------------------------------*/
        string *unirEstados(AUTOMATO *estados1, AUTOMATO *estados2){
            AUTOMATO *estadosNovos = new AUTOMATO;
            string *estadosE;
            estadosNovos->estados = new string[estados1->qtEstados+estados2->qtEstados+2];
            estadosNovos->qtEstados = estados1->qtEstados+estados2->qtEstados+2;
            for(int x = 0; x < estados1->qtEstados; x++){
                estadosNovos->estados[x] = estados1->estados[x];
            }

            for(int y = 0; y < estados2->qtEstados; y++){
                estadosNovos->estados[estados1->qtEstados+y] = estados2->estados[y];
            }
            estadosE = estadosNovos->estados;
            return estadosE;
        };

        /*----------------------- FUNÇÃO PARA UNIR ESTADOS---------------------------------*/
        string *unirEstadosFecho(AUTOMATO *estados1){
            AUTOMATO *estadosNovos = new AUTOMATO;
            string *estadosE;
            estadosNovos->estados = new string[estados1->qtEstados+2];
            estadosNovos->qtEstados = estados1->qtEstados+2;
            for(int x = 0; x < estados1->qtEstados; x++){
                estadosNovos->estados[x] = estados1->estados[x];
            }
            estadosE = estadosNovos->estados;
            return estadosE;
        };

        /*----------------------- FUNÇÃO PARA UNIR TRANSIÇÕES------------------------------*/
        // TRANSICOES *unirTransicoes(AUTOMATO *transicoes1){
        //     TRANSICOES *transicao;
        //     base->transicoes = new TRANSICOES*[2];
        //     base->transicoes[0] = new TRANSICOES[1];
        //     base->transicoes[0][0].qtEstados = 1;
        //     base->transicoes[0][0].estados = new int[1];
        //     base->transicoes[0][0].estados[0] = 1;
        //     base->transicoes[1] = new TRANSICOES[1];
        //     base->transicoes[1][0].qtEstados = 0;

        //     for(int x = 0; x < transicoes1->qtEstados; x++){
        //         for(int y = 0; y < transicoes1->alfabeto.size(); y++){

        //         }
        //     }
        // };



        //INÍCIOS DE FUNÇÕES DE TESTES E IMPLEMENTAÇÃO DA ORIGINAL
        void insercaoTransicoesBase(string estadoTransicao, string simbolo, AUTOMATO *transicao1){
            cout << " NO ESTADO < " << estadoTransicao << " > ENTRA < " << simbolo << " > VAI PARA: ";
            string armazena;
            TRANSICOES *transicaoEstados;
            transicao1->transicoes = new TRANSICOES*[transicao1->qtEstados];
            
            //transicao1->transicoes[0][0].estados = new int[transicao1->qtEstados];

            //transicaoEstados->transicao = new TRANSICOES[transicao1->qtEstados];
            //transicao1->transicoes[0][0].estados[0] = 1; 
            //transicao1->transicao = new AUTOMATO*[transicao1->qtEstados];

            transicao1->estados = renomearEstados(transicao1);

            //TRANSICOES *transicao;
        //     base->transicoes = new TRANSICOES*[2];
        //     base->transicoes[0] = new TRANSICOES[1];
        //     base->transicoes[0][0].qtEstados = 1;
        //     base->transicoes[0][0].estados = new int[1];
        //     base->transicoes[0][0].estados[0] = 1;
        //     base->transicoes[1] = new TRANSICOES[1];
        //     base->transicoes[1][0].qtEstados = 0;

            //if(armazena == )
            for(int x = 0; x < estadoTransicao.length(); x++){
                for(int y = 0; y < transicao1->alfabeto.size(); y++){
                    transicao1->transicoes[x][y].estados[x] = x+1;
                }
            }
            //armazena = simbolo;

            cout << " NO ESTADO < " << estadoTransicao << " > ENTRA < " << simbolo << " > VAI PARA: " << transicao1->estados[1];
            cout << endl;
        };


        //FINAL DE FUNÇÕES DE TESTES


        /*----------------------- FUNÇÃO BASE - CONCLUÍDA-------------------------------*/
    	AUTOMATO *Base(string simbolo) {
            AUTOMATO *base = new AUTOMATO; // Criando objeto automato
            base->alfabeto = simbolo; // Alfabeto recebendo o simbolo
            //Código abaixo para criar os estados
            base->qtEstados = 2;
            base->estados = new string[base->qtEstados];
            base->estados[0] = "0";
            base->estados[1] = "1";
            base->estadoInicial = 0;//Correspondente ao estado inicial
            base->qtEstFinais = 1;//Definindo a quantidade de estados finais, só 1
            base->estadosFinais = new int[1];//Criando objeto estados finais
            base->estadosFinais[0] = 1; // Dizendo que é o estado final
            //Código abaixo referente as transições do automato
            string estadoTransicao;
            estadoTransicao = base->estados[0];

            insercaoTransicoesBase(estadoTransicao, simbolo, base);

            // base->transicoes = new TRANSICOES*[2];
            // base->transicoes[0] = new TRANSICOES[1];
            // base->transicoes[0][0].qtEstados = 1;
            // base->transicoes[0][0].estados = new int[1];
            // base->transicoes[0][0].estados[0] = 1;
            // base->transicoes[1] = new TRANSICOES[1];
            // base->transicoes[1][0].qtEstados = 0;

            //Só para testes, depois remover
            cout << "-----------------------------------------------" << endl;
            cout << " ALFABETO: " << base->alfabeto << endl;
            cout << " ESTADO INICIAL: " << base->estadoInicial << endl;
            cout << " CONJUNTO DE ESTADOS: ";
            for(int x = 0; x < base->qtEstados; x++){
                cout << " " << base->estados[x];
            }
            cout << endl << " ESTADO FINAIS: ";
            for(int x = 0; x < base->qtEstFinais; x++){
                cout << " " << base->estadosFinais[x];
            }
            cout << endl << " QUANTIDADE ESTADOS: " << base->qtEstados << endl;
            cout << " QUANTIDADE ESTADOS FINAIS: " << base->qtEstFinais<< endl;

            /*for(int x = 0; x < base->qtEstados-1; x++){
                for(int y = 0; y < base->alfabeto.size(); y++){
                    cout << " ENTRANDO: '" << base->alfabeto << "' NO ESTADO: '" << base->estados[x] << "' VAI PARA O ESTADO: ";
                    cout << " '" << base->transicoes[x][y].estados[x] << "'";
                }
            }*/
            cout << endl << "-----------------------------------------------" << endl << endl;
            return base;
        };


        /*----------------------- FUNÇÃO CONCATENAÇÃO---------------------------------*/
        AUTOMATO *Concatenacao(AUTOMATO *a, AUTOMATO *b) {
            AUTOMATO *novo = new AUTOMATO;
            novo->alfabeto = unirAlfabetos(a->alfabeto, b->alfabeto);
            novo->qtEstados = a->qtEstados+b->qtEstados+2;
            novo->estados = new string[novo->qtEstados];
            //Unir Estados
            novo->estados = unirEstados(a, b);
            //Criando mais dois novos estados
            novo->estados[novo->qtEstados-1] = "1";
            novo->estados[novo->qtEstados-2] = "1";
            //Renomeando Estados
            novo->estados = renomearEstados(novo);
            novo->estadoInicial = 0;
            novo->estadosFinais = new int[1];
            novo->estadosFinais[0] = novo->qtEstados-1;//Estado final
            novo->qtEstFinais = 1;
            //Unir Transições

            novo->transicoes = new TRANSICOES*[novo->qtEstados];

            novo->transicoes[0] = new TRANSICOES[1];
            novo->transicoes[0][0].qtEstados = 1;
            novo->transicoes[0][0].estados = new int[1];
            novo->transicoes[0][0].estados[0] = 1;
            novo->transicoes[1] = new TRANSICOES[1];
            novo->transicoes[1][0].qtEstados = 0;
            //Preencher as transições do novo autômatos com as transições de a e b

            cout << " ENTRANDO: '" << novo->alfabeto[0] << "' NO ESTADO: '" << novo->estados[0] << "' VAI PARA O ESTADO: ";
            cout << " '" << novo->transicoes[0][0].estados[0] << "'" << endl;



            //Só para testes, depois remover
            cout << "-----------------------------------------------" << endl;
            cout << " ALFABETO: " << novo->alfabeto << endl;
            cout << " ESTADO INICIAL: " << novo->estadoInicial << endl;
            cout << " CONJUNTO DE ESTADOS: ";
            for(int x = 0; x < novo->qtEstados; x++){
                cout << " " << novo->estados[x];
            }
            cout << endl << " ESTADO FINAIS: ";
            for(int x = 0; x < novo->qtEstFinais; x++){
                cout << " " << novo->estadosFinais[x];
            }
            cout << endl << " QUANTIDADE ESTADOS: " << novo->qtEstados << endl;
            cout << " QUANTIDADE ESTADOS FINAIS: " << novo->qtEstFinais<< endl;

            // for(int x = 0; x < novo->qtEstados-1; x++){
            //     for(int y = 0; y < novo->alfabeto.size(); y++){
            //         cout << " ENTRANDO: '" << novo->alfabeto << "' NO ESTADO: '" << novo->estados[x] << "' VAI PARA O ESTADO: ";
            //         cout << " '" << novo->transicoes[x][y].estados[x] << "'";
            //     }
            // }
            cout << endl << "-----------------------------------------------" << endl << endl;

            return novo;
        };

        AUTOMATO *Uniao(AUTOMATO *a, AUTOMATO *b) {
            AUTOMATO *novo = new AUTOMATO;
            novo->alfabeto = unirAlfabetos(a->alfabeto,b->alfabeto);
            novo->qtEstados = a->qtEstados+b->qtEstados;
            novo->estados = new string[novo->qtEstados];
            //Preencher os estados do novo autômatos com os estados de a e b
            novo->estados = unirEstados(a, b);
            novo->estados = renomearEstados(novo);
            //Preencher as transições do novo autômatos com as transições de a e b
            novo->estadoInicial = 0;
            novo->estadosFinais = new int[1];
            novo->estadosFinais[0] = novo->qtEstados-1;
            novo->qtEstFinais = 1;

            cout << "-----------------------------------------------" << endl;
            cout << " ALFABETO: " << novo->alfabeto << endl;
            cout << " ESTADO INICIAL: " << novo->estadoInicial << endl;
            cout << " CONJUNTO DE ESTADOS: ";
            for(int x = 0; x < novo->qtEstados; x++){
                cout << " " << novo->estados[x];
            }
            cout << endl << " ESTADO FINAIS: ";
            for(int x = 0; x < novo->qtEstFinais; x++){
                cout << " " << novo->estadosFinais[x];
            }
            cout << endl << " QUANTIDADE ESTADOS: " << novo->qtEstados << endl;
            cout << " QUANTIDADE ESTADOS FINAIS: " << novo->qtEstFinais<< endl;

            return novo;
        };


        AUTOMATO *FechoDeKleene(AUTOMATO *a) {
            AUTOMATO *novo = new AUTOMATO;
            novo->alfabeto = unirAlfabetos(a->alfabeto,"");
            novo->qtEstados = a->qtEstados+2;
            novo->estados = new string[novo->qtEstados];
            //Preencher os estados do novo autômatos com os estados de a
            //Unir Estados
            novo->estados = unirEstadosFecho(a);
            //Criando mais dois novos estados
            novo->estados[novo->qtEstados-1] = "1";
            novo->estados[novo->qtEstados-2] = "1";
            //Renomeando Estados
            novo->estados = renomearEstados(novo);

            //Preencher as transições do novo autômatos com as transições de a
            novo->estadoInicial = 0;
            novo->estadosFinais = new int[1];
            novo->estadosFinais[0] = novo->qtEstados-1;
            novo->qtEstFinais = 1;


            //Só para testes, depois remover
            cout << "-----------------------------------------------" << endl;
            cout << " ALFABETO: " << novo->alfabeto << endl;
            cout << " ESTADO INICIAL: " << novo->estadoInicial << endl;
            cout << " CONJUNTO DE ESTADOS: ";
            for(int x = 0; x < novo->qtEstados; x++){
                cout << " " << novo->estados[x];
            }
            cout << endl << " ESTADO FINAIS: ";
            for(int x = 0; x < novo->qtEstFinais; x++){
                cout << " " << novo->estadosFinais[x];
            }
            cout << endl << " QUANTIDADE ESTADOS: " << novo->qtEstados << endl;
            cout << " QUANTIDADE ESTADOS FINAIS: " << novo->qtEstFinais<< endl;

            // for(int x = 0; x < novo->qtEstados-1; x++){
            //     for(int y = 0; y < novo->alfabeto.size(); y++){
            //         cout << " ENTRANDO: '" << novo->alfabeto << "' NO ESTADO: '" << novo->estados[x] << "' VAI PARA O ESTADO: ";
            //         cout << " '" << novo->transicoes[x][y].estados[x] << "'";
            //     }
            // }
            cout << endl << "-----------------------------------------------" << endl << endl;

            return novo;
        };

        void montadorAutomato(string posTho){
           PILHAAUTOMATO *topo = NULL;

            AUTOMATO *recebe1, *recebe2, *automato;
            for(int x = 0; x < posTho.length(); x++){
                simbolo = posTho[x];

            	if(simbolo != "+" && simbolo != "." && simbolo != "*"){
                    //Chamando a base para gerar a expressão regular que tá nos simbolo o automato
                    empilhar(&topo, Base(simbolo));
                    //listar(topo);
                    cout << "Montou a Base" << endl << endl;
                    //listar(topo);
                }
                //Para operador unário Fecho de Kleene
                else if(simbolo == "*"){
                    recebe1 = topo->automato;
                    desempilhar(&topo);
                    cout << "-----------------------------------" << endl;
                    //listar(topo);
                    empilhar(&topo, FechoDeKleene(recebe1));
                    cout << "Entrou aqui Fecho de Kleene" << endl;
                    //listar(topo);
                }
                else if(simbolo == "+" || simbolo == "."){
                    recebe2 = topo->automato;
                    //novo->estados = unirEstados(a->estados, b->estados);
                    desempilhar(&topo);
                    if(topo != NULL){
                        recebe1 = topo->automato;
                        desempilhar(&topo);
                        if(simbolo == "+"){
                            empilhar(&topo, Concatenacao(recebe1, recebe2));//Chamando concatenação, falta tratar ainda tá incompleta
                            cout << "Entrou aqui Concatenação" << endl;
                            //listar(topo);
                        }
                        else if(simbolo == "."){
                            empilhar(&topo, Uniao(recebe1, recebe2));
                            cout << "Entrou aqui União" << endl;
                        }
                    }
                }
                //listar(topo);
            }
        };
};
