#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "Pessoa.h"

class PessoaFisica : public Pessoa{
public:
  PessoaFisica(){;}
  PessoaFisica(string &n, string &cpf){
    this->nome = n;
    this->cpf = cpf;}
  virtual ~PessoaFisica(){}
  string getCpf() const {return cpf;}

protected:
  string cpf;
};

#endif