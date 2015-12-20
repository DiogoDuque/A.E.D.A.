#include "CartaoPontos.h"

int VALIDADE = 365;

CartaoPontos::CartaoPontos(Cliente* c) : pontos(0), ativado(true), validade(VALIDADE), cliente(c), nServicos(0)
{

}

int CartaoPontos::getPontos() const
{
	return pontos;
}

bool CartaoPontos::getEstado() const
{
	return ativado;
}

int CartaoPontos::getNServicos() const
{
	return nServicos;
}

Cliente* CartaoPontos::getCliente() const
{
	return cliente;
}

/**
*
*/
void CartaoPontos::mudaEstadoAtivacao()
{
	if (ativado)
		ativado = false;
	else
		ativado = true;
}


/**
*Adiciona um dado numero de pontos ao cartão de pontos.
*/
void CartaoPontos::addPontos(int pontos)
{
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