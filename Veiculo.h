#ifndef Veiculo_h
#define Veiculo_h

#include <string>
#include <vector>

using namespace std;

struct Servico
{
	string nome;
	float preco;
};

class Veiculo
{
public:
	Veiculo(int year, int month, string comb, Funcionario *f1); //especificar o tipo de servico. caso nao conheca o servico, pede preco
	virtual void getInfo() const;
	bool estaPronto();
	int ofereceDesconto();
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
	Automovel(int year, int month, string comb, Funcionario *f, int seats);
	void getInfo() const;

private:
	int lugares;
};

class Motorizada : public Veiculo
{
public:
	Motorizada();
	void getInfo() const;

private:
	int cilindrada;
};

class Camiao : public Veiculo
{
public:
	Camiao(int tara);
	void getInfo() const;

private:
	int tara; //tara????
};

class Autocarro : public Veiculo
{
public:
	Autocarro();
	void getInfo() const;

private:
	int capacidade;
};


#endif
