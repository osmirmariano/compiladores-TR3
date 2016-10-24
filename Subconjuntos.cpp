#include <iostream>
#include <vector>
#include "Automato.cpp"
#include "Transicao.cpp"
#include "Transicaoafd.cpp"
#include "Thompson.cpp"
using namespace std;

class Subconjuntos{
	public:
		vector<string> recebeu;
	public:
		Subconjuntos(){
			void mostrarEstruturaAutomato(Automato automato);
			vector<string> fechosE(vector<string> estadoAtual);
			vector<string> fechoEOficial(Automato automato, string estadoAtual);
			void imprimirFechos (Automato automato, string estadoAtual);
		};
		~Subconjuntos();

		vector<string> fechosE(Automato automato, string estadoAtual){
			vector<string> armazena;
            vector<Transicao> transicoes = automato.getTransicoes();
            armazena.clear();
            for(int z = 0; z < transicoes.size(); z++){
	        	if(transicoes[z].getSimbolo() == '&' ){
	        		if(transicoes[z].getOrigem() == estadoAtual){
		        		armazena.push_back(transicoes[z].getDestino());
		           	}
	           	}
	        }
	        return armazena;
		};


		vector<string> fechoEOficial(Automato automato, string estadoAtual){
			vector<string> fechos;
			vector<string> teste;
			vector<Transicao> transicoes = automato.getTransicoes();
			vector<string> recebe = fechosE(automato, estadoAtual);
			fechos.push_back(estadoAtual);

			for(int x = 0; x < recebe.size(); x++){
				fechos.push_back(recebe[x]);
			}
			for(int x = 0; x < recebe.size(); x++){
				teste = fechosE(automato, recebe[x]);
				for(int y = 0; y < teste.size(); y++){
					fechos.push_back(teste[y]);
					vector<string> util = fechosE(automato, teste[y]);
					for(int z = 0; z < util.size(); z++){
						fechos.push_back(util[z]);
					}
				}
			}
			return fechos;
		};

		void imprimirFechos (Automato automato, string estadoAtual){
			string estado;
			estado = estadoAtual;
			vector<string> resultado = fechoEOficial(automato, estadoAtual);
			int flag = 0, x = 0;
			//Remover elementos repetidos
	        int tamanho =  resultado.size();
	        for(int x = 0; x < tamanho; x++){
	        	for(int y = x+1; y < tamanho; y++){
	        		if(resultado[x] == resultado[y]){
	        			int b = x;
	        			while(b < tamanho){
	        				resultado[b] = resultado[b+1];
	        				b++;
	        			}
	        			tamanho--;
	        			x = x-1;
	        			y = y-1;
	        		}
	        	}
	        }
	        cout << " FECHOS-E (" << estado << "): ";
	        cout << "{";
            for(int x = 0; x < tamanho; x++){
            	cout << resultado[x];
            	if(flag < tamanho-1){
            		cout << ",";
            		flag++;
            	}
            }
            cout << "}" << endl;
		};

		void mostrarEstruturaAutomato(Automato automato){
            vector<Transicao> transicoes = automato.getTransicoes();
            vector<string> fechos;
            cout << " \t AUTOMATO COM MOVIMENTO VAZIO" << endl;
			cout << " ALFABETO: " << automato.getAlfabeto() << endl;
			cout << " TAMANHO ALFABETO: " << automato.getTamanhoAlfabeto() << endl;
			cout << " ESTADO INICIAL: " << automato.getEstadoInicial() << endl;
			cout << " ESTADO FINAL: " << automato.getEstadoFinal() << endl;
			cout << " ESTADOS: ";
			for(int x = 0; x < automato.getNumeroEstados(); x++){
                cout << automato.getEstado(x) << " ";
			}
			cout << endl;
            cout << " QUANT ESTADOS: " << automato.getNumeroEstados() << endl;
            cout << " QUANT TRANSIÇÕES: " << automato.getNumeroTransicoes() << endl;
            cout << "\t TRANSIÇÕES: " << endl;
			for(int x = 0; x < transicoes.size(); x++){
                cout << " TRANSIÇÕES: " << transicoes[x].getOrigem() << " --> " << transicoes[x].getDestino() << endl;
			}
			cout << "------------------------------------------------------------" << endl;
		};

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

		vector<Transicaoafd> uneTransicoes(vector<Transicaoafd> transicoes1, vector<Transicaoafd> transicoes2) {
			vector<Transicaoafd> transicoes;
			for (int i = 0; i < transicoes1.size(); i++){
				transicoes.push_back(transicoes1[i]);
			}
			for (int i = 0; i < transicoes2.size(); i++){
				transicoes.push_back(transicoes2[i]);
			}
			return transicoes;
		};
		// Automato baseAFD(Automato automato, vector<string> conversao) {
		// 	string estados, recebe, alfabetoAfd;
		// 	vector<string> afd;
		// 	vector<Transicao> transicoes = automato.getTransicoes();
		// 	//Para Alfabeto
		// 	cout << " \t AUTOMATO FINITO DETERMINISTICO" << endl;
		// 	recebe = automato.getAlfabeto();
		// 	for(int x = 0; x < recebe.length()-1; x++){
		// 		alfabetoAfd += recebe[x];
		// 	}
		// 	automato.setAlfabeto(alfabetoAfd);
		// 	cout << " ALFABETO: " << automato.getAlfabeto() << endl;
		// 	cout << " TAMANHO ALFABETO: " << automato.getTamanhoAlfabeto() << endl;

		// 	for(int x = 0; x < conversao.size(); x++){
		// 		estados += conversao[x];
		// 	}
		// 	afd.push_back(estados);
		// 	automato.setEstados(afd);

		// 	//Para Estado Inicial
		// 	automato.setEstadoInicial(afd[0]);
		// 	cout << " ESTADO INICIAL: " << automato.getEstadoInicial() << endl;

		// 	//Para Transição
		// 	string dados = automato.getAlfabeto();
		// 	for(int x = 0; x < automato.getTamanhoAlfabeto()-1; x++){
		// 		for(int y = 0; y < conversao.size(); y++){
		// 			for(int z = 0; z < transicoes.size(); z++){
		// 				if(conversao[y] == transicoes[z].getOrigem()){
		// 					if(transicoes[z].getSimbolo() == dados[x]){
		// 						estados += transicoes[z].getDestino();
		// 						cout << " TRANSIÇÕES: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl;
		// 					}
		// 				}
		// 			}
		// 		}
		// 		//cout << "ESTADOS: " << estados << endl;
		// 		afd.push_back(estados);
		// 		automato.setEstados(afd);
		// 		//uneEstados(afd);
		// 		//automato.setEstados(uneEstados(automato.getEstados()));
		// 		afd.clear();
		// 		estados.clear();
		// 	}
		// 	return automato;
		// };

		Automato mostrarEstruturaAutomato(Automato automato, vector<string> conversao){
			vector<string> afdFinal;
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
								for(int a = 0; a < fechoEOficial(automato, transicoes[z].getDestino()).size(); a++){
									recebeu = fechoEOficial(automato, transicoes[z].getDestino());
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
								ajuda = dados[x];
								op2 = estados;
								automato.setTransicaoafd(op1, op2, ajuda);
								cout << "SIMBOLO: " << dados[x] << endl;
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
			//automato.adicionaTransicoesafd(automato.getTransicoesafd());
							
			cout << "TAMANHO: " << transicaoafd.size() << endl;
			for(int b = 0; b < transicaoafd.size(); b++){
                cout << " TRANSIÇÕES: " << transicaoafd[b].getOrigem() << " --> " << transicaoafd[b].getDestino() << endl;
			}

			cout << "QUANT ESTADOS: "  << automato.getNumeroEstados() << endl;
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << "NOVOS ESTADOS: " << automato.getEstado(x) << endl;
				for(int y = x+1; y < automato.getNumeroEstados(); y++){
					if(automato.getEstado(x) != automato.getEstado(y)){
						automato.setEstados(uniaoEstados);
					}
					else{
						cout << "OI OSMIR MARIANO" << endl;
						break;
					}
				}
			}
			cout << endl << endl;
			imprimirAutomato(automato, dados);
			return automato;
		};

		void automatoAFD(Automato automato, vector<string> itensEstados){
			// if(verificarRepetidos(automato) == true){
			// 	for(int x = 0; x < automato.getNumeroEstados(); x++){
			// 		mostrarEstruturaAutomato(automato, automato.getEstado(x))
			// 	}
			// }
		};

		// bool verificarRepetidos(Automato automato){
		// 	cout << "TMA: " <<  automato.getNumeroEstados() << endl;
		// 	for(int x = 0; x < automato.getNumeroEstados(); x++){
		// 		for(int y = x+1; y < automato.getNumeroEstados(); y++){
		// 			cout << "ESTADOS: " << automato.getEstado(x) << endl;
		// 			if(automato.getEstado(x) != automato.getEstado(y)){
		// 				return true;
		// 			}
		// 			else
		// 				return false;
		// 		}
		// 	}
		// }

		void renomear(Automato automato){

		};

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
                        /*armazena = dados;
                        if(armazena[j] == transicaoafd[k].getSimbolo()){
                        	cout << transicaoafd[k].getDestino();
                        }*/
					}
				}
			}
			cout << endl;
		};
};
