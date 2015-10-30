#include "Funcionario.h"
#include <string>

using namespace std;
unsigned int Funcionario::maxVeiculos = 10;

Funcionario::Funcionario(string name)
{
	nome = name;
}

bool Funcionario::acrescentaVeiculos(Veiculo *v)
{
	if (veiculos.size() >= maxVeiculos)
		return false;
	veiculos.push_back(v);
	return true;
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
