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
			//cout << " ESTADO ATAUL: " << estadoAtual  << endl;
			fechos.push_back(estadoAtual);

			for(int x = 0; x < recebe.size(); x++){
				fechos.push_back(recebe[x]);
			}
			//int valor = fechosE (automato, estadoAtual).size();
			for(int x = 0; x < recebe.size(); x++){
				teste = fechosE(automato, recebe[x]);

				for(int y = 0; y < teste.size(); y++){
					//cout << "TESTES: " << teste[y] << endl;
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
            cout << "}" << endl << endl;
            cout << "--------------------------------------------------------" << endl;	
		};


		/*---------------------------------------------------------------------------*/
		//Obtendo os fechosE
		vector<string> fechoE(Automato automato, string estadoAtual){
			vector<string> recebe = fechosE(automato, estadoAtual);
			for(int x = 0; x < recebe.size(); x++){
				cout << "RECEBE: " << recebe[x] << endl;
			}

			int valor = 0, flag = 0, x = 0;
			vector<string> fechos;
			string estado = estadoAtual;
            vector<Transicao> transicoes = automato.getTransicoes();

            fechos.push_back(estadoAtual);
			//Pegando as os estados com transições vazias
	        for(int z = 0; z < transicoes.size(); z++){
	        	cout << " ORIGEM: " << transicoes[z].getOrigem() << endl;
	        	cout << " SIMBOLO: " << transicoes[z].getSimbolo() << endl;
	        	cout << " ESTADO ATUAL ANTES: " << estadoAtual << endl;
	        	cout << " TRANSIÇÕES FORA: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl;
	        	if(transicoes[z].getOrigem() == estadoAtual){
	        		if(transicoes[z].getSimbolo() == '&' ){
		        		cout << " TRANSIÇÕES: " << transicoes[z].getOrigem() << " --> " << transicoes[z].getDestino() << endl;
		        		fechos.push_back(transicoes[z].getDestino());
		        		//cout << "TAMANHO: " << fechos.size() << endl;
			           	estadoAtual = fechos[x];
			           	cout << " ESTADO ATUAL: " << estadoAtual << endl;
			           	cout << " ESTADO FECHO: " << fechos[x] << endl;
			           	cout << " DESTINO: " << transicoes[z].getDestino() << endl << endl;
			           	//}
		        		if(fechos[x] != transicoes[z].getOrigem()){
		        			estadoAtual = transicoes[x+1].getOrigem();
		        			//cout << "NOVO ATUAL: " << estadoAtual << endl;
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
	        cout << " FECHOS-E (" << estado << "): ";
	        cout << "{";
            for(int x = 0; x < tamanho; x++){
            	cout << fechos[x];
            	if(flag < tamanho-1){
            		cout << ",";
            		flag++;
            	}
            }
            cout << "}" << endl << endl;
            cout << "--------------------------------------------------------" << endl;
			return fechos;
		};
};
