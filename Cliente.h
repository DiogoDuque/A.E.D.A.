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
private:
	string nome;
	static int numRegisto;
	vector<Veiculo *> veiculos;


}

#endif