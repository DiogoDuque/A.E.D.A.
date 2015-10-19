#include <iostream>
#include <conio.h>			//usada para arrows
#include <windows.h>		//usada para arrows
#include <cstdlib>			//usada para arrows

using namespace std;

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

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

/*
IDEIAS


- Oferecer descontos

- Impor taxa de permanencia de veiculos apos o tempo de reparos

- Software para clientes e outro para a empresa


*/