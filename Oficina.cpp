#include "Oficina.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Oficina::Oficina(string myNomeOficina)
{
	nomeOficina = myNomeOficina;

	//importar servicos
	ifstream file("servicos.txt");
	string s1, s2, s3;
	while (!file.eof())
	{
		getline(file, s1);
		file >> s2;
		file >> s3;
		Servico temp(s1, (float)stoi(s2), stoi(s3));
		getline(file, s1); //limpar '\n'
		servicos.push_back(temp);
	}
}

string Oficina::getNome() const
{
	return nomeOficina;
}

vector<Veiculo*> &Oficina::getVeiculos()
{
	return veiculos;
}

vector<Cliente> &Oficina::getClientes()
{
	return clientes;
}

vector<Funcionario*> Oficina::getFuncionarios() const
{
	return funcionarios;
}

vector<Servico> Oficina::getServicos() const
{
	return servicos;
}

void Oficina::adicionaVeiculo(Veiculo *v)
{
	veiculos.push_back(v);
}

void Oficina::adicionaFuncionario(Funcionario *f)
{
	funcionarios.push_back(f);
}

void Oficina::adicionaCliente(Cliente cl)
{
	clientes.push_back(cl);
}

/**
*Retorna true caso o veículo exista e seja possível de ser removido, caso contrário retorna false
*/
void Oficina::removeVeiculo(Veiculo *v)
{
	bool eliminou = false;

	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i] == v)
		{
			veiculos.erase(veiculos.begin() + i);
			eliminou = true;
			break;
		}
	}

	if (!eliminou)
		throw(VeiculoNaoExistente(v->getID()));
}

/**
*Função que remove funcionarios, e se tiverem veiculos associados, passa esse veiculos para o funcionario com menos veiculos
*/
void Oficina::removeFuncionario(Funcionario *f1)
{
	bool eliminou = false;

	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i] == f1)
		{
			if (funcionarios[i]->getVeiculos().size() != 0)		//se o funcionario tiver veiculos a seu cargo, passa-los para outros funcionarios
			{
				for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size(); j++)
					funcionarios[funcionarioComMenosVeiculos(i)]->acrescentaVeiculos(funcionarios[i]->getVeiculos()[j]);
			}

			funcionarios.erase(funcionarios.begin() + i);
			eliminou = true;
			break;
		}
	}

	if (!eliminou)
	{
	    cout << "O funcionario com o ID  nao existe..." << endl;
        throw(FuncionarioNaoExistente(f1->getID()));
	}
}

void Oficina::removeCliente(Cliente cl)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].getNumRegisto() == cl.getNumRegisto())
		{
			clientes.erase(clientes.begin() + i);
			break;
		}
	}


	throw(ClienteNaoExistente(cl.getNome()));
}

Funcionario* Oficina::getFuncionarioMenosVeiculos() const
{
	return funcionarios[funcionarioComMenosVeiculos(-1)];
}

/**
*Devolve o indice do funcionario com menos veiculos (exceto o funcionario que queremos remover)
*/
int Oficina::funcionarioComMenosVeiculos(int indiceNaoUsar) const
{
	int indice = -1;
	unsigned int numVeiculos = 1000;

	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i]->getVeiculos().size() < numVeiculos)
		{
			numVeiculos = funcionarios[i]->getVeiculos().size();
			indice = i;
		}
	}

	return indice;
}

void Oficina::passaDias(int n)
{
	if (n < 0)
	{
		throw(NumeroDiasInvalido(n));
	}
	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		veiculos[i]->passaDias(n);
	}
}


//FALTA UMA FUNCAO AQUI!!!!

void Oficina::associaVeiculoCliente(Veiculo* v1, Cliente c1)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].getNumRegisto() == c1.getNumRegisto())
		{
			c1.addVeiculo(v1);
			return;
		}
	}

	throw(ClienteNaoExistente(c1.getNome()));
}

void Oficina::showInfo() const
{
    if(funcionarios.size()==0)
    {
        throw(OficinaNaoTemFuncionarios());
    }

	cout << "   FUNCIONARIOS EXISTENTES NA EMPRESA RESPONSAVEIS PELOS AUTOMOVEIS ACTUALMENTE:" << endl << endl;

	for (unsigned int i = 0; i < funcionarios.size(); i++) //percorre a lista de funcionarios
	{
		cout << "   " << i+1 << ". " << funcionarios[i]->getNome() << endl;
		cout << "     Veiculos a seu cargo: " << endl;

		for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size(); j++)
		{
			cout << "      - Veiculo " << j + 1 << ": ";
			funcionarios[i]->getVeiculos()[j]->getInfo();
			cout << endl;
		}
	}
}

void Oficina::ordenaClientes()
{
    sort(clientes.begin(), clientes.end());
}

bool compFunc(Funcionario * &f1, Funcionario * &f2)
{
	return (f1->getNome() < f2->getNome());
}

void Oficina::listaFunc()
{
	sort(funcionarios.begin(), funcionarios.end(), compFunc);

}

void Oficina::removeVeiculosTratados()
{
	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size(); j++)
		{
			if (funcionarios[i]->getVeiculos()[j]->estaPronto())
				funcionarios[i]->removeVeiculo(j);
		}
	}
}
