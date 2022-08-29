#include <iostream>
#include "Banco/Banco.h"
#include "Conta/ContaCorrente.h"
#include "Conta/ContaCorrenteLimite.h"
#include "Conta/ContaPoupanca.h"

int main() {
  Banco naci("Banco NACI", "2832873", "Banco");
  cout << "            " << naci.getNome() << "\n";
  cout << "_____________________________________\n";
  while (true){
    cout << "\n\n- Você é cliente ou gerente? -\n\n";
    int v;
    cout << "    (1) Cliente\n    (2) Gerente\n    (3) Criar Conta\n    (-1) Sair\n\n-> ";
    cin >> v;
    if (v == 1){
        while (true){
        int nC;
        cout << "\nNúmero da Conta: ";
        cin >> nC;
        if (naci.verificaConta(nC)){
            cout << "   - Menu Cliente -\n\n    (1) Depositar\n    (2) Retirar\n    (3) Transferir\n    (4) Ver Saldo\n    (5) Extrato\n-> ";
          int t;
          cin >> t;
          double valor;
          if  (t == 1){
            cout << "Valor a depositar: ";
            cin >> valor;
            *(naci.getConta(nC)) << valor;
          }
          else if (t == 2){
            cout << "Valor a retirar: ";
            cin >> valor;
            *(naci.getConta(nC)) >> valor;
          }
          else if (t == 3){
            cout << "Conta a transferir: ";
            int c;
            cin >> c;
            if (naci.verificaConta(c)){
              cout << "Valor a transferir: ";
            cin >> valor;
            (naci.getConta(nC))->transferir(valor, naci.getConta(c));
            }
            else{
              cout << "    A conta não existe!\n";
            }
          }
          else if (t == 4){
            cout << "Saldo: ";
            cout << (naci.getConta(nC))->getSaldo();
          }
          else if (t == 5){
            naci.getConta(nC)->extrato();
          }
        }
        else if (!naci.verificaConta(nC)){
          cout << "\n        A conta não existe!\n\n";
        }
        cout << "\n(1) Voltar para o ínicio\n(2) Sair\n\n->";
        int c;
        cin >> c;
        if (c == 2){
          break;
          }
        }
    }
    else if (v == 2){
      while (true){
        int opG;
        cout << "      - Menu Gerente -\n\n    (1) Abrir Conta\n    (2) Consultar Conta\n    (3) Atualizar Conta\n    (4) Fechar Conta\n\n-> ";
        cin >> opG;
        if (opG == 1){
          cout << "\n---------Abrir Conta---------\n";
          int tc, tp;
          cout << "\n      - Tipo de Pessoa -\n\n    (1) Pessoa Fisica.\n    (2) Pessoa Juridica.\n\n-> ";
          cin >> tp;
          cout << "\n      - Tipo de Conta -\n\n    (1) Conta Corrente\n    (2) Conta Corrente Limite\n    (3) Conta Poupança\n-> ";
          cin >> tc;
          naci.cadastro(tc, tp);
        }
        else if (opG == 2){
          cout << "\n\n-----Consultar-----\n\n";
          cout << "    (1) Conta\n    (2) Listar Contas do Banco\n    (3) Listar Contas de Correntista\n\n-> ";
          int tC;
          cin >> tC;
          if (tC == 1){
            int nC;
            cout << "\nNúmero da Conta: ";
            cin >> nC;
            naci.consultar(nC);
          }
          else if (tC == 2){
            naci.listarContas();
          }
          else if (tC == 3){
            cout << "\nNome do Correntista: ";
            string n;
            cin >> n;
            naci.listarContasCorrentistas(n);
          }
        }
        else if (opG == 3){
          int nC;
          cout << "\nNúmero da Conta: ";
          cin >> nC;
          naci.atualizarConta(nC);
          naci.consultar(nC);
        }
        else if (opG == 4){
          int nC;
          cout << "\nNúmero da Conta: ";
          cin >> nC;
          naci.remover(nC);
          cout << "A conta foi removida!\n";
        }
        cout << "(1) Voltar para o ínicio\n(2) Sair\n\n-> ";
        int c;
        cin >> c;
        if (c == 2){
          break;
      }
      }
    }
    else if (v == 3){
      cout << "\n------Criar Conta------\n";
      cout << "\n    (1) Já Possui Uma Conta";
      cout << "\n    (2) Não Possui Conta\n-> ";
      int t;
      cin >> t;
      if (t == 1){
        cout << "\nConta -> ";
        int c;
        cin >> c;
        if (naci.verificaConta(c)){
          int tc, tp;
        cout << "\n      - Tipo de Pessoa -\n\n    (1) Pessoa Fisica.\n    (2) Pessoa Juridica.\n\n-> ";
        cin >> tp;
        cout << "\n      - Tipo de Conta -\n\n    (1) Conta Corrente\n    (2) Conta Corrente Limite\n    (3) Conta Poupança\n-> ";
          cin >> tc;
          naci.cadastro(tc, tp);
        }
        else{
          cout << "\n    Conta Inválida!\n";
        }
      }
      else if (t == 2){
        cout << "\n---------Abrir Conta---------\n";
          int tc, tp;
          cout << "\n      - Tipo de Pessoa -\n\n    (1) Pessoa Fisica.\n    (2) Pessoa Juridica.\n\n-> ";
          cin >> tp;
          cout << "\n      - Tipo de Conta -\n\n    (1) Conta Corrente\n    (2) Conta Corrente Limite\n    (3) Conta Poupança\n-> ";
          cin >> tc;
          naci.cadastro(tc, tp);
      }
    }
    else if (v == (-1)){
      break;
    }
  }

  return 0;
}