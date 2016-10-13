#include <iostream>
#include <vector>
#include "Automato.cpp"
#include "Transicao.cpp"
using namespace std;

class Subconjuntos{
	public:
		Subconjuntos(){
			vector<string> fechoE(vector<string> estadoAtual);
		};
		~Subconjuntos();

		//Obtendo os fechosE
		vector<string> fechoE(vector<string> estadoAtual){
            Automato automato;
            vector<Transicao> transicoes = automato.getTransicoes();
			vector<string> fechos;
			string simbolo
			simbolo = automato.getAlfabeto();
            fechos = estadoAtual;
            //cout << "TESTE DE ESTADOS: " << automato.getEstados();

            for(int x = 0; x < automato.getTamanhoAlfabeto; x++){
                for(int y = 0; y < transicoes.size(); y++){
                    if(simbolo[x] == "&"){
                        if(transicoes[y] )
                    }
                }

            }
			//vector<string> estadoAtual;
			//if()
			return fechos;
		};

};
