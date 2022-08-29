#ifndef DATA_H
#define DATA_H

#include <iostream>
using std::ostream;

class Data
{

friend ostream &operator<<(ostream &out, Data data)
{
  std::cout << data.getDia() << "/" << data.getMes() << "/" << data.getAno();

  return out;
}

public:
  Data(){;}
  Data(int, int, int);
  virtual ~Data(){;}
  int getDia() const;
  int getMes() const;
  int getAno() const;
  Data getData();


private:
  int dia;
  int mes;
  int ano;
};

#endif