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
	void estadoInativo();
private:
	int pontos;
	bool ativado;
};

#endif