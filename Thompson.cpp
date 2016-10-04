#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include "Automato.cpp"
#include "Transicao.cpp"


using namespace std;

class Thompson{
	public:
		string posTho;
	public:
		//Construtor
		Thompson(){
			Automato constroiAutomato(string);
			bool temVazio(string);
			string moveVazio(string);
			bool operando(string);
			bool operando(char);
			bool operadorUnario(string);
			bool operadorBinario(string);
			bool operadorConcatenacao(string);
			bool operadorUniao(string);
			Automato base(char);
			Automato concatenacao(Automato, Automato);
			Automato uniao(Automato, Automato);
			Automato fechoDeKleene(Automato);
			char retiraAspas(string);
			vector<Transicao> uneTransicoes(vector<Transicao>, vector<Transicao>);
			vector<string> uneEstados(vector<string>, vector<string>);
			string uneAlfabetos(string, string);
			bool contemLetra(string, char);
			Automato renomeiaConcatenacaoB(Automato, string);
			Automato renomeiaUniaoA(Automato);
			Automato renomeiaUniaoB(Automato);
			Automato renomeiaUniao(Automato);
			Automato renomeiaFechoA(Automato);
			Automato renomeiaFecho(Automato);
		};

		/*------------------------FUNÇÃO PARA MONTAR O AUTOMATO----------------------------*/
		Automato montadorAutomato(string posTho) {
			stack<Automato> pilha;
			Automato automato, op1, op2;
			string simbolo;
			if(posTho.length() == 0){
				cout << "---------------------------------------------------" << endl;
				cout << " É NECESSÁRIO INSERIR PRIMEIRO UMA EXPRESSÃO" << endl;
				cout << " \tPOR FAVOR, ESCOLHA A OPÇÃO 1" << endl;
				cout << "---------------------------------------------------" << endl;
			}
			else{
				//Percorrendo cada simbolo da posfixa
				for (int i = 0; i < posTho.size(); i++) {
					simbolo = posTho[i];
					//Se for um operando empilha a base
					if (operando(simbolo)){
						pilha.push(base(retiraAspas(simbolo)));
					}
					//Se for um operador Unário Fecho de Kleene
					else if (operadorUnario(simbolo)) {
						op1 = pilha.top();
						pilha.pop();
						pilha.push(fechoDeKleene(op1));
					} 
					//Condição para operador binário
					else if (operadorBinario(simbolo)) {
						op2 = pilha.top();
						pilha.pop();
						//Verifica se a pilha ta vazia
						if (!pilha.empty()) {
							op1 = pilha.top();
							pilha.pop();
							//sendo um operador de concatenção
							if (operadorConcatenacao(simbolo)){
								pilha.push(concatenacao(op1, op2));
							}
							//sendo um operador de união
							else if (operadorUniao(simbolo))
								pilha.push(uniao(op1, op2));
						}
					}
				}

				automato = pilha.top();
				pilha.pop();

				if (temVazio(posTho))
					automato.setAlfabeto(moveVazio(automato.getAlfabeto()));
				else
					automato.setAlfabeto(automato.getAlfabeto() + "&");

				if (pilha.empty()){
					mostrarAutomato(automato);
					return automato;
				}
			}

		};

		/*------------------------FUNÇÃO PARA MOSTRAR A. F. M. &----------------------------*/
		void mostrarAutomato(Automato automato){
			vector<Transicao> transicoes = automato.getTransicoes();
			string origem, texto, simbolo, teste, armazena;
			string aux;
			aux = automato.getAlfabeto();
			cout << endl << "----------------------------------------------------------------------" << endl;
			cout << " ESTADOS" ;
			for (int x = 0; x < aux.size(); x++){
				cout << "    |    " << aux[x];
			}
			cout << endl << "----------------------------------------------------------------------" << endl;
			for (int x = 0; x < automato.getNumeroEstados(); x++) {
				origem = automato.getEstado(x);
				if (automato.getEstado(x) == automato.getEstadoInicial()){
					cout << "  ->" << origem << "      |";
				}
				else if (automato.getEstado(x) == automato.getEstadoFinal()){
					cout << "   *" << origem << "      |";
				}
				else{
                	cout << "    " << origem << "      |";
                }

				for (int  j = 0; j < automato.getTamanhoAlfabeto(); j++) {
					teste.clear();
					for (int k = 0; k <  transicoes.size(); k++) {
                        armazena = automato.getAlfabeto();
                        if(armazena[j] == transicoes[k].getSimbolo()){
							if (transicoes[k].getOrigem() == origem && simbolo == texto){
								teste += transicoes[k].getDestino();
	                        }
                        }

					}
					if (teste.empty()){
						cout << "         | ";
					}

					else{
                        cout << "   {" + teste + "}  |";
					}
				}
				cout << endl << "----------------------------------------------------------------------" << endl;
			}
			cout << endl;
		};

		/*------------------------FUNÇÃO PARA VERIFICAR PALAVRA VAZIA------------------------*/
		bool temVazio(string posTho) {
			for (int i = 0; i < posTho.size(); i++)
				if (posTho[i] == '&')
					return true;
			return false;
		};

		/*------------------------FUNÇÃO PARA RECEBE PALAVRA VAZIA--------------------------*/
		string moveVazio(string alfabeto) {
			string aux = "";
			for (int i = 0; i < alfabeto.size(); i++)
				if (alfabeto[i] != '&')
					aux.push_back(alfabeto[i]);
			aux.push_back('&');
			return aux;
		};

		/*---------------------------FUNÇÃO PARA SABER SE É OPERANDO------------------------*/
		bool operando(string simbolo) {
			for (int i = 0; i < simbolo.size(); i++) {
				if (operadorUnario(simbolo) || operadorBinario(simbolo))
					return false;
			}
			return true;
		};

		bool operando(char simbolo) {
			string simb;
			simb = simbolo;
			if (operadorUnario(simb) || operadorBinario(simb))
				return false;
			return true;
		};

		/*---------------------------FUNÇÃO PARA SABER SE É OPERADOR UNÁRIO--------------------*/
		bool operadorUnario(string simbolo) {
			if (simbolo == "*")
				return true;
			return false;
		};

		/*---------------------------FUNÇÃO PARA SABER SE É OPERADOR BINÁRIO--------------------*/
		bool operadorBinario(string simbolo) {
			if (simbolo == "+" || simbolo == ".")
				return true;
			return false;
		};

		/*-----------------------FUNÇÃO PARA SABER SE É OPERADOR CONCATENAÇÃO--------------------*/
		bool operadorConcatenacao(string simbolo) {
			if (simbolo == ".")
				return true;
			return false;
		};

		/*-------------------------FUNÇÃO PARA SABER SE É OPERADOR UNIÃO-------------------------*/
		bool operadorUniao(string simbolo) {
			if (simbolo == "+")
				return true;
			return false;
		};

		/*-----------------------------FUNÇÃO PARA DEFINIR A BASE--------------------------------*/
		Automato base(char simbolo) {
			Automato automato;
			automato.setAlfabeto(simbolo);
			automato.setEstado("q0");
			automato.setEstado("q1");
			automato.setTransicao("q0", "q1", simbolo);
			automato.setEstadoInicial("q0");
			automato.setEstadoFinal("q1");
			return automato;
		};

		/*---------------------------FUNÇÃO PARA DEFINIR A CONCATENÇÃO----------------------------*/
		Automato concatenacao(Automato a, Automato b) {
			Automato automato;
			b = renomeiaConcatenacaoB(b, a.getEstadoFinal());
			automato.setAlfabeto(uneAlfabetos(a.getAlfabeto(), b.getAlfabeto()));
			automato.setEstados(uneEstados(a.getEstados(), b.getEstados()));
			automato.setTransicoes(uneTransicoes(a.getTransicoes(), b.getTransicoes()));
			automato.setEstadoInicial("q0");
			automato.setEstadoFinal(b.getEstadoFinal());
			automato.setTransicao(a.getEstadoFinal(), b.getEstadoInicial(), '&');
			return automato;
		};

		/*---------------------------FUNÇÃO PARA DEFINIR A UNIÃO--------------------------------*/
		Automato uniao(Automato a, Automato b) {
			Automato automato;
			a = renomeiaUniaoA(a);
			b = renomeiaUniaoB(b);
			automato.setEstado("inicio");
			automato.setTransicao("inicio", a.getEstadoInicial(), '&');
			automato.setTransicao("inicio", b.getEstadoInicial(), '&');
			automato.adicionaEstados(uneEstados(a.getEstados(), b.getEstados()));
			automato.adicionaTransicoes(uneTransicoes(a.getTransicoes(), b.getTransicoes()));
			automato.setEstado("fim");
			automato.setTransicao(a.getEstadoFinal(), "fim", '&');
			automato.setTransicao(b.getEstadoFinal(), "fim", '&');
			automato.setAlfabeto(uneAlfabetos(a.getAlfabeto(), b.getAlfabeto()));
			automato.setEstadoInicial("inicio");
			automato.setEstadoFinal("fim");
			automato = renomeiaUniao(automato);
			return automato;
		};


		/*---------------------------FUNÇÃO PARA DEFINIR FECHO DE KLEENE------------------------*/
		Automato fechoDeKleene(Automato a) {
			Automato automato;
			a = renomeiaFechoA(a);
			automato.setEstado("inicio");
			automato.setTransicao("inicio", a.getEstadoInicial(), '&');
			automato.setTransicao("inicio", "fim", '&');
			automato.setAlfabeto(a.getAlfabeto());
			automato.adicionaEstados(a.getEstados());
			automato.adicionaTransicoes(a.getTransicoes());
			automato.setEstado("fim");
			automato.setTransicao(a.getEstadoFinal(), a.getEstadoInicial(), '&');
			automato.setTransicao(a.getEstadoFinal(), "fim", '&');
			automato.setEstadoInicial("inicio");
			automato.setEstadoFinal("fim");
			automato = renomeiaFecho(automato);
			return automato;
		};

		char retiraAspas(string simbolo) {
			char letra;
			for (int i = 0; i < simbolo.size(); i++)
				if (simbolo[i] != '\'')
					letra = simbolo[i];
			return letra;
		};


		/*----------------------------------FUNÇÃO PARA UNIR TRANSIÇÕES--------------------------*/
		vector<Transicao> uneTransicoes(vector<Transicao> transicoes1, vector<Transicao> transicoes2) {
			vector<Transicao> transicoes;
			for (int i = 0; i < transicoes1.size(); i++){
				transicoes.push_back(transicoes1[i]);
			}
			for (int i = 0; i < transicoes2.size(); i++){
				transicoes.push_back(transicoes2[i]);
			}
			return transicoes;
		};

		/*----------------------------------FUNÇÃO PARA UNIR ESTADOS-----------------------------*/
		vector<string> uneEstados(vector<string> estados1, vector<string> estados2) {
			vector<string> estados;
			for (int i = 0; i < estados1.size(); i++){
				estados.push_back(estados1[i]);
			}
			for (int i = 0; i < estados2.size(); i++){
				estados.push_back(estados2[i]);
			}
			return estados;
		};

		/*----------------------------------FUNÇÃO PARA UNIR ALFABETOS--------------------------*/
		string uneAlfabetos(string alfabeto1, string alfabeto2) {
			string alfabeto;
			alfabeto = alfabeto1;
			for (int i = 0; i < alfabeto2.size(); i++) {
				if (!contemLetra(alfabeto, alfabeto2[i]))
					alfabeto.push_back(alfabeto2[i]);
			}
			return alfabeto;
		};

		/*-----------------------FUNÇÃO PARA SE A LETRA PASSADA É IGUAL AO SIMBOLO----------------*/
		bool contemLetra(string alfabeto, char simbolo) {
			for (int i = 0; i < alfabeto.size(); i++) {
				if (alfabeto[i] == simbolo)
					return true;
			}
			return false;
		};

		/*---------------------------------FUNÇÃO PARA RENOMEAR CONCATENAÇÃO-----------------------*/
		Automato renomeiaConcatenacaoB(Automato automato, string estadoFinal) {
			string final = "";
			int contador;
			for (int i = 1; i < estadoFinal.size(); i++){
				final.push_back(estadoFinal[i]);
			}
			contador = stoi(final);
			contador++;
			string novo, anterior;
			for (int i = 0; i < automato.getNumeroEstados(); i++, contador++) {
				anterior = automato.getEstado(i);
				novo = "q" + to_string(contador);
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		};
		
		/*---------------------------------FUNÇÃO PARA RENOMEAR UNIÃO-----------------------------*/
		Automato renomeiaUniaoA(Automato automato) {
			string novo, anterior;

			for (int i = 0; i < automato.getNumeroEstados(); i++) {
				anterior = automato.getEstado(i);
				novo = "a" + anterior;
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		};

		Automato renomeiaUniaoB(Automato automato) {
			string novo, anterior;

			for (int i = 0; i < automato.getNumeroEstados(); i++) {
				anterior = automato.getEstado(i);
				novo = "b" + anterior;
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		};

		Automato renomeiaUniao(Automato automato) {
			string novo, anterior;

			for (int i = 0, contador = 0; i < automato.getNumeroEstados(); i++, contador++) {
				anterior = automato.getEstado(i);
				novo = "q" + to_string(contador);
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		};


		/*---------------------------------FUNÇÃO PARA RENOMEAR FECHO DE KLEENE-----------------------*/
		Automato renomeiaFechoA(Automato automato) {
			string novo, anterior;

			for (int i = 0; i < automato.getNumeroEstados(); i++) {
				anterior = automato.getEstado(i);
				novo = "a" + anterior;
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		};

		Automato renomeiaFecho(Automato automato) {
			string novo, anterior;

			for (int i = 0, contador = 0; i < automato.getNumeroEstados(); i++, contador++) {
				anterior = automato.getEstado(i);
				novo = "q" + to_string(contador);
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		};
};
