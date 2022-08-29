#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
using std::string;

class Pessoa
{
public:
  Pessoa(){;}
  Pessoa(string &nome){
    this->nome = nome;}
  virtual ~Pessoa(){;}
  void setNome(string &nome){
    this->nome = nome;
  }
  virtual string getNome() const{
    return nome;
  }

protected:
  string nome;
  string id;
};

#endif