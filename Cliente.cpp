#include "Cliente.h"

using namespace std;

int Cliente::clienteID = 1;

/**
*Contrutor de cliente.
*/
Cliente::Cliente(string myNome)
{
	nome = myNome;
	CartaoPontos* cartao = new CartaoPontos(this);
	numRegisto = clienteID;
	estaInativo = false;
	contagemDiasInativos = 0;

	clienteID++;
}

/**
*Retorna o numero de registo do cliente.
*/
int Cliente::getNumRegisto() const
{
	return numRegisto;
}

/**
*Retorna o nome do cliente.
*/
string Cliente::getNome() const
{
	return nome;
}

/**
*Retorna o vector dos veiculos associados ao cliente.
*/
vector<Veiculo *> Cliente::getVeiculos() const
{
	return veiculos;
}

/**
*Adiciona o veiculo 'v1' ao vector de veiculos do cliente.
*/
void Cliente::addVeiculo(Veiculo *v1)
{
	veiculos.push_back(v1);
}

/**
*Overload do operador << de cliente.
*/
ostream & operator<<(ostream &out, const Cliente &v1)
{
	out << v1.getNome() << ", ID = " << v1.getNumRegisto() << endl;
	out << "      Numero de veiculos associados: " << v1.getVeiculos().size();

	return out;
}

/**
*Overload do operador < de cliente.
*/
/*bool Cliente::operator<(const Cliente& cl) const
{
    return (nome < cl.getNome());
}*/

/**
*Remove o veiculo 'v1' do vector veiculos do cliente.
*/
void Cliente::removeVeiculo(Veiculo *v1)
{
	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i] == v1)
		{
			veiculos.erase(veiculos.begin() + i);
			return;
		}
	}
}

/**
*Adiciona o servico 's1' ao veiculo que se encontra na posicao 'posVeiculo' do vetor veiculos do cliente.
*/
void Cliente::adicionaServicoVeiculo(int posVeiculo, Servico s1)
{
	veiculos[posVeiculo]->adicionaServico(s1);
	cartao->addPontos(s1.getPreco() / CONVERSION_RATE); //atualizar cartao de pontos
}

/**
*Define um novo nome.
*/
void Cliente::setNome(string nome)
{
	this->nome = nome;
}

/**
*Define uma nova morada.
*/
void Cliente::setMorada(string morada)
{
	this->morada = morada;
}

/**
*Define um novo mail.
*/
void Cliente::setMail(string mail)
{
	this->mail = mail;
}

/**
*Define um novo telefone.
*/
void Cliente::setTelefone(string numTelefone, int indice)
{
	if (telefones.empty())
		telefones.push_back(numTelefone);
	else
		telefones[indice - 1] = numTelefone;
}

/**
*Definicao do operador menor para cliente (usado na tabela de dispersao).
*/
bool Cliente::operator<(const Cliente &c2) const
{
	if (nome > c2.getNome())
		return true;
	else
	if (nome < c2.getNome())
		return false;
	else
	if (numRegisto > c2.getNumRegisto())
		return true;

	return false;
}

/**
*Display das informacoes importantes relativamente a um cliente que esta inativo
*/
void Cliente::displayInformacaoClienteInativo() const
{
	if (!estaInativo)
		return;

	cout << nome << endl << "\t" << morada << endl << "\t" << mail << endl;

	for (unsigned int i = 0; i < telefones.size(); i++)
		cout << "\t" << telefones[i] << endl;

	cout << endl;
}

/**
*Muda o estado de inatividade do cliente de acordo com o argumento.
*/
void Cliente::setInatividade(bool inatividade)
{
	estaInativo = inatividade;
}

/**
*Retorna o valor de verdade ou falsidade do estado de inatividade.
*/
bool Cliente::getInatividade() const
{
	return estaInativo;
}

/**
*Reorna um apontador para o cartao do cliente.
*/
CartaoPontos* Cliente::getCartaoCliente() const
{
	return cartao;
}

/**
*Muda o estado de inatividade do cliente de acordo com o argumento.
*/
void Cliente::showAllTelefones() const
{
	for (unsigned int i = 0; i < telefones.size(); i++)
		cout << i + 1 << ". " << telefones[i] << endl;	
}

bool Cliente::operator ==(const Cliente & c1) const
{
	return nome == c1.getNome();
	//return (numRegisto == c1.getNumRegisto());
}

/**
*Adiciona um novo telefone ao cliente.
*/
void Cliente::addTelefone(string novoTelefone)
{
	telefones.push_back(novoTelefone);
}

void Cliente::setInatividadeCartao(bool inatividade)
{
	cartao->setAtivacao(inatividade);
}

/**
*Adiciona 'dias' a variavel 'contagemDiasUltimoServico'
*/
void Cliente::adicionaDiasInativos(int dias)
{
	contagemDiasInativos += dias;
}

void Cliente::resetContagemDiasInativos()
{
	contagemDiasInativos = 0;
}


int Cliente::getContagemDiasInativos() const
{
	return contagemDiasInativos;
}