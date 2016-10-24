#ifndef TRANSICAOAFD_H
#define TRANSICAOAFD_H

#include <string>
#include <vector>

using namespace std;


class Transicaoafd{
	private:
		string origem;
		string destino;
		char simbolo;

	public:
		//CONSTRUTOR
		Transicaoafd(){
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

#endif // TRANSICAOAFD_H