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
	estaInativo = false;

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
/*bool Cliente::operator<(const Cliente& cl) const
{
    return (nome < cl.getNome());
}*/

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

void Cliente::setNome(string nome)
{
	this->nome = nome;
}

void Cliente::setMorada(string morada)
{
	this->morada = morada;
}

void Cliente::setMail(string mail)
{
	this->mail = mail;
}

void Cliente::setTelefone(string numTelefone, int indice)
{
	if (telefones.empty())
		telefones.push_back(numTelefone);
	else
		telefones[indice - 1] = numTelefone;
}

/**
*Definicao do operador menor para cliente (usado na tabela de dispersao).
*/
bool Cliente::operator<(const Cliente &c2) const
{
	if (nome > c2.getNome())
		return true;
	else
	if (nome < c2.getNome())
		return false;
	else
	if (numRegisto > c2.getNumRegisto())
		return true;

	return false;
}

/**
*Display das informacoes importantes relativamente a um cliente que esta inativo
*/
void Cliente::showInfoClienteInativo() const
{
	if (!estaInativo)
		return;

	cout << nome << endl << "    " << morada << endl;

	for (unsigned int i = 0; i < telefones.size(); i++)
		cout << "    " << telefones[i] << endl;
}

/**
*Muda o estado de inatividade do cliente de acordo com o argumento.
*/
void Cliente::setInatividade(bool inatividade)
{
	estaInativo = inatividade;
}

/**
*Retorna o valor de verdade ou falsidade do estado de inatividade
*/
bool Cliente::getInatividade() const
{
	return estaInativo;
}

/**
*Muda o estado de inatividade do cliente de acordo com o argumento.
*/
void Cliente::showAllTelefones() const
{
	for (unsigned int i = 0; i < telefones.size(); i++)
		cout << i + 1 << ". " << telefones[i] << endl;	
}

bool Cliente::operator ==(const Cliente & c1) const
{
	return (numRegisto == c1.getNumRegisto());
}


void Cliente::criaCartaoPontos()
{
	cartao.
}