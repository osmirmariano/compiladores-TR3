#ifndef CONVERSAOAFD_H
#define CONVERSAOAFD_H

#include <iostream>
#include <vector>
#include <sstream>
#include "Subconjuntos.cpp"
#include "Automato.cpp"
#include "Transicao.cpp"
#include "Transicaoafd.cpp"

using namespace std;

class ConversaoAFD{
	public:
		Subconjuntos *subcon =  new Subconjuntos();
	public:
		ConversaoAFD(){

		};

		/*--------------------------FUNÇÃO VERIFICAR CADA ELEMENTO OS ESTADOS------------------*/
		vector<string> gerando(Automato automato, vector<string> conversao, string simbolo){
			vector<string> recebeu;
			vector<string> receb;
			vector<Transicao> transicoes = automato.getTransicoes();
			int o = 0;
			receb.clear();
			//Fazer o teste para cada posição de conversão e com todos gerar um único estado
			for(int x = 0; x < simbolo.length(); x++){
				for(int y = 0; y < conversao.size(); y++){
					for(int z = 0; z < transicoes.size(); z++){
						if(conversao[y] == transicoes[z].getOrigem()){
							if(transicoes[z].getSimbolo() == simbolo[x]){
								for(int a = 0; a < subcon->fechoEOficial(automato, transicoes[z].getDestino()).size(); a++){
									recebeu = subcon->fechoEOficial(automato, transicoes[z].getDestino());
									receb.push_back(recebeu[o]);
									o++;
								}
								o = 0;
							}
						}
					}
				}
				for(int b = 0; b < receb.size(); b++){
					cout << "  " << receb[b];
				}
				return receb;
			}
		};
};

#endif // CONVERSAOAFD_H