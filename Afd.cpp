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

		Automato baseAFD(Automato automato, vector<string> conversao) {
			string estados, recebe, alfabetoAfd;
			vector<string> afd;
			vector<Transicao> transicoes = automato.getTransicoes();
			//Para Alfabeto
			recebe = automato.getAlfabeto();
			for(int x = 0; x < recebe.length()-1; x++){
				alfabetoAfd += recebe[x];
			}
			automato.setAlfabeto(alfabetoAfd);
			cout << " ALFABETO: " << automato.getAlfabeto() << endl;

			/*------------------------------------GERANDO ESTADOS------------------------------*/
			//Para Estados
			for(int x = 0; x < conversao.size(); x++){
				estados += conversao[x];
			}
			cout << "ESTADOS N LIMPOS: " << estados << endl;
			afd.push_back(estados);
			automato.setEstados(afd);
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << " ESTADOS: " << automato.getEstado(x) << endl;
			}
			cout << endl << endl;
			estados.clear();
			afd.clear();
			cout << "ESTADOS LIMPOS: " << estados << endl;
			for(int x = 0; x < conversao.size(); x++){
				for(int y = 0; y < transicoes.size(); y++){
					if(conversao[x] == transicoes[y].getOrigem()){
						if(transicoes[y].getSimbolo() == 'a'){
							estados += transicoes[y].getDestino();
							cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl; 
						}
						/*else{
							estados += transicoes[y].getDestino();
							//cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl; 
						}*/
					}
				}
				afd.push_back(estados);
				automato.setEstados(afd);
				afd.clear();
				estados.clear();
			}

			for(int x = 0; x < conversao.size(); x++){
				for(int y = 0; y < transicoes.size(); y++){
					if(conversao[x] == transicoes[y].getOrigem()){
						if(transicoes[y].getSimbolo() == 'b'){
							estados += transicoes[y].getDestino();
							cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl; 
						}
						/*else{
							estados += transicoes[y].getDestino();
							//cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl; 
						}*/
					}
				}
				afd.push_back(estados);
				automato.setEstados(afd);
				afd.clear();
				estados.clear();
			}
			
			/*------------------------------------GERANDO ESTADOS------------------------------*/


			//Para Estado Inicial
			//automato.setEstadoInicial(afd[0]);
			//cout << " ESTADO INICIAL: " << automato.getEstadoInicial() << endl;
			//Para Transição
			/*cout << "\t TRANSIÇÕES: " << endl;
			for(int x = 0; x < transicoes.size(); x++){
                //cout << " TRANSIÇÕES: " << transicoes[x].getOrigem() << " --> " << transicoes[x].getDestino() << endl;
                if(transicoes[x].getSimbolo() == 'a'){
					cout << " SIMBOLO: " << transicoes[x].getSimbolo() << endl;
                	cout << " TRANSIÇÕES: " << transicoes[x].getOrigem() << " --> " << transicoes[x].getDestino() << endl;

                }
                if(transicoes[x].getSimbolo() == 'b'){
					cout << "SIMBOLO: " << transicoes[x].getSimbolo() << endl;
                	cout << " TRANSIÇÕES: " << transicoes[x].getOrigem() << " --> " << transicoes[x].getDestino() << endl;
                }
			}*/
			return automato;
		};

		void mostrarEstruturaAutomato(Automato automato, vector<string> conversao){
			/*vector<string> afdFinal;
			vector<string> afd;
			string estados;
			vector<Transicao> transicoes = automato.getTransicoes();*/

			baseAFD(automato, conversao);

			/*//Para Estados
			for(int x = 0; x < conversao.size(); x++){
				estados += conversao[x];
			}
			afd.push_back(estados);
			automato.setEstados(afd);
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << " ESTADOS: " << automato.getEstado(x) << endl;
			}

			for(int x = 0; x < conversao.size(); x++){
				cout << "OI 1" << endl;
				for(int y = 0; y < transicoes.size(); y++){
					if(transicoes[y].getOrigem() == conversao[x]){
						cout << "OI 2" << endl;
						cout << "SIMBOLO: " << transicoes[x].getSimbolo() << endl;
                
						if(transicoes[y].getSimbolo() == 'a'){
							cout << "OI 3" << endl;
							cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl;
							afdFinal.push_back(transicoes[y].getDestino());
							estados += afdFinal[y];
						}
					}
				}
				afd.push_back(estados);
				automato.setEstados(afd);
			}
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << " ESTADOS: " << automato.getEstado(x) << endl;
			}*/
			
		};
			
};
#endif // AFD_H