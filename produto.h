#ifndef PRODUTO_H
#define PRODUTO_H
#include<string.h>
#include<iostream>


using namespace std;

typedef struct  sFornecedor{
	string nome_fornecedor;
	string nome_representante;
}Fornecedor;

class Produto{
	
	public:
		Produto();
		Produto(int, string, double, Fornecedor&);
		//Produto(Produto&);
		~Produto();	
		
		//Gets	
		int get_cod_produto();
		string get_descricao();
		double get_valor();
		int get_id();
		
		//Set
		void set_cod_produto(int);
		void set_descricao(string);
		void set_valor(double);
		void set_id(int);
	
		//Váriavel
		Fornecedor fornecedor;
		
		int dia, mes, ano;
	

	private:
		int cod_produto;
		string descricao;
		double valor;
		int id;
};
#endif




