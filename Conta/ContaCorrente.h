#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente :  public Conta{
public:
  ContaCorrente(int, Pessoa*);
  virtual ~ContaCorrente(){;}
  virtual void extrato() const override;
};

#endif