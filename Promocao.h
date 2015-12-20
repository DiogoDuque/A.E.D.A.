#ifndef Promocao_h
#define Promocao_h

#include <ctime>
#include <vector>
#include "Veiculo.h"
#include "Cliente.h"
#include "Oficina.h"

class Promocao
{
public:
	Promocao(Servico servico1);
	int getNClientes() const { return nClientes; };
	int getPontos() const { return pontos; };
	float getDesconto() const { return desconto; };
	Servico getServico() const { return servico; };
	vector<Cliente*> getRejeitados() const { return rejeitados; };
	void addRejeitado(Cliente* cl) { rejeitados.push_back(cl); };
	int passaDias(int n);
	int validarPromo(Cliente* cliente);
	bool operator==(Promocao promo);

private:
	Servico servico;
	int nClientes; //nr de clientes que podem aceitar a promocao
	int pontos; //pontos a gastar para aceitar a promocao
	float desconto; //0.3 < desconto < 0.8
	int validade;
	vector<Cliente*> rejeitados; //clientes que escolheram rejeitar o servico
};


#endif