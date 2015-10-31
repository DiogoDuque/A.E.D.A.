#ifndef Funcionario_h
#define Funcionario_h

#include "Veiculo.h"
#include <iostream>
#include <vector>

using namespace std;

class Veiculo;

static int ID = 1;

class Funcionario
{
public:
	Funcionario(string name);
	string getNome() const { return nome; };
	int getID() const	{return id; };		//Este ID � uma var geral que � medida que se acrescentam mais funcionarios, o ID vai crescendo automaticamente
	void acrescentaVeiculos(Veiculo *v);
	vector <Veiculo *> getVeiculos() const;
private:
	static unsigned int maxVeiculos;
	string nome;
	int id;
	vector<Veiculo *> veiculos;
};

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
