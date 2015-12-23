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
#include <algorithm>

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
	cout << "Projeto realizado por: Daniel Fernandes, Diogo Duque e Jose Carlos";

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
}

//'n' --> 0 para clientes, 1 para funcionarios, 2 para veiculos, 3 para servicos, 4 para os veiculos de um determinado cliente
//'pos' --> -1 se nao for necessario, diferente de -1 para indicar a posicao do cliente desejado
int mostraInfo(Oficina oficina1, string frase, int n, int pos)
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
	{
		cout << endl << endl;
		oficina1.showInfoVeiculos();
	}

	if (n == 3)
	for (unsigned int i = 0; i < oficina1.getServicos().size(); i++)
	{
		gotoxy(3, 3 + i * 2);
		cout << oficina1.getServicos()[i];
	}

	if (n == 4)
	{
		for (unsigned int i = 0; i < oficina1.getClientes()[pos].getVeiculos().size(); i++)
		{
			gotoxy(3, 3 + i * 2);
			oficina1.getClientes()[pos].getVeiculos()[i]->getInfo() ;//cout << oficina1.showInfoVeiculos();
		}
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
					 if (n == 3)
					 {
						 if (posicao < oficina1.getServicos().size() - 1)
						 {
							 gotoxy(0, 3 + posicao * 2);
							 cout << "   ";
							 posicao++;
						 }
					 }

					 if (n == 4)
					 {
						 if (posicao < oficina1.getClientes()[pos].getVeiculos().size() - 1)
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

void associarServicosVeiculos(Oficina *oficina1, Veiculo *a1, int posCliente)
{
	vector<string> servicosString;
	for (unsigned int i = 0; i < oficina1->getServicos().size(); i++)
		servicosString.push_back(oficina1->getServicos()[i].getNome());

	//int temp = makeMenu("ESCOLHER SERVICO", servicosString, "", 0);
	int posicao = mostraInfo(*oficina1, "ESCOLHER SERVICO", 3, -1);
	oficina1->getClientes()[posCliente].getCartaoCliente()->addPontos(oficina1->getServicos()[posicao].getPreco() / (float)CONVERSION_RATE);
	unsigned int i = 0;
	for (; i < oficina1->getVeiculos().size(); i++)
	{
		if (oficina1->getVeiculos()[i]->getID() == a1->getID())
			break;
	}

	oficina1->adicionaServicoVeiculo(posCliente, i, posicao);


	//a1->adicionaServico(oficina1->getServicos()[posicao]);


	/*cout << oficina1->getDiaAtual() + 1 << " / " << oficina1->getMesAtual() << " / " << oficina1->getAnoAtual() << oficina1->getServicos()[posicao] << endl << oficina1->getClientes()[posCliente].getNome() << endl << a1->getID();

	Servico *s = &oficina1->getServicos()[posicao];
	cout << s->getNome();
	oficina1->adicionaMarcacao(new MarcacaoServico(oficina1->getDiaAtual() + 1, oficina1->getMesAtual(), oficina1->getAnoAtual(), 8, s, oficina1->getClientes()[posCliente].getNome(), a1->getID()));
	*/
}

void menuManager(Oficina oficina1)
{
	vector <int> options = { 0 }; //sera usado para se poder retroceder nos menus
	int temp;
	while (options.size() > 0)
	{
		switch (options.back())
		{
		case 0: //MENU PRINCIPAL 1-6
		{
					temp = makeMenu(oficina1.getNome(), { "Gestao de funcionarios", "Gestao de veiculos",
						"Gestao de clientes", "Gestao de servicos", "Mostrar informacao acerca da oficina", "Avancar no tempo", "Marcacoes", "Promocoes" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else
					if (temp == 6)
						options.push_back(24);
					else
					if (temp == 7)
						options.push_back(28);
					else options.push_back(1 + temp);
					break;
		}
		case 1: //GESTAO DE FUNCIONARIOS 7-8-9
		{
					temp = makeMenu("GESTAO DE FUNCIONARIOS (prima ESC para retroceder)", { "Empregar funcionario", "Despedir funcionario", "Listar funcionarios" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(7 + temp);
					break;
		}
		case 2: //GESTAO DE VEICULOS (10 - 13 - 14) 11 12 13
		{
					temp = makeMenu("GESTAO DE VEICULOS (prima ESC para retroceder)", { "Dar entrada a um veiculo", "Dar saida a um veiculo", "Acrescentar servico a veiculo ja existente", "Listar Veiculos" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(10 + temp);
					break;
		}
		case 3: //GESTAO DE CLIENTES 16 - 17 - 18 - 19 - 20
		{
					temp = makeMenu("GESTAO DE CLIENTES (prima ESC para retroceder)", { "Registar cliente", "Eliminar cliente", "Listar clientes", "Listar clientes inativos", "Pesquisar clientes inativos" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(16 + temp);
					break;
		}
		case 4:	//GESTAO DE SERVICOS 21 - 22 - 23
		{
					temp = makeMenu("GESTAO DE SERVICOS (prima ESC para retroceder)", { "Criar novo servico", "Eliminar servico", "Listar servicos" }, "", 0);
					if (temp == -1)
						options.pop_back();
					else options.push_back(21 + temp);
					break;
		}
		case 5: //MOSTRAR INFO
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
		case 6:		//Avancar dias
		{

						int diasAvancar;

						clrscr();
						gotoxy(3, 0); cout << "AVANCAR DIAS NA OFICINA";
						gotoxy(3, 2); cout << "Quantos dias deseja avancar: ";
						cin >> diasAvancar;

						while (cin.fail() || diasAvancar <= 0)
						{
							cin.clear();
							cin.ignore(1000, '\n');

							cout << "   Introduziu um valor inapropriado. Tente novamente: ";
							cin >> diasAvancar;
						}

						cin.ignore(1000, '\n');
						oficina1.passaDias(diasAvancar);

						cout << "   ."; Sleep(500); cout << " ."; Sleep(500); cout << " ."; Sleep(500);
						cout << endl << endl << "   Passaram-se " << diasAvancar << " dias na oficina '" << oficina1.getNome() << "'";

						oficina1.removeVeiculosTratados();

						oficina1.avancaDiasParaClientes(diasAvancar);

						waitForEnter();
						options.pop_back();
						break;
		}
		case 7: //FUNC - ADD
		{
					string nomeFunc;

					gotoxy(3, 0);
					cout << "EMPREGAR FUNCIONARIOS" << endl;

					gotoxy(3, 3);
					cout << "Introduza o nome do novo funcionario: ";
					getline(cin, nomeFunc);

					while (cin.fail() || nomeFunc.empty())
					{
						cin.clear();
						cin.ignore(1000, '\n');

						cout << "   Introduziu um nome inapropriado. Tente novamente: ";
						getline(cin, nomeFunc);
					}

					Funcionario *f1 = new Funcionario(nomeFunc);
					oficina1.adicionaFuncionario(f1);

					cout << endl << "   O funcionario '" << nomeFunc << "' foi adicionado com sucesso!" << endl;

					waitForEnter();
					options.pop_back();
					break;
		}
		case 8: //FUNC - DEL
		{
					if (oficina1.getFuncionarios().size() == 1 && oficina1.getFuncionarios()[0]->getVeiculos().size() != 0)
					{
						gotoxy(3, 0); cout << "REMOVE FUNCIONARIO";
						gotoxy(3, 2); cout << "So existe 1 unico funcionario na oficina, e este esta a tratar de " << oficina1.getFuncionarios()[0]->getVeiculos().size() << " veiculos..." << endl;
						cout << "   Nao o pode despedir, caso contrario o negocio acaba...";
						waitForEnter();
						options.pop_back();
					}
					else
					if (oficina1.getFuncionarios().size() == 0)
					{
						gotoxy(3, 0); cout << "REMOVE FUNCIONARIO";
						gotoxy(3, 2); cout << "Actualmente, nao ha funcionarios a trabalhar na oficina...";
						waitForEnter();
						options.pop_back();
					}
					else
					{
						int posicao = mostraInfo(oficina1, "REMOVE FUNCIONARIO", 1, -1);

						if (posicao == -1)
							options.pop_back();
						else
							oficina1.removeFuncionario(oficina1.getFuncionarios()[posicao]);
					}

					break;
		}
		case 9:	//FUNC - Listar
		{
					clrscr();
					cout << "   LISTAGEM DE FUNCIONARIOS (por nome)" << endl << endl;

					oficina1.listaFunc();

					waitForEnter();
					options.pop_back();
					break;
		}
		case 10: //VEIC - ADD
		{
					 int temp;

					 temp = makeMenu("ADICIONAR VEICULO", { "SIM", "NAO" }, "O cliente ja se encontra registado na nossa base de dados?", 1);

					 if (temp == -1)
						 options.pop_back();
					 else
						 options.push_back(14 + temp);
					 break;
		}
		case 11:	//Remover um veiculo
		{
						clrscr();

						if (oficina1.getVeiculos().size() == 0)
						{
							gotoxy(3, 0); cout << "REMOVE VEICULO";
							gotoxy(3, 2); cout << "Actualmente, nao ha veiculos na oficina...";
							waitForEnter();
							options.pop_back();
						}
						else
						{

							int posVeiculo = mostraInfo(oficina1, "REMOVER VEICULO", 2, -1);

							if (posVeiculo == -1)
								options.pop_back();
							else
							if (!oficina1.podeRemoverVeiculo(posVeiculo))
							{
								clrscr();
								cout << "   ATENCAO!" << endl << endl;
								cout << "   O veiculo que esta a tentar remover esta a ser reparado! Aguarde ate a reparacao estar completa...";
								waitForEnter();
							}
							else
								oficina1.removeVeiculo(posVeiculo);
						}

						break;
		}
		case 12:	//Adiciona um servico a um veiculo
		{
						int posCliente = mostraInfo(oficina1, "ESCOLHA O CLIENTE", 0, -1);

						if (posCliente == -1)
							options.pop_back();
						else
						{
							int posVeiculo = mostraInfo(oficina1, "SELECIONE O VEICULO A REPARAR", 4, posCliente);

							if (posVeiculo == -1)
								options.pop_back();
							else
							{
								int posServico = mostraInfo(oficina1, "SELECIONE O SERVICO", 3, -1);

								if (posServico == -1)
									options.pop_back();
								else
								{
									oficina1.getClientes()[posCliente].getCartaoCliente()->addPontos(oficina1.getServicos()[posCliente].getPreco() / (float)CONVERSION_RATE);
									oficina1.adicionaServicoVeiculo(posCliente, posVeiculo, posServico);
									oficina1.actualizaInatividadeCliente(posCliente);
								}
							}
						}

						waitForEnter();
						options.pop_back();
						break;

		}
		case 13:		//Listagem de veiculos
		{
							clrscr();
							cout << "   LISTAGEM DE VEICULOS (por ID)" << endl << endl;

							oficina1.listaVeiculos();

							waitForEnter();
							options.pop_back();
							break;
		}
		case 14:		//Quando o cliente ja e antigo
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

							int posCliente = mostraInfo(oficina1, "SELECIONA O CLIENTE A QUE DESEJA ASSOCIAR O AUTOMOVEL", 0, -1);

							if (posCliente == -1)
							{
								options.pop_back();
								break;
							}

							string combustivel;
							int ano, mes;
							int tipoVeiculo = -1;

							gotoxy(3, 0);
							cout << "ADICIONAR VEICULO";

							gotoxy(3, 3);
							cout << "Introduza o ano do veiculo: ";
							cin >> ano;

							while (cin.fail() || ano < 1769 || ano > 2015)
							{
								cin.clear();
								cin.ignore(1000, '\n');

								cout << "   Introduziu um valor inapropriado. Tente novamente: ";
								cin >> ano;
							}

							cout << "   Introduza o mes: ";
							cin >> mes;

							while (cin.fail() || mes > 12 || mes < 1)
							{
								cin.clear();
								cin.ignore(1000, '\n');

								cout << "   Introduziu um valor inapropriado. Tente novamente: ";
								cin >> mes;
							}

							cin.ignore(1000, '\n');		//Elimina o 'ENTER' que fica no buffer

							cout << "   Introduza o tipo de combustivel: ";
							getline(cin, combustivel);

							while (cin.fail())
							{
								cin.clear();
								cin.ignore(1000, '\n');

								cout << "   Introduziu um valor inapropriado. Tente novamente: ";
								getline(cin, combustivel);
							}

							clrscr();
							gotoxy(3, 1);
							cout << "ESPECIFIQUE O TIPO DE VEICULO";

							gotoxy(0, 3);
							cout << "->";

							vector<string> veiculos = { "Automovel", "Motorizada", "Camiao", "Autocarro" };
							for (unsigned int i = 0; i < 4; i++)
							{
								gotoxy(3, 3 + 2 * i);
								cout << veiculos[i];
							}

							unsigned int input, selecao = 0;
							while (tipoVeiculo == -1)
							{
								gotoxy(0, 3 + 2 * selecao);
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
											   gotoxy(0, 3 + 2 * selecao);
											   cout << "  ";
											   selecao--;
										   }
										   break;
								}
								case DOWN:
								{
											 if (selecao < 3)
											 {
												 gotoxy(0, 3 + 2 * selecao);
												 cout << "  ";
												 selecao++;
											 }
											 break;
								}
								}
							}

							gotoxy(3, 12);

							switch (tipoVeiculo)
							{
							case 0:		//Automovel
							{
											int numLugares;

											cout << "Introduza o numero de lugares: ";
											cin >> numLugares;

											while (cin.fail())
											{
												cin.clear();
												cin.ignore(1000, '\n');

												cout << "   Introduziu um valor inapropriado. Tente novamente: ";
												cin >> numLugares;
											}

											cin.ignore(1000, '\n');

											Veiculo *a1 = new Automovel(ano, mes, combustivel, numLugares);
											oficina1.adicionaVeiculo(a1);

											int indice = oficina1.funcionarioComMenosVeiculos();
											a1->setFuncionario(oficina1.getFuncionarios()[indice]);
											oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
											oficina1.getClientes()[posCliente].addVeiculo(a1);
											associarServicosVeiculos(&oficina1, a1, posCliente);

											clrscr();
											anim_automovel();
											waitForEnter();
											break;
							}
							case 1:		//Mota
							{
											int cilindrada;

											cout << "   Introduza a cilindrada: ";
											cin >> cilindrada;

											while (cin.fail())
											{
												cin.clear();
												cin.ignore(1000, '\n');

												cout << "   Introduziu um valor inapropriado. Tente novamente: ";
												cin >> cilindrada;
											}

											cin.ignore(1000, '\n');

											Veiculo *a1 = new Motorizada(ano, mes, combustivel, cilindrada);
											oficina1.adicionaVeiculo(a1);

											int indice = oficina1.funcionarioComMenosVeiculos();
											a1->setFuncionario(oficina1.getFuncionarios()[indice]);
											oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
											oficina1.getClientes()[posCliente].addVeiculo(a1);
											associarServicosVeiculos(&oficina1, a1, posCliente);

											clrscr();
											anim_mota();
											waitForEnter();
											break;
							}
							case 2:		//Camiao
							{
											int tara;

											cout << "Introduza a tara: ";
											cin >> tara;

											while (cin.fail())
											{
												cin.clear();
												cin.ignore(1000, '\n');

												cout << "   Introduziu um valor inapropriado. Tente novamente: ";
												cin >> tara;
											}

											cin.ignore(1000, '\n');

											Veiculo *a1 = new Camiao(ano, mes, combustivel, tara);
											oficina1.adicionaVeiculo(a1);

											int indice = oficina1.funcionarioComMenosVeiculos();
											a1->setFuncionario(oficina1.getFuncionarios()[indice]);
											oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
											oficina1.getClientes()[posCliente].addVeiculo(a1);
											associarServicosVeiculos(&oficina1, a1, posCliente);


											clrscr();
											anim_camiao();
											waitForEnter();
											break;
							}
							case 3:		//Autocarro
							{
											int numLugares;

											cout << "Introduza o numero de lugares: ";
											cin >> numLugares;

											while (cin.fail())
											{
												cin.clear();
												cin.ignore(1000, '\n');

												cout << "   Introduziu um valor inapropriado. Tente novamente: ";
												cin >> numLugares;
											}

											cin.ignore(1000, '\n');

											Veiculo *a1 = new Autocarro(ano, mes, combustivel, numLugares);
											oficina1.adicionaVeiculo(a1);

											int indice = oficina1.funcionarioComMenosVeiculos();
											a1->setFuncionario(oficina1.getFuncionarios()[indice]);
											oficina1.getFuncionarios()[indice]->acrescentaVeiculos(a1);
											oficina1.getClientes()[posCliente].addVeiculo(a1);
											associarServicosVeiculos(&oficina1, a1, posCliente);

											clrscr();
											anim_autocarro();
											waitForEnter();
											break;
							}
							}
							oficina1.actualizaInatividadeCliente(posCliente);

							options.pop_back();
							break;

		}
		case 15:		//Quando e a primeira vez que o cliente visita a oficina
		{
							clientesNaoRegistados(0);
							options.pop_back();

							break;
		}

		case 16:		//Registar cliente
		{
							string nome;

							gotoxy(3, 0);
							cout << "REGISTAR CLIENTE";

							gotoxy(3, 3);
							cout << "Introduza o nome do cliente: ";
							getline(cin, nome);

							while (cin.fail() || nome.empty())
							{
								cin.clear();
								cin.ignore(1000, '\n');

								cout << "   Introduziu um valor inapropriado. Tente novamente: ";
								getline(cin, nome);
							}

							string morada, mail, telefone;

							cout << "   Introduza a morada: ";
							getline(cin, morada);
							cout << "   Introduza o mail: ";
							getline(cin, mail);
							cout << "   Introduza um numero de telefone: ";
							getline(cin, telefone);

							Cliente c1(nome);
							c1.setMorada(morada);
							c1.setMail(mail);
							c1.setTelefone(telefone, 0);

							oficina1.adicionaCliente(c1);

							cout << endl << "   O cliente '" << nome << "' foi adicionado com sucesso!";

							waitForEnter();
							options.pop_back();
							break;
		}
		case 17:		//Remove cliente
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
								int posicao = mostraInfo(oficina1, "REMOVE CLIENTE", 0, -1);

								if (posicao == -1)
									options.pop_back();
								else
									oficina1.removeCliente(oficina1.getClientes()[posicao]);
							}

							break;
		}
		case 18:		//Lista clientes
		{
							clrscr();
							cout << "   LISTAGEM DE CLIENTES (por nome)" << endl << endl;

							oficina1.listaClientes();

							waitForEnter();
							options.pop_back();
							break;
		}
		case 19:		//Clientes --> listagem dos inativos
		{
							clrscr();
							cout << "   LISTAGEM DE CLIENTES INATIVOS" << endl << endl;

							oficina1.listaClientesInativos();

							cout << "1. Actualizar informacoes\t2. Adicionar informacoes\t0. Retroceder" << endl;
							cout << "O que pretende fazer: ";

							int tecla;
							cin >> tecla;

							switch (tecla)
							{
							case 1:
							{
									  int numCliente, numMudar;

									  cout << endl << "Introduza o numero (desta listagem) do cliente: ";
									  cin >> numCliente;

									  cout << endl << "1. Mudar nome, 2. Mudar morada, 3. Mudar mail, 4. Mudar Telefones, 0. Retroceder" << endl;
									  cout << "O que pretende fazer: ";
									  cin >> numMudar;

									  if (numMudar == 0)
									  {
										  options.pop_back();
										  break;
									  }

									  cout << endl;

									  oficina1.actualizaClienteInativo(numCliente - 1, numMudar);

									  break;
							}
							case 2:
							{
									  int numCliente, numMudar;

									  cout << endl << "Introduza o numero (desta listagem) do cliente: ";
									  cin >> numCliente;

									  cout << endl << "1. Adicionar telefone\t0. Retroceder" << endl;
									  cout << "o que pretende fazer: ";
									  cin >> numMudar;

									  if (numMudar == 0)
									  {
										  options.pop_back();
										  break;
									  }

									  cout << endl;

									  oficina1.adicionaInformacao(numCliente - 1, numMudar);

									  break;
							}
							case 0:
								break;
							}

							options.pop_back();
							//waitForEnter();
							break;
		}
		case 20:		//Clientes --> pesquisa dos inativos
		{
							clrscr();
							cout << "   PESQUISA DE CLIENTES INATIVOS" << endl << endl;

							string nomeCliente;

							cout << "   Introduza o nome do cliente: ";
							getline(cin, nomeCliente);

							oficina1.pesquisaClienteInativo(nomeCliente);

							waitForEnter();
							options.pop_back();
							break;
		}
		case 21:		//Adicionar servicos
		{
							string nome;
							float preco;
							int dias;

							gotoxy(3, 0); cout << "REGISTAR NOVO SERVICO";
							gotoxy(3, 3); cout << "Introduza o nome do nome servico: ";
							getline(cin, nome);

							while (cin.fail() || nome.empty())
							{
								cin.clear();
								cin.ignore(1000, '\n');

								cout << "   Introduziu um nome inapropriado. Tente novamente: ";
								getline(cin, nome);
							}

							cout << "   Introduza o preco: ";
							cin >> preco;

							while (cin.fail())
							{
								cin.clear();
								cin.ignore(1000, '\n');

								cout << "   Introduziu um valor inapropriado. Tente novamente: ";
								cin >> preco;
							}

							cout << "   Introduza o tempo que demora a realizar o servico: ";
							cin >> dias;

							while (cin.fail())
							{
								cin.clear();
								cin.ignore(1000, '\n');

								cout << "   Introduziu um valor inapropriado. Tente novamente: ";
								cin >> dias;
							}

							Servico s1(nome, preco, dias);
							oficina1.adicionaServico(s1);

							cout << "   O servico '" << nome << "' foi adicionado com sucesso!";

							waitForEnter();
							options.pop_back();
							break;
		}
		case 22:		//Remover servicos
		{
							if (oficina1.getServicos().size() == 0)
							{
								gotoxy(3, 0); cout << "REMOVE SERVICOS";
								gotoxy(3, 2); cout << "Actualmente, a oficina nao dispoe de quaisquer servicos...";
								waitForEnter();
								options.pop_back();
							}
							else
							{
								vector<string> servicos;
								for (unsigned int i = 0; i < oficina1.getServicos().size(); i++)
									servicos.push_back(oficina1.getServicos()[i].getNome());

								int posicao = mostraInfo(oficina1, "REMOVE SERVICOS", 3, -1);

								if (posicao == -1)
								{
									options.pop_back();
									break;
								}
								else
								{
									if (!oficina1.removeServico(posicao))
									{
										clrscr();
										cout << endl << endl << "   Nao se pode eliminar esse servico, visto que esse servico esta a decorrer para um veiculo";

									}
								}
							}

							waitForEnter();
							break;

		}
		case 23:		//Listagem de servicos
		{
							clrscr();
							cout << "   LISTAGEM DE SERVICOS (por preco)" << endl << endl;

							oficina1.listaServicos();

							waitForEnter();
							options.pop_back();
							break;
		}
		case 24:		//Sub-menu das marcacoes
		{
							clrscr();
							int temp2 = makeMenu("MARCACOES (prima ESC para retroceder)", { "Cancelar marcacoes", "Remarcar marcacoes", "Listar marcacoes" }, "", 0);

							if (temp2 == -1)
								options.pop_back();
							else options.push_back(25 + temp2);

							break;
		}
		case 25:		//Marcacoes --> cancelar marcacoes
		{
							clrscr();
							cout << "   CANCELAR MARCACOES" << endl << endl;

							cout << "Introduza o nome do cliente" << endl;

							string nomeCliente;
							cin >> nomeCliente;

							oficina1.listaMarcacoesDeCliente(nomeCliente);

							cout << "Introduza o numero da marcacao que pretende cancelar" << endl;

							int id;
							cin >> id;

							oficina1.cancelaMarcacao(oficina1.getMarcacao(nomeCliente, id));

							waitForEnter();
							options.pop_back();

							break;
		}
		case 26:		//Marcacoes --> remarcar marcacoes
		{
							clrscr();
							cout << "   REMARCAR MARCACOES" << endl << endl;

							cout << "Introduza o nome do cliente" << endl;

							string nomeCliente;
							cin >> nomeCliente;

							if(!oficina1.listaMarcacoesDeCliente(nomeCliente))
                            {
                                cin.get();
                                waitForEnter();
                                options.pop_back();
                                break;
                            }

							cout << "Introduza o numero da marcacao que pretende remarcar" << endl;

							int id;
							cin >> id;

							cout << "Quantos dias pretende adiar a marcacao?" << endl;

							int dias;
							cin >> dias;

							oficina1.remarcaMarcacao(oficina1.getMarcacao(nomeCliente, id), dias);

							waitForEnter();
							options.pop_back();

							break;
		}
		case 27:		//Marcacoes --> listar marcacoes
		{
							clrscr();
							cout << "   LISTAGEM DE MARCACOES" << endl << endl;

							oficina1.listaMarcacoes();

							waitForEnter();
							options.pop_back();

							break;
		}
		case 28: /*********************************************DUQUE*********************/
		{
					 while (true)
					 {
						 //apresentacao das promocoes disponiveis
						 if (oficina1.getListaPromocoes().size() == 0)
						 {
							 cout << "Nao existem promocoes de momento. Volte noutra altura...\n";
							 waitForEnter();
							 break;
						 }
						 int promoIndex = makeMenu("Promocoes disponiveis", oficina1.getListaPromocoes(), "", 0);
						 if (promoIndex == -1)
							 break;

						 //clientes que tem direito à promo
						 if (oficina1.getSorteadosString(oficina1.getPromoByIndex(promoIndex)).size() == 0)
						 {
							 cout << "Nao existem clientes com pontos suficientes! Volte noutra altura...\n";
							 waitForEnter();
							 break;
						 }
						 string s = "Clientes com acesso à promocao no servico \"" + oficina1.getListaPromocoes()[promoIndex] + "\"";
						 int clienteIndex = makeMenu(s, oficina1.getSorteadosString(oficina1.getPromoByIndex(promoIndex)), "", 0);
						 if (clienteIndex == -1)
							 continue;

						 //cliente tem que fazer uma escolha
						 int choice = makeMenu("Que deseja fazer com o servico?", vector<string> {"Aceitar", "Rejeitar"}, "", 0);
						 if (choice == 0) //realizar servico
						 {
							 //descobrir index do Cliente no vector de tds os clientes
							 int posCliente;
							 for (int i = 0; i < oficina1.getClientes().size(); i++)
							 {
								 if (oficina1.getSorteados(oficina1.getPromoByIndex(promoIndex))[clienteIndex]->getCartaoCliente() == oficina1.getClientes()[i].getCartaoCliente())
									 posCliente = i;
							 }

							 //descobrir index do servico
							 Servico serv = oficina1.getPromoByIndex(promoIndex).getServico();
							 int posServico;
							 for (int i = 0; i < oficina1.getServicos().size(); i++)
							 {
								 if (serv.getNome() == oficina1.getServicos()[i].getNome())
									 posServico = i;
							 }

							 //mostrar veiculos para escolha
							 vector <Veiculo*> veics = oficina1.getClientes()[posCliente].getVeiculos();
							 clrscr();
							 cout << "Escolha um veiculo: \n\n";
							 for (int i = 0; i < veics.size(); i++)
							 {
								 cout << i + 1 << ". ";
								 veics[i]->getInfo();
								 cout<< endl;
							 }
							 cout << "\n Veiculo: ";
							 int posVeiculo;
							 cin >> posVeiculo;
							 posVeiculo--;
							 //aplicar
							 oficina1.adicionaServicoVeiculo(posCliente, posVeiculo, posServico);
							 oficina1.actualizaInatividadeCliente(posCliente);
							 oficina1.getPromoByIndex(promoIndex).validarPromo(oficina1.getSorteados(oficina1.getPromoByIndex(promoIndex))[clienteIndex]);
							 if (oficina1.getPromoByIndex(promoIndex).getNClientes() == 0)
								 oficina1.removePromocao(oficina1.getPromoByIndex(promoIndex));
						 }
						 if (choice == 1) //rejeitar
						 {
							 oficina1.getPromoByIndex(promoIndex).addRejeitado(oficina1.getSorteados(oficina1.getPromoByIndex(promoIndex))[clienteIndex]);
						 }
						 break;
					 }
					 clrscr();
					 cout << "Saindo da zona das promoces...\n";
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

		Oficina oficina1(nomeOficina);

		ifstream file("servicos.txt");
		if (file.good())
			file.close();
		else {
			file.close();
			cout << "Foi impossivel importar o ficheiro de servicos.\nPor favor certifique-se que este esta no diretorio correto!\n\n";
		}

		ifstream myFile;
		myFile.open("clientes.txt");





		string nome, morada, mail, telefone, inatividade;

		nome = "Joao";
		morada = "Rua da Lapa";
		mail = "joao@hotmail.com";
		telefone = "917683726";

		Cliente c1(nome);
		c1.setMorada(morada);
		c1.setMail(mail);
		c1.setTelefone(telefone, 0);

		c1.setInatividade(true);
		oficina1.adicionaClienteInativo(c1);

		oficina1.adicionaCliente(c1);



		string nome2, morada2, mail2, telefone2, inatividade2;

		nome2 = "Maria";
		morada2 = "Rua da circuncalacao";
		mail2 = "maria@hotmail.com";
		telefone2 = "93567526";

		Cliente c2(nome2);
		c2.setMorada(morada2);
		c2.setMail(mail2);
		c2.setTelefone(telefone2, 0);

		c2.setInatividade(true);
		oficina1.adicionaClienteInativo(c2);

		oficina1.adicionaCliente(c2);





		/*while (!myFile.eof())
		{
		string nome, morada, mail, telefone, inatividade;

		getline(myFile, nome);
		getline(myFile, morada);
		getline(myFile, mail);
		getline(myFile, telefone);
		getline(myFile, inatividade);

		Cliente c1(nome);
		c1.addMorada(morada);
		c1.addMail(mail);
		c1.addTelefone(telefone);

		cout << nome << endl << morada << endl << mail << endl << telefone << endl << inatividade;
		waitForEnter();

		if (inatividade == "true")
		{
		c1.setInatividade(true);
		oficina1.adicionaClienteInativo(c1);
		}
		else
		{
		c1.setInatividade(false);
		oficina1.adicionaCliente(c1);
		}
		}*/

		menuManager(oficina1);

		clrscr();
		return 0;
	}
