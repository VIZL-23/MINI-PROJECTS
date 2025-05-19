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
  
};

class SavingsAccount: public Account{
public:
  SavingsAccount(int accno, string name, int bal){
    this->accno = accno;
    this->name = name;
    this->bal = bal;
  }

  int time;
  static int rate;

  void deposit(int amount)override{
    bal+=amount;
    cout<<"DEPOSITED AMOUNT: "<<amount<<endl;
  }

  void withdraw(int amount)override{
    if(bal-amount>0){
      if(amount>10000){
        cout<<"MAXIMUM WITHDRAWAL AMOUNT IS 10000"<<endl;
      }
      else{
        bal-=amount;  
        cout<<"WITHDRAWED AMOUNT: "<<amount;
      }
    }
    else{
      cout<<"LOW BALANCE, PLEASE DEPOSIT SOME AMOUNT"<<endl;
    }
  }
  void display()override{
    cout<<"TOTAL AMOUNT IN YOUR SAVINGS ACCOUNT: "<<bal+bal*time*rate*0.01<<endl;
  }
};

int SavingsAccount::rate=5;

class CurrentAccount: public Account{
public:
  CurrentAccount(int accno, string name, int bal){
    this->accno = accno;
    this->name = name;
    this->bal = bal;
  }
  void deposit(int amount)override{
      bal+=amount;
      cout<<"DEPOSITED AMOUNT: "<<amount<<endl;
    }

    void withdraw(int amount)override{
      if(bal-amount>0){
          bal-=amount;  
          cout<<"WITHDRAWED AMOUNT: "<<amount;
        }
      else{
        cout<<"LOW BALANCE, PLEASE DEPOSIT SOME AMOUNT"<<endl;
      }
    }
    void display()override{
      cout<<"TOTAL AMOUNT IN YOUR CURRENT ACCOUNT: "<<bal;
    }

};




#endif