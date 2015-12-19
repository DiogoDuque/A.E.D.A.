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

Cliente* CartaoPontos::getCliente() const
{
	return cliente;
}

void CartaoPontos::mudaEstadoAtivacao()
{
	if (ativado)
		ativado = false;
	else
		ativado = true;
}

void CartaoPontos::addPontos(int pontos)
{
	this->pontos += pontos;
	nServicos++;
}

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
	if (nServicos > card->getNServicos())
		return false;
}