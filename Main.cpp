#include "Others.h"
#include "Oficina.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>		//usado para o 'ENTER'
#include <cstdlib>			//usado para o 'ENTER'

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

IDEIAS


- Oferecer descontos

- Impor taxa de permanencia de veiculos apos o tempo de reparos

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

		for (unsigned int j = 0; j < 4; j++)
		{
			if (i >= 42) //quando o carro comecar a entrar na garagem, comeca a desaparecer a parte da frente
			if (carro[j].size() >(unsigned)60 - i) //se esta string for comprida demais, � cortada para nao se sobrepor � oficina
				carro[j].pop_back();

			gotoxy(0 + i, 12 + j);
			cout << carro[j];
			t = clock();
		}

		while (clock() - t < 80) //pausa entre frames
		{
		}
	}
	gotoxy(0, 0);
}

void despedeFuncionarios(vector <Funcionario> v)
{
	int temp;

	vector <string> nomes;

	for (unsigned int i = 0; i < v.size(); i++)
		nomes.push_back(v[i].getNome());

	temp = makeMenu("DESPEDIR FUNCIONARIOS", nomes);
}

void menuManager(Oficina oficina1)
{
	vector <int> options = { 0 }; //sera usado para se poder retroceder nos menus
	int temp;
	while (options.size() > 0)
	{
		switch (options.back())
		{
		case 0: //MENU PRINCIPAL 1-4
		{
					temp = makeMenu(oficina1.getNome(), { "Gestao de funcionarios", "Gestao de veiculos",
						"Gestao de clientes", "Mostrar informacao acerca da oficina" });
					if (temp == -1)
						options.pop_back();
					else options.push_back(1 + temp);
					break;
		}
		case 1: //GESTAO DE FUNCIONARIOS 5-6
		{
					temp = makeMenu("GESTAO DE FUNCIONARIOS", { "Empregar funcionario", "Despedir funcionario" });
					if (temp == -1)
						options.pop_back();
					else options.push_back(5 + temp);
					break;
		}
		case 2: //GESTAO DE VEICULOS 7-8
		{
					temp = makeMenu("GESTAO DE VEICULOS", { "Dar entrada a um veiculo", "Dar saida a um veiculo" });
					if (temp == -1)
						options.pop_back();
					else options.push_back(7 + temp);
					break;
		}
		case 3: //GESTAO DE CLIENTES 9-10
		{
					temp = makeMenu("GESTAO DE FUNCIONARIOS", { "Empregar funcionario", "Despedir funcionario" });
					if (temp == -1)
						options.pop_back();
					else options.push_back(9 + temp);
					break;
		}
		case 4: //MOSTRAR INFO
		{
					clrscr();
					oficina1.showInfo();
					pause();
					options.pop_back();
					break;
		}
		case 5: //FUNC - ADD
		{
					string nomeFunc;

					gotoxy(3, 0);
					cout << "EMPREGAR FUNCIONARIOS" << endl;

					gotoxy(3, 3);
					cout << "Introduza o nome do novo funcionario: ";
					getline(cin, nomeFunc);

					Funcionario f1(nomeFunc);
					oficina1.adicionaFuncionario(f1);

					gotoxy(3, 5);
					cout << "O funcionario " << nomeFunc << " foi adicionado com sucesso!" << endl;

					gotoxy(3, 7);
					cout << "PRIMA 'ENTER' PARA CONTINUAR";

					cin.ignore();

					//IMPLEMENTAR PARA NAO DAR PARA ESCREVER NADA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					if (GetAsyncKeyState(VK_RETURN))
					{
						options.pop_back();
						break;
					}
		}
		case 6:
		{
				  despedeFuncionarios();
		}
		default:
			break;
		}
	}
}

int main()
{
	//intro();
	clrscr();
	string nomeOficina;
	cout << "Nome da Oficina: ";
	getline(cin, nomeOficina);
	Oficina oficina1(nomeOficina);

	menuManager(oficina1);

	clrscr();
	return 0;
}

/*
void pause() --> avanca apos ENTER
void clrscr() --> meter so uma linha para apagar consola
*/