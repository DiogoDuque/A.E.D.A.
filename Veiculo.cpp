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

float Veiculo::ofereceDesconto()
{
	float desconto = 0;

	if (servicos.size() == 9)		//só ao 10º serviço é que se oferecem descontos. O desconto é 25% da média do preço de todos os serviços que o veiculo ja efectuou
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


// MOTORIZADA (VEICULO)
void Motorizada::getInfo() const
{
	Veiculo::getInfo();
	cout << endl;
}


//CAMIAO (VEICULO)
void Camiao::getInfo() const
{
	Veiculo::getInfo();
	cout << "Tara: " << tara << endl << endl;
}

//AUTOCARRO (VEICULO)
void Autocarro::getInfo() const
{
	Veiculo::getInfo();
	cout << "Capacidade: " << capacidade << endl << endl;
}