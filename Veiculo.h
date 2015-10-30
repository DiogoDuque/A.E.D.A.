#ifndef Veiculo_h
#define Veiculo_h

#include "Funcionario.h"
#include <string>
#include <vector>
#include <string>

using namespace std;
class Funcionario;

class Servico
{
	string nome;
	float preco;
	bool terminado;
	int dias;
public:
    Servico(string name, float price, int days);
    bool terminado() const;
    string getName() const;
    float getPreco() const;
    int getDias() const;
    void passaDias(int n);
    void desconto(float d);
};

class Veiculo
{
public:
	Veiculo(int year, int month, string comb); //especificar o tipo de servico. caso nao conheca o servico, pede preco
	void setFuncionario(Funcionario* f1); //TO DO!
	virtual void getInfo() const;
	bool estaPronto();
	float ofereceDesconto();
	void passaDias(int n);
protected:
	int ano;
	int mes;
	string combustivel;
	Funcionario *f;
	vector<Servico> servicos;
};

class Automovel : public Veiculo
{
public:
	Automovel(int year, int month, string comb, int seats);
	void getInfo() const;

private:
	int lugares;
};

class Motorizada : public Veiculo
{
public:
	Motorizada(int year, int month, string comb, int cilindr);
	void getInfo() const;

private:
	int cilindrada;
};

class Camiao : public Veiculo
{
public:
	Camiao(int year, int month, string comb, int tar);
	void getInfo() const;

private:
	int tara; //tara
};

class Autocarro : public Veiculo
{
public:
	Autocarro(int year, int month, string comb, int max_lugares);
	void getInfo() const;

private:
	int capacidade;
};

class VeiculoNaoExistente
{
    string nome;
public:
    VeiculoNaoExistente(string name);
    string getNome() const;
};

#endif
