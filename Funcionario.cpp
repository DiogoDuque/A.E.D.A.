#include "Funcionario.h"
#include <string>

using namespace std;

unsigned int Funcionario::maxVeiculos = 10;

Funcionario::Funcionario(string name)
{
	nome = name;

	id = ID;
	ID++;
}

void Funcionario::acrescentaVeiculos(Veiculo *v)
{
	if (veiculos.size() >= maxVeiculos)
    {
        throw(FuncionarioNaoPodeTerMaisVeiculos(veiculos.size()));
    }

	veiculos.push_back(v);
}

vector <Veiculo *> Funcionario::getVeiculos() const
{
	return veiculos;
}

FuncionarioNaoExistente::FuncionarioNaoExistente(int i) : id(i) {}

int FuncionarioNaoExistente::getID() const
{
    return id;
}

FuncionarioNaoPodeTerMaisVeiculos::FuncionarioNaoPodeTerMaisVeiculos(int n) : num(n) {}

int FuncionarioNaoPodeTerMaisVeiculos::getNumeroVeiculos() const
{
    return num;
}
