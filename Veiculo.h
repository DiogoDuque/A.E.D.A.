#ifndef Veiculo_h
#define Veiculo_h

#include "Funcionario.h"
#include <vector>
#include <string>

using namespace std;

class Funcionario; //necessario visto que Veiculo e Funcionario sao interdependentes

class Servico
{
	string nome;
	float preco;
	bool terminado;
	int dias;
public:
    Servico(string name, float price, int days);
    bool estaTerminado() const;
    string getNome() const;
    float getPreco() const;
    int getDias() const;
    void passaDias(int n);
    void desconto(float d);
};

class Veiculo
{
public:
	Veiculo(int year, int month, string comb); //especificar o tipo de servico. caso nao conheca o servico, pede preco
	void setFuncionario(Funcionario *f1); //TO DO!
	virtual void getInfo() const;
	bool estaPronto();
	float ofereceDesconto();
	void passaDias(int n);
    int getID() const;
	void apresenta() const;
protected:
    int id;
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
	int lugares;
};

class VeiculoNaoExistente
{
    int id;
public:
    VeiculoNaoExistente(int i);
    int getID() const;
};

#endif
