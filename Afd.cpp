#ifndef AFD_H
#define AFD_H

#include <iostream>
#include <vector>
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
		};
		~Afd();

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

		void gerandoEstadosAFD(Automato automato, vector<string> conversao){
			vector<string> recebeEstados;
			vector<string> uniaoEstados;
			string simbolo = automato.getAlfabeto();
			string recebeSimbolo, estados;

			estados = converterString(conversao);
			uniaoEstados.push_back(estados);
			automato.setEstados(uniaoEstados);
			estados.clear();

			for(int x = 0; x < simbolo.length()-1; x++){
				recebeSimbolo = simbolo[x];
				recebeEstados = gerando(automato, conversao, recebeSimbolo);
				estados = converterString(recebeEstados);
				if (verificaIguais(automato, estados) == true){
					uniaoEstados.push_back(estados);
					automato.setEstados(uniaoEstados);
				}
			}

			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << " ESTADOS: " << automato.getEstado(x) << endl;
			}
		};

	

		string converterString(vector <string> convert){
			string novaString;
			for(int x = 0; x < convert.size(); x++){
				novaString += convert[x];
			}
			return novaString;
		};

		bool verificaIguais(Automato automato, string estados){
			for(int y = 0; y < automato.getNumeroEstados(); y++){
				if(automato.getEstado(y) != estados)
					return true;
				else
					return false;
			}
		};

		/*------------------------------FUNÇÃO PARA GERAR AFD------ ------------------------*/
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
			imprimirAutomato(automato, dados);
			return automato;
		};


		// void gerandoAFDFinal(Automato automato, vector<string> conversao){
		// 	Automato automatoafd = gerandoAFD(automato, conversao);
		// 	vector<string> estadosEnvia;
			
		// 	for(int x = 0; x < automatoafd.getNumeroEstados(); x++){
		// 		cout << "ESTADOS: " << automatoafd.getEstado(x) << endl;
		// 		//estadosEnvia = automatoafd.getEstado(x);
		// 		// for(int y = 0; y < estadosEnvia.length(); y++){
		// 		// 	cout << "ESTADOS 2: " << estadosEnvia[y] << endl;
		// 		// }	
		// 		//cout << "ESTADOS 2: " << automatoafd.getEstado(x).length() << endl;
		// 	}

		// };
		
		// void automatoAFD(Automato automato){
		// 	vector<string> std;
		// 	for(int x = 0; x < automato.getNumeroEstados(); x++){
		// 		cout << "ESTADOS: " << automato.getEstado(x) << endl;
		// 		std.push_back(automato.getEstado(x+1));
		// 		gerandoAFD(automato, std);
		// 		std.clear();
		// 	}
		// };


		// void renomear(Automato automato){

		// };

		void imprimirAutomato(Automato automato, string dados){
			vector<Transicao> transicoes = automato.getTransicoes();
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();
			
			string armazena;
			cout << endl << "----------------------------------------------------------------------" << endl;
			cout << " ESTADOS" ;
			for (int x = 0; x < automato.getTamanhoAlfabeto()-1; x++){
				cout << "                 |    " << dados[x];
			}
			cout << endl << "----------------------------------------------------------------------" << endl;
			for (int x = 0; x < automato.getNumeroEstados(); x++) {
				if(x == 0)
					cout << " ->" << automato.getEstado(x) << "          |";
				else
					cout << "  " << automato.getEstado(x) << "   |";
				cout << endl << "----------------------------------------------------------------------" << endl;

				for (int  j = 0; j < automato.getTamanhoAlfabeto()-1; j++) {
					for (int k = 0; k <  transicaoafd.size(); k++) {
						if(automato.getEstado(x) == transicaoafd[k].getOrigem()){
	                        if(dados[j] == transicaoafd[k].getSimbolo()){
	                        	//cout << transicaoafd[k].getDestino() << " | ";
	                        }
						}
					}
				}
			}
			cout << endl;
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