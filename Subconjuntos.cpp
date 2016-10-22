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

		void conversaoAFNE_AFD(Automato automato, vector<string> conversao){
			cout << " q0: ";
			for(int x = 0; x < conversao.size(); x++){
            	cout << " " << conversao[x];
            }
		};


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
		
};
