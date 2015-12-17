#include "CartaoPontos.h"

CartaoPontos::CartaoPontos() : pontos(0), ativado(true)
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

void CartaoPontos::estadoInativo()
{
	pontos = 0;
	ativado = false;
}