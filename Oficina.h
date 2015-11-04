#ifndef Oficina_h
#define Oficina_h

#include "Veiculo.h"
#include "Funcionario.h"
#include "Cliente.h"
#include <iostream>

using namespace std;
/*
- podemos tentar adaptar a oficina para ela ter um numero maximo de veiculos de cada tipo
- nao sei de que fazer o operator
*/

class Oficina
{
public:
	Oficina(string nomeOficina);
	string getNome() const;
	vector<Veiculo*> getVeiculos() const;
	vector<Cliente> getClientes() const;
	vector<Funcionario*> getFuncionarios() const;
	void adicionaVeiculo(Veiculo *v);
	void adicionaCliente(Cliente cl);
	void adicionaFuncionario(Funcionario *f1);
	void removeVeiculo(Veiculo *v);
	void removeCliente(Cliente cl);
	void removeFuncionario(Funcionario *f1);
	Funcionario* getFuncionarioMenosVeiculos() const;
	int funcionarioComMenosVeiculos(int indiceNaoUsar) const;
	void passaDias(int n);
    void ordenaClientes();
	void associaVeiculoCliente(Veiculo *v1, Cliente c1);
	void showInfo() const;
private:
	string nomeOficina;
	vector <Veiculo*> veiculos;
	vector <Funcionario*> funcionarios;
	vector <Cliente> clientes;
	vector <Servico> servicos; //importar dum ficheiro
};

class NumeroDiasInvalido
{
    int dias;
public:
	NumeroDiasInvalido(int n) { dias = n; };
	int getDias() const { return dias; };
};

class OficinaNaoTemFuncionarios {};

#endif
