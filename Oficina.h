#ifndef Oficina_h
#define Oficina_h

#include "Veiculo.h"
#include "Funcionario.h"
#include "Cliente.h"

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
	void adicionaFuncionario(Funcionario f);
	bool removeVeiculo(Veiculo *v);
	bool removeCliente(Cliente cl);
	bool removeFuncionario(Funcionario f);
	int funcionarioComMenosVeiculos(int indiceNaoUsar) const;
	
	void showInfo() const;
private:
	string nomeOficina;
	vector <Veiculo*> veiculos;
	vector <Funcionario> funcionarios;
	vector <Cliente> clientes;
	const vector <Servico> servicos; //importar dum ficheiro
};

#endif
