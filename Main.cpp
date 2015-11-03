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
#include <sstream>

#define UP 72
#define DOWN 80
#define ENTER '\r'
#define ESC 27

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

void waitForEnter()
{
	cout << endl << endl << "   Prima 'ENTER' para continuar...";

	cin.ignore();

	if (GetAsyncKeyState(VK_RETURN))
		return;
}

void funcionariosNaoRegistados()
{
	gotoxy(3, 0); cout << "ATENCAO!";
	gotoxy(3, 2); cout << "Nao pode despedir funcionarios se nao ha funcionarios para despedir...";

	gotoxy(3, 4); waitForEnter();
}

void clientesNaoRegistados(int n)
{
	gotoxy(3, 0); cout << "ATENCAO!";
	gotoxy(3, 2);
	
	if (n == 0)
		 cout << "Para registar veiculos tem primeiro de se registar na base de dados.";
	if (n == 1)
		cout << "Para registar veiculos tem primeiro de haver clientes...";
	
	gotoxy(3, 4); cout << "Por favor, volte ao menu principal e selecione a opcao 'GESTAO DE CLIENTES'";

	gotoxy(3, 6); waitForEnter();
}

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
			if (carro[j].size() >(unsigned)60 - i) //se esta string for comprida demais, é cortada para nao se sobrepor à oficina
				carro[j].pop_back();

			gotoxy(0 + i, 12 + j);
			cout << carro[j];
		}
		t = clock();
		if (i >= 42)
			Beep(600, 25); //fazer beep

		while (clock() - t < 80) //pausa entre frames
		{
		}
	}
	gotoxy(0, 0);
}

int mostraClientes(Oficina oficina1, string frase)
{
	clrscr();

	gotoxy(3, 0);
	cout << frase;

	for (unsigned int i = 0; i < oficina1.getClientes().size(); i++)
	{
		gotoxy(3, 3 + i);
		cout << oficina1.getClientes()[i].getNome() << " - ID: " << oficina1.getClientes()[i].getNumRegisto();
	}

	gotoxy(0, 3);
	cout << "->";

	unsigned int input;
	int posicao = 0;

	while (true)
	{
		gotoxy(0, 3 + posicao);
		cout << "->";

		switch (input = _getch())
		{
		case ESC:
		{
					clrscr();
					return -1;
		}
		case ENTER:
		{
					  clrscr();
					  return posicao;
		}
		case UP:
		{
				   if (posicao > 0)
				   {
					   gotoxy(0, 3 + posicao);
					   cout << "   ";
					   posicao--;
				   }

				   break;
		}
		case DOWN:
		{
					 if (posicao < oficina1.getClientes().size() - 1)
					 {
						 gotoxy(0, 3 + posicao);
						 cout << "   ";
						 posicao++;
					 }

					 break;
		}
		default:
			break;
		}

	}

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
						"Gestao de clientes", "Mostrar informacao acerca da oficina" }, -1);
					if (temp == -1)
						options.pop_back();
					else options.push_back(1 + temp);
					break;
		}
		case 1: //GESTAO DE FUNCIONARIOS 5-6
		{
					temp = makeMenu("GESTAO DE FUNCIONARIOS", { "Empregar funcionario", "Despedir funcionario" }, -1);
					if (temp == -1)
						options.pop_back();
					else options.push_back(5 + temp);
					break;
		}
		case 2: //GESTAO DE VEICULOS 7-??
		{
					temp = makeMenu("GESTAO DE VEICULOS", { "Dar entrada a um veiculo", "Dar saida a um veiculo" }, -1);
					if (temp == -1)
						options.pop_back();
					else options.push_back(7 + temp);
					break;
		}
		case 3: //GESTAO DE CLIENTES ????
		{
					temp = makeMenu("GESTAO DE CLIENTES", { "Registar cliente", "Eliminar cliente" }, -1);
					if (temp == -1)
						options.pop_back();
					else options.push_back(10 + temp);
					break;
		}
		case 4: //MOSTRAR INFO
		{
					clrscr();

					try
					{
						oficina1.showInfo();
					}
					catch (OficinaNaoTemFuncionarios)
					{
						gotoxy(3, 0); cout << "Actualmente a oficina nao tem funcionarios...";
					}

					waitForEnter();
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

					Funcionario *f1 = new Funcionario(nomeFunc);
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
		case 6: //FUNC - DEL
		{
					clrscr();

					if (oficina1.getClientes().size() == 0)
					{
						funcionariosNaoRegistados();
						options.pop_back();
						break;
					}

					string IDFunc;

					cout << "Este sao os funcionarios que trabalham actualmente\nna empresa:" << endl << endl;

					for (unsigned int i = 0; i < oficina1.getFuncionarios().size(); i++)
						cout << i + 1 << ": " << oficina1.getFuncionarios()[i]->getNome() << " - ID: " << oficina1.getFuncionarios()[i]->getID() << endl;

					cout << "Qual deseja despedir (ID): ";
					getline(cin, IDFunc);

					/*De string para int*/
					istringstream ss(IDFunc);
					int intIDFunc;
					ss >> intIDFunc;

					oficina1.removeFuncionario(intIDFunc);
					break;
		}
		case 7: //VEIC - ADD
		{
					int temp;

					temp = makeMenu("ADICIONAR VEICULO", { "SIM", "NAO" }, 0);

					if (temp == -1)
						options.pop_back();
					else
						options.push_back(8 + temp);
					break;
		}
		case 8:		//Quando e a primeira vez que o cliente visita a oficina
		{
						clientesNaoRegistados(0);
						options.pop_back();

						break;
		}
		case 9:		//Quando o cliente ja e antigo
		{
						if (oficina1.getClientes().size() == 0)
						{
							clientesNaoRegistados(1);
							options.pop_back();

							break;
						}

						int posCliente = mostraClientes(oficina1, "SELECIONA O CLIENTE A QUE DESEJA ASSOCIAR O AUTOMOVEL");

						if (posCliente == -1)
						{
							options.pop_back();
							break;
						}

						string ano, mes, combustivel;
						int anoInt, mesInt;
						int tipoVeiculo = -1;

						gotoxy(3, 0);
						cout << "ADICIONAR VEICULO";

						gotoxy(3, 3);
						cout << "Introduza o ano do carro: ";
						getline(cin, ano);

						gotoxy(3, 4);
						cout << "Introduza o mes: ";
						getline(cin, mes);

						gotoxy(3, 5);
						cout << "Introduza o tipo de combustivel: ";
						getline(cin, combustivel);

						istringstream ss(ano);
						ss >> anoInt;
						istringstream ss2(mes);
						ss2 >> mesInt;

						gotoxy(3, 7);
						cout << "ESPECIFIQUE O TIPO DE VEICULO";

						gotoxy(0, 9);
						cout << "->";

						vector<string> veiculos = { "Automovel", "Motorizada", "Camiao", "Autocarro" };
						for (unsigned int i = 0; i < 4; i++)
						{
							gotoxy(3, 9 + 2 * i);
							cout << veiculos[i];
						}

						unsigned int input, selecao = 0;
						while (tipoVeiculo == -1)
						{
							gotoxy(0, 9 + 2 * selecao);
							cout << "->";

							switch (input = _getch())
							{
							case ESC:
							{
										options.pop_back();
										break;
							}
							case ENTER:
							{
										  tipoVeiculo = selecao;
										  break;
							}
							case UP:
							{
									   if (selecao > 0)
									   {
										   gotoxy(0, 9 + 2 * selecao);
										   cout << "  ";
										   selecao--;
									   }
									   break;
							}
							case DOWN:
							{
										 if (selecao < 3)
										 {
											 gotoxy(0, 9 + 2 * selecao);
											 cout << "  ";
											 selecao++;
										 }
										 break;
							}
							}
						}

						gotoxy(3, 19);

						switch (tipoVeiculo)
						{
						case 0:
						{
								  int numLugaresInt;
								  string numLugares;

								  cout << "Introduza o numero de lugares: ";
								  getline(cin, numLugares);

								  istringstream ss(numLugares);
								  ss >> numLugaresInt;

								  Veiculo *a1 = new Automovel(anoInt, mesInt, combustivel, numLugaresInt);
								  oficina1.adicionaVeiculo(a1);

								  int indice = oficina1.funcionarioComMenosVeiculos(-1);
								  a1->setFuncionario(oficina1.getFuncionarios()[indice]);
								  break;
						}
						case 1:
						{
								  int cilindradaInt;
								  string cilindrada;

								  cout << "Introduza a cilindrada: ";
								  getline(cin, cilindrada);

								  istringstream ss(cilindrada);
								  ss >> cilindradaInt;

								  Veiculo *a1 = new Motorizada(anoInt, mesInt, combustivel, cilindradaInt);
								  oficina1.adicionaVeiculo(a1);

								  int indice = oficina1.funcionarioComMenosVeiculos(-1);
								  a1->setFuncionario(oficina1.getFuncionarios()[indice]);
								  break;
						}
						case 2:
						{
								  int taraInt;
								  string tara;

								  cout << "Introduza a tara: ";
								  getline(cin, tara);

								  istringstream ss(tara);
								  ss >> taraInt;

								  Veiculo *a1 = new Camiao(anoInt, mesInt, combustivel, taraInt);
								  oficina1.adicionaVeiculo(a1);

								  int indice = oficina1.funcionarioComMenosVeiculos(-1);
								  a1->setFuncionario(oficina1.getFuncionarios()[indice]);
								  break;
						}
						case 3:
						{
								  int numLugaresInt;
								  string numLugares;

								  cout << "Introduza o numero de lugares: ";
								  getline(cin, numLugares);

								  istringstream ss(numLugares);
								  ss >> numLugaresInt;

								  Veiculo *a1 = new Autocarro(anoInt, mesInt, combustivel, numLugaresInt);
								  oficina1.adicionaVeiculo(a1);

								  int indice = oficina1.funcionarioComMenosVeiculos(-1);
								  a1->setFuncionario(oficina1.getFuncionarios()[indice]);
								  break;
						}
						}

						options.pop_back();
		}
		case 10:		//Registar cliente
		{
							string nome;

							gotoxy(3, 0);
							cout << "REGISTAR CLIENTE";

							gotoxy(3, 3);
							cout << "Introduza o nome do cliente: ";
							getline(cin, nome);

							Cliente c1(nome);
							oficina1.adicionaCliente(c1);

							gotoxy(3, 5);
							cout << "O cliente '" << nome << "' foi adicionado com sucesso!";
							
							waitForEnter();
							options.pop_back();
							
							break;
		}
		case 11:		//Remove cliente
		{
							if (oficina1.getClientes().size() == 0)
							{
								gotoxy(3, 0); cout << "REMOVE CLIENTE";
								gotoxy(3, 2); cout << "Actualmente, nao ha clientes registados na oficina...";
							
								waitForEnter();
								options.pop_back();
							}
							else
							{
								int posicao = mostraClientes(oficina1, "REMOVE CLIENTE");

								if (posicao == -1)
									options.pop_back();

								oficina1.removeCliente(oficina1.getClientes()[posicao]);
							}

							break;
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
	while (nomeOficina.size() < 3)
	{
		clrscr();
		cout << "Nome demasiado curto! Introduza um nome correto.\nNome da Oficina: ";
		getline(cin, nomeOficina);
	}
	Oficina oficina1(nomeOficina);

	menuManager(oficina1);

	clrscr();
	return 0;
}

/*
void pause() --> avanca apos ENTER
void clrscr() --> meter so uma linha para apagar consola
*/