#include "Funcionario.h"
#include <string>

using namespace std;

int Funcionario::ID = 1;
unsigned int Funcionario::maxVeiculos = 10;

/**
*Contrutor da classe funcionario.
*/
Funcionario::Funcionario(string name)
{
	nome = name;

	id = ID;
	ID++;
}

/**
*Acrescenta o veiculo 'v' ao vector de veiculos do funcionario (associa o veiculo 'v' ao funcionario). Caso o funcionario tenha 10 veiculos, lanca uma excecao que informa que o funcionario nao pode tratar de mais veiculos.
*/
void Funcionario::acrescentaVeiculos(Veiculo *v)
{
	if (veiculos.size() >= maxVeiculos)
        throw(FuncionarioNaoPodeTerMaisVeiculos(veiculos.size()));
	else
		veiculos.push_back(v);
}

/**
*Retorna o vector veiculos do funcionario.
*/
vector <Veiculo *> Funcionario::getVeiculos() const
{
	return veiculos;
}

/**
*Contrutor para a classe FuncionarioNaoExistente.
*/
FuncionarioNaoExistente::FuncionarioNaoExistente(int i) : id(i) {}

/**
*Retorna o 'id' do funcionario.
*/
int FuncionarioNaoExistente::getID() const
{
    return id;
}

/**
*Contrutor da classe FuncionarioNaoPodeTerMaisVeiculos.
*/
FuncionarioNaoPodeTerMaisVeiculos::FuncionarioNaoPodeTerMaisVeiculos(int n) : num(n) {}

/**
*Retorna o numero de veiculos que estao associados ao funcionario.
*/
int FuncionarioNaoPodeTerMaisVeiculos::getNumeroVeiculos() const
{
    return num;
}

/**
*Overload do operador << do funcionario.
*/
ostream & operator<<(ostream & out, const Funcionario &f1)
{
	out << f1.getNome() << ", ID = " << f1.getID();
	out << endl << "      Veiculos responsaveis: " << f1.getVeiculos().size();
	return out;
}

/**
*Remove o veiculo da posicao 'pos' do vector 'veiculos' do funcionario.
*/
void Funcionario::removeVeiculo(int pos)
{
	veiculos.erase(veiculos.begin() + pos);
}