#include "Banco.h"
#include <iterator>

Banco::Banco(string nome, string cnpj, string razao) : PessoaJuridica(nome, cnpj, razao){}


Banco::~Banco(){
  for (auto el : contas){
    delete el;
  }
  for (auto el : correntistas){
    delete el;
  } 
}

void Banco::cadastro(int &tc, int &tp){
  string nome, cnpj, razao, cpf;
  double lim;
  cout << "\n  Nome-> ";
  cin.ignore();
  getline(cin, nome);

  if (!(verificaPessoa(nome))){
    if (tp == 1){
      cout << "  CPF-> ";
      cin >> cpf;
      Pessoa *p = new PessoaFisica(nome, cpf);
      correntistas.push_back(p);
      if (tc == 1){
        contas.push_back(new ContaCorrente(contas.size(), p));
      }
      else if (tc == 2){
        cout << "  Limite-> ";
        cin >> lim;
        contas.push_back(new ContaCorrenteLimite(contas.size(), p, lim));
      }
      else if (tc == 3){
        contas.push_back(new ContaPoupanca(contas.size(), p));
      }
    }
    else if (tp == 2){
      cout << "  CNPJ->";
      cin >> cnpj;
      cout << "  Razão Social-> ";
      cin.ignore();
      getline(cin, razao);
      Pessoa *p = new PessoaJuridica(nome, cnpj, razao);
      correntistas.push_back(p);
      if (tc == 1){
        contas.push_back(new ContaCorrente(contas.size(), p));
      }
      else if (tc == 2){
        cout << "  Limite-> ";
        cin >> lim;
        contas.push_back(new ContaCorrenteLimite(contas.size(), p, lim));
      }
      else if (tc == 3){
        contas.push_back(new ContaPoupanca(contas.size(), p));
      }
    }
  }
  else{
    if (tp == 1){
      if (tc == 1){
        contas.push_back(new ContaCorrente(contas.size(), getPessoa(nome)));
      }
      else if (tc == 2){
        cout << "  Limite-> ";
        cin >> lim;
        contas.push_back(new ContaCorrenteLimite(contas.size(), getPessoa(nome), lim));
      }
      else if (tc == 3){
        contas.push_back(new ContaPoupanca(contas.size(), getPessoa(nome)));
      }
    }
    else if (tp == 2){
      if (tc == 1){
        contas.push_back(new ContaCorrente(contas.size(), getPessoa(nome)));
      }
      else if (tc == 2){
        cout << "  Limite-> ";
        cin >> lim;
        contas.push_back(new ContaCorrenteLimite(contas.size(), getPessoa(nome), lim));
      }
      else if (tc == 3){
        contas.push_back(new ContaPoupanca(contas.size(), getPessoa(nome)));
      }
    }
  }
  cout << "\n    Sua conta esta pronta!\n\n";
  consultar(contas.size()-1);
}

void Banco::consultar(int conta) const{
  bool esta = false;
  for(auto el : contas){
    if(el->getNumConta() == conta){
      esta = true;
    }
  }

  if (esta){
    for (auto el : contas){
      if (el->getNumConta() == conta){
        el->extrato();
      }
    }
  }
  else if (!esta){
    cout << "A conta não existe!\n";
  }
}

bool Banco::verificaConta(int &conta) const{
  bool esta = false;
  for(auto el : contas){
    if(el->getNumConta() == conta){
      esta = true;
    }
  }
  return esta;
}

bool Banco::verificaPessoa(string &pessoa) const{
  bool esta = false;
  for (auto el : correntistas){
    if (el->getNome() == pessoa){
      esta = true;
    }
  }
  return esta;
}

void Banco::remover(int &conta){
  int cont = 0;
  bool esta = false;
  for(auto *el : contas){
    if(el->getNumConta() == conta){
      esta = true;
      break;
    }
    cont++;
  }

  if (esta){
    list<Conta*>::iterator it = contas.begin();
    for(int i = 0; i < cont; i++)
      it++;
    contas.erase(it);
  }
  else{
    cout << "A conta não existe!" << endl << endl;
  }
}

void Banco::listarContas() const{
  cout << "Banco: " << getNome() << std::endl;
  for (auto *el : contas){
    cout << "\nConta: ";
    cout.fill('0');
    cout << setw(3) << el->getNumConta() << std::endl;
    cout << "Cliente: " << el->getNomeCorrentista() << std::endl << std::endl;
  }
}

void Banco::listarContasCorrentistas(string &correntista) const{
  cout << "Contas de " << correntista << std::endl << std::endl;
  for (auto *el : contas){
    if (el->getNomeCorrentista() == correntista){
      el->extrato();
    }
  }
}

void Banco::atualizarConta(int &conta){
  bool esta = false;
  for(auto *el : contas){
    if(el->getNumConta() == conta){
      esta = true;
      break;
    }
  }

  string nome;
  
  if (esta){
    for (auto el : contas){
      if (el->getNumConta() == conta){
          cout << "Nome-> ";
          cin >> nome;
          (el->getCorrentista())->setNome(nome);
      }
    }
  }
  else{
    cout << "A conta não existe!" << endl << endl;
  }
}

Pessoa* Banco::getPessoa(string &nome) const{
  for (auto el : correntistas){
    if (el->getNome() == nome){
      return el;
    }
  }
}

Conta* Banco::getConta(int &conta) const{
  for (auto el : contas){
    if (el->getNumConta() == conta){
      return el;
    }
  }
}