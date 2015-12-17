#ifndef CartaoPontos_h
#define CartaoPontos_h

#include "Cliente.h"

using namespace std;

class CartaoPontos
{
public:
	CartaoPontos();
	int getPontos() const;
private:
	int pontos;
	//Cliente *c;
};

#endif