#ifndef CartaoPontos_h
#define CartaoPontos_h

#include "Cliente.h"

using namespace std;

class CartaoPontos
{
public:
	CartaoPontos();
	int getPontos() const;
	void addPontos(int pontos);
private:
	int pontos;
	bool ativado;
};

#endif