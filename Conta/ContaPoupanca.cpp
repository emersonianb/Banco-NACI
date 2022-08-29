#include "ContaPoupanca.h"

using std::cout;

ContaPoupanca::ContaPoupanca(int num, Pessoa* pe) : Conta(num, pe){
  this->aniversario = aniversario.getData();
}

void ContaPoupanca::extrato() const{
  cout << "--------Conta Poupança--------" << "\n";
  cout << "Número: ";
  cout.fill('0');
  cout << setw(3) << numeroConta << "\n";
  cout << "Cliente: " << correntista->getNome() << "\n";
  cout << "Saldo: " << saldo << "\n";
  cout << "Transações: " << transacoes;
  cout << "\nAniversario: " << aniversario.getDia() << "/" << aniversario.getMes() << "\n\n";
}