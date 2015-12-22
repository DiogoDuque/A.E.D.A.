#include "CartaoPontos.h"

/**
*Construtor do Cart�o de Pontos.
*/
CartaoPontos::CartaoPontos(Cliente* c) : pontos(0), ativado(false), validade(0), cliente(c), nServicos(0)
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
void CartaoPontos::addPontos(int pts)
{
	if (!ativado)
		ativado = true;
	validade = VALIDADE;
	pontos += pts;
	nServicos++;
}

/**
*Subtrai um dado numero de pontos ao cart�o de pontos.
*/
void CartaoPontos::subPontos(int pts)
{
	pontos -= pts;
}

/**
*Caso um cliente seja desativado(ativacao=false), esta fun��o rep�e os seus pontos a zero. permite tambem reativa��o do cliente(ativacao=true).
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

/**
*Substrai n � validade do cartao, e pode modificar o estado de ativacao do cartao.
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