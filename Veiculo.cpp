#include "Veiculo.h"
#include "Funcionario.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

Servico::Servico(string name, float price, int days) : nome(name), preco(price), terminado(false), dias(days) {}

bool Servico::estaTerminado() const
{
    return terminado;
}

string Servico::getName() const
{
    return nome;
}

float Servico::getPreco() const
{
    return preco;
}

int Servico::getDias() const
{
    return dias;
}

//VEICULO [ABSTRATA]
Veiculo::Veiculo(int year, int month, string comb)
{
	ano = year;
	mes = month;
	combustivel = comb;
}

void Veiculo::getInfo() const
{
	cout << "Ano: " << ano << "\nMes: " << mes << "\nCombustivel: " << combustivel << endl;
}

bool Veiculo::estaPronto()
{
    for(int i = 0; i < servicos.size(); i++)
    {
        if(!servicos[i].estaTerminado())
        {
            return false;
        }
    }

    return true;
}

float Veiculo::ofereceDesconto()
{
	float desconto = 0;

	if (servicos.size() == 9)		//só ao 10º serviço é que se oferecem descontos. O desconto é 25% da média do preço de todos os serviços que o veiculo ja efectuou
	{
		for (unsigned int i = 0; i < servicos.size(); i++)
			desconto += servicos[i].getPreco();

		desconto = (desconto / (float) 9.0) * (float) 0.25;
        servicos[8].desconto(desconto);
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

Motorizada::Motorizada(int year, int month, string comb, int cilindr) : Veiculo(year, month, comb), cilindrada(cilindr) {}

// MOTORIZADA (VEICULO)
void Motorizada::getInfo() const
{
	Veiculo::getInfo();
	cout << endl;
}

Camiao::Camiao(int year, int month, string comb, int tar) : Veiculo(year, month, comb), tara(tar) {}

//CAMIAO (VEICULO)
void Camiao::getInfo() const
{
	Veiculo::getInfo();
	cout << "Tara: " << tara << endl << endl;
}

Autocarro::Autocarro(int year, int month, string comb, int max_lugares) : Veiculo(year, month, comb), capacidade(max_lugares) {}

//AUTOCARRO (VEICULO)
void Autocarro::getInfo() const
{
	Veiculo::getInfo();
	cout << "Capacidade: " << capacidade << endl << endl;
}

void Veiculo::passaDias(int n)
{
    for(int i = 0; i < servicos.size(); i++)
    {
        servicos[i].passaDias(n);
    }
}

void Servico::passaDias(int n)
{
    dias += n;
}

void Veiculo::setFuncionario(Funcionario* f1)
{
    f = f1;
}

VeiculoNaoExistente::VeiculoNaoExistente(string name) : nome(name) {}

string VeiculoNaoExistente::getNome() const
{
    return nome;
}

void Servico::desconto(float d)
{
    preco -= d;
}
