#include "ContaCorrenteLimite.h"

using std::cout;

ContaCorrenteLimite::ContaCorrenteLimite(int num, Pessoa* pe, double &lim) : Conta(num, pe){
  this->limite = lim;
}


void ContaCorrenteLimite::extrato() const{
  cout << "--------Conta Corrente com Limite--------" << "\n";
  cout << "Número: ";
  cout.fill('0');
  cout << setw(3) << numeroConta << "\n";
  cout << "Cliente: " << correntista->getNome() << "\n";
  cout << "Saldo: " << saldo << "\n";
  cout << "Transações: " << transacoes;
  cout << "\nLimite: " << limite << "\n\n";
}

Conta &ContaCorrenteLimite::operator>>(const int &valor){
  if ((this->saldo >= valor) && (valor <= this->limite)){
    this->saldo -= valor;
  }
  else if(valor > limite){
    cout << "Valor ultrapassa limite da conta.\n";
  }
  else{
    cout << "Saldo insuficiente para retirada.\n";
  }
  return *this;
}