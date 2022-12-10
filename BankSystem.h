#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include<bits/stdc++.h>
using namespace std;

class Client;
class BankAccount{
    protected:
        static int A;
        double balance;
        string account_id,type;
        Client *owner;
    public:
        BankAccount();
        BankAccount(double balance);

        //setters & getters
        void setBalance(double balance);
        string getAccount_id();
        double getBalance();
        string getType();
        //withdrawing and depositting
        virtual bool withdraw(double target){
            if(balance-target>=0){
                balance-=target;
                return true;}
            return false;
        }
        virtual bool deposit(double target){
            balance+=target;
            return true;
        }
        void setOwner(Client &c);/*{
            owner=&c;
        }*/
        Client* getOwner();
};
int BankAccount::A=0;
#endif