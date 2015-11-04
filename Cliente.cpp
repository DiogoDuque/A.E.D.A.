#include "Cliente.h"

using namespace std;

int Cliente::clienteID = 1;

Cliente::Cliente(string myNome)
{
	nome = myNome;
	numRegisto = clienteID;

	clienteID++;
}

void Cliente::setNumRegisto()
{
	numRegisto = numRegisto + 1;
}

int Cliente::getNumRegisto() const
{
	return numRegisto;
}

vector<Veiculo *> Cliente::getVeiculos() const
{
	return veiculos;
}

string Cliente::getNome() const
{
    return nome;
}

ClienteNaoExistente::ClienteNaoExistente(string name) : nome(name) {}

string ClienteNaoExistente::getNome() const
{
    return nome;
}

void Cliente::addVeiculo(Veiculo *v1)
{
	veiculos.push_back(v1);
}

ostream & operator<<(ostream &out, const Cliente &v1)
{
	out << v1.getNome() << ", ID = " << v1.getNumRegisto() << endl;
	out << "      Numero de veiculos associados: " << v1.getVeiculos().size();

	return out;
}