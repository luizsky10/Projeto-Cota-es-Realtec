#include<iostream>
#include "produto.h"
#include <fstream>
#include <vector>
#include <stdexcept>
#include <limits> 
#include <time.h>
#include <ctime>

using namespace std;

int main(){
	int v=0;
	
	fstream arquivo_codp;
	fstream arquivo_descricao;
	fstream arquivo_valor;
	fstream arquivo_nome_fornecedor;
	fstream arquivo_nome_representante;
	fstream arquivo_data_cotacao;
	fstream arquivo_qtd;
	fstream arquivo_id;
	fstream arquivo_dia;
	fstream arquivo_mes;
	fstream arquivo_ano;
	
	// Diversos necessários
	int cd=0;
	double val=0;
	string str, desc, nf, nr, dt;
	int i=0;
	int qtd=0;
	int idd=0;
	vector<Produto>  lista;
	vector<Produto>::iterator it;
	
	int dia, mes, ano;
	
	int again=0;
   	char yn;				
  	char error='a';	
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	int codigo=0;
	int id_melhorpreco=0;
	double mpreco=999999999;
	
	Produto pdt; 
	Produto pdti;

	///////////////////////////////////////////////////////////////////////////////
	
	// Abertura dos arquivos de entrada
	arquivo_codp.open("codpdt.txt", ios::in);
	arquivo_descricao.open("descricao.txt", ios::in);
	arquivo_valor.open("valor.txt",ios::in);
	arquivo_nome_fornecedor.open("nomefornecedor.txt", ios::in);
	arquivo_nome_representante.open("nomerepresentante.txt",ios::in);
	//arquivo_data_cotacao.open("datacotacao.txt", ios::in);
	arquivo_qtd.open("qtd.txt", ios::in);
	arquivo_qtd >> qtd;
	arquivo_id.open("id.txt", ios::in);
	arquivo_dia.open("dia.txt", ios::in);
	arquivo_mes.open("mes.txt", ios::in);
	arquivo_ano.open("ano.txt", ios::in);
	
	// Loop para alimentar o banco de dados
	for(i=0; i < qtd; i++){ 
			arquivo_codp >> cd;
			pdti.set_cod_produto(cd);
			
			getline(arquivo_descricao, desc);
			pdti.set_descricao(desc);
			
			arquivo_valor >> val;
			pdti.set_valor(val);
			
			getline(arquivo_nome_fornecedor,nf);
			pdti.fornecedor.nome_fornecedor = nf;
			
			getline(arquivo_nome_representante, nr);
			pdti.fornecedor.nome_representante = nr;
			
			arquivo_ano >> ano;
			pdti.ano = ano;		
			
			arquivo_mes >> mes;
			pdti.mes = mes;				
		
			arquivo_dia >> dia;
			pdti.dia = dia;
		   
		    arquivo_id >> idd;
			pdti.set_id(idd);
			
			lista.push_back(pdti);
		
			
	}
	

	// Fechamento dos arquivos de entrada
	
	arquivo_codp.close();
	arquivo_descricao.close();
	arquivo_valor.close();
	arquivo_nome_fornecedor.close();
	arquivo_nome_representante.close();
	arquivo_data_cotacao.close();
	arquivo_qtd.close();
	arquivo_id.close();
	arquivo_dia.close();
	arquivo_mes.close();
	arquivo_ano	.close();
	
	
	
	/////////////////////////////////////////////////////////////////////////////////
	// Abertura dos arquivos de saída
	arquivo_codp.open("codpdt.txt", ios::out | ios::app);
	arquivo_descricao.open("descricao.txt", ios::out | ios::app);
	arquivo_valor.open("valor.txt",ios::out | ios::app);
	arquivo_nome_fornecedor.open("nomefornecedor.txt", ios::out | ios::app);
	arquivo_nome_representante.open("nomerepresentante.txt",ios::out | ios::app);
	arquivo_data_cotacao.open("datacotacao.txt", ios::out | ios::app);
	arquivo_qtd.open("qtd.txt", ios::out);
	arquivo_id.open("id.txt", ios::out | ios::app);
	arquivo_dia.open("dia.txt", ios::out | ios::app);
	arquivo_mes.open("mes.txt", ios::out | ios::app);
	arquivo_ano.open("ano.txt", ios::out | ios::app);

	
	
	// DECLARAÇÃO DO LOOP PRINCIPAL
	
	while(v != 5){
		
		cout << "Escolha uma opcao"<<endl;
		cout <<"0 - Cadastrar uma nova cotacao"<<endl;
		cout <<"1 - Pesquisar produto"<<endl;
		cout <<"2 - Pesquisar fornecedor com melhor preco"<<endl;
		cout <<"5 - Para encerrar o programa"<<endl;
		cin >> v;
		
		switch (v){
			case 0:
				
				
				cout <<"Digite o codigo do produto:"<<endl;
					while(again <= 0){
						try{
							cin >>cd;
							if(!cin)
								throw error;
							break; 		

						}catch(...) {
							 cin.clear(); // Clear error flags
							 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
							cout<<"Erro o valor precisar ser numerico, digite novamente o valor"<<endl;
						}
					}
						
				pdt.set_cod_produto(cd);
				arquivo_codp << pdt.get_cod_produto() << "\n";
				
				cin.ignore();
				cout <<"Digite a descricao"<<endl; 
				getline(cin, str);
				pdt.set_descricao(str);
				arquivo_descricao << pdt.get_descricao() << "\n";

				
				cout <<"Digite o valor"<<endl;
				while(again <= 0){
					try{
						cin >>val;
						if(!cin)
							throw error;
						break; 		
					
					}catch(...) {
						 cin.clear(); // Clear error flags
						 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
						cout<<"Erro o valor precisar ser numerico, digite novamente o valor"<<endl;
					}
				}
					
				pdt.set_valor(val);
				arquivo_valor << pdt.get_valor() << "\n";

				
				cin.ignore();
				cout <<"Digite o nome do fornecedor"<<endl;
				getline(cin, pdt.fornecedor.nome_fornecedor);
				arquivo_nome_fornecedor << pdt.fornecedor.nome_fornecedor << "\n";


				cout <<"Digite o nome do representante"<<endl;
				getline(cin, pdt.fornecedor.nome_representante);
				arquivo_nome_representante << pdt.fornecedor.nome_representante << "\n";
				

				cout << "Digite o ano da data de validade"<<endl;
				while(again <= 0){
					try{
						cin >> ano;
						if(!cin)
							throw error;
						if(ano < ltm->tm_year + 1900)
							throw -1;
						break; 		
					}catch(int) {
						 cin.clear(); // Clear error flags
						 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
						cout<<"Data de validade expirada, digite outra data"<<endl;
					}
				
					catch(...) {
						 cin.clear(); // Clear error flags
						 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
						cout<<"Erro o valor precisar ser numerico, digite novamente o valor"<<endl;
					}
				}
				pdt.ano = ano;
				arquivo_ano << ano << "\n";				
				
			
			cout << "Digite o mes da data de validade"<<endl;
				while(again <= 0){
					try{
						cin >> mes;
						if(!cin)
							throw error;		
						if(ano <= ltm->tm_year + 1900 && mes < ltm->tm_mon +1 || mes < 1 || mes > 12)
							throw -1;
						break;						
					}catch(int) {
						 cin.clear(); // Clear error flags
						 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
						cout<<"Data de validade expirada, digite outra data"<<endl;
					}					
					
					catch(...) {
						 cin.clear(); // Clear error flags
						 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
						cout<<"Erro o valor precisar ser numerico, digite novamente o valor"<<endl;
					}
				}
				pdt.mes = mes;
				arquivo_mes << mes << "\n";		
		
			cout << "Digite o dia da data de validade"<<endl;
			while(again <= 0){
					try{
						cin >> dia;
						if(!cin)
							throw error;
								
						if((ano <= ltm->tm_year + 1900 && mes <= ltm->tm_mon +1 && dia <= ltm->tm_mday) || dia < 1 || dia > 31)
							throw -1;
						break; 			
				
					}catch(int) {
						 cin.clear(); // Clear error flags
						 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
						cout<<"Data de validade expirada, digite outra data"<<endl;
					}					
					catch(...) {
						 cin.clear(); // Clear error flags
						 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer			
						cout<<"Erro o valor precisar ser numerico, digite novamente o valor"<<endl;
					}
				}
				pdt.dia = dia;
				arquivo_dia << dia << "\n";
							
				
				idd++;
				pdt.set_id(idd);
				arquivo_id << pdt.get_id()<<"\n";
				
				lista.push_back(pdt);
				qtd++;
							
				break;
			case 1:
				cout <<"Digite o codigo do produto"<<endl;
				cin >> cd;
				cout <<endl;				
				for(int t =0; t < qtd; t++){
					if(lista.at(t).get_cod_produto() == cd){
							cout <<"Codigo do produto: "<< lista.at(t).get_cod_produto()<<endl;
							cout <<"Descricao: "<< lista.at(t).get_descricao()<<endl;
							cout <<"Valor: "<< lista.at(t).get_valor()<<endl;
							cout <<"Fornecedor: "<< lista.at(t).fornecedor.nome_fornecedor<<endl;
							cout <<"Representante: "<< lista.at(t).fornecedor.nome_representante<<endl;
							cout <<"Data de validade: Dia: "<<lista.at(t).dia << " Mes: "<<lista.at(t).mes << " Ano: "<<lista.at(t).ano<<endl;
							cout << "//////////////////////////////////////////////////////////////////////////////"<<endl;
							cout <<endl;
							cout <<endl;					
					}
				}
				break;
			
			case 2:
				cout <<"Digite o codigo do produto"<<endl;
				cin >> codigo;		
				for(int t =0; t < qtd; t++){
					if(lista.at(t).get_cod_produto() == codigo){
						if(lista.at(t).get_valor() < mpreco){
							if(lista.at(t).ano > ltm->tm_year + 1900){
								mpreco = lista.at(t).get_valor();
								id_melhorpreco = lista.at(t).get_id();
							}else if(lista.at(t).ano == ltm->tm_year + 1900 && lista.at(t).mes > ltm->tm_mon +1){
								mpreco = lista.at(t).get_valor();
								id_melhorpreco = lista.at(t).get_id();							
							}else if(lista.at(t).ano == ltm->tm_year + 1900 && lista.at(t).mes == ltm->tm_mon +1 && lista.at(t).dia >= ltm->tm_mday){
								mpreco = lista.at(t).get_valor();
								id_melhorpreco = lista.at(t).get_id();									
							}
						}
					}
				}
					cout <<endl;
					cout <<"Codigo do produto: "<< lista.at(id_melhorpreco -1 ).get_cod_produto()<<endl;	
				    cout << "O fornecedor com o melhor preco para este produto e: "<<endl;	
					cout <<"Fornecedor: "<< lista.at(id_melhorpreco -1).fornecedor.nome_fornecedor<<endl;
					cout <<"Representante: "<< lista.at(id_melhorpreco -1).fornecedor.nome_representante<<endl;					
					cout <<"Valor: "<< lista.at(id_melhorpreco -1).get_valor()<<endl;
					cout <<"Data de validade: Dia: "<<lista.at(id_melhorpreco -1).dia << " Mes: "<<lista.at(id_melhorpreco -1).mes << " Ano: "<<lista.at(id_melhorpreco -1).ano<<endl;
					cout << "//////////////////////////////////////////////////////////////////////////////"<<endl;
					cout <<endl;
					cout <<endl;		
					break;
			
	}
		
	}
	
	arquivo_qtd << qtd;
	
	
	cout <<qtd<<endl;
	arquivo_codp.close();
	arquivo_descricao.close();
	arquivo_valor.close();
	arquivo_nome_fornecedor.close();
	arquivo_nome_representante.close();
	arquivo_data_cotacao.close();
	arquivo_qtd.close();
	arquivo_dia.close();
	arquivo_mes.close();	
	arquivo_ano.close();	
	
	///////////////////////////////////////////////////////
	
	
	return 0;
}
