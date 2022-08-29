#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"
using std::cout;

class PessoaJuridica : public Pessoa
{
public:
  PessoaJuridica(string &n, string &cnpj, string &razao) : Pessoa(n){
    this->cnpj = cnpj;
    razaoSocial = razao;
  }
  virtual ~PessoaJuridica(){}
  string getCnpj() const{return this->cnpj;}
  void setRazao(string &razao){
    this->razaoSocial = razao;
  }
  string getRazao() const{return this->razaoSocial;}

protected:
  string cnpj;
  string razaoSocial;
};

#endif