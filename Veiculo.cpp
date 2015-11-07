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

/**
*Construtor da classe 'Servico'.
*/
Servico::Servico(string name, float price, int days) : nome(name), preco(price), terminado(false), dias(days) {}

/**
*Retorna o 'nome' do servico.
*/
string Servico::getNome() const
{
    return nome;
}

/**
*Retorna o 'preco' do sevico.
*/
float Servico::getPreco() const
{
    return preco;
}

/**
*Retorna o numero de 'dias' que o servico demora.
*/
int Servico::getDias() const
{
    return dias;
}

/**
*Subtrai 'n' dias aos 'dias' que o servico demora a ser realizado. Quando o numero de 'dias' e zero, o servico esta terminado.
*/
void Servico::passaDias(int n)
{
	dias -= n;
	if (dias <= 0)
	{
		dias = 0;
		terminado = true;
	}
}

/**
*Retorna o valor de verdade de 'terminado', ou seja, se o servico ja acabou ou nao.
*/
bool Servico::estaTerminado() const
{
	return terminado;
}

/**
*Overload do operador << do servico.
*/
ostream & operator<<(ostream &out, Servico s1)
{
	out << "Nome: " << s1.getNome() << ", preco: " << s1.getPreco() << ", dias: " << s1.getDias() << endl;
	return out;
}

/**
*Overload do operador == do servico.
*/
bool Servico::operator==(const Servico s1)
{
	if (nome == s1.getNome() && dias == s1.getDias() && preco == s1.getPreco())
		return true;

	return false;
}


/*###################
  #     VEICULO     #
  ###################
*/

/**
*Construtor da classe veiculo.
*/
Veiculo::Veiculo(int year, int month, string comb)
{
	ano = year;
	mes = month;
	combustivel = comb;
	id = next_id;

	next_id++;
}

/**
*Retorna o 'id' do veiculo.
*/
int Veiculo::getID() const
{
	return id;
}

/**
*Faz display da informacao do veiculo.
*/
void Veiculo::getInfo() const
{


	cout << "ID: " << id << ", ano: " << ano << ", mes: " << mes << ", combustivel: " << combustivel << ", status: ";

}

/**
*Associa o funcionario 'f1' ao veiculo.
*/
void Veiculo::setFuncionario(Funcionario *f1)
{
	f = f1;
}

/**
*Retorna verdade caso todos os servicos do veiculo estajam terminados, caso contrario, retorna falso.
*/
bool Veiculo::estaPronto()
{
    for(unsigned int i = 0; i < servicos.size(); i++)
    {
        if(!servicos[i].estaTerminado())
            return false;
    }

    return true;
}

/**
*Faz passar 'n' dias para todos os servicos do veiculo.
*/
void Veiculo::passaDias(int n)
{
	for (unsigned int i = 0; i < servicos.size(); i++)
		servicos[i].passaDias(n);
}

/**
*Adiciona o servico 's1' ao vector de servicos do veiculo.
*/
void Veiculo::adicionaServico(Servico s1)
{
	servicos.push_back(s1);
}

/**
*Retorna o vector de servicos do veiculo.
*/
vector<Servico> Veiculo::getServicos() const
{
	return servicos;
}

/**
*Caso o servico 's1' nao esteja acabado no veiculo, esse servico nao pode ser elimanado (funcao usada para eliminar o servico 's1' da oficina).
*/
bool Veiculo::veiculoUsaServico(Servico s1)
{
	for (unsigned int i = 0; i < servicos.size(); i++)		//Caso o servico que se quer eliminar nao esteja acabado num veiculo, não se pode eliminar
	{
		if (s1 == servicos[i] && !servicos[i].estaTerminado())
			return true;
	}

	return false;
}


/*###################
  #    AUTOMOVEL    #
  ###################
*/

/**
*Construtor da class derivada 'Automovel' (deriva de 'Veiculo').
*/
Automovel::Automovel(int year, int month, string comb, int seats) :
Veiculo(year, month, comb)
{
	lugares = seats;
}

/**
*Faz display da informacao do automovel.
*/
void Automovel::getInfo() const
{
	Veiculo::getInfo();
	cout << ", numero de lugares: " << lugares;

	cout << ", status: ";

	bool tudoPronto = true;

	for (unsigned int i = 0; i < servicos.size(); i++)
	{
		if (!servicos[i].estaTerminado())
			tudoPronto = false;
	}

	if (tudoPronto)
		cout << " REPARADO.";
	else
		cout << " A SER REPARADO.";

	cout << endl << "   Total de servicos requeridos: " << servicos.size();
}


/*###################
  #   MOTORIZADA    #
  ###################
*/

/**
*Construtor da class derivada 'Motorizada' (deriva de 'Veiculo').
*/
Motorizada::Motorizada(int year, int month, string comb, int cilindr) : Veiculo(year, month, comb), cilindrada(cilindr) {}

/**
*Faz display da informacao da motorizada.
*/
void Motorizada::getInfo() const
{
	Veiculo::getInfo();

	cout << ", status: ";

	bool tudoPronto = true;

	for (unsigned int i = 0; i < servicos.size(); i++)
	{
		if (!servicos[i].estaTerminado())
			tudoPronto = false;
	}

	if (tudoPronto)
		cout << " REPARADO.";
	else
		cout << " A SER REPARADO.";

	cout << endl << "   Total de servicos requeridos: " << servicos.size();
}


/*###################
  #     CAMIAO      #
  ###################
*/

/**
*Construtor da class derivada 'Camiao' (deriva de 'Veiculo').
*/
Camiao::Camiao(int year, int month, string comb, int tar) : Veiculo(year, month, comb), tara(tar) {}

/**
*Faz display da informacao do camiao.
*/
void Camiao::getInfo() const
{
	Veiculo::getInfo();
	cout << ", tara: " << tara;

	cout << ", status: ";

	bool tudoPronto = true;

	for (unsigned int i = 0; i < servicos.size(); i++)
	{
		if (!servicos[i].estaTerminado())
			tudoPronto = false;
	}

	if (tudoPronto)
		cout << " REPARADO.";
	else
		cout << " A SER REPARADO.";

	cout << endl << "   Total de servicos requeridos: " << servicos.size();
}


/*###################
  #    AUTOCARRO    #
  ###################
*/

/**
*Construtor da class derivada 'Autocarro' (deriva de 'Veiculo').
*/
Autocarro::Autocarro(int year, int month, string comb, int max_lugares) : Veiculo(year, month, comb), lugares(max_lugares) {}

/**
*Faz display da informacao do autocarro.
*/
void Autocarro::getInfo() const
{
	Veiculo::getInfo();
	cout << ", capacidade: " << lugares;

	cout << ", status: ";

	bool tudoPronto = true;

	for (unsigned int i = 0; i < servicos.size(); i++)
	{
		if (!servicos[i].estaTerminado())
			tudoPronto = false;
	}

	if (tudoPronto)
		cout << " REPARADO.";
	else
		cout << " A SER REPARADO.";

	cout << endl << "   Total de servicos requeridos: " << servicos.size();
}

/*###################
  #      ERROS      #
  ###################
*/

/**
*Contrutor da classe VeiculoNaoExistente.
*/
VeiculoNaoExistente::VeiculoNaoExistente(int i) : id(i) {}

/**
*Retorna o 'id' do veiculo.
*/
int VeiculoNaoExistente::getID() const
{
    return id;
}