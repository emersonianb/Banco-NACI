#ifndef CONTACORRENTELIMITE_H
#define CONTACORRENTELIMITE_H

#include "Conta.h"

class ContaCorrenteLimite : public Conta{
public:
  ContaCorrenteLimite(int, Pessoa*, double&);
  virtual ~ContaCorrenteLimite(){}
  virtual void extrato() const override;
  virtual Conta &operator>>(const int &valor) override;

private:
  double limite;
};

#endif