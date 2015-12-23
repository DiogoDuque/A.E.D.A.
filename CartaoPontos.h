#ifndef CartaoPontos_h
#define CartaoPontos_h

#include "Cliente.h"

#define VALIDADE 365

class Cliente;

using namespace std;

class CartaoPontos
{
public:
	CartaoPontos(Cliente* c);
	int getPontos() const;
	bool getEstado() const;
	int getNServicos() const;
	Cliente* getCliente() const;
	void addPontos(int pts);
	void subPontos(int pts);
	void setAtivacao(bool ativacao);
	bool operator<(CartaoPontos card);
	void passaDias(int n);
	int getValidade() const;
private:
	Cliente* cliente;
	int pontos;
	int nServicos; //nr de servicos; incrementado no addPontos()
	bool ativado;
	int validade;	//Numero de dias restantes
};

#endif