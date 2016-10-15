#include <iostream>
#include <vector>
#include "Automato.cpp"
#include "Transicao.cpp"
#include "Thompson.cpp"
using namespace std;

class Subconjuntos{
	public:
		Subconjuntos(){
			//vector<string> fechoE(vector<string> estadoAtual);
			void mostrarEstruturaAutomato(Automato automato);
			void mostrar();
		};
		~Subconjuntos();

		//Obtendo os fechosE
		/*vector<string> fechoE(vector<string> estadoAtual){
            int valor = 0;
            Automato automato;
            vector<Transicao> transicoes = automato.getTransicoes();
			vector<string> fechos;
			string simbolo
			simbolo = automato.getAlfabeto();
            fechos = estadoAtual;
            //cout << "TESTE DE ESTADOS: " << automato.getEstados();

            for(int x = 0; x < automato.getTamanhoAlfabeto; x++){
                fechoE[valor] = transicoes[valor].getOrigem();
                for(int y = 0; y < transicoes.size(); y++){
                    if(simbolo[x] == "&"){
                        if(transicoes[y] )
                    }
                }
                valor++;

            }
			//vector<string> estadoAtual;
			//if()
			return fechos;
		};*/

		void mostrarEstruturaAutomato(Automato automato){
            vector<Transicao> transicoes = automato.getTransicoes();
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
			for(int x = 0; x < transicoes.size(); x++){
                cout << " TRANSIÇÕES: " << transicoes[x].getOrigem() << " --> " << transicoes[x].getDestino() << endl;
			}
			cout << endl;
            string teste = automato.getAlfabeto();
			for(int x = 0; x < automato.getNumeroTransicoes(); x++){
				for(int y = 0; y < transicoes.size(); y++) {
                    if(teste[x] == '&' ){
                        cout << " TRANSIÇÕES: " << transicoes[y].getOrigem() << " --> " << transicoes[y].getDestino() << endl;
                    }
				}
			}
		}
};
