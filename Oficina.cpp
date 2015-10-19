#include "Oficina.h"
#include <iostream>
#include <vector>

using namespace std;

Oficina::Oficina(string myNomeOficina)
{
	nomeOficina = myNomeOficina;
}

void Oficina::adicionaVeiculo(Veiculo *v)
{
	veiculos.push_back(v);
}

void adicionaCliente(Cliente cl)
{
	clientes.push_back(c1);
}

/*
Retorna true caso o veículo exista e seja possível de ser removido, caso contrário retorna false
*/
bool Oficina::removeVeiculo(Veiculo *v)
{
	for (int i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i] == v)
		{
			veiculos.erase(veiculos.begin() + i);
			return true;
		}
	}

	return false;
}

void Oficina::adicionaFuncionario(Funcionario f)
{
	funcionarios.push_back(f);
}

//Devolve o indice do funcionario com menos veiculos (expecto o funcionario que queremos remover)
int Oficina::funcionarioComMenosVeiculos(int indiceNaoUsar) const
{
	int indice = -1;
	int quantidade = 0;

	for (int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i].getVeiculos().size() > quantidade)
		{
			if (indiceNaoUsar != i)
				indice = i;
		}
	}

	return indice;
}

bool Oficina::removeCliente(Cliente cl)
{
	for (int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].getNumRegisto() == c1.getNumRegisto())
		{
			clientes.erase(clientes.begin() + i);
			return true;
		}
	}

	return false;
}

//Função que remove funcionarios, e se tiverem veiculos associados, passa esse veiculos para o funcionario com menos veiculos
bool Oficina::removeFuncionario(Funcionario f)
{
	for (int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i].getID() == f.getID())
		{
			if (funcionarios[i].getVeiculos().size() != 0)		//se o funcionario tiver veiculos a seu cargo, passa-los para outros funcionarios
			{
				for (int j = 0; j < funcionarios[i].getVeiculos().size(); j++)
					funcionarios[funcionarioComMenosVeiculos(i)].acrescentaVeiculos(funcionarios[i].getVeiculos[j]);
			}

			funcionarios.erase(funcionarios.begin() + i);
			return true;
		}
	}

	return false;
}


void Oficina::showInfo() const
{
	cout << "Funcionarios existentes na empresa:" << endl << endl;

	for (int i = 0; i < funcionarios.size(); i++)
	{
		cout << "- " << funcionarios[i].getNome() << endl;
		cout << "Veiculos a seu cargo: " << endl;

		for (int j = 0; j < funcionarios[i].getVeiculos().size(); j++)
		{
			cout << "Veiculo Nº1" << endl << endl;
			funcionarios[i].getVeiculos()[j]->getInfo();
		}
	}
}