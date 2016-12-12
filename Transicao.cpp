#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <string>
#include <vector>

using namespace std;

class Transicao{
	private:
		string origem;
		string destino;
		char simbolo;

	public:
		//CONSTRUTOR
		Transicao(){
			void setOrigem(string);
			void setDestino(string);
			void setSimbolo(char);
			string getOrigem();
			string getDestino();
			char getSimbolo();
		};

		/*-----------------------------FUNÇÃO SETORIGEM--------------------------------*/
		void setOrigem(string origem) {
			this->origem = origem;
		};

		/*-----------------------------FUNÇÃO SETDESTINO--------------------------------*/
		void setDestino(string destino) {
			this->destino = destino;
		};

		/*-----------------------------FUNÇÃO SETSIMBOLO--------------------------------*/
		void setSimbolo(char simbolo) {
			this->simbolo = simbolo;
		};

		/*-----------------------------FUNÇÃO GETORIGEM---------------------------------*/
		string getOrigem() {
			return origem;
		};

		/*-----------------------------FUNÇÃO GETDESTINO--------------------------------*/
		string getDestino() {
			return destino;
		};

		/*-----------------------------FUNÇÃO GETSIMBOLO--------------------------------*/
		char getSimbolo() {
			return simbolo;
		};
};

#endif // TRANSICAO_H