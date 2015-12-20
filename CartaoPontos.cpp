#include "CartaoPontos.h"

/**
*Construtor do Cartão de Pontos.
*/
CartaoPontos::CartaoPontos(Cliente* c) : pontos(0), ativado(true), validade(VALIDADE), cliente(c), nServicos(0)
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
void CartaoPontos::addPontos(int pontos)
{
	if (!ativado)
		ativado = true;
	this->pontos += pontos;
	nServicos++;
}

/**
*Caso um cliente seja desativado(ativacao=false), esta função repõe os seus pontos a zero. permite tambem reativação do cliente(ativacao=true).
*/
void CartaoPontos::setAtivacao(bool ativacao)
{
	ativado = ativacao;

	if (!ativado)
		pontos = 0;
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