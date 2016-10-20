#include <iostream>
#include <vector>
#include "Automato.cpp"
#include "Transicao.cpp"
#include "Thompson.cpp"
using namespace std;

class Subconjuntos{
	public:
		Subconjuntos(){
			void mostrarEstruturaAutomato(Automato automato);
			vector<string> fechoE(vector<string> estadoAtual);
		};
		~Subconjuntos();



		void mostrarEstruturaAutomato(Automato automato){
            vector<Transicao> transicoes = automato.getTransicoes();
            vector<string> fechos;
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
			//fechoE(automato);
		};

		//FUNÇÃO PARA RETORNAR O ESTADO ATUAL PARA CALCULAR OS FECHOS E
		string retornaEstadoAtual(Automato automato, int valor){
			string estadoAtual;
			estadoAtual = automato.getEstado(valor);
			return estadoAtual;
		};

		//Obtendo os fechosE
		vector<string> fechoE(Automato automato/*, vector<string> estadoAtual*/){
			int valor = 0, a = 0;
			vector<string> fechos;
            vector<Transicao> transicoes = automato.getTransicoes();
			string simbolo, recebe1;
			string estadoAtual;
			simbolo = automato.getAlfabeto();

			estadoAtual = retornaEstadoAtual(automato, valor++);
            fechos.push_back(estadoAtual);
            cout << endl << "ESTADO ATUAL: " << estadoAtual << endl;
			

            //for(int y = 0; y < automato.getTamanhoAlfabeto(); y++){
            	//cout << " ALFABETO: " << simbolo[y] << endl;
	            //if(simbolo[y] == '&'){
            //int  y = 0;
	        for(int z = 0; z < transicoes.size(); z++){
	        	if(transicoes[z].getSimbolo() == '&'){
					fechos.push_back(transicoes[z].getDestino());
	           	}
	        }
	        for(int x = 0; x < fechos.size(); x++){
	        	cout << "FECHO Q0: " << fechos[x] << endl;
	        }
	            			//cout << endl << "TESTE: " << transicoes[z].getSimbolo() << endl;
		            		//cout << "simbolo: " << simbolo[y] << endl;
		            		//cout << " TRANSIÇÕES: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl;
						
						/*recebe1 += fechos[z+1];
						cout << "RECEBE: " << recebe1 << endl;
						if(fechos[z] != estadoAtual){
							estadoAtual = fechos[z-1];
							//y = 0;
							//z = 0;
						}*/
							// y++;
							// if(y == 3)
							// 	y = 0;
            	//}
            //}

            /*for(int x = 0; x < 10; x++){
            	cout << "FECHOS: " << fechos[x] << endl;
            }*/
            /*for(int x = 0; x < automato.getTamanhoAlfabeto(); x++){
            	//fechos.push_back(retornaEstadoAtual(automato, valor));
                if(simbolo[x] == '&'){
                	for(int y = 0; y < transicoes.size(); y++){
                		if(transicoes[y].getOrigem() == estadoAtual){
	                       cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl;
	                       fechos.push_back(transicoes[y].getDestino());
	                       cout << " FECHOS: " << fechos[y];
                		}
	                }
                }
                valor++;
            }
			*/

			return fechos;
		};
};
