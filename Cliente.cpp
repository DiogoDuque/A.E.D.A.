#include "Cliente.h"

using namespace std;

int Cliente::clienteID = 1;

Cliente::Cliente(string myNome)
{
	nome = myNome;
	numRegisto = clienteID;

	clienteID++;
}

int Cliente::getNumRegisto() const
{
	return numRegisto;
}

string Cliente::getNome() const
{
	return nome;
}

vector<Veiculo *> Cliente::getVeiculos() const
{
	return veiculos;
}

void Cliente::setNumRegisto()
{
	numRegisto = numRegisto + 1;
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

bool Cliente::operator<(const Cliente& cl) const
{
    return (nome < cl.getNome());
}
