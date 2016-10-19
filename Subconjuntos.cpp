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
			int valor = 0;
			vector<string> fechos;
            
            vector<Transicao> transicoes = automato.getTransicoes();
			string simbolo;
			string estadoAtual;
			simbolo = automato.getAlfabeto();
			//cout << "ESTADO ATUAL: " << retornaEstadoAtual(automato, valor) << endl;
			
            cout << "QUANTIDADE DE ESTADOS: " << automato.getNumeroEstados() << endl;
            cout << "QUANTIDADE DO ALFABETO: " << automato.getTamanhoAlfabeto() << endl;
            cout << "QUANTIDADE DE TRANSIÇÕES: " << transicoes.size() << endl;
            for(int x = 0; x < automato.getNumeroEstados(); x++){
            	estadoAtual = retornaEstadoAtual(automato, valor);
            	cout << "ESTADO ATUAL: " << estadoAtual << endl;
            	for(int y = 0; y < automato.getTamanhoAlfabeto(); x++){
            		if(simbolo[y] == '&'){
	            		for(int z = 0; z < transicoes.size(); z++){
	            			cout << " TRANSIÇÕES: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl;
	            		}
	            	}
            	}
            	valor++;
            }


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
