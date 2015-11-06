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
	int getID() const	{return id; };		//Este ID é uma var geral que à medida que se acrescentam mais funcionarios, o ID vai crescendo automaticamente
	void acrescentaVeiculos(Veiculo *v);
	vector <Veiculo *> getVeiculos() const;
	void removeVeiculo(int pos);

	
private:
	static int ID;
	static unsigned int maxVeiculos;
	string nome;
	int id;
	vector<Veiculo *> veiculos;
};

ostream & operator<<(ostream & out, const Funcionario &f1);

class FuncionarioNaoExistente
{
    int id;
public:
    FuncionarioNaoExistente(int i);
    int getID() const;
};

class FuncionarioNaoPodeTerMaisVeiculos
{
    int num;
public:
    FuncionarioNaoPodeTerMaisVeiculos(int n);
    int getNumeroVeiculos() const;
};

#endif
