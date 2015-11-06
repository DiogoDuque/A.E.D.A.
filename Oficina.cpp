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

void Oficina::adicionaServico(Servico s1)
{
	servicos.push_back(s1);
}

/**
*Retorna true caso o ve�culo exista e seja poss�vel de ser removido, caso contr�rio retorna false
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
*Fun��o que remove funcionarios, e se tiverem veiculos associados, passa esse veiculos para o funcionario com menos veiculos
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

bool Oficina::removeServico(int pos)
{
	bool podeEliminar = true;

	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i]->veiculoUsaServico(servicos[pos]))
			podeEliminar = false;
	}

	if (podeEliminar)
	{
		servicos.erase(servicos.begin() + pos);
		return true;
	}
	else
		return false;
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

bool compFunc(Funcionario * &f1, Funcionario * &f2)
{
	return (f1->getNome() < f2->getNome());
}

void Oficina::showInfoFuncionarios() const
{
	for (unsigned int i = 0; i < funcionarios.size(); i++)
		cout << "   " << i + 1 << ". " << *funcionarios[i] << endl;;
}

void Oficina::listaFunc()
{
	if (funcionarios.size() == 0)
	{
		cout << "   Actualmente nao existem funcionarios contratados...";
		return;
	}

	sort(funcionarios.begin(), funcionarios.end(), compFunc);
	showInfoFuncionarios();
}

bool compVeiculos(Veiculo * &v1, Veiculo * &v2)
{
	return (v1->getID() < v2->getID());
}

void Oficina::showInfoVeiculos() const
{
	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		cout << "   Veiculo '" << i + 1 << "'\n   ";
		veiculos[i]->getInfo();
		cout << endl << endl;
	}
}

void Oficina::listaVeiculos()
{
	if (veiculos.size() == 0)
	{
		cout << "   Actualmente nao existem clientes registados...";
		return;
	}

	sort(veiculos.begin(), veiculos.end(), compVeiculos);
	showInfoVeiculos();

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

bool compClientes(const Cliente &c1, const Cliente &c2)
{
	return (c1.getNome() < c2.getNome());
}

void Oficina::showInfoClientes() const
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		cout << "   " << i + 1 << ". ";
		cout << clientes[i] << endl;
	}
}

void Oficina::listaClientes()
{
	if (clientes.size() == 0)
	{
		cout << "   Actualmente nao existem clientes registados...";
		return;
	}

	sort(clientes.begin(), clientes.end(), compClientes);
	showInfoClientes();
}

bool compServicos(const Servico &s1, const Servico &s2)
{
	if (s1.getPreco() < s2.getPreco())
		return true;
	else
	if (s1.getPreco() > s2.getPreco())
		return false;
	else
	if (s1.getDias() < s2.getDias())
		return true;
	else
	if (s1.getDias() > s2.getDias())
		return false;
	else
	if (s1.getNome() < s2.getNome())
		return true;

	return false;
}

void Oficina::showInfoServicos() const
{
	for (unsigned int i = 0; i < servicos.size(); i++)
		cout << "   " << servicos[i] << endl;
}

void Oficina::listaServicos()
{
	if (servicos.size() == 0)
	{
		cout << "Actualmente, a oficina nao dispoe de quaisquer servicos...";
		return;
	}

	sort(servicos.begin(), servicos.end(), compServicos);
	showInfoServicos();
}