#include "CartaoPontos.h"

/**
*Construtor do Cart�o de Pontos.
*/
CartaoPontos::CartaoPontos(Cliente* c) : pontos(0), ativado(true), validade(VALIDADE), cliente(c), nServicos(0)
{

}

/**
*Retorna a quantidade de pontos disponivis no cart�o.
*/
int CartaoPontos::getPontos() const
{
	return pontos;
}

/**
*Retorna o estado de ativa��o do cart�o.
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
*Retorna o cliente a quem o cart�o pertence.
*/
Cliente* CartaoPontos::getCliente() const
{
	return cliente;
}

/**
*Adiciona um dado numero de pontos ao cart�o de pontos.
*/
void CartaoPontos::addPontos(int pontos)
{
	if (!ativado)
		ativado = true;
	this->pontos += pontos;
	nServicos++;
}

/**
*Caso um cliente seja desativado(ativacao=false), esta fun��o rep�e os seus pontos a zero. permite tambem reativa��o do cliente(ativacao=true).
*/
void CartaoPontos::setAtivacao(bool ativacao)
{
	ativado = ativacao;

	if (!ativado)
		pontos = 0;
}

/**
*Operador '<' para a correta ordena��o da priority_queue.
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