#ifndef AFD_H
#define AFD_H

#include <iostream>

using namespace std;

class Afd{
	public:
		Afd(){
			void mostrarEstruturaAutomato(Automato automato, vector<string> conversao);
		};
		~Afd();

		vector<string> uneEstados(vector<string> estados1) {
			vector<string> estados;
			for (int i = 0; i < estados1.size(); i++){
				estados.push_back(estados1[i]);
			}
			for(int x = 0; x < estados.size(); x++){
				cout << "Estados: " << estados[x] << endl;
			}
			return estados;
		};

		Automato baseAFD(Automato automato, vector<string> conversao) {
			string estados, recebe, alfabetoAfd;
			vector<string> afd;
			vector<Transicao> transicoes = automato.getTransicoes();
			//Para Alfabeto
			cout << " \t AUTOMATO FINITO DETERMINISTICO" << endl;
			recebe = automato.getAlfabeto();
			for(int x = 0; x < recebe.length()-1; x++){
				alfabetoAfd += recebe[x];
			}
			automato.setAlfabeto(alfabetoAfd);
			cout << " ALFABETO: " << automato.getAlfabeto() << endl;
			cout << " TAMANHO ALFABETO: " << automato.getTamanhoAlfabeto() << endl;

			for(int x = 0; x < conversao.size(); x++){
				estados += conversao[x];
			}
			afd.push_back(estados);
			automato.setEstados(afd);

			//Para Estado Inicial
			automato.setEstadoInicial(afd[0]);
			cout << " ESTADO INICIAL: " << automato.getEstadoInicial() << endl;

			//Para Transição
			string dados = automato.getAlfabeto();
			for(int x = 0; x < automato.getTamanhoAlfabeto()-1; x++){
				for(int y = 0; y < conversao.size(); y++){
					for(int z = 0; z < transicoes.size(); z++){
						if(conversao[y] == transicoes[z].getOrigem()){
							if(transicoes[z].getSimbolo() == dados[x]){
								estados += transicoes[z].getDestino();
								cout << " TRANSIÇÕES: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl; 
							}
						}
					}
				}
				//cout << "ESTADOS: " << estados << endl;
				afd.push_back(estados);
				automato.setEstados(afd);
				//uneEstados(afd);
				//automato.setEstados(uneEstados(automato.getEstados()));
				afd.clear();
				estados.clear();
			}
			return automato;
		};

		Automato mostrarEstruturaAutomato(Automato automato, vector<string> conversao){
			vector<string> afdFinal;
			vector<string> afd;
			vector<string> uniaoEstados;
			string estados, recebe, alfabetoAfd;
			vector<Transicao> transicoes = automato.getTransicoes();

			for(int x = 0; x < conversao.size(); x++){
				estados += conversao[x];
			}
			afd.push_back(estados);
			uniaoEstados.push_back(estados);

			cout << endl << endl;
			estados.clear();
			afd.clear();
			
			string dados = automato.getAlfabeto();
			for(int x = 0; x < automato.getTamanhoAlfabeto()-1; x++){
				for(int y = 0; y < conversao.size(); y++){
					for(int z = 0; z < transicoes.size(); z++){
						if(conversao[y] == transicoes[z].getOrigem()){
							if(transicoes[z].getSimbolo() == dados[x]){
								estados += transicoes[z].getDestino();
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
			cout << "QUANT ESTADOS: "  << automato.getNumeroEstados() << endl;
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << "NOVOS ESTADOS: " << automato.getEstado(x) << endl;
			}
			cout << endl << endl;
			imprimirAutomato(automato, dados);
			return automato;
		};

		void imprimirAutomato(Automato automato, string dados){
			cout << endl << "----------------------------------------------------------------------" << endl;
			cout << " ESTADOS" ;
			for (int x = 0; x < automato.getTamanhoAlfabeto()-1; x++){
				cout << "    |    " << dados[x];
			}
			cout << endl << "----------------------------------------------------------------------" << endl;
			for (int x = 0; x < automato.getNumeroEstados(); x++) {
				/*origem = automato.getEstado(x);
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
			cout << endl;*/
		};
		
};
#endif // AFD_H