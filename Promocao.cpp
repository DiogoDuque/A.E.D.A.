#include "Promocao.h"

using namespace std;


Promocao::Promocao(Servico servico1) :servico(servico1)
{
	srand((unsigned int)time(NULL));
	nClientes = rand() % 3 + 1;
	pontos = (int) floor(servico1.getPreco() / (rand() % 3 + 1));
	desconto = (float)(rand() % 6 + 3) / 10;
	validade = 60;
}

/**
*Subtrai n dias � validade da promocao. Retorna o prazo da mesma.
*/
int Promocao::passaDias(int n)
{
	validade -= n;
	if (validade <= 0)
		return 0;
	return validade;
}

/**
*Aplica a promocao ao cliente, retirando-lhe pontos do cartao.
*Retorna o nr de clientes a quem ainda se pode aplicar o desconto. se -1, o cliente nao tem pontos suficientes.
*/
int Promocao::validarPromo(Cliente* cliente)
{
	CartaoPontos* card(cliente->getCartaoCliente());
	if (card->getPontos() < pontos)
		return -1;
	cliente->getCartaoCliente()->subPontos(pontos);
	nClientes--;
	return nClientes;
}