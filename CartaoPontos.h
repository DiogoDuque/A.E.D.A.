#ifndef CartaoPontos_h
#define CartaoPontos_h

#include "Cliente.h"

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
	void mudaEstadoAtivacao();
	void addPontos(int pontos);
	void setAtivacao(bool ativacao);
	bool operator<(CartaoPontos* card);
private:
	Cliente* cliente;
	int pontos;
	int nServicos; //nr de servicos; incrementado no addPontos()
	bool ativado;
	int validade;	//Numero de dias restantes
};

#endif