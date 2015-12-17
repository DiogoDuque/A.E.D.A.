#include "Cliente.h"

using namespace std;

int Cliente::clienteID = 1;

/**
*Contrutor de cliente.
*/
Cliente::Cliente(string myNome)
{
	nome = myNome;
	numRegisto = clienteID;

	clienteID++;
}

/**
*Retorna o numero de registo do cliente.
*/
int Cliente::getNumRegisto() const
{
	return numRegisto;
}

/**
*Retorna o nome do cliente.
*/
string Cliente::getNome() const
{
	return nome;
}

/**
*Retorna o vector dos veiculos associados ao cliente.
*/
vector<Veiculo *> Cliente::getVeiculos() const
{
	return veiculos;
}

/**
*Adiciona o veiculo 'v1' ao vector de veiculos do cliente.
*/
void Cliente::addVeiculo(Veiculo *v1)
{
	veiculos.push_back(v1);
}

/**
*Overload do operador << de cliente.
*/
ostream & operator<<(ostream &out, const Cliente &v1)
{
	out << v1.getNome() << ", ID = " << v1.getNumRegisto() << endl;
	out << "      Numero de veiculos associados: " << v1.getVeiculos().size();

	return out;
}

/**
*Overload do operador < de cliente.
*/
bool Cliente::operator<(const Cliente& cl) const
{
    return (nome < cl.getNome());
}

/**
*Remove o veiculo 'v1' do vector veiculos do cliente.
*/
void Cliente::removeVeiculo(Veiculo *v1)
{
	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i] == v1)
		{
			veiculos.erase(veiculos.begin() + i);
			return;
		}
	}
}

/**
*Adiciona o servico 's1' ao veiculo que se encontra na posicao 'posVeiculo' do vetor veiculos do cliente.
*/
void Cliente::adicionaServicoVeiculo(int posVeiculo, Servico s1)
{
	veiculos[posVeiculo]->adicionaServico(s1);
}

void Cliente::addMorada(string morada)
{
	this->morada = morada;
}

void Cliente::addMail(string mail)
{
	this->mail = mail;
}

void Cliente::addTelefone(string telefone)
{
	telefones.push_back(telefone);
}