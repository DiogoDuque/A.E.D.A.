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
	//0-5
	oficina.push_back("                                                            _______________________________\n");
	oficina.push_back("                                                           /                               \\\n");
	oficina.push_back("                                                          /                                 \\\n");
	oficina.push_back("                                                         /                                   \\\n");
	oficina.push_back("                                                        /_____________________________________\\\n");
	oficina.push_back("                                                        \\        |                 |          |\n");
	//6-9
	oficina.push_back("                                                         \\__     |  O F I C I N A  |          |\n");
	oficina.push_back("                                                            |    |_________________|     __   |\n");
	oficina.push_back("                                                            |                           | .|  |\n");
	oficina.push_back("____________________________________________________________|___________________________|__|__|\n");

	//max 19 chars
	carro.push_back("     ________");
	carro.push_back(" ___//__][__\\\\____");
	carro.push_back(" |o  _   |-  | _ o)");
	carro.push_back("_`--(_)-------(_)'");

	//disp oficina
	gotoxy(0, 4);
	for (int h = 0; h < oficina.size(); h++)
		cout << oficina[h];

	//a parte da frente do carro comeca a aparecer
	for (int i = 0; i < 10; i++) //18 - indice do mais à frente do carro
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(0 + i, 10 + j);
			cout << carro[j];
		}
		//pausa por x tempo
	}
}

int main()
{
	intro();
	return 0;
}