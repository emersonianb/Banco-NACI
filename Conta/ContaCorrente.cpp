#include "ContaCorrente.h"

using std::cout;

ContaCorrente::ContaCorrente(int num, Pessoa* pe) : Conta(num, pe){}

void ContaCorrente::extrato() const {
  cout << "--------Conta Corrente--------" << "\n";
  cout << "Número: ";
  cout.fill('0');
  cout << setw(3) << numeroConta << "\n";
  cout << "Cliente: " << correntista->getNome() << "\n";
  cout << "Saldo: " << saldo << "\n";
  cout << "Transações: " << transacoes;
  cout << "\n\n";
}