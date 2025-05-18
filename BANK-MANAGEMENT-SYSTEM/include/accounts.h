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
private:
  int time;
public:
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
    cout<<"TOTAL AMOUNT IN YOUR SAVINGS ACCOUNT: "<<bal<<endl;
  }
};

class CurrentAccount: public Account{
public:


};




#endif