#ifndef Funcionario_h
#define Funcionario_h

#include "Veiculo.h"

class Funcionario
{
public:
	Funcionario(string name);
	string getNome() const { return nome; };
	int getID() const	{return ID; };		//Este ID é uma var global que ha medida que se acrescentam mais funcionarios, o ID vai crescendo automaticamente
	bool acrescentaVeiculos(Veiculo *v);
	vector <Veiculo *> getVeiculos() const;
private:
	string nome;
	int ID;
	vector<Veiculo *> veiculos;
};

#endif