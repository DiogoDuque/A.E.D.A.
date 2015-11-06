#include "Veiculo.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int Veiculo::next_id = 1;


/*###################
  #     SERVICO     #
  ###################
*/
Servico::Servico(string name, float price, int days) : nome(name), preco(price), terminado(false), dias(days) {}

string Servico::getNome() const
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

void Servico::passaDias(int n)
{
	dias -= n;
	if (dias < 0)
		dias = 0;
}

bool Servico::estaTerminado() const
{
	return terminado;
}

void Servico::desconto(float d)
{
	preco -= d;
}


/*###################
  #     VEICULO     #
  ###################
*/
Veiculo::Veiculo(int year, int month, string comb)
{
	ano = year;
	mes = month;
	combustivel = comb;
	id = next_id;

	next_id++;
}

int Veiculo::getID() const
{
	return id;
}

void Veiculo::getInfo() const
{
	cout << "ID: " << id << ", ano: " << ano << ", mes: " << mes << ", combustivel: " << combustivel;
}

void Veiculo::setFuncionario(Funcionario *f1)
{
	f = f1;
}

bool Veiculo::estaPronto()
{
    for(unsigned int i = 0; i < servicos.size(); i++)
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

void Veiculo::passaDias(int n)
{
	for (unsigned int i = 0; i < servicos.size(); i++)
	{
		servicos[i].passaDias(n);
	}
}

void Veiculo::apresenta() const //JUST FOR DEBUGGING
{
	cout << f->getNome() << endl;
}

void Veiculo::adicionaServico(Servico s1)
{
	servicos.push_back(s1);
}

vector<Servico> Veiculo::getServicos() const
{
	return servicos;
}


/*###################
  #    AUTOMOVEL    #
  ###################
*/
Automovel::Automovel(int year, int month, string comb, int seats) :
Veiculo(year, month, comb)
{
	lugares = seats;
}

void Automovel::getInfo() const
{
	Veiculo::getInfo();
	cout << ", numero de lugares: " << lugares;
}


/*###################
  #   MOTORIZADA    #
  ###################
*/
Motorizada::Motorizada(int year, int month, string comb, int cilindr) : Veiculo(year, month, comb), cilindrada(cilindr) {}

void Motorizada::getInfo() const
{
	Veiculo::getInfo();
}


/*###################
  #     CAMIAO      #
  ###################
*/
Camiao::Camiao(int year, int month, string comb, int tar) : Veiculo(year, month, comb), tara(tar) {}

void Camiao::getInfo() const
{
	Veiculo::getInfo();
	cout << ", tara: " << tara;
}


/*###################
  #    AUTOCARRO    #
  ###################
*/
Autocarro::Autocarro(int year, int month, string comb, int max_lugares) : Veiculo(year, month, comb), lugares(max_lugares) {}

void Autocarro::getInfo() const
{
	Veiculo::getInfo();
	cout << ", capacidade: " << lugares;
}

/*###################
  #      ERROS      #
  ###################
*/
VeiculoNaoExistente::VeiculoNaoExistente(int i) : id(i) {}

int VeiculoNaoExistente::getID() const
{
    return id;
}