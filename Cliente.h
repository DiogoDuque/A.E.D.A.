#ifndef Cliente_h
#define Cliente_h

#include "Veiculo.h"

using namespace std;

class Cliente
{
public:
	Cliente(string nome);
	void setNumRegisto();
	int getNumRegisto() const;
	vector<Veiculo *> getVeiculos() const;
	string getNome() const;
private:
	static int clienteID;
	string nome;
	int numRegisto;
	vector<Veiculo *> veiculos;


};

class ClienteNaoExistente
{
    string nome;
public:
    ClienteNaoExistente(string name);
    string getNome() const;
};

#endif
