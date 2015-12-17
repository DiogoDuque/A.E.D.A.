#include "Oficina.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
*Construtor para a classe 'Oficina'.
*/
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

/**
*Retorna o nome da oficina.
*/
string Oficina::getNome() const
{
	return nomeOficina;
}

/**
*Retorna os veiculos da oficina.
*/
vector<Veiculo*> &Oficina::getVeiculos()
{
	return veiculos;
}

/**
*Retorna os clientes da oficina.
*/
vector<Cliente> &Oficina::getClientes()
{
	return clientes;
}

/**
*Retorna os funcionarios da oficina.
*/
vector<Funcionario*> Oficina::getFuncionarios() const
{
	return funcionarios;
}

/**
*Retorna os servicos da oficina.
*/
vector<Servico> Oficina::getServicos() const
{
	return servicos;
}

/**
*Adiciona o veiculo 'v' ao vector 'veiculos' da oficina.
*/
void Oficina::adicionaVeiculo(Veiculo *v)
{
	veiculos.push_back(v);
}

/**
*Adiciona o funcionario 'f' ao vector 'funcionarios' da oficina.
*/
void Oficina::adicionaFuncionario(Funcionario *f)
{
	funcionarios.push_back(f);
}

/**
*Adiciona o cliente 'c1' ao vector 'clientes' da oficina.
*/
void Oficina::adicionaCliente(Cliente cl)
{
	clientes.push_back(cl);
}

/**
*Adiciona o servico 's1' ao vector 'servicos' da oficina.
*/
void Oficina::adicionaServico(Servico s1)
{
	servicos.push_back(s1);
}

/**
*Remove o veiculo 'v' do vector de veiculos da oficina, assim como do vector veiculos do cliente.
*/
void Oficina::removeVeiculo(int posVeiculo)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
		clientes[i].removeVeiculo(veiculos[posVeiculo]);
	
	veiculos.erase(veiculos.begin() + posVeiculo);
}

/**
*Remove o funcionario 'f1', e se 'f1' tiver veiculos associados, passa esse veiculos para o funcionario com menos veiculos (o funcionario que esta menos ocupado).
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
					funcionarios[funcionarioComMenosVeiculos()]->acrescentaVeiculos(funcionarios[i]->getVeiculos()[j]);
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

/**
*Remove o cliente 'c1' do vector 'clientes' da oficina (caso este exista). Se nao existir, lanca uma excecao.
*/
void Oficina::removeCliente(Cliente cl)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].getNumRegisto() == cl.getNumRegisto())
		{
			clientes.erase(clientes.begin() + i);
			return;
		}
	}

	throw(ClienteNaoExistente(cl.getNome()));
}

/**
*Remove o servico que esta na posicao 'pos' do vector 'servicos' da oficina. No entanto, so da para remover caso o servico nao esteja a ser efectuado em nenhum veiculo, ou seja, so elimina o servico se nao houver veiculos que estao a ser reparados com aquele servico.
*/
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

/**
*Retorna o indice do funcionario com menos veiculos.
*/
int Oficina::funcionarioComMenosVeiculos() const
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

/**
*Substrai 'n' dias a todos os servicos de todos os veiculos.
*/
void Oficina::passaDias(int n)
{
	for (unsigned int i = 0; i < veiculos.size(); i++)
		veiculos[i]->passaDias(n);
}

/**
*Associa o veiculo 'v1' ao cliente 'c1'. Se o cliente 'c1' nao existe, lanca uma excecao.
*/
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

/**
*Faz o display dos funcionarios da empresa e dos veiculos que cada um tem associados.
*/
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

/**
*Funcao de comparacao de funcionarios (usada no sort).
*/
bool compFunc(Funcionario * &f1, Funcionario * &f2)
{
	return (f1->getNome() < f2->getNome());
}

/**
*Display da informacao dos funcionarios.
*/
void Oficina::showInfoFuncionarios() const
{
	for (unsigned int i = 0; i < funcionarios.size(); i++)
		cout << "   " << i + 1 << ". " << *funcionarios[i] << endl;;
}

/**
*Faz uma lista ordenada (de acordo com a funcao de ordenacao) dos funcionarios.
*/
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

/**
*Funcao de comparacao de veiculos (usado no sort).
*/
bool compVeiculos(Veiculo * &v1, Veiculo * &v2)
{
	return (v1->getID() < v2->getID());
}

/**
*Display da informacao dos veiculos
*/
void Oficina::showInfoVeiculos() const
{
	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		cout << "   Veiculo '" << i + 1 << "'\n   ";
		veiculos[i]->getInfo();
		cout << endl << endl;
	}
}

/**
*Faz uma lista ordenada (de acordo com a funcao de ordenacao) dos veiculos.
*/
void Oficina::listaVeiculos()
{
	if (veiculos.size() == 0)
	{
		cout << "   Actualmente nao existem veiculos registados...";
		return;
	}

	sort(veiculos.begin(), veiculos.end(), compVeiculos);
	showInfoVeiculos();

}

/**
*Remove a associacao dos veiculos que ja estao tratados aos funcionarios.
*/
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

/**
*Funcao de comparacao de clientes (usado no sort).
*/
bool compClientes(const Cliente &c1, const Cliente &c2)
{
	return (c1.getNome() < c2.getNome());
}

/**
*Faz o display da informacao dos clientes.
*/
void Oficina::showInfoClientes() const
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		cout << "   " << i + 1 << ". ";
		cout << clientes[i] << endl;
	}
}

/**
*Faz uma lista ordenada (de acordo com a funcao de ordenacao) dos clientes.
*/
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

/**
*Funcao de comparacao dos servicos.
*/
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

/**
*Faz o display da informacao dos servicos.
*/
void Oficina::showInfoServicos() const
{
	for (unsigned int i = 0; i < servicos.size(); i++)
		cout << "   " << servicos[i] << endl;
}

/**
*Faz uma lista ordenada (de acordo com a funcao de comparacao) dos servicos.
*/
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

/**
*Adiciona o servico na posicao 'posServico' do vector servicos da oficina ao veiculo na posicao 'posVeiculo' do vector veiculos do cliente na posicao 'posCliente' do vector clientes da oficina, ou seja, adiciona mais um servico a um veiculo.
*/
void Oficina::adicionaServicoVeiculo(int posCliente, int posVeiculo, int posServico)
{
	clientes[posCliente].adicionaServicoVeiculo(posVeiculo, servicos[posServico]);

	int indice = funcionarioComMenosVeiculos();
	veiculos[posVeiculo]->setFuncionario(funcionarios[indice]);
	funcionarios[indice]->acrescentaVeiculos(veiculos[posVeiculo]);
}

/**
*Retorna 'falso' se existir algum funcionario a operar o veiculo na posicao 'posVeiculo' da oficina. Caso contrario retorna 'true'.
*/
bool Oficina::podeRemoverVeiculo(int posVeiculo) const
{
	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i]->verificaSeExiste(veiculos[posVeiculo]))
			return false;
	}

	return true;
}

/**
*Retorna a tabela de dispersao dos clientes inativos
*/
hashClientes Oficina::getClientesInativos() const
{
	return clientesInativos;
}