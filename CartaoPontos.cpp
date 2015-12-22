#include "CartaoPontos.h"

/**
*Construtor do Cartão de Pontos.
*/
CartaoPontos::CartaoPontos(Cliente* c) : pontos(0), ativado(false), validade(0), cliente(c), nServicos(0)
{

}

/**
*Retorna a quantidade de pontos disponivis no cartão.
*/
int CartaoPontos::getPontos() const
{
	return pontos;
}

/**
*Retorna o estado de ativação do cartão.
*/
bool CartaoPontos::getEstado() const
{
	return ativado;
}

/**
*Retorna o numero de servicos efetuados com este cartao.
*/
int CartaoPontos::getNServicos() const
{
	return nServicos;
}

/**
*Retorna o cliente a quem o cartão pertence.
*/
Cliente* CartaoPontos::getCliente() const
{
	return cliente;
}

/**
*Adiciona um dado numero de pontos ao cartão de pontos.
*/
void CartaoPontos::addPontos(int pts)
{
	if (!ativado)
		ativado = true;
	validade = VALIDADE;
	pontos += pts;
	nServicos++;
}

/**
*Subtrai um dado numero de pontos ao cartão de pontos.
*/
void CartaoPontos::subPontos(int pts)
{
	pontos -= pts;
}

/**
*Caso um cliente seja desativado(ativacao=false), esta função repõe os seus pontos a zero. permite tambem reativação do cliente(ativacao=true).
*/
void CartaoPontos::setAtivacao(bool ativacao)
{
	if (ativacao == ativado)
		return;

	if (ativacao==false)
	{
		pontos = 0;
		validade = 0;
	}
	else validade = VALIDADE;

	ativado = ativacao;
}

/**
*Operador '<' para a correta ordenação da priority_queue.
*/
bool CartaoPontos::operator<(CartaoPontos* card)
{
	if (pontos < card->getPontos())
		return true;
	if (pontos > card->getPontos())
		return false;

	if (nServicos < card->getNServicos())
		return true;
	else return false;
}

/**
*Substrai n à validade do cartao, e pode modificar o estado de ativacao do cartao.
*/
void CartaoPontos::passaDias(int n)
{
	validade -= n;
	if (validade < 0)
	{
		validade = 0;
		setAtivacao(false);
	}
}

/**
*Retorna a validade dos pontos do cartao.
*/
int CartaoPontos::getValidade() const
{
	return validade;
}