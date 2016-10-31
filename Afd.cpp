#ifndef AFD_H
#define AFD_H

#include <iostream>
#include <vector>
#include <sstream>
#include "Subconjuntos.cpp"
#include "Automato.cpp"
#include "Transicao.cpp"
#include "Transicaoafd.cpp"

using namespace std;

class Afd{
	public:
		Subconjuntos *subcon =  new Subconjuntos();
	public:
		Afd(){
			Automato gerandoAFDOriginal(Automato automato, vector<string> conversao);
			void imprimirAutomato(Automato automato, string dados);
			void gerandoEstadosAFD(Automato automato, vector<string> conversao);
			vector<string> gerando(Automato automato, vector<string> conversao, string simbolo);
			string converterString(vector <string> convert);
			bool verificaIguais(Automato automato, string estados);
			Automato renomearEstadosAFD(Automato automato);
		};
		~Afd();

		/*--------------------------FUNÇÃO PARA RENOMEAR ESTADOS PARA AFD-----------------------*/
		Automato renomearEstados(Automato automato){
			stringstream conversao;
            vector<string> nomeNovo;
            string anterior, novo;
            int tamanho = automato.getNumeroEstados();
			for(int x = 0; x < tamanho; x++){
				anterior = automato.getEstado(x);
				conversao << x;
                novo = conversao.str();
				automato.alteraEstado(anterior, novo);
               	conversao.str("");
			}
			return automato;
		};

		/*--------------------------FUNÇÃO VERIFICAR CADA ELEMENTO OS ESTADOS------------------*/
		vector<string> gerando(Automato automato, vector<string> conversao, string simbolo){
			vector<string> recebeu;
			vector<string> receb;
			vector<Transicao> transicoes = automato.getTransicoes();
			int o = 0;
			receb.clear();

			for(int x = 0; x < simbolo.length(); x++){
				for(int y = 0; y < conversao.size(); y++){
					for(int z = 0; z < transicoes.size(); z++){
						if(conversao[y] == transicoes[z].getOrigem()){
							if(transicoes[z].getSimbolo() == simbolo[x]){
								for(int a = 0; a < subcon->fechoEOficial(automato, transicoes[z].getDestino()).size(); a++){
									recebeu = subcon->fechoEOficial(automato, transicoes[z].getDestino());
									receb.push_back(recebeu[o]);
									o++;
								}
								o = 0;
							}
						}
					}
				}
				return receb;
			}
		};

		/*----------------------------FUNÇÃO PARA CRIAR OS ESTADOS---------------------------*/
		void gerandoEstadosAFD(Automato automato, vector<string> conversao){
			//automato = renomearEstados(automato);
			vector<string> recebeEstados;
			vector<string> uniaoEstados;
			string simbolo = automato.getAlfabeto();
			string recebeSimbolo, estados, op1, op2;

			estados = converterString(conversao);
			uniaoEstados.push_back(estados);
			automato.setEstados(uniaoEstados);
			op1 = estados;
			estados.clear();

			for(int x = 0; x < simbolo.length()-1; x++){
				recebeSimbolo = simbolo[x];
				recebeEstados = gerando(automato, conversao, recebeSimbolo);
				estados = converterString(recebeEstados);
				if (verificaIguais(automato, estados) == true){
					uniaoEstados.push_back(estados);
					automato.setEstados(uniaoEstados);
					op2 = estados;
				}
				char simb = simbolo[x];
				gerandoTransicoesAFD(automato, conversao, op1, op2, simb);				
			}
		};


		void principalAFD(Automato automato){

		};

		void gerandoTransicoesAFD(Automato automato, vector<string> conversao, string op1, string op2, char simbolo){
			//automato = renomearEstados(automato);// Depois chamar agora fazendo os testes
			vector<Transicao> transicoes = automato.getTransicoes();
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();

			int cont = 0;
			for(int y = 0; y < conversao.size(); y++){
				for(int a = 0; a < transicoes.size(); a++){
					if(conversao[y] == transicoes[a].getOrigem()){
						if(transicoes[a].getSimbolo() == simbolo){
							if(cont < 1)
								automato.setTransicaoafd(op1, op2, simbolo);
							cont++;
						}
					}
				}
			}
			imprimirTransicoesAFD(automato);
			//imprimirAutomatoAFD(automato);
		};

		void imprimirTransicoesAFD(Automato automato){
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();			
			for(int b = 0; b < transicaoafd.size(); b++){
                cout << transicaoafd[b].getSimbolo() << " - TRANSIÇÕES: " << transicaoafd[b].getOrigem() << " --> " << transicaoafd[b].getDestino() << endl;
			}
		}
	
		/*----------------------------FUNÇÃO PARA TRANSFORMAR EM STRING------------------------*/
		string converterString(vector <string> convert){
			string novaString;
			for(int x = 0; x < convert.size(); x++){
				novaString += convert[x];
			}
			return novaString;
		};

		/*----------------------------FUNÇÃO VERIFICAR SE TEM REPETIDOS------------------------*/
		bool verificaIguais(Automato automato, string estados){
			for(int y = 0; y < automato.getNumeroEstados(); y++){
				if(automato.getEstado(y) != estados)
					return true;
				else
					return false;
			}
		};

		void imprimirAutomatoAFD(Automato automato){
			vector<Transicao> transicoes = automato.getTransicoes();
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();

			Automato automatoAFD;
			automatoAFD = renomearEstados(automato);
			string dados = automatoAFD.getAlfabeto();
			string armazena;
			cout << endl << "----------------------------------------------------------------------" << endl;
			cout << "     ESTADOS" ;
			for (int x = 0; x < automatoAFD.getTamanhoAlfabeto()-1; x++){
				cout << "     |    " << dados[x];
			}
			cout << endl << "----------------------------------------------------------------------" << endl;
			for (int x = 0; x < automatoAFD.getNumeroEstados(); x++) {
				if(x == 0)
					cout << "       ->" << automatoAFD.getEstado(x) << "       |";
				else
					cout << "         " << automatoAFD.getEstado(x) << "       |";
				cout << endl << "----------------------------------------------------------------------" << endl;

				for (int  j = 0; j < automatoAFD.getTamanhoAlfabeto()-1; j++) {
					for (int k = 0; k <  transicaoafd.size(); k++) {
						if(automatoAFD.getEstado(x) == transicaoafd[k].getOrigem()){
	                        if(dados[j] == transicaoafd[k].getSimbolo()){
	                        	cout << transicaoafd[k].getDestino() << " | ";
	                        	//imprimirTransicoesAFD(automatoAFD);
	                        }
						}
					}
				}
			}
			cout << endl;
		};









		/*------------------------------FUNÇÃO PARA GERAR AFD------ ---------------------------*/
		Automato gerandoAFDOriginal(Automato automato, vector<string> conversao){
			vector<string> afdFinal;
			vector<string> recebeu;
			vector<string> afd;
			vector<string> uniaoEstados;
			string estados, recebe, alfabetoAfd, op1, op2;
			vector<Transicao> transicoes = automato.getTransicoes();
			
			for(int x = 0; x < conversao.size(); x++){
				estados += conversao[x];
			}
			afd.push_back(estados);
			
			uniaoEstados.push_back(estados);
			op1 = estados;

			cout << endl << endl;
			estados.clear();
			afd.clear();
			int o = 0;

			string dados = automato.getAlfabeto();
			for(int x = 0; x < automato.getTamanhoAlfabeto()-1; x++){
				for(int y = 0; y < conversao.size(); y++){
					for(int z = 0; z < transicoes.size(); z++){
						if(conversao[y] == transicoes[z].getOrigem()){
							if(transicoes[z].getSimbolo() == dados[x]){
								for(int a = 0; a < subcon->fechoEOficial(automato, transicoes[z].getDestino()).size(); a++){
									recebeu = subcon->fechoEOficial(automato, transicoes[z].getDestino());
									estados += recebeu[o];
									o++;
								}
								o = 0;
							}
						}
					}
				}
				for(int y = 0; y < conversao.size(); y++){
					for(int a = 0; a < transicoes.size(); a++){
						if(conversao[y] == transicoes[a].getOrigem()){
							if(transicoes[a].getSimbolo() == dados[x]){
								char ajuda;
								int cont = 0, ocm = 0;
								ajuda = dados[x];
								op2 = estados;
								automato.setTransicaoafd(op1, op2, ajuda);
							}
						}
					}
				}
				afd.push_back(estados);
				uniaoEstados.push_back(estados);
				afd.clear();
				estados.clear();
			}
			automato.setEstados(uniaoEstados);
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();
							
			for(int b = 0; b < transicaoafd.size(); b++){
                cout << transicaoafd[b].getSimbolo() << " - TRANSIÇÕES: " << transicaoafd[b].getOrigem() << " --> " << transicaoafd[b].getDestino() << endl;
			}

			for(int x = 0; x < automato.getNumeroEstados(); x++){
				for(int y = x+1; y < automato.getNumeroEstados(); y++){
					if(automato.getEstado(x) != automato.getEstado(y)){
						automato.setEstados(uniaoEstados);
					}
					else{
						break;
					}
				}
			}
			cout << endl << endl;
			//gerandoAFDFinal(automato);
			for(int x = 0; x < recebeu.size(); x++){
				cout << "  " << recebeu[x];
			}
			//gerandoAFDFinal(automato, conversao);
			imprimirAutomatoAFD(automato);
			return automato;
		};





		/*------------------------FUNÇÃO ABAIXO PARA TESTES DE AFD E FECHO E-------------------*/
		void baseAFD(Automato automato) {
			string estados, recebe, alfabetoAfd;
			vector<string> afd;
			vector<Transicao> transicoes = automato.getTransicoes();
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();
			//Para Alfabeto
			cout << " \t AUTOMATO FINITO DETERMINISTICO" << endl;
			recebe = automato.getAlfabeto();
			for(int x = 0; x < recebe.length()-1; x++){
				alfabetoAfd += recebe[x];
			}
			automato.setAlfabeto(alfabetoAfd);
			cout << " ALFABETO: " << automato.getAlfabeto() << endl;
			cout << " TAMANHO ALFABETO: " << automato.getTamanhoAlfabeto() << endl;

			//Para Estado Inicial
			automato.setEstadoInicial(afd[0]);
			cout << " ESTADO INICIAL: " << automato.getEstadoInicial() << endl;

			//Para Transição
			for(int x = 0; x < transicaoafd.size(); x++){
                cout << " TRANSIÇÕES: " << transicaoafd[x].getOrigem() << " --> " << transicaoafd[x].getDestino() << endl;
			}
		};		
};
#endif // AFD_H