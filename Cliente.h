#ifndef Cliente_h
#define Cliente_h

#include "Veiculo.h"

using namespace std;

class Cliente
{
public:
	Cliente(string nome);

	int getNumRegisto() const;
	string getNome() const;
	vector<Veiculo *> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo(Veiculo *v1);
	bool operator <(const Cliente& cl) const;

private:
	static int clienteID;
	string nome;
	int numRegisto;
	vector<Veiculo *> veiculos;
};

ostream & operator<<(ostream &out, const Cliente &v1);

/**
*Classe que funciona como uma excecao quando um determinado cliente nao existe.
*/
class ClienteNaoExistente
{
    string nome;
public:
	/**
	*Contrutor para a classe ClienteNaoExistente
	*/
	ClienteNaoExistente(string name) { nome = name; };
	/**
	*Retorna o nome do cliente
	*/
	string getNome() const { return nome; };
};

#endif
