#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <time.h>
#include "../Data/Data.h"
#include <string>
using std::string;

class Transacao{

friend ostream &operator<<(ostream &out, const Transacao& t)
{
  out << "[Valor: " << t.valor << ", " << t.descricao << ", " << t.data << "]";
  
  return out;
}

public:
  Transacao(){;}
  Transacao(double, string);
  ~Transacao(){;}

private:
  double valor;
  string descricao;
  void printTransacao() const;
  Data data;
};

#endif