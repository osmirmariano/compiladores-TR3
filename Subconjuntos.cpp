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
			vector<string> fechosE(Automato automato, string estadoAtual);
			vector<string> fechoEOficial(Automato automato, string estadoAtual);
			void imprimirFechos (Automato automato, string estadoAtual);
			//Automato renomearEstados(Automato automato);
		};
		~Subconjuntos();

		/*-----------------------------FUNÇÃO PARA RENOMEAR ESTADOS--------------------------*/
		/*Automato renomearEstados(Automato automato){
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
		};*/
		
		/*-----------------------------FUNÇÃO FECHOSE----------------------------------*/
	    vector<string> fechosE(Automato automato, string estadoAtual){
			vector<string> armazena;
            vector<Transicao> transicoes = automato.getTransicoes();
            armazena.clear();

            for(int z = 0; z < transicoes.size(); z++){
	        	if(transicoes[z].getOrigem() == estadoAtual){
	        		if(transicoes[z].getSimbolo() == '&' ){
		        		armazena.push_back(transicoes[z].getDestino());
		           	}
	           	}
	        }

	        return armazena;
		};

		/*-----------------------------FUNÇÃO FECHOSE OFICIAL----------------------------*/
		vector<string> fechoEOficial(Automato automato, string estadoAtual){
			vector<string> recebe;
			vector<string> recebes;
			recebe = fechosE(automato, estadoAtual);
			for(int x = 0; x < fechosE(automato, estadoAtual).size(); x++){
				recebes.push_back(recebe[x]);
			}

			for(int x = 0; x < recebes.size(); x++){
				string enviar = recebes[x];
				fechosE(automato, enviar);
				vector<string> alterar;
				alterar = fechosE(automato, enviar);
				for(int y = 0; y < alterar.size(); y++){
					recebes.push_back(alterar[y]);
				}
			}
			recebes.push_back(estadoAtual);
			return recebes;
		};

		
		
		/*---------------------------FUNÇÃO PARA IMPRIMIR FECHO E ------------------------*/
		void imprimirFechos (Automato automato, string estadoAtual){
			string estado;
			estado = estadoAtual;
			vector<string> resultado = fechoEOficial(automato, estadoAtual);
			int flag = 0, x = 0;
	        int tamanho =  resultado.size();
	        cout << " FECHOS-E (" << estado << ") = ";
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
};

#endif // SUBCONJUNTOS_H