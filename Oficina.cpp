#include "Oficina.h"
#include <iostream>
#include <vector>

using namespace std;

Oficina::Oficina(string myNomeOficina)
{
	nomeOficina = myNomeOficina;
}

string Oficina::getNome() const
{
	return nomeOficina;
}

void Oficina::adicionaVeiculo(Veiculo *v)
{
	veiculos.push_back(v);
}

void Oficina::adicionaCliente(Cliente cl)
{
	clientes.push_back(cl);
}

/*
Retorna true caso o veículo exista e seja possível de ser removido, caso contrário retorna false
*/
void Oficina::removeVeiculo(Veiculo *v)
{
	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i] == v)
		{
			veiculos.erase(veiculos.begin() + i);
		}
	}

	throw(VeiculoNaoExistente(v->getID()));
}

void Oficina::adicionaFuncionario(Funcionario f)
{
	funcionarios.push_back(f);
}

//Devolve o indice do funcionario com menos veiculos (expecto o funcionario que queremos remover)
int Oficina::funcionarioComMenosVeiculos(int indiceNaoUsar) const
{
	int indice = -1;
	unsigned int numVeiculos = 1000;

	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i].getVeiculos().size() < numVeiculos)
		{
			numVeiculos = funcionarios[i].getVeiculos().size();
			indice = i;
		}
	}

	return indice;
}

void Oficina::removeCliente(Cliente cl)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].getNumRegisto() == cl.getNumRegisto())
		{
			clientes.erase(clientes.begin() + i);
		}
	}

    throw(ClienteNaoExistente(cl.getNome()));
}

//Função que remove funcionarios, e se tiverem veiculos associados, passa esse veiculos para o funcionario com menos veiculos
void Oficina::removeFuncionario(int id)
{
	bool eliminou = false;

	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i].getID() == id)
		{
			if (funcionarios[i].getVeiculos().size() != 0)		//se o funcionario tiver veiculos a seu cargo, passa-los para outros funcionarios
			{
				for (unsigned int j = 0; j < funcionarios[i].getVeiculos().size(); j++)
					funcionarios[funcionarioComMenosVeiculos(i)].acrescentaVeiculos(funcionarios[i].getVeiculos()[j]);
			}

			funcionarios.erase(funcionarios.begin() + i);
			eliminou = true;
			break;
		}
	}

	if (!eliminou)
		cout << "O funcionario com o ID '" << id << "' nao existe..." << endl;
		//throw(FuncionarioNaoExistente(id));
}


void Oficina::showInfo() const
{
    if(!funcionarios.size())
    {
        throw(OficinaNaoTemFuncionarios());
    }

	cout << "Funcionarios existentes na empresa:" << endl << endl;

	for (unsigned int i = 0; i < funcionarios.size(); i++) //percorre a lista de funcionarios
	{
		cout << "- " << funcionarios[i].getNome() << endl;
		cout << "Veiculos a seu cargo: " << endl;

		for (unsigned int j = 0; j < funcionarios[i].getVeiculos().size(); j++)
		{
			cout << "Veiculo " << j + 1 << ": ";
			funcionarios[i].getVeiculos()[j]->getInfo();
			cout << endl;
		}
	}
}

void Oficina::passaDias(int n)
{
    if(n < 0)
    {
        throw(NumeroDiasInvalido(n));
    }
    for(int i = 0; i < veiculos.size(); i++)
    {
        veiculos[i]->passaDias(n);
    }
}

Funcionario Oficina::getFuncionarioMenosVeiculos() const
{
    return funcionarios[funcionarioComMenosVeiculos(-1)];
}

NumeroDiasInvalido::NumeroDiasInvalido(int n) : dias(n) {}

int NumeroDiasInvalido::getDias() const
{
    return dias;
}

vector<Veiculo*> Oficina::getVeiculos() const
{
    return veiculos;
}

vector<Funcionario> Oficina::getFuncionarios() const
{
    return funcionarios;
}

vector<Cliente> Oficina::getClientes() const
{
    return clientes;
}
