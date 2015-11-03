#include "Cliente.h"

using namespace std;

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
