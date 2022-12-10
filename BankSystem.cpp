#include "BankSystem.h"
#include "SavingsBankAccount.h"

/*------------------Start BankAccount----------------------*/ 
BankAccount::BankAccount(){
    balance=0;
    type="Basic";
    account_id="FCAI-"+to_string(++A);
}

BankAccount::BankAccount(double balance):balance(balance){
    type="Basic";
    account_id="FCAI-"+to_string(++A);
}

void BankAccount:: setBalance(double balance){this->balance=balance;}
string BankAccount::getAccount_id(){return account_id;}
double BankAccount::getBalance(){return balance;}
string BankAccount::getType(){return type;}
void BankAccount::setOwner(Client &c){
    owner=&c;
}
/*--------------------End-----------------------------*/ 

