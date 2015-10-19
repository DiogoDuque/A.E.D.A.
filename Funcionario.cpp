#include "Funcionario.h"
#include <string>

using namespace std;

Funcionario::Funcionario(string name)
{
	nome = name;
}

bool Funcionario::acrescentaVeiculos(Veiculo *v)
{
	veiculos.push_back(v);
}

vector <Veiculo *> Funcionario::getVeiculos() const
{
	return veiculos;
}