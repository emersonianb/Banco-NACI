#include "Transacao.h"
using std::cout;

Transacao::Transacao(double valor, string descricao){
  this->valor = valor;
  this->descricao = descricao;
  this->data = data.getData();
}
