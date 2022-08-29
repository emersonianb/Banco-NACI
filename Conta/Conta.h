#ifndef CONTA_H
#define CONTA_H

#include "../Pessoa/PessoaFisica.h"
#include "../Pessoa/PessoaJuridica.h"
#include "../Transacao/Transacao.h"
#include <iomanip>
#include <list>
#include <string>
using std::string; using std::list;
using std::ostream; using std::setw;

ostream &operator<<(ostream &out, const list <Transacao> &list);

class Conta
{

public:
  Conta(int, Pessoa*);
  virtual ~Conta(){;}
  int getNumConta() const;
  string getNomeCorrentista() const;
  double getSaldo() const;
  Pessoa* getCorrentista() const;
  void transferir(double&, Conta*);
  virtual void extrato() const = 0;
  virtual Conta &operator<<(const int &valor);
  virtual Conta &operator>>(const int &valor);

protected:
  int numeroConta;
  Pessoa *correntista;
  double saldo = 0;
  list <Transacao> transacoes;

};

#endif