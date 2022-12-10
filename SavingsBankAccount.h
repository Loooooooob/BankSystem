#ifndef SAVINGSBANKACCOUNT_H
#define SAVINGSBANKACCOUNT_H

#pragma once

class SavingsBankAccount:public BankAccount{
   private:
        double minimumBalance=1000;
    public:
    SavingsBankAccount(double Balance,double minimumBalance);
    //setters & getters
    void set_minimumBalance(double minimumBalance);
    double get_minimumBalance();
    bool withdraw(double target);
    bool deposit(double target);
};
#endif