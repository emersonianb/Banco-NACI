#include "Conta.h"
using std::cout;

ostream &operator<<(ostream &out, const list <Transacao>  &list){
  if (list.size() < 30){
    for (auto &el : list){
    out << el;
    }
  }
  return out;
}


Conta::Conta(int num, Pessoa* pe){
  this->numeroConta = num;
  this->correntista = pe;
}

int Conta::getNumConta() const{
  return this->numeroConta;
}

string Conta::getNomeCorrentista() const{
  return (correntista->getNome());
}

double Conta::getSaldo() const{
  return this->saldo;
}

Pessoa* Conta::getCorrentista() const{
  return (correntista);
}

void Conta::transferir(double &valor, Conta* conta){
  if (valor <= saldo){
    *this >> valor;
  *conta << valor;
  }
  else{
    cout << "Saldo Insuficiente!\n";
  }
}

Conta &Conta::operator<<(const int &valor){
  this->saldo += valor;
  Transacao t(valor, "Deposito");
  transacoes.push_front(t);
  return *this;
}

Conta &Conta::operator>>(const int &valor){
  if (this->saldo >= valor){
    this->saldo -= valor;
    Transacao t(valor, "Saque");
    transacoes.push_front(t);
  }
  else{
    cout << "Saldo insuficiente para retirada.\n";
  }
  
  return *this;
}