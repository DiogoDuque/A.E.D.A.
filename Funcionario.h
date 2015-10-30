#ifndef Funcionario_h
#define Funcionario_h

#include "Veiculo.h"
#include <iostream>
#include <vector>

using namespace std;
class Veiculo;

class Funcionario
{
public:
	Funcionario(string name);
	string getNome() const { return nome; };
	int getID() const	{return ID; };		//Este ID � uma var geral que � medida que se acrescentam mais funcionarios, o ID vai crescendo automaticamente
	bool acrescentaVeiculos(Veiculo *v);
	vector <Veiculo *> getVeiculos() const;
private:
	static unsigned int maxVeiculos;
	string nome;
	int ID;
	vector<Veiculo *> veiculos;
};

class FuncionarioNaoExistente
{
    int id;
public:
    FuncionarioNaoExistente(int i);
    int getID() const;
};

#endif
