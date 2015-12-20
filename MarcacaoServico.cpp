#include "MarcacaoServico.h"

/**
*Construtor da classe MarcacaoServico
*/

MarcacaoServico::MarcacaoServico(int d, int m, int a, int h, Servico* s) : dia(d), mes(m), ano(a), hora(h), servico(s) {}

/**
*Operador < da classe MarcacaoServico. Retorna true se a data da primeira marcacao for menor a data da segunda e utiliza ordem alfabetica do nome do cliente associado para resolver casos de empate
*/

bool MarcacaoServico::operator<(const MarcacaoServico& m) const
{
    if(ano == m.getAno())
    {
        if(mes == m.getMes())
        {
            if(dia == m.getDia())
            {
                if(hora == m.getHora())
                {
                    return nomeCliente < m.getNomeCliente();
                }

                return hora < m.getHora();
            }

            return dia < m.getDia();
        }

        return mes < m.getMes();
    }

    return ano < m.getAno();
}

/**
*Retorna o ano da marcacao
*/

int MarcacaoServico::getAno() const
{
    return ano;
}

/**
*Retorna o dia da marcacao
*/

int MarcacaoServico::getDia() const
{
    return dia;
}

/**
*Retorna a hora da marcacao
*/

int MarcacaoServico::getHora() const
{
    return hora;
}

/**
*Retorna o mes da marcacao
*/

int MarcacaoServico::getMes() const
{
    return mes;
}

/**
*Retorna o servico associado a marcacao
*/

Servico* MarcacaoServico::getServico() const
{
    return servico;
}

/**
*Retorna o nome do cliente associado a marcacao
*/

string MarcacaoServico::getNomeCliente() const
{
    return nomeCliente;
}

/**
*Adia a marcacao 'd' dias
*/

void MarcacaoServico::adiaDias(int d)
{
    dia += d;

    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if(dia > 31)
        {
            d -= 31;

            if(mes == 12)
            {
                ano++;
                mes = 1;
            }
            else
            {
                mes++;
            }
        }
    }
    else if(mes == 2)
    {
        if(ano%4 == 0)
        {
            if(dia > 29)
            {
                dia -= 29;
                mes++;
            }
        }
        else
        {
            if(dia > 28)
            {
                dia -= 28;
                mes++;
            }
        }
    }
    else
    {
        if(dia > 30)
        {
            dia -= 30;
            mes++;
        }
    }
}

/**
*Operador de output para a classe MarcacaoServico
*/

ostream& operator<<(ostream& os, const MarcacaoServico& m)
{
    os << m.getNomeCliente() << "   " << m.getServico()->getNome() << "  " << m.getServico()->getPreco() << " " << m.getDia() << "/" << m.getMes() << "/" << m.getAno() << "  " << m.getHora() << "   " << m.getServico()->getDias();

    return os;
}
