#ifndef Cliente_h
#define Cliente_h

#include "Veiculo.h"

using namespace std;

class Cliente
{
public:
	Cliente(string nome);
	
	int getNumRegisto() const;
	string getNome() const;
	vector<Veiculo *> getVeiculos() const;
	void setNumRegisto();
	void addVeiculo(Veiculo *v1);
	
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
