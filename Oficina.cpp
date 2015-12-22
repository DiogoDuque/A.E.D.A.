#include "Oficina.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include <windows.h>		//usado para o 'ENTER'
#include <cstdlib>			//usado para o 'ENTER'

using namespace std;

/**
*Construtor para a classe 'Oficina'.
*/
Oficina::Oficina(string myNomeOficina) : diaAtual(1), mesAtual(1), anoAtual(2015), horaAtual(8), marcacoes(BST<MarcacaoServico*>(new MarcacaoServico(0, 0, 0, 0, new Servico("", 0, 0), "", 0)))
{
	nomeOficina = myNomeOficina;

	//importar servicos
	ifstream file("servicos.txt");
	string s1, s2, s3;
	while (!file.eof())
	{
		getline(file, s1);
		file >> s2;
		file >> s3;
		Servico temp(s1, (float)stoi(s2), stoi(s3));
		getline(file, s1); //limpar '\n'
		servicos.push_back(temp);
	}
}

/**
*Retorna o nome da oficina.
*/
string Oficina::getNome() const
{
	return nomeOficina;
}

/**
*Retorna os veiculos da oficina.
*/
vector<Veiculo*> &Oficina::getVeiculos()
{
	return veiculos;
}

/**
*Retorna os clientes da oficina.
*/
vector<Cliente> &Oficina::getClientes()
{
	return clientes;
}

/**
*Retorna os funcionarios da oficina.
*/
vector<Funcionario*> Oficina::getFuncionarios() const
{
	return funcionarios;
}

/**
*Retorna os servicos da oficina.
*/
vector<Servico> Oficina::getServicos() const
{
	return servicos;
}

/**
*Adiciona o veiculo 'v' ao vector 'veiculos' da oficina.
*/
void Oficina::adicionaVeiculo(Veiculo *v)
{
	veiculos.push_back(v);
}

/**
*Adiciona o funcionario 'f' ao vector 'funcionarios' da oficina.
*/
void Oficina::adicionaFuncionario(Funcionario *f)
{
	funcionarios.push_back(f);
}

/**
*Adiciona o cliente 'c1' ao vector 'clientes' da oficina.
*/
void Oficina::adicionaCliente(Cliente cl)
{
	clientes.push_back(cl); //cliente adicionado ao vetor de clientes
	cartoes.push(cl.getCartaoCliente()); //cartao adicionado à pr_queue de cartoes
}

/**
*Adiciona o servico 's1' ao vector 'servicos' da oficina.
*/
void Oficina::adicionaServico(Servico s1)
{
	servicos.push_back(s1);
}

/**
*Remove o veiculo 'v' do vector de veiculos da oficina, assim como do vector veiculos do cliente.
*/
void Oficina::removeVeiculo(int posVeiculo)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
		clientes[i].removeVeiculo(veiculos[posVeiculo]);

	veiculos.erase(veiculos.begin() + posVeiculo);
}

/**
*Remove o funcionario 'f1', e se 'f1' tiver veiculos associados, passa esse veiculos para o funcionario com menos veiculos (o funcionario que esta menos ocupado).
*/
void Oficina::removeFuncionario(Funcionario *f1)
{
	bool eliminou = false;

	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i] == f1)
		{
			if (funcionarios[i]->getVeiculos().size() != 0)		//se o funcionario tiver veiculos a seu cargo, passa-los para outros funcionarios
			{
				for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size(); j++)
					funcionarios[funcionarioComMenosVeiculos()]->acrescentaVeiculos(funcionarios[i]->getVeiculos()[j]);
			}

			funcionarios.erase(funcionarios.begin() + i);
			eliminou = true;
			break;
		}
	}

	if (!eliminou)
	{
		cout << "O funcionario com o ID  nao existe..." << endl;
		throw(FuncionarioNaoExistente(f1->getID()));
	}
}

/**
*Remove o cliente 'c1' do vector 'clientes' da oficina (caso este exista). Se nao existir, lanca uma excecao.
*/
void Oficina::removeCliente(Cliente cl)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].getNumRegisto() == cl.getNumRegisto())
		{
			clientes.erase(clientes.begin() + i);
			return;
		}
	}

	throw(ClienteNaoExistente(cl.getNome()));
}

/**
*Remove o servico que esta na posicao 'pos' do vector 'servicos' da oficina. No entanto, so da para remover caso o servico nao esteja a ser efectuado em nenhum veiculo, ou seja, so elimina o servico se nao houver veiculos que estao a ser reparados com aquele servico.
*/
bool Oficina::removeServico(int pos)
{
	bool podeEliminar = true;

	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i]->veiculoUsaServico(servicos[pos]))
			podeEliminar = false;
	}

	if (podeEliminar)
	{
		servicos.erase(servicos.begin() + pos);
		return true;
	}
	else
		return false;
}

/**
*Retorna o indice do funcionario com menos veiculos.
*/
int Oficina::funcionarioComMenosVeiculos() const
{
	int indice = -1;
	unsigned int numVeiculos = 1000;

	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i]->getVeiculos().size() < numVeiculos)
		{
			numVeiculos = funcionarios[i]->getVeiculos().size();
			indice = i;
		}
	}

	return indice;
}

/**
*Substrai 'n' dias a todos os servicos de todos os veiculos, à validade dos cartoes de pontos e das promocoes.
*Tambem pode causar notificacoes de promocoes.
*/
void Oficina::passaDias(int n)
{
	//gerar promocoes (possivelmente) ---- TO DO
	srand((unsigned int)time(NULL));
	if (rand() % 5 == 0) //gerar promo 1/5 das vezes que passam dias
	{
		int index = rand() % servicos.size();
		promocoes.push_back(Promocao(servicos[index]));
	}

	//update das validades das promos
	for (vector<Promocao>::iterator it = promocoes.begin(); it < promocoes.end(); it++)
	{
		int validade = it->passaDias(n);
		if (validade == 0)
		{
			promocoes.erase(it);
			it--;
		}
	}

	//update das validades dos cartoes de pontos
	vector<CartaoPontos*> temp;
	while (!cartoes.empty())
	{
		CartaoPontos* card = cartoes.top();
		cartoes.pop();
		card->passaDias(n);
		temp.push_back(card);

	}
	for (unsigned int i = 0; i < temp.size(); i++)
	{
		cartoes.push(temp[i]);
	}

	//
	BSTItrIn<MarcacaoServico*> i(marcacoes);

	while (!i.isAtEnd())
	{
		int x = i.retrieve()->getDia() - diaAtual;
		if (x >= 0)
		{
			i.retrieve()->getServico()->passaDias(x);
		}

		i.advance();
	}

	diaAtual += n;

	if (mesAtual == 1 || mesAtual == 3 || mesAtual == 5 || mesAtual == 7 || mesAtual == 8 || mesAtual == 10 || mesAtual == 12)
	{
		if (diaAtual > 31)
		{
			diaAtual -= 31;

			if (mesAtual == 12)
			{
				anoAtual++;
				mesAtual = 1;
			}
			else
			{
				mesAtual++;
			}
		}
	}
	else if (mesAtual == 2)
	{
		if (anoAtual % 4 == 0)
		{
			if (diaAtual > 29)
			{
				diaAtual -= 29;
				mesAtual++;
			}
		}
		else
		{
			if (diaAtual > 28)
			{
				diaAtual -= 28;
				mesAtual++;
			}
		}
	}
	else
	{
		if (diaAtual > 30)
		{
			diaAtual -= 30;
			mesAtual++;
		}
	}
}

/**
*Associa o veiculo 'v1' ao cliente 'c1'. Se o cliente 'c1' nao existe, lanca uma excecao.
*/
void Oficina::associaVeiculoCliente(Veiculo* v1, Cliente c1)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].getNumRegisto() == c1.getNumRegisto())
		{
			c1.addVeiculo(v1);
			return;
		}
	}

	throw(ClienteNaoExistente(c1.getNome()));
}

/**
*Faz o display dos funcionarios da empresa e dos veiculos que cada um tem associados.
*/
void Oficina::showInfo() const
{
	if (funcionarios.size() == 0)
	{
		throw(OficinaNaoTemFuncionarios());
	}

	cout << "   FUNCIONARIOS EXISTENTES NA EMPRESA RESPONSAVEIS PELOS AUTOMOVEIS ACTUALMENTE:" << endl << endl;

	for (unsigned int i = 0; i < funcionarios.size(); i++) //percorre a lista de funcionarios
	{
		cout << "   " << i + 1 << ". " << funcionarios[i]->getNome() << endl;
		cout << "     Veiculos a seu cargo: " << endl;

		for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size(); j++)
		{
			cout << "      - Veiculo " << j + 1 << ": ";
			funcionarios[i]->getVeiculos()[j]->getInfo();
			cout << endl;
		}
	}
}

/**
*Funcao de comparacao de funcionarios (usada no sort).
*/
bool compFunc(Funcionario * &f1, Funcionario * &f2)
{
	return (f1->getNome() < f2->getNome());
}

/**
*Display da informacao dos funcionarios.
*/
void Oficina::showInfoFuncionarios() const
{
	for (unsigned int i = 0; i < funcionarios.size(); i++)
		cout << "   " << i + 1 << ". " << *funcionarios[i] << endl;;
}

/**
*Faz uma lista ordenada (de acordo com a funcao de ordenacao) dos funcionarios.
*/
void Oficina::listaFunc()
{
	if (funcionarios.size() == 0)
	{
		cout << "   Actualmente nao existem funcionarios contratados...";
		return;
	}

	sort(funcionarios.begin(), funcionarios.end(), compFunc);
	showInfoFuncionarios();
}

/**
*Funcao de comparacao de veiculos (usado no sort).
*/
bool compVeiculos(Veiculo * &v1, Veiculo * &v2)
{
	return (v1->getID() < v2->getID());
}

/**
*Display da informacao dos veiculos
*/
void Oficina::showInfoVeiculos() const
{
	for (unsigned int i = 0; i < veiculos.size(); i++)
	{
		cout << "   Veiculo '" << i + 1 << "'\n   ";
		veiculos[i]->getInfo();
		cout << endl << endl;
	}
}

/**
*Faz uma lista ordenada (de acordo com a funcao de ordenacao) dos veiculos.
*/
void Oficina::listaVeiculos()
{
	if (veiculos.size() == 0)
	{
		cout << "   Actualmente nao existem veiculos registados...";
		return;
	}

	sort(veiculos.begin(), veiculos.end(), compVeiculos);
	showInfoVeiculos();

}

/**
*Remove a associacao dos veiculos que ja estao tratados aos funcionarios.
*/
void Oficina::removeVeiculosTratados()
{
	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size(); j++)
		{
			if (funcionarios[i]->getVeiculos()[j]->estaPronto())
				funcionarios[i]->removeVeiculo(j);
		}
	}
}

/**
*Funcao de comparacao de clientes (usado no sort).
*/
bool compClientes(const Cliente &c1, const Cliente &c2)
{
	return (c1.getNome() < c2.getNome());
}

/**
*Faz o display da informacao dos clientes.
*/
void Oficina::showInfoClientes() const
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		cout << "   " << i + 1 << ". ";
		cout << clientes[i] << endl;
	}
}

/**
*Faz uma lista ordenada (de acordo com a funcao de ordenacao) dos clientes.
*/
void Oficina::listaClientes()
{
	if (clientes.size() == 0)
	{
		cout << "   Actualmente nao existem clientes registados...";
		return;
	}

	sort(clientes.begin(), clientes.end(), compClientes);
	showInfoClientes();
}

/**
*Funcao de comparacao dos servicos.
*/
bool compServicos(const Servico &s1, const Servico &s2)
{
	if (s1.getPreco() < s2.getPreco())
		return true;
	else
		if (s1.getPreco() > s2.getPreco())
			return false;
		else
			if (s1.getDias() < s2.getDias())
				return true;
			else
				if (s1.getDias() > s2.getDias())
					return false;
				else
					if (s1.getNome() < s2.getNome())
						return true;

	return false;
}

/**
*Faz o display da informacao dos servicos.
*/
void Oficina::showInfoServicos() const
{
	for (unsigned int i = 0; i < servicos.size(); i++)
		cout << "   " << servicos[i] << endl;
}

/**
*Faz uma lista ordenada (de acordo com a funcao de comparacao) dos servicos.
*/
void Oficina::listaServicos()
{
	if (servicos.size() == 0)
	{
		cout << "Actualmente, a oficina nao dispoe de quaisquer servicos...";
		return;
	}

	sort(servicos.begin(), servicos.end(), compServicos);
	showInfoServicos();
}

/**
*Adiciona o servico na posicao 'posServico' do vector servicos da oficina ao veiculo na posicao 'posVeiculo' do vector veiculos do cliente na posicao 'posCliente' do vector clientes da oficina, ou seja, adiciona mais um servico a um veiculo.
*/
void Oficina::adicionaServicoVeiculo(int posCliente, int posVeiculo, int posServico)
{
	clientes[posCliente].adicionaServicoVeiculo(veiculos[posVeiculo], servicos[posServico]);

	int indice = funcionarioComMenosVeiculos();
	veiculos[posVeiculo]->setFuncionario(funcionarios[indice]);
	funcionarios[indice]->acrescentaVeiculos(veiculos[posVeiculo]);
	marcacoes.insert(new MarcacaoServico(diaAtual + 1, mesAtual, anoAtual, 8, &servicos[posServico], clientes[posCliente].getNome(), veiculos[posVeiculo]->getID()));
}

/**
*Retorna 'falso' se existir algum funcionario a operar o veiculo na posicao 'posVeiculo' da oficina. Caso contrario retorna 'true'.
*/
bool Oficina::podeRemoverVeiculo(int posVeiculo) const
{
	for (unsigned int i = 0; i < funcionarios.size(); i++)
	{
		if (funcionarios[i]->verificaSeExiste(veiculos[posVeiculo]))
			return false;
	}

	return true;
}

/**
*Retorna a tabela de dispersao dos clientes inativos
*/
hashClientes Oficina::getClientesInativos() const
{
	return clientesInativos;
}

/**
*Faz uma listagem dos clientes inativos.
*/
void Oficina::listaClientesInativos()
{
	if (clientesInativos.empty())
	{
		cout << "   Actualmente nao existem clientes inativos...";
		return;
	}

	hashClientes::iterator itr = clientesInativos.begin();

	for (unsigned int i = 1; itr != clientesInativos.end(); i++, itr++)
	{
		cout << "   " << i << ". ";
		(*itr).displayInformacaoClienteInativo();
	}
}

/**
*Adiciona o cliente 'c' inativo a tabela de prioridades 'clientesInativos' de oficina
*/
void Oficina::adicionaClienteInativo(Cliente c)
{
	if (c.getInatividade())
		clientesInativos.insert(c);
}

/**
*Permite modificar elementos de um cliente, tais como o nome, morada, mail ou telefones
*/
void Oficina::actualizaClienteInativo(int numCliente, int numMudar)
{
	cin.ignore(1000, '\n');		//Tira o 'ENTER' do buffer

	hashClientes::iterator itr = clientesInativos.begin();

	for (int i = 0; i < numCliente; i++)
		itr++;

	Cliente c1 = (*itr);
	clientesInativos.erase(*itr);

	switch (numMudar)
	{
	case 1:		//Mudar nome
	{
		string novoNome;

		cout << "Introduza um novo nome: ";
		getline(cin, novoNome);

		c1.setNome(novoNome);

		cout << endl << "O nome foi alterado com sucesso!" << endl << endl;
		Sleep(1000);

		break;
	}
	case 2:		//Mudar morada
	{
		string novaMorada;

		cout << "Introduza uma nova morada: ";
		getline(cin, novaMorada);

		c1.setMorada(novaMorada);

		cout << endl << "A morada foi alterado com sucesso!" << endl << endl;
		Sleep(1000);

		break;
	}
	case 3:		//Mudar mail
	{
		string novoMail;

		cout << "Introduza um novo mail: ";
		getline(cin, novoMail);

		c1.setMail(novoMail);

		cout << endl << "O mail foi alterado com sucesso!" << endl << endl;
		Sleep(1000);

		break;
	}
	case 4:		//Mudar telefone
	{
		int indiceTelefone;
		string novoTelefone;

		c1.showAllTelefones();
		cout << "Introduza o indice do telefone que deseja mudar: ";
		cin >> indiceTelefone;

		cin.ignore(1000, '\n');		//Tira o 'ENTER' do buffer

		cout << "Introduza o novo numero de telefone: ";
		getline(cin, novoTelefone);

		c1.setTelefone(novoTelefone, indiceTelefone);

		cout << endl << "O telefone foi alterado com sucesso!" << endl << endl;
		Sleep(1000);

		break;
	}
	default: break;
	}

	clientesInativos.insert(c1);
}

/**
*Permite adicionar elementos a um cliente (neste caso novos telefones).
*/
void Oficina::adicionaInformacao(int numCliente, int numMudar)
{
	cin.ignore(1000, '\n');		//Tira o 'ENTER' do buffer

	hashClientes::iterator itr = clientesInativos.begin();

	for (int i = 0; i < numCliente; i++)
		itr++;

	Cliente c1 = (*itr);
	clientesInativos.erase(*itr);

	switch (numMudar)
	{
	case 1:
	{
		string novoTelefone;

		cout << "Introduza um numero de telefone para adicionar: ";
		getline(cin, novoTelefone);

		c1.addTelefone(novoTelefone);

		cout << endl << "O telefone foi adicionado com sucesso!" << endl << endl;
		Sleep(1000);

		break;
	}
	default: break;
	}

	clientesInativos.insert(c1);
}

/**
*Atualiza a inatividade do cliente (a posição do cliente é dada no parametro) para false (ou seja, deixa de ser inativo), e elimina esse cliente da tabela de dispersão.
*/
void Oficina::actualizaInatividadeCliente(int posCliente)
{
	if (clientes[posCliente].getInatividade())
	{
		clientes[posCliente].setInatividade(false);
		clientes[posCliente].setInatividadeCartao(false);

		clientes[posCliente].resetContagemDiasInativos();

		hashClientes::iterator itr = clientesInativos.find(clientes[posCliente]);

		if (itr != clientesInativos.end())
			clientesInativos.erase(itr);
	}
}

/**
*Faz uso dos iteradores para procurar o cliente de nome 'nomeCliente'.
*/
void Oficina::pesquisaClienteInativo(string nomeCliente)
{
	Cliente c1(nomeCliente);
	hashClientes::iterator itr = clientesInativos.find(c1);

	if (itr != clientesInativos.end())
	{
		cout << endl << "   O cliente '" << nomeCliente << "' foi encontrado!" << endl << endl << "     ";

		(*itr).displayInformacaoClienteInativo();
		return;
	}
	else
		cout << endl << "   O cliente '" << nomeCliente << "' nao foi encontrado!" << endl;
}

/**
*Pesquisa no vetor de clientes ativos aqueles que têm mais de 365 dias de inatividade. Caso isso se verifique, o cliente e inserido na tabela de dispersao dos clientes inativos.
*/
void Oficina::avancaDiasParaClientes(int diasAvancar)
{
	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		clientes[i].adicionaDiasInativos(diasAvancar);

		if (clientes[i].getContagemDiasInativos() > 365)
		{
			clientes[i].setInatividade(true);
			clientesInativos.insert(clientes[i]);
		}
	}
}

/**
*Retorna a arvore de marcacoes
*/

BST<MarcacaoServico*> Oficina::getMarcacoes() const
{
	return marcacoes;
}

/**
*Retorna uma marcacao dado o seu servico, a data, hora e o nome do cliente associado
*/
MarcacaoServico* Oficina::getMarcacao(Servico* s, int ano, int mes, int dia, int hora, string nome)
{
	BSTItrIn<MarcacaoServico*> i(marcacoes);

	while (!i.isAtEnd())
	{
		if (i.retrieve()->getNomeCliente() == nome && i.retrieve()->getAno() == ano && i.retrieve()->getMes() == mes && i.retrieve()->getDia() == dia && i.retrieve()->getHora() == hora && i.retrieve()->getServico() == s)
		{
			return i.retrieve();
		}

		i.advance();
	}

	return NULL;
}

/**
*Cancela uma marcacao
*/
void Oficina::cancelaMarcacao(MarcacaoServico* m)
{
    if(m == NULL)
    {
        cout << "Introduza um numero valido" << endl;
        return;
    }

    string nome = m->getNomeCliente();
    int id = m->getIDVeiculo();
    string nomeServico = m->getServico()->getNome();

    for(unsigned int i = 0; i < clientes.size(); i++)
    {
        if(nome == clientes[i].getNome())
        {
            for(unsigned int j = 0; j < clientes[i].getVeiculos().size(); j++)
            {
                if(clientes[i].getVeiculos()[j]->getID() == id)
                {
                    for(int k = 0; k < clientes[i].getVeiculos()[j]->getServicos().size(); k++)
                    {
                        if(clientes[i].getVeiculos()[j]->getServicos()[k].getNome() == nomeServico)
                        {
                            clientes[i].getVeiculos()[j]->removeServico(k);
                            break;
                        }
                    }

                    break;
                }
            }

            break;
        }
    }

	marcacoes.remove(m);

	cout << "O cancelamento da sua marcacao foi efetuado com sucesso" << endl;
}

/**
*Remarca uma dada marcacao para outra data
*/
void Oficina::remarcaMarcacao(MarcacaoServico* m, int dias)
{
    if(m == NULL)
    {
        cout << "Introduza um numero valido" << endl;
        return;
    }

	m->adiaDias(dias);

    cout << "A sua remarcacao foi efetuada com sucesso" << endl;
}

/**
*Lista todas as marcacoes por ordem crescente de data e, em caso de igualdade, por ordem alfabetica dos nomes dos clientes associados
*/
void Oficina::listaMarcacoes()
{
	BSTItrIn<MarcacaoServico*> i(marcacoes);

	int j = 1;

	while (!i.isAtEnd())
	{
		cout << j << ". " << *(i.retrieve()) << endl;
		j++;

		i.advance();
	}

	if(j == 1)
    {
        cout << "Nao ha de momento marcacoes" << endl;
    }
}

/**
*Retorna uma marcacao a partir de um nome e um numero
*/
MarcacaoServico* Oficina::getMarcacao(string nome, int id)
{
    BSTItrIn<MarcacaoServico*> i(marcacoes);

	int j = 1;

	while (!i.isAtEnd())
	{
		if (i.retrieve()->getNomeCliente() == nome)
		{
			if (j == id)
			{
				return i.retrieve();
			}

			j++;
		}

		i.advance();
	}

	return NULL;
}

/**
*Lista marcacoes de um dado cliente
*/
void Oficina::listaMarcacoesDeCliente(string nome)
{
    BSTItrIn<MarcacaoServico*> i(marcacoes);

	int j = 1;

	while (!i.isAtEnd())
	{
	    if(i.retrieve()->getNomeCliente() == nome)
		{
		    cout << j << ". " << *(i.retrieve()) << endl;
            j++;
		}

		i.advance();
	}

	if(j == 1)
    {
        cout << "Este cliente nao tem marcacoes" << endl;
    }
}

/**
*Adiciona uma marcacao a arvore
*/
void Oficina::adicionaMarcacao(MarcacaoServico* m)
{
    marcacoes.insert(m);
}

/**
*Retorna o ano atual
*/
int Oficina::getAnoAtual() const
{
    return anoAtual;
}

/**
*Retorna o dia atual
*/
int Oficina::getDiaAtual() const
{
    return diaAtual;
}

/**
*Retorna o mes atual
*/
int Oficina::getMesAtual() const
{
    return mesAtual;
}

/**
*Retorna a hora atual
*/
int Oficina::getHoraAtual() const
{
    return horaAtual;
}

/**
*Retorna um vector com apontadores para os clientes que poderao, no momento, usufruir da promocao.
*/
vector<Cliente*> Oficina::getSorteados(Promocao promo)
{
	vector<Cliente*> sorteados;
	vector<Cliente*> rejeitados;

	int max = promo.getNClientes();

	//retirar clientes da queue de cartoes para inserir no vetor
	while (!cartoes.empty())
	{
		if (sorteados.size() == max) //verifica nr maximo de sorteados
			break;

		CartaoPontos* card = cartoes.top();
		cartoes.pop();
		if (promo.getPontos() > card->getPontos()) //verifica se tem pontos suficientes
		{
			cartoes.push(card);
			break;
		}

		//retirar da queue e por no rejeitados ou sorteados
		bool rejeitado = false;
		for (unsigned int i = 0; i < promo.getRejeitados().size(); i++)
		{
			if (card->getCliente() == promo.getRejeitados()[i])
			{
				rejeitado = true;
				break;
			}
		}

		if (rejeitado)
			rejeitados.push_back(card->getCliente());
		else sorteados.push_back(card->getCliente());

	}

	//reinserir clientes na queue
	for (unsigned int i = 0; i < sorteados.size(); i++)
		cartoes.push(sorteados[i]->getCartaoCliente());
	for (unsigned int i = 0; i < rejeitados.size(); i++)
		cartoes.push(rejeitados[i]->getCartaoCliente());

	return sorteados;
}

/**
*Remove uma promocao do vector de promocoes
*/
void Oficina::removePromocao(Promocao promo)
{
	for (unsigned int i = 0; i < promocoes.size(); i++)
	{
		if (promo == promocoes[i])
		{
			promocoes.erase(promocoes.begin() + i);
			break;
		}
	}

}

/**
*Retorna um vetor com os nomes dos servicos a que as promocoes se referem.
*/
vector<string> Oficina::getListaPromocoes()
{
	vector<string> promos;
	for (unsigned int i = 0; i < promocoes.size(); i++)
	{
		promos.push_back(promocoes[i].getServico().getNome());
	}
	return promos;
}

/**
*Retorna o vetor dos nomes dos clientes que, no momento, podem aceder a uma dada promocao.
*/
vector<string> Oficina::getSorteadosString(Promocao promo)
{
	vector<Cliente*> temp = this->getSorteados(promo);
	vector<string> sorteados;
	for (unsigned int i = 0; i < temp.size(); i++)
	{
		sorteados.push_back(temp[i]->getNome());
	}
	return sorteados;
}

/**
*Retorna por referencia a promocao com indice 'i' no vector de promocoes.
*/
Promocao& Oficina::getPromoByIndex(int i)
{
	return promocoes[i];
}