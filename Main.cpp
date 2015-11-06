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
	gotoxy(3, 2); cout << "Para registar veiculos e necessario que haja funcionarios para os reparar..." << endl << "   Faca o favor de empregar alguem!";

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

void associarServicosVeiculos(Oficina oficina1, Veiculo *a1)
{
	vector<string> servicosString;
	for (unsigned int i = 0; i < oficina1.getServicos().size(); i++)
		servicosString.push_back(oficina1.getServicos()[i].getNome());

	int temp = makeMenu("ESCOLHER SERVICO", servicosString, "", 0);

	a1->adicionaServico(oficina1.getServicos()[temp]);
}

/**
*Animação inicial. É executada apenas uma vez no inicio do programa.
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

/**
*Ecrã mostrado quando um automóvel é criada.
*/
void anim_automovel()
{
	gotoxy(15, 5);
	cout << "        _......_";
	gotoxy(15, 6);
	cout << " , __.-'\\______\\\\'.______";
	gotoxy(15, 7);
	cout << " >`  '-`.--------'---`-`-`-.";
	gotoxy(15, 8);
	cout << "/    .-. \\________ \"\" .-.  =\\";
	gotoxy(15, 9);
	cout << "'---( o )------------( o )--'";
	gotoxy(15, 10);
	cout << "     '-'              '-'";
	gotoxy(55, 6);
	cout << "MENSAGEM: O seu automovel entrou na oficina e esta";
	gotoxy(55, 7);
	cout << "agora a ser arranjado pelos nossos melhores mecanicos.";
	gotoxy(0, 14);
	pause();
}

/**
*Ecrã mostrado quando uma mota é criada.
*/
void anim_mota()
{
	gotoxy(15, 5);
	cout << "         r==";
	gotoxy(15, 6);
	cout << "     _  //";
	gotoxy(15, 7);
	cout << "    |_)//(''''':";
	gotoxy(15, 8);
	cout << "      //  \\_____:_____.-----.P";
	gotoxy(15, 9);
	cout << "     //   | ===  |   /        \\";
	gotoxy(15, 10);
	cout << " .:'//.   \\ \\=|   \\ /  .:'':.";
	gotoxy(15, 11);
	cout << ":' // ':   \\ \\ ''..'--:'-.. ':";
	gotoxy(15, 12);
	cout << "'. '' .'    \\:.....:--'.-'' .'";
	gotoxy(15, 13);
	cout << " ':..:'                ':..:'";
	gotoxy(55, 7);
	cout << "MENSAGEM: A sua mota entrou na oficina e esta agora";
	gotoxy(55, 8);
	cout << "a ser arranjado pelos nossos melhores mecanicos.";
	gotoxy(0, 17);
	pause();
}

/**
*Ecrã mostrado quando um camião é criado.
*/
void anim_camiao()
{
	gotoxy(10, 5);
	cout << "         V   ~~~   ~~~   ~~~";
	gotoxy(10, 6);
	cout << "        _|_| |=========================|";
	gotoxy(10, 7);
	cout << "       (___| |                         |";
	gotoxy(10, 8);
	cout << "    __//__]| |                         |";
	gotoxy(10, 9);
	cout << "  >|:___ \'||\'|                         |";
	gotoxy(10, 10);
	cout << "   [/.-.\\= |-|.-._.-.===========.-._.-.=;";
	gotoxy(10, 11);
	cout << "   -|(o)|\\-~~|(o)|(o)\\~~''~''~~|(o)|(o)\\";
	gotoxy(10, 12);
	cout << "     \'-\'      \'-\' \'-\'           \'-\' \'-\'";
	gotoxy(60, 7);
	cout << "MENSAGEM: O seu camiao entrou na oficina e esta agora";
	gotoxy(60, 8);
	cout << "a ser arranjado pelos nossos melhores mecanicos.";
	gotoxy(0, 16);
	pause();
}

/**
*Ecrã mostrado quando um autocarro é criado.
*/
void anim_autocarro()
{
	gotoxy(15, 5);
	cout << " ______________________________";
	gotoxy(15, 6);
	cout << "/__  __  __  ___   ___   __   _\\";
	gotoxy(15, 7);
	cout << "|__)(__)|[]|(___) (___) |[]| (_|";
	gotoxy(15, 8);
	cout << "|       |  |            |  |   |";
	gotoxy(15, 9);
	cout << "[,-.____|__|____________|__|,-.]";
	gotoxy(15, 10);
	cout << " `-'                        `-'";
	gotoxy(55, 6);
	cout << "MENSAGEM: O seu autocarro entrou na oficina e esta";
	gotoxy(55, 7);
	cout << "agora a ser arranjado pelos nossos melhores mecanicos.";
	gotoxy(0, 14);
	pause();
}

//selecao --> 0 para clientes, 1 para funcionarios, 2 para veiculos
int mostraInfo(Oficina oficina1, string frase, int n)
{
	clrscr();

	gotoxy(3, 0);
	cout << frase;

	if (n == 0)
	for (unsigned int i = 0; i < oficina1.getClientes().size(); i++)
	{
		gotoxy(3, 3 + i * 2);
		cout << oficina1.getClientes()[i].getNome() << " - ID: " << oficina1.getClientes()[i].getNumRegisto();
	}

	if (n == 1)
	for (unsigned int i = 0; i < oficina1.getFuncionarios().size(); i++)
	{
		gotoxy(3, 3 + i * 2);
		cout << *oficina1.getFuncionarios()[i];
	}

	if (n == 2)
	for (unsigned int i = 0; i < oficina1.getVeiculos().size(); i++)
	{
		gotoxy(3, 3 + i * 2);
		oficina1.getVeiculos()[i]->getInfo();
		cout << endl;
	}

	gotoxy(0, 3);
	cout << "->";

	unsigned int input;
	unsigned int posicao = 0;

	while (true)
	{
		gotoxy(0, 3 + posicao * 2);
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
					   gotoxy(0, 3 + posicao * 2);
					   cout << "   ";
					   posicao--;
				   }

				   break;
		}
		case DOWN:
		{
					 if (n == 0)
					 {
						 if (posicao < oficina1.getClientes().size() - 1)
						 {
							 gotoxy(0, 3 + posicao * 2);
							 cout << "   ";
							 posicao++;
						 }
					 }
					 if (n == 1)
					 {
						 if (posicao < oficina1.getFuncionarios().size() - 1)
						 {
							 gotoxy(0, 3 + posicao * 2);
							 cout << "   ";
							 posicao++;
						 }
					 }
					 if (n == 2)
					 {
						 if (posicao < oficina1.getVeiculos().size() - 1)
						 {
							 gotoxy(0, 3 + posicao * 2);
							 cout << "   ";
							 posicao++;
						 }
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
						"Gestao de clientes", "Mostrar informacao acerca da oficina", "Avancar no tempo" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(1 + temp);
					break;
		}
		case 1: //GESTAO DE FUNCIONARIOS 5-6-7
		{
					temp = makeMenu("GESTAO DE FUNCIONARIOS", { "Empregar funcionario", "Despedir funcionario", "Listar funcionarios" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(5 + temp);
					break;
		}
		case 2: //GESTAO DE VEICULOS (8 - 11 - 12) 9 10
		{
					temp = makeMenu("GESTAO DE VEICULOS", { "Dar entrada a um veiculo", "Dar saida a um veiculo", "Listar Veiculos" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(8 + temp);
					break;
		}
		case 3: //GESTAO DE CLIENTES 11 - 12
		{
					temp = makeMenu("GESTAO DE CLIENTES", { "Registar cliente", "Eliminar cliente", "Listar clientes" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(13 + temp);
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

					while (nomeFunc.empty())
					{
						cout << endl << "   O funcionario tem de ter um nome!" << endl << "Por favor, volte a introduzir o nome: ";
						getline(cin, nomeFunc);
					}

					Funcionario *f1 = new Funcionario(nomeFunc);
					oficina1.adicionaFuncionario(f1);

					cout << endl << "   O funcionario '" << nomeFunc << "' foi adicionado com sucesso!" << endl;
					cout << endl << "   PRIMA 'ENTER' PARA CONTINUAR";

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
					if (oficina1.getFuncionarios().size() == 0)
					{
						gotoxy(3, 0); cout << "REMOVE FUNCIONARIO";
						gotoxy(3, 2); cout << "Actualmente, nao ha funcionarios a trabalhar na oficina...";
						waitForEnter();
						options.pop_back();
					}
					else
					{
						int posicao = mostraInfo(oficina1, "REMOVE FUNCIONARIO", 1);

						if (posicao == -1)
							options.pop_back();
						else
                            try
							{
							    oficina1.removeFuncionario(oficina1.getFuncionarios()[posicao]);
							}
							catch(FuncionarioNaoExistente) {}
					}

					break;
		}
		case 7:
		{
				  clrscr();
				  cout << "   LISTAGEM DE FUNCIONARIOS" << endl << endl;

				  for (unsigned int i = 0; i < oficina1.getFuncionarios().size(); i++)
				  {
					  cout << "   " << i + 1 << ". " << *oficina1.getFuncionarios()[i] << endl;;
				  }

				  waitForEnter();
				  options.pop_back();
				  break;
		}
		case 8: //VEIC - ADD
		{
					int temp;

					temp = makeMenu("ADICIONAR VEICULO", { "SIM", "NAO" }, "O cliente ja se encontra registado na nossa base de dados?", 1);

					if (temp == -1)
						options.pop_back();
					else
						options.push_back(11 + temp);
					break;
		}
		case 9:	//Remover um veiculo
		{
					int temp = mostraInfo(oficina1, "REMOVER VEICULO", 2);

					if (temp == -1)
						options.pop_back();
					else
					{
						try
						{
							oficina1.removeVeiculo(oficina1.getVeiculos()[temp]);
						}
						catch (VeiculoNaoExistente x)
						{
							cout << "   O Veiculo '" << x.getID() << "' nao existe na oficina..." << endl;
						}
					}

					waitForEnter();
					break;
		}
		case 10:		//Listagem de veiculos
		{
				   clrscr();
				   cout << "   LISTAGEM DE VEICULOS" << endl << endl;

				   for (unsigned int i = 0; i < oficina1.getFuncionarios().size(); i++)
				   {
					   cout << "   " << i + 1 << ". ";
					   oficina1.getVeiculos()[i]->getInfo();
					   cout << endl;
				   }

				   waitForEnter();
				   options.pop_back();
				   break;
		}
		case 11:		//Quando o cliente ja e antigo
		{
							if (oficina1.getClientes().size() == 0)
							{
								clientesNaoRegistados(1);
								options.pop_back();

								break;
							}

							if (oficina1.getFuncionarios().size() == 0)
							{
								funcionariosNaoRegistados();
								options.pop_back();

								break;
							}

							int posCliente = mostraInfo(oficina1, "SELECIONA O CLIENTE A QUE DESEJA ASSOCIAR O AUTOMOVEL", 0);

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
							Veiculo *a1;
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
									  try
									  {
									      oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
									  }
									  catch(FuncionarioNaoPodeTerMaisVeiculos) {}
									  oficina1.getClientes()[posCliente].addVeiculo(a1);

									  /*cout << endl << endl;
									  oficina1.getClientes()[posCliente].getVeiculos()[0]->getInfo();*/

									  //a1->apresenta();
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
									  try
									  {
									      oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
									  }
									  catch(FuncionarioNaoPodeTerMaisVeiculos) {}
									  oficina1.getClientes()[posCliente].addVeiculo(a1);
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
									  try
									  {
									      oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
									  }
									  catch(FuncionarioNaoPodeTerMaisVeiculos) {}
									  oficina1.getClientes()[posCliente].addVeiculo(a1);
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
									  try
									  {
									      oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
									  }
									  catch(FuncionarioNaoPodeTerMaisVeiculos) {}
									  oficina1.getClientes()[posCliente].addVeiculo(a1);

									  associarServicosVeiculos(oficina1, a1);
									  clrscr();
									  cout << a1->getServicos()[0].getNome() << " - " << a1->getServicos()[0].getPreco();
									  break;
							}
							}

							cout << endl << "   O veiculo pertencente a '" << oficina1.getClientes()[posCliente].getNome() << "', com o ID = '" << oficina1.getClientes()[posCliente].getNumRegisto() << "' foi adicionado com sucesso!" << endl;

							waitForEnter();
							options.pop_back();
							break;
		}
		case 12:		//Quando e a primeira vez que o cliente visita a oficina
		{
							clientesNaoRegistados(0);
							options.pop_back();

							break;
		}

		case 13:		//Registar cliente
		{
							string nome;

							gotoxy(3, 0);
							cout << "REGISTAR CLIENTE";

							gotoxy(3, 3);
							cout << "Introduza o nome do cliente: ";
							getline(cin, nome);

							while (nome.empty())
							{
								cout << endl << "   O cliente tem de ter um nome!" << endl;
								cout << "   Por favor, volte a escrever o nome do cliente: ";
								getline(cin, nome);
							}

							Cliente c1(nome);
							oficina1.adicionaCliente(c1);

							cout << endl << "   O cliente '" << nome << "' foi adicionado com sucesso!";

							waitForEnter();
							options.pop_back();
							break;
		}
		case 14:		//Remove cliente
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
								int posicao = mostraInfo(oficina1, "REMOVE CLIENTE", 0);

								if (posicao == -1)
									options.pop_back();
								else
									try
									{
									    oficina1.removeCliente(oficina1.getClientes()[posicao]);
									}
									catch(ClienteNaoExistente cl)
									{
                                        cout << "O cliente " << cl.getNome() << " não existe!" << endl;
									}
							}

							break;
		}
		case 15:		//Lista clientes
		{
				   clrscr();
				   cout << "   LISTAGEM DE CLIENTES" << endl << endl;

				   for (unsigned int i = 0; i < oficina1.getClientes().size(); i++)
				   {
					   cout << "   " << i + 1 << ". ";
					   cout << oficina1.getClientes()[i] << endl;
				   }

				   waitForEnter();
				   options.pop_back();
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

	ifstream file("servicos.txt");
	if (file.good())
		file.close();
	else {
		file.close();
		cout << "Foi impossivel importar o ficheiro de servicos.\nPor favor certifique-se que este esta no diretorio correto!\n\n";
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
