#ifndef Cliente_h
#define Cliente_h

#include "Veiculo.h"
#include "CartaoPontos.h"

#define CONVERSION_RATE (int)5 //por cada 5 euros, ganha 1 ponto
class CartaoPontos;

using namespace std;

class Cliente
{
public:
	Cliente(string myNome);

	int getNumRegisto() const;
	string getNome() const;
	vector<Veiculo *> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo(Veiculo *v1);
	bool operator<(const Cliente& cl) const;
	bool operator==(const Cliente & c1) const;
	void adicionaServicoVeiculo(Veiculo* veic, Servico s1);
	
	void setNome(string nome);
	void setMorada(string morada);
	void setMail(string mail);
	void setTelefone(string telefone, int indice);
	//bool operator<(const Cliente &c2);
	void displayInformacaoClienteInativo() const;
	void showAllTelefones() const;
	void setInatividade(bool inatividade);
	bool getInatividade() const;
	CartaoPontos* getCartaoCliente() const;
	void addTelefone(string novoTelefone);
	void setInatividadeCartao(bool inatividade);
	void adicionaDiasInativos(int dias);
	int getContagemDiasInativos() const;
	void resetContagemDiasInativos();

private:
	static int clienteID;
	string nome;
	int numRegisto;
	vector<Veiculo *> veiculos;

	string morada;
	string mail;
	vector<string> telefones;

	bool estaInativo;
	int contagemDiasInativos;
	CartaoPontos* cartao;

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
