#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <iostream>
#include <string>
#include <vector>
#include "Transicao.cpp"


using namespace std;

class Automato {
	private:
		string alfabeto;
		vector<string> estados;
		vector<Transicao> transicoes;
		string estadoInicial;
		string estadoFinal;

	public:
		//CONSTRUTOR
		Automato(){
			void setAlfabeto(string);
			void setAlfabeto(char);
			void setEstados(vector<string>);
			void setEstado(string);
			void setTransicoes(vector<Transicao>);
			void setTransicao(string, string, char);
			void setEstadoInicial(string);
			void setEstadoFinal(string);
			void alteraEstado(string, string);
			void adicionaEstados(vector<string>);
			void adicionaTransicoes(vector<Transicao>);
			string getAlfabeto();
			vector<string> getEstados();
			string getEstado(int);
			vector<Transicao> getTransicoes();
			string getEstadoInicial();
			string getEstadoFinal();
			int getNumeroEstados();
			int getNumeroTransicoes();
			int getTamanhoAlfabeto();
		};

		/*-----------------------------FUNÇÃO SETALFABETO--------------------------------*/
		void setAlfabeto(string alfabeto) {
			this->alfabeto = alfabeto;
		};

		/*-----------------------------FUNÇÃO SETALFABETO--------------------------------*/
		void setAlfabeto(char letra) {
			this->alfabeto.push_back(letra);
		};

		/*-----------------------------FUNÇÃO SETESTADOS---------------------------------*/
		void setEstados(vector<string> estados) {
			this->estados = estados;
		};

		/*-----------------------------FUNÇÃO SETESTADOS---------------------------------*/
		void setEstado(string estado) {
			estados.push_back(estado);
		};

		/*-----------------------------FUNÇÃO SETTRANSIÇÕES------------------------------*/
		void setTransicoes(vector<Transicao> transicoes) {
			this->transicoes = transicoes;
		};

		/*-----------------------------FUNÇÃO SETTRANSIÇÕES------------------------------*/
		void setTransicao(string origem, string destino, char simbolo) {
			Transicao transicao;
			transicao.setOrigem(origem);
			transicao.setDestino(destino);
			transicao.setSimbolo(simbolo);
			this->transicoes.push_back(transicao);
		};

		/*-----------------------------FUNÇÃO SETESTADO INICIAL--------------------------*/
		void setEstadoInicial(string estadoInicial) {
			this->estadoInicial = estadoInicial;
		};

		/*-----------------------------FUNÇÃO SETESTADO FINAL----------------------------*/
		void setEstadoFinal(string estadoFinal) {
			this->estadoFinal = estadoFinal;
		};

		/*-----------------------------FUNÇÃO ALTERAR ESTADOS----------------------------*/
		void alteraEstado(string antigo, string novo) {
			for (int i = 0; i < estados.size(); i++){
				if (estados[i] == antigo)
					estados[i] = novo;
			}
			for (int i = 0; i < transicoes.size(); i++) {
				if (transicoes[i].getOrigem() == antigo)
					transicoes[i].setOrigem(novo);
				if (transicoes[i].getDestino() == antigo)
					transicoes[i].setDestino(novo);
			}
			if (estadoInicial == antigo)
				estadoInicial = novo;
			if (estadoFinal == antigo)
				estadoFinal = novo;
		};

		/*-----------------------------FUNÇÃO ADICIONAR ESTADOS---------------------------*/
		void adicionaEstados(vector<string> estados) {
			for (int i = 0; i < estados.size(); i++)
				this->estados.push_back(estados[i]);
		};

		/*-----------------------------FUNÇÃO ADICIONAR TRANSIÇÕES------------------------*/
		void adicionaTransicoes(vector<Transicao> transicoes) {
			for (int i = 0; i < transicoes.size(); i++){
				this->transicoes.push_back(transicoes[i]);
			}
		};

		/*--------------------------------FUNÇÃO GETALFABETO------------------------------*/
		string getAlfabeto() {
			return alfabeto;
		};

		/*--------------------------------FUNÇÃO GETESTADOS-------------------------------*/
		vector<string> getEstados() {
			return estados;
		};

		/*--------------------------------FUNÇÃO GETESTADO--------------------------------*/
		string getEstado(int indice) {
			return estados[indice];
		};

		/*--------------------------------FUNÇÃO GETTRANSIÇÕES-----------------------------*/
		vector<Transicao> getTransicoes() {
			return transicoes;
		};

		/*--------------------------------FUNÇÃO GETESTADO INICAL--------------------------*/
		string getEstadoInicial() {
			return estadoInicial;
		};

		/*--------------------------------FUNÇÃO GETESTADO FINAL---------------------------*/
		string getEstadoFinal() {
			return estadoFinal;
		};

		/*--------------------------------FUNÇÃO GETNUMERO DE ESTADOS-----------------------*/
		int getNumeroEstados() {
			return estados.size();
		};

		/*--------------------------------FUNÇÃO GETUMERO DE TRANSIÇÕES---------------------*/
		int getNumeroTransicoes() {
			return transicoes.size();
		};

		/*--------------------------------FUNÇÃO GET TAMANHO ALFABETO-----------------------*/
		int getTamanhoAlfabeto() {
			return alfabeto.size();
		};
};

#endif // AUTOMATO_H