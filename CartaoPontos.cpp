#include "CartaoPontos.h"

int VALIDADE = 365;

CartaoPontos::CartaoPontos() : pontos(0), ativado(true), validade(VALIDADE)
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
}

void CartaoPontos::setAtivacao(bool ativacao)
{
	ativado = ativacao;

	if (!ativado)
		pontos = 0;
}