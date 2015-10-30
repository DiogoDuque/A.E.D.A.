#include "Veiculo.h"
#include "Funcionario.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

//VEICULO [ABSTRATA]
Veiculo::Veiculo(int year, int month, string comb)
{
	ano = year;
	mes = month;
	combustivel = comb;
	f = f1;
}

void Veiculo::getInfo() const
{
	cout << "Ano: " << ano << "\nMes: " << mes << "\nCombustivel: " << combustivel << endl;
}

bool Veiculo::estaPronto()
{
    for(int i = 0; i < servicos.size(); i++)
    {
        if(!servicos[i].terminado())
        {
            return false;
        }
    }

    return true;
}

float Veiculo::ofereceDesconto()
{
	float desconto = 0;

	if (servicos.size() == 9)		//s� ao 10� servi�o � que se oferecem descontos. O desconto � 25% da m�dia do pre�o de todos os servi�os que o veiculo ja efectuou
	{
		for (unsigned int i = 0; i < servicos.size(); i++)
			desconto += servicos[i].preco;

		desconto = (desconto / (float) 9.0) * (float) 0.25;
	}

	return desconto;
}


//AUTOMOVEL (VEICULO)
Automovel::Automovel(int year, int month, string comb, int seats) :
Veiculo(year, month, comb)
{
	lugares = seats;
}

void Automovel::getInfo() const
{
	Veiculo::getInfo();
	cout << "Numero de lugares: " << lugares << endl << endl;
}

Motorizada(int year, int month, string comb, int cilindr) : Veiculo(year, month, comb), cilindrada(cilindr) {}

// MOTORIZADA (VEICULO)
void Motorizada::getInfo() const
{
	Veiculo::getInfo();
	cout << endl;
}

Camiao(int year, int month, string comb, int tar) : Veiculo(year, month, comb), tara(tar) {}

//CAMIAO (VEICULO)
void Camiao::getInfo() const
{
	Veiculo::getInfo();
	cout << "Tara: " << tara << endl << endl;
}

Autocarro(int year, int month, string comb, int max_lugares) : Veiculo(year, month, comb), capacidade(max_lugares) {}

//AUTOCARRO (VEICULO)
void Autocarro::getInfo() const
{
	Veiculo::getInfo();
	cout << "Capacidade: " << capacidade << endl << endl;
}
