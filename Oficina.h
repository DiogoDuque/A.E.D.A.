#ifndef Oficina_h
#define Oficina_h

#include "Veiculo.h"
#include "Funcionario.h"
#include "Cliente.h"
#include <iostream>

using namespace std;

class Oficina
{
public:
	Oficina(string nomeOficina);
	string getNome() const;
	vector<Veiculo*> &getVeiculos();
	vector<Cliente> &getClientes();
	vector<Funcionario*> getFuncionarios() const;
	vector<Servico> getServicos() const;
	void adicionaVeiculo(Veiculo *v);
	void adicionaCliente(Cliente cl);
	void adicionaFuncionario(Funcionario *f1);
	void adicionaServico(Servico s1);
	void adicionaServicoVeiculo(int posCliente, int posVeiculo, int posServico);
	void removeVeiculo(Veiculo *v);
	void removeCliente(Cliente cl);
	void removeFuncionario(Funcionario *f1);
	bool removeServico(int pos);
	void removeVeiculosTratados();
	int funcionarioComMenosVeiculos() const;
	void passaDias(int n);
	void associaVeiculoCliente(Veiculo *v1, Cliente c1);
	void showInfo() const;
	void showInfoFuncionarios() const;
	void showInfoVeiculos() const;
	void showInfoClientes() const;
	void showInfoServicos() const;
	void listaFunc();
	void listaVeiculos();
	void listaClientes();
	void listaServicos();
private:
	string nomeOficina;
	vector <Veiculo*> veiculos;
	vector <Funcionario*> funcionarios;
	vector <Cliente> clientes;
	vector <Servico> servicos; //importar dum ficheiro
};

/**
*Classe que funciona como uma excecao quando a oficina nao tem funcionarios.
*/
class OficinaNaoTemFuncionarios {};

#endif
