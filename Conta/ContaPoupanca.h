#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include <iostream>
#include "Conta.h"

class ContaPoupanca : public Conta{
public:
  ContaPoupanca(int, Pessoa*);
  virtual ~ContaPoupanca(){;}
  virtual void extrato() const override;

private:
  Data aniversario;
};

#endif