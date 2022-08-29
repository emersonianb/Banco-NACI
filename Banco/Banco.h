#ifndef BANCO_H
#define BANCO_H

#include "../Pessoa/Pessoa.h"
#include "../Conta/ContaCorrente.h"
#include "../Conta/ContaPoupanca.h"
#include "../Conta/ContaCorrenteLimite.h"
#include "../Pessoa/PessoaJuridica.h"
#include <iomanip>
using std::setw;
#include <list>
using std::list;
using std::cin;
using std::endl;

class Banco : public PessoaJuridica{

public:
  Banco(string, string, string);
  ~Banco();
  void cadastro(int&, int&);
  void consultar(int) const;
  bool verificaConta(int&) const;
  bool verificaPessoa(string&) const;
  void remover(int&);
  void listarContas() const;
  void listarContasCorrentistas(string&) const;
  void atualizarConta(int&);
  Pessoa* getPessoa(string&) const;
  Conta* getConta(int&) const;

private:
  list <Pessoa*> correntistas;
  list <Conta*> contas;
};

#endif