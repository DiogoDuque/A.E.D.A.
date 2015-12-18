#ifndef CartaoPontos_h
#define CartaoPontos_h

using namespace std;

class CartaoPontos
{
public:
	CartaoPontos();
	int getPontos() const;
	bool getEstado() const;
	void mudaEstadoAtivacao();
	void addPontos(int pontos);
	void setAtivacao(bool ativacao);
private:
	int pontos;
	bool ativado;
	int validade;		//Numero de dias restante
};

#endif