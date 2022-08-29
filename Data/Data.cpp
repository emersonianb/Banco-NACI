#include "Data.h"
#include <iostream>

Data::Data(int d, int m, int a){
  this->dia = d;
  this->mes = m;
  this->ano = a;
}

int Data::getDia() const{
  return dia;
}
int Data::getMes() const{
  return mes;
}
int Data::getAno() const{
  return ano;
}

Data Data::getData(){
  struct tm *p;
  time_t seconds;
  time(&seconds);
  p = localtime(&seconds);
  int day = p->tm_mday;
  int mon = p->tm_mon + 1;
  int year = p->tm_year + 1900;
  Data dt(day, mon, year);
  return dt;
}