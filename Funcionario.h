#ifndef Funcionario_h
#define Funcionario_h

#include "Veiculo.h"
#include <iostream>
#include <vector>

using namespace std;

class Funcionario
{
public:
	Funcionario(string name);
	string getNome() const { return nome; };
	int getID() const	{return ID; };		//Este ID é uma var global que à medida que se acrescentam mais funcionarios, o ID vai crescendo automaticamente
	bool acrescentaVeiculos(Veiculo *v);
	vector <Veiculo *> getVeiculos() const;
private:
	string nome;
	int ID;
	vector<Veiculo *> veiculos;
};

#endif