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
	void adicionaVeiculo(Veiculo *v);
	void adicionaCliente(Cliente cl);
	void adicionaFuncionario(Funcionario *f1);
	void removeVeiculo(Veiculo *v);
	void removeCliente(Cliente cl);
	void removeFuncionario(Funcionario *f1);
	int funcionarioComMenosVeiculos(int indiceNaoUsar) const;
	void passaDias(int n);
    Funcionario* getFuncionarioMenosVeiculos() const;
    void ordenaClientes();
	string getNome() const;
    vector<Veiculo*> getVeiculos() const;
    vector<Funcionario*> getFuncionarios() const;
    vector<Cliente> getClientes() const;
	void associaVeiculoCliente(Veiculo *v1, Cliente c1);

	void showInfo() const;
private:
	string nomeOficina;
	vector <Veiculo*> veiculos;
	vector <Funcionario*> funcionarios;
	vector <Cliente> clientes;
	const vector <Servico> servicos; //importar dum ficheiro
};

class NumeroDiasInvalido
{
    int dias;
public:
    NumeroDiasInvalido(int n);
    int getDias() const;
};

class OficinaNaoTemFuncionarios {};

#endif
