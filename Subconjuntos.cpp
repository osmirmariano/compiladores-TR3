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
		vector<string> fechoE(Automato automato, string estadoAtual){
			int valor = 0, flag = 0;
			vector<string> fechos;
			//fechos.clear();
			string estado = estadoAtual;
            vector<Transicao> transicoes = automato.getTransicoes();

	        int x = 0;
            fechos.push_back(estadoAtual);
			//Pegando as os estados com transições vazias
	        for(int z = 0; z < transicoes.size(); z++){
	        	cout << "ORIGEM: " << transicoes[z].getOrigem() << endl;
	        	cout << "SIMBOLO: " << transicoes[z].getSimbolo() << endl;
	        	cout << " TRANSIÇÕES: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl << endl;
		        			
	        	if(transicoes[z].getOrigem() == estadoAtual){
	        		if(transicoes[z].getSimbolo() == '&' ){
	        		//cout << "SIMBOLO: " << transicoes[z].getSimbolo() << endl;
	        			//if(transicoes[z].getOrigem() != estadoAtual){
		        			cout << " TRANSIÇÕES: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl;
		        			fechos.push_back(transicoes[z].getDestino());
		        			//cout << "TAMANHO: " << fechos.size() << endl;
			           		estadoAtual = fechos[x];
			           		cout << "ESTADO ATUAL: " << estadoAtual << endl;
			           		cout << "ESTADO FECHO: " << fechos[x] << endl;
			           		cout << "DESTINO: " << transicoes[z].getDestino() << endl;
			           	//}
		        		if(fechos[x] != transicoes[z].getOrigem()){
		        			estadoAtual = transicoes[x+1].getOrigem();
		        			cout << "NOVO ATUAL: " << estadoAtual << endl;
		        		}
		        		x++;

		           	}
	           	}	 
	        }
		           		

	        //Remover elementos repetidos
	        int tamanho =  fechos.size();
	        for(int x = 0; x < tamanho; x++){
	        	for(int y = x+1; y < tamanho; y++){
	        		if(fechos[x] == fechos[y]){
	        			int b = x;
	        			while(b < tamanho){
	        				fechos[b] = fechos[b+1];
	        				b++;
	        			}
	        			tamanho--;
	        			x = x-1;
	        			y = y-1;
	        		}
	        	}
	        }
	        cout << "FECHOS-E (" << estado << "): ";
	        cout << "{";
            for(int x = 0; x < tamanho; x++){
            	cout << fechos[x];
            	if(flag < tamanho-1){
            		cout << ",";
            		flag++;
            	}
            }
            cout << "}" << endl << endl;
			return fechos;
		};
};
