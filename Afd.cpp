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
			return estados;
		};

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
			vector<string> afdFinal;
			vector<string> afd;
			string estados, recebe, alfabetoAfd;
			vector<Transicao> transicoes = automato.getTransicoes();
			baseAFD(automato, conversao);

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
			afd.push_back(estados);
			automato.setEstados(afd);
			//cout << "Estados: " << automato.getEstado() << endl;
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << " ESTADOS: " << automato.getEstado(x) << endl;
			}
			//automato.adicionaEstados(uneEstados(automato.getEstados()));
			automato.setEstados(automato.getEstados());
			//automato.setEstados(uneEstados(a.getEstados(), b.getEstados()));

			cout << "QUANT ESTADOS: "  << automato.getNumeroEstados() << endl;
			cout << endl << endl;
			estados.clear();
			afd.clear();
			
			for(int x = 0; x < conversao.size(); x++){
				for(int y = 0; y < transicoes.size(); y++){
					if(conversao[x] == transicoes[y].getOrigem()){
						for(int z = 0; z < alfabetoAfd.length(); z++){
							if(transicoes[y].getSimbolo() == alfabetoAfd[z]){
								estados += transicoes[y].getDestino();
								cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl; 
							}
						}
					}
				}
			}
			cout << "ESTADOSSSS: " << estados << endl;
			afd.push_back(estados);
			automato.setEstados(afd);
			//automato.adicionaEstados(automato.getEstados());
			automato.setEstados(automato.getEstados());
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << " ESTADOS FINAL: " << automato.getEstado(x) << endl;
			}

			/*afd.clear();
			estados.clear();
			//automato.setEstados(uneEstados(automato.getEstados()));

			for(int x = 0; x < conversao.size(); x++){
				for(int y = 0; y < transicoes.size(); y++){
					if(conversao[x] == transicoes[y].getOrigem()){
						if(transicoes[y].getSimbolo() == 'b'){
							estados += transicoes[y].getDestino();
							cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl; 
						}
					}
				}
				cout << "ESTADOSSSS: " << estados << endl;
				afd.push_back(estados);
				automato.setEstados(afd);
				//automato.adicionaEstados(automato.getEstados());
				automato.setEstados(automato.getEstados());
			}*/
			//automato.setEstados(uneEstados(automato.getEstados()));
			cout << endl << endl;
			/*------------------------------------GERANDO ESTADOS------------------------------*/
		};
		
};
#endif // AFD_H