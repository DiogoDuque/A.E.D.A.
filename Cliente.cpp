#include "Cliente.h"

using namespace std;

int Cliente::numRegisto = 0;

Cliente::Cliente(string myNome)
{
	nome = myNome;
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

Cliente::getNome() const
{
    return nome;
}

ClienteNaoExistente::ClienteNaoExistente(string name) : nome(name) {}

string ClienteNaoExistente::getNome()
{
    return nome;
}
