#ifndef SUBCONJUNTOS_H
#define SUBCONJUNTOS_H

#include <iostream>
#include <vector>
#include <sstream>
#include "Automato.cpp"
#include "Transicao.cpp"
#include "Transicaoafd.cpp"
#include "Thompson.cpp"
using namespace std;

class Subconjuntos{
	public:
		Subconjuntos(){
			void mostrarEstruturaAutomato(Automato automato);
			vector<string> fechosE(Automato automato, string estadoAtual);
			vector<string> fechoEOficial(Automato automato, string estadoAtual);
			void imprimirFechos (Automato automato, string estadoAtual);
			Automato renomearEstados(Automato automato);
		};
		~Subconjuntos();


		// Automato renomearEstados(Automato automato){
		// 	stringstream conversao;
  //           vector<string> nomeNovo;
  //           int tamanho = automato.getNumeroEstados();
		// 	for(int x = 0; x < tamanho; x++){
		// 		conversao << x;
  //               nomeNovo.push_back(conversao.str());
		// 		automato.setEstados(nomeNovo);
  //              	conversao.str("");
		// 	}
		// 	return automato;
		// };


		Automato renomearEstados(Automato automato){
			stringstream conversao;
            vector<string> nomeNovo;
            string anterior, novo;
            int tamanho = automato.getNumeroEstados();
			for(int x = 0; x < tamanho; x++){
				anterior = automato.getEstado(x);
				conversao << x;
                novo = conversao.str();
				automato.alteraEstado(anterior, novo);
               	conversao.str("");
			}
			return automato;
		};
		
		// Automato renomeiaConcatenacaoB(Automato automato, string estadoFinal) {
		// 	string final = "";
		// 	int contador;
		// 	for (int i = 1; i < estadoFinal.size(); i++){
		// 		final.push_back(estadoFinal[i]);
		// 	}
		// 	contador = stoi(final);
		// 	contador++;
		// 	string novo, anterior;
		// 	for (int i = 0; i < automato.getNumeroEstados(); i++, contador++) {
		// 		anterior = automato.getEstado(i);
		// 		novo = "q" + to_string(contador);
		// 		automato.alteraEstado(anterior, novo);
		// 	}

		// 	return automato;
		// };

		/*-----------------------------FUNÇÃO FECHOSE---------------------------------*/
		vector<string> fechosE(Automato automato, string estadoAtual){
			//automato = renomearEstados(automato);
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

		/*-----------------------------FUNÇÃO FECHOSE OFICIAL----------------------------*/
		vector<string> fechoEOficial(Automato automato, string estadoAtual){
			//automato = renomearEstados(automato);
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

		
		/*---------------------------FUNÇÃO PARA IMPRIMIR FECHO E ------------------------*/
		void imprimirFechos (Automato automato, string estadoAtual){
			//automato = renomearEstados(automato);
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
	        			x--;
	        			y--;
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
			//automato = renomearEstados(automato);
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
                cout << " " << transicoes[x].getSimbolo() << " TRANSIÇÕES: " << transicoes[x].getOrigem() << " --> " << transicoes[x].getDestino() << endl;
			}
			cout << "------------------------------------------------------------" << endl;
		};
};

#endif // SUBCONJUNTOS_H