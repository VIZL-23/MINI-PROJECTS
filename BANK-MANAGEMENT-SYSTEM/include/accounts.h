#ifndef accounts_h
#define accounts_h
#include <iostream>

using namespace std;

class Account{
public:
  int accno;
  string name;
  int bal;

  virtual void deposit(int amount) = 0;
  virtual void withdraw(int amount) = 0;
  virtual void display() = 0;
  virtual string toString() = 0;
  
};

class SavingsAccount: public Account{
public:
  SavingsAccount(int accno, string name, int bal);

  int time;
  static int rate;

  void deposit(int amount)override;
  void withdraw(int amount)override;
  void display()override;
  string toString() override;
};


class CurrentAccount: public Account{
public:
  CurrentAccount(int accno, string name, int bal);

  void deposit(int amount)override;
  void withdraw(int amount)override;
  void display()override;

};




#endif