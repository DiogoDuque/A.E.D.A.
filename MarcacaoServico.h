#ifndef MARCACAOSERVICO_H
#define MARCACAOSERVICO_H

#include "Veiculo.h"

class MarcacaoServico
{
    public:
        MarcacaoServico(int d, int m, int a, int h, Servico* s);
        int getDia() const;
        int getMes() const;
        int getAno() const;
        int getHora() const;
        Servico* getServico() const;
        string getNomeCliente() const;
        void adiaDias(int d);
        bool operator<(const MarcacaoServico& m) const;
    protected:
    private:
        string nomeCliente;
        int dia;
        int mes;
        int ano;
        int hora;
        Servico* servico;
};

ostream& operator<<(ostream& os, const MarcacaoServico& m);

#endif // MARCACAOSERVICO_H
