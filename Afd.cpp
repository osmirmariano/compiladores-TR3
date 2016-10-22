#ifndef AFD_H
#define AFD_H

#include <iostream>

using namespace std;

class Afd{
	public:
		Afd(){
			void mostrarEstruturaAutomato(Automato automato, vector<string> conversao);
		};
		~Afd();

		Automato base(vector<string> conversao) {
			Automato automato;
			cout << " ALFABETO: " << automato.getAlfabeto() << endl;
			string estados, alfabetoAfd;
			vector<string> afd;
			automato.setAlfabeto(automato.getAlfabeto());
			for(int x = 0; x < conversao.size(); x++){
				estados += conversao[x];
			}
			afd.push_back(estados);
			automato.setEstados(afd);
			cout << " TAM: " << automato.getNumeroEstados() << endl;
			for(int x = 0; x < automato.getNumeroEstados(); x++){
				cout << " ESTADOS: " << automato.getEstado(x) << endl;
			}
			automato.setEstadoInicial(afd[0]);
			cout << " ESTADO INICIAL: " << automato.getEstadoInicial() << endl;

			/*for(int x = 0; x < automato.getTamanhoAlfabeto()-1; x++){
				alfabetoAfd += automato.getAlfabeto();
			}
			cout << " ALF: " << alfabetoAfd << endl;
			automato.setAlfabeto(alfabetoAfd);
			cout << " ALFABETO: " << automato.getAlfabeto() << endl;*/
			/*automato.setEstado("q1");
			automato.setTransicao("q0", "q1", simbolo);
			automato.setEstadoInicial("q0");
			automato.setEstadoFinal("q1");*/
			return automato;
		};

		void mostrarEstruturaAutomato(Automato automato, vector<string> conversao){
			base(conversao);
			cout << " TAMANHO ALFABETO: " << automato.getTamanhoAlfabeto() << endl;
		};
};
#endif // AFD_H