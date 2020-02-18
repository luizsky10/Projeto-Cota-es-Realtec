#include "produto.h"
#include<iostream>
#include<string>
	
	//Construtor Padrão
	
	Produto::Produto(){
		cod_produto = 0;
		descricao = " ";
		valor =0;
		fornecedor.nome_fornecedor = " ";
		fornecedor.nome_representante = " ";
	}
	//Construtor Normal
	Produto::Produto(int cod, string descricao1, double valor1, Fornecedor &f1){
		cod_produto = cod;
		descricao = descricao1;
		valor = valor1;
		fornecedor.nome_fornecedor = f1.nome_fornecedor;
		fornecedor.nome_representante = f1.nome_representante;
	}

	// Destrutor
	Produto::~Produto(){}


	// Gets
	int Produto::get_cod_produto(){
		return cod_produto;
	}
	string Produto::get_descricao(){
		return descricao;
	}
	double Produto::get_valor(){
		return valor;
	}
	int Produto::get_id(){
		return id;
	}


	// Sets
		void Produto::set_cod_produto(int cdproduto){
			cod_produto = cdproduto;
		}
		void Produto::set_descricao(string desc){
			descricao = desc;
		}
		void Produto::set_valor(double val){
			valor = val;
		}
		void Produto::set_id(int id1){
			id = id1;
		}







