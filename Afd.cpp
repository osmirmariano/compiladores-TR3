#ifndef AFD_H
#define AFD_H

#include <iostream>
#include <vector>
#include <sstream>
#include "Subconjuntos.cpp"
#include "Automato.cpp"
#include "Transicao.cpp"
#include "Transicaoafd.cpp"

using namespace std;

class Afd{
	public:
		Subconjuntos *subcon =  new Subconjuntos();
	public:
		Afd(){
			string converterString(vector <string> convert);
			bool verificaIguais(Automato automato, string estados);
			vector<string> gerando(Automato automato, vector<string> conversao, string simbolo);
			void gerandoEstadosAFD(Automato automato, vector<string> conversao);
			void automatoAfdFinal(Automato automato, vector<string> recebeEstados);
			vector<Transicaoafd> gerandoTransicoesAFD(Automato automato, vector<string> conversao, string op1, string op2, char simbolo, vector<string> recebeEstados);
			void imprimirAutomatoAFD(Automato automato, vector<string> conversao);
			void imprimirTransicoesAFD(Automato automato);
			void imprimirEstadosAFD(Automato automato);
		};
		~Afd();

		/*--------------------------FUNÇÃO PARA RENOMEAR ESTADOS PARA AFD-----------------------*/
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

		

		
		void excluirRepetidos(Automato automato){

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
				return receb;
			}
		};

		/*----------------------------FUNÇÃO VERIFICAR SE TEM REPETIDOS------------------------*/
		bool verificaIguais(Automato automato, string estados){
			for(int y = 0; y < automato.getNumeroEstados(); y++){
				if(automato.getEstado(y) != estados)
					return true;
				else
					return false;
			}
		};

		/*----------------------------FUNÇÃO PARA TRANSFORMAR EM STRING------------------------*/
		string converterString(vector <string> convert){
			string novaString;
			for(int x = 0; x < convert.size(); x++){
				novaString += convert[x];
			}
			return novaString;
		};

		/*----------------------------FUNÇÃO VERIFICAR SE TEM REPETIDOS------------------------*/
		bool verificaIguais1(vector<string> estadosAfd, string estados){
			for(int y = 0; y < estadosAfd.size(); y++){
				if(estadosAfd[y] != estados)
					return true;
				else
					return false;
			}
			return true;
		};


		vector<string> afd(Automato automato, vector<string> conversao){
			vector<string> estadosAfd;
			vector<string> estadosGerados;
			string estado, recebeSimbolo;
			string simbolo = automato.getAlfabeto();

			estado = converterString(conversao);
			cout << " " << estado << endl;
			if(verificaIguais1(estadosAfd, estado)  == true){
				estadosAfd.push_back(estado);
			}
			estado.clear();


			for(int x = 0; x < simbolo.length()-1; x++){
				recebeSimbolo = simbolo[x];
				estadosGerados = gerando(automato, conversao, recebeSimbolo);

				estado = converterString(estadosGerados);
				if(verificaIguais1(estadosAfd, estado)  == true){
					estadosAfd.push_back(estado);
					estado.clear();
					gerandoEstadosAFD(automato, estadosGerados);
				}
			}
			return estadosAfd;
		};

		
		Automato gerandoEstadosAFD(Automato automato, vector<string> conversao){
			vector<string> recebendo;
			vector<string> novo;
			recebendo = afd(automato, conversao);
			for(int x = 0; x < recebendo.size(); x++){
				if(recebendo[x] != ""){
					novo.push_back(recebendo[x]);
				}
			}
			for(int x = 0; x < novo.size(); x++){
				cout << "ESTADOS: " << novo[x] << endl;
			}
			return automato;
		};

		/*----------------------------FUNÇÃO PARA CRIAR OS ESTADOS---------------------------*/
		Automato gerandoEstadosAsFD(Automato automato, vector<string> conversao){
			vector<string> recebeEstados;
			vector<string> uniaoEstados;
			string simbolo = automato.getAlfabeto();
			string recebeSimbolo, estados, op1, op2;
			
			for(int x = 0; x < simbolo.length()-1; x++){
				estados = converterString(conversao);
				if (verificaIguais(automato, estados) == false){
					uniaoEstados.push_back(estados);
					automato.setEstados(uniaoEstados);
					op1 = estados;
				}
				estados.clear();

				recebeSimbolo = simbolo[x];
				recebeEstados = gerando(automato, conversao, recebeSimbolo);
				estados = converterString(recebeEstados);

				if (verificaIguais(automato, estados) == true){
					uniaoEstados.push_back(estados);
					automato.setEstados(uniaoEstados);
					op2 = estados;
					char simb = simbolo[x];
					gerandoTransicoesAFD(automato, conversao, op1, op2, simb, recebeEstados);	
					gerandoEstadosAFD(automato, recebeEstados);
					//automatoAfdFinal(automato, recebeEstados);
				}
			}
			return automato;
		};

		void automatoAfdFinal(Automato automato, vector<string> recebeEstados){
			gerandoEstadosAFD(automato, recebeEstados);
		};

		vector<Transicaoafd> gerandoTransicoesAFD(Automato automato, vector<string> conversao, string op1, string op2, char simbolo, vector<string> recebeEstados){
			vector<Transicao> transicoes = automato.getTransicoes();
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();

			int cont = 0;
			for(int y = 0; y < conversao.size(); y++){
				for(int a = 0; a < transicoes.size(); a++){
					if(conversao[y] == transicoes[a].getOrigem()){
						if(transicoes[a].getSimbolo() == simbolo){
							if(cont < 1)
								automato.setTransicaoafd(op1, op2, simbolo);
							cont++;
						}
					}
				}
			}
			///imprimirEstadosAFD(automato);

			imprimirTransicoesAFD(automato);			
			return transicaoafd;
		};

		void imprimirTransicoesAFD(Automato automato){
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();			
			for(int b = 0; b < transicaoafd.size(); b++){
                cout << transicaoafd[b].getSimbolo() << " - TRANSIÇÕES: " << transicaoafd[b].getOrigem() << " --> " << transicaoafd[b].getDestino() << endl;
			}
		};

		void imprimirEstadosAFD(Automato automato){			
			for(int b = 0; b < automato.getNumeroEstados(); b++){
                cout << " ESTADOS: " << automato.getEstado(b)  << endl;
			}
		};


		void imprimirAutomatoAFD(Automato automato, vector<string> conversao){
			vector<Transicao> transicoes = automato.getTransicoes();
			vector<Transicaoafd> transicaoafd = automato.getTransicoesafd();
			imprimirTransicoesAFD(automato);
			Automato automatoAFD;
			automatoAFD = gerandoEstadosAFD(automato, conversao);
			//automatoAFD = renomearEstados(automato);
			string dados = automatoAFD.getAlfabeto();
			string armazena;
			cout << endl << "----------------------------------------------------------------------" << endl;
			cout << "     ESTADOS" ;
			for (int x = 0; x < automatoAFD.getTamanhoAlfabeto()-1; x++){
				cout << "     |    " << dados[x];
			}
			cout << endl << "----------------------------------------------------------------------" << endl;
			for (int x = 0; x < automatoAFD.getNumeroEstados(); x++) {
				if(x == 0)
					cout << "       ->" << automatoAFD.getEstado(x) << "       |";
				else
					cout << "         " << automatoAFD.getEstado(x) << "       |";
				cout << endl << "----------------------------------------------------------------------" << endl;

				for (int  j = 0; j < automatoAFD.getTamanhoAlfabeto()-1; j++) {
					for (int k = 0; k <  transicaoafd.size(); k++) {
						if(automatoAFD.getEstado(x) == transicaoafd[k].getOrigem()){
	                        if(dados[j] == transicaoafd[k].getSimbolo()){
	                        	cout << transicaoafd[k].getDestino() << " | ";
	                        	imprimirTransicoesAFD(automatoAFD);
	                        }
						}
					}
				}
			}
			cout << endl;
		};
	
};
#endif // AFD_H