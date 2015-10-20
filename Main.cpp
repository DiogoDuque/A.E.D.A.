#include "Others.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>

using namespace std;

/*
int clienteJaExiste(string nome, unsigned int n_cliente, Oficina ofi)
{
for (int i = 0; i < ofi.getClientes().size(); i++)
{
if (ofi.getClientes[i].getNome() == nome && ofi.getClientes[i].getID() == n_cliente)
return i;
}

return -1;
}

int main()
{
	Oficina oficina("Duque do Zé");
	//Registar novo cliente
	string nome;
	unsigned int n_cliente;

	cout << "Introduza o seu nome: ";
	getline(cin, nome);
	cout << "Introduza o seu numero de cliente: ";
	cin >> n_cliente;

	clienteJaExiste(nome, n_cliente, oficina);

	oficina.clientes.push_back(cl);
}

IDEIAS


- Oferecer descontos

- Impor taxa de permanencia de veiculos apos o tempo de reparos

- Software para clientes e outro para a empresa

- Adicionar hierarquias aos trabalhadores (mecanico, executivo)

- Adicionar salarios aos trabalhadores


*/

void intro()
{
	vector <string> oficina, carro;
	//0-6
	oficina.push_back("                                                            _______________________________\n");
	oficina.push_back("                                                           /                               \\\n");
	oficina.push_back("                                                          /                                 \\\n");
	oficina.push_back("                                                         /                                   \\\n");
	oficina.push_back("                                                        /_____________________________________\\\n");
	oficina.push_back("                                                        \\        |                 |          |\n");
	oficina.push_back("                                                         \\__     |  O F I C I N A  |          |\n");
	//7-10
	oficina.push_back("                                                            |    |_________________|          |\n");
	oficina.push_back("                                                            |                            __   |\n");
	oficina.push_back("                                                            |                           | .|  |\n");
	oficina.push_back("____________________________________________________________|___________________________|__|__|\n");

	//max 19 chars
	carro.push_back("     ________");
	carro.push_back(" ___//__][__\\\\____");
	carro.push_back(" |o  _   |-  | _ o)");
	carro.push_back("_`--(_)-------(_)'");

	gotoxy(10, 20);
	cout << "Projeto realizado por: *****";

	//disp oficina
	gotoxy(0, 5);
	for (unsigned int h = 0; h < oficina.size(); h++)
		cout << oficina[h];

	//viagem do carro
	for (int i = 0; i < 60; i++)
	{
		time_t t;

		for (int j = 0; j < 4; j++)
		{
			if (i >= 42) //quando o carro comecar a entrar na garagem, comeca a desaparecer a parte da frente
				if (carro[j].size() > 60 - i) //se esta string for comprida demais, é cortada para nao se sobrepor à oficina
					carro[j].pop_back();

			gotoxy(0 + i, 12 + j);
			cout << carro[j];
			t = clock();
		}

		while (clock() - t < 90) //pausa entre frames
		{}
	}
	gotoxy(0, 0);
}

int main()
{
	intro();
	return 0;
}