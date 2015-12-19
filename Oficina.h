#ifndef Oficina_h
#define Oficina_h

#include "Veiculo.h"
#include "Funcionario.h"
#include "Cliente.h"
#include "CartaoPontos.h"
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct hCliente
{
	int operator()(const Cliente & c1) const
	{
		int v = 0;

		for (unsigned int i = 0; i < c1.getNome().size(); i++)
			v = v * 37 + c1.getNome()[i];

		return v;
	}

	bool operator()(const Cliente & c1, const Cliente & c2) const
	{
		/*if (c1.getNome() > c2.getNome())
			return true;

		return false;*/
		return (c1.getNome() == c2.getNome());
	}
};

typedef unordered_set<Cliente, hCliente, hCliente> hashClientes;

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
	bool podeRemoverVeiculo(int posVeiculo) const;
	void removeVeiculo(int posVeiculo);
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

	hashClientes getClientesInativos() const;
	void listaClientesInativos();
	void adicionaClienteInativo(Cliente c);
	void actualizaClienteInativo(int numCliente, int numMudar);
	void actualizaInatividadeCliente(int posCliente);
	void adicionaInformacao(int numCliente, int numMudar);
	void pesquisaClienteInativo(string nomeCliente);
	void avancaDiasParaClientes(int diasAvancar);
private:
	string nomeOficina;
	vector <Veiculo*> veiculos;
	vector <Funcionario*> funcionarios;
	vector <Cliente> clientes;
	vector <Servico> servicos; //importar dum ficheiro

	priority_queue<CartaoPontos*> cartoes;
	hashClientes clientesInativos;
};

/**
*Classe que funciona como uma excecao quando a oficina nao tem funcionarios.
*/
class OficinaNaoTemFuncionarios {};

#endif
