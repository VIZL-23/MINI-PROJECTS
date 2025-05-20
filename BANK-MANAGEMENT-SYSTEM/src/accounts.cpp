#include "../include/accounts.h"
#include <iostream>

using namespace std;

//SAVINGSacc_CLASS_FUNCTIONS
  SavingsAccount::SavingsAccount(int accno, string name, int bal){
      this->accno = accno;
      this->name = name;
      this->bal = bal;
      this->time=1;
    }
  void SavingsAccount::deposit(int amount){
      bal+=amount;
      cout<<"DEPOSITED AMOUNT: "<<amount<<endl;
    }
  void SavingsAccount::withdraw(int amount){
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
  void SavingsAccount::display(){
      cout<<"TOTAL AMOUNT IN YOUR SAVINGS ACCOUNT: "<<bal+bal*time*rate*0.01<<endl;
    }
  string SavingsAccount::toString(){
    return to_string(accno)+","+name+",Savings,"+to_string(bal);
    }
  int SavingsAccount::rate=5;

//CURRENTacc_CLASS_FUNCTIONS
  CurrentAccount::CurrentAccount(int accno, string name, int bal){
      this->accno = accno;
      this->name = name;
      this->bal = bal;
    }
  void CurrentAccount::deposit(int amount){
      bal+=amount;
      cout<<"DEPOSITED AMOUNT: "<<amount<<endl;
    }
  void CurrentAccount::withdraw(int amount){
      if(bal-amount>0){
          bal-=amount;  
          cout<<"WITHDRAWED AMOUNT: "<<amount;
        }
      else{
        cout<<"LOW BALANCE, PLEASE DEPOSIT SOME AMOUNT"<<endl;
      }
    }
  void CurrentAccount::display(){
      cout<<"TOTAL AMOUNT IN YOUR CURRENT ACCOUNT: "<<bal<<endl;
    }
  string SavingsAccount::toString(){
    return to_string(accno)+","+name+",Current,"+to_string(bal);
    }
