#include "SavingsBankAccount.h"
/*--------------Start SavingsBankAccount------------------*/ 
SavingsBankAccount::SavingsBankAccount(double Balance,double minimumBalance):BankAccount(Balance),minimumBalance(minimumBalance){
    type="Saving";
    if(minimumBalance>balance){
        balance=minimumBalance;
        this->minimumBalance=minimumBalance;
    }
}
void SavingsBankAccount:: set_minimumBalance(double minimumBalance){
    this->minimumBalance=minimumBalance;
}
double SavingsBankAccount:: get_minimumBalance(){
    return minimumBalance;
}
bool SavingsBankAccount::withdraw(double target){
    if(balance-target>=minimumBalance){
        balance-=target;
        return true;
    }
    return false;
}
bool SavingsBankAccount::deposit(double target){
    if(target>=100){
        balance+=target;
        return true;
    }
    return false;
}
/*--------------------End-----------------------------*/ 