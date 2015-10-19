#include <string>
#include <vector>

using namespace std;

struct Servico
{
	string descricao;
	float preco;
	float duracao;		//em horas
} limpezaAutomovel, limpezaMotorizado, limpezaCamiao, limpezaAutocarro, revisaoAutomovel, revisaoMotorizado, revisaoCamiao, revisaoAutocarro, mudancaOleoAutomovel,
mudancaOleoMotorizado, mudancaOleoCamiao, mudancaOleoAutocarro;

limpezaAutomovel.descricao = "Limpeza geral do automovel";
limpezaAutomovel.preco = 25;
limpezaAutomovel.duracao = 1.5;

limpezaMotorizado.descrica = "Limpeza geral do motorizado";
limpezaMotorizado.preco = 20;
limpezaMotorizado.duracao = 0.9;

limpezaCamiao.descricao = "Limpeza geral do camiao";
limpezaCamiao.preco = 40;
limpezaCamiao.duracao = 3;

limpezaAutocarro.descricao = "Limpeza geral do autocarro";
limpezaAutocarro.preco = 40;
limpezaAutocarro.duracao = 3.2;