#ifndef CLIENT_H
#define CLIENT_H
#include"BankSystem.h"
#pragma once

class Client{
    private:
        string name,address,phoneNum;
        BankAccount *bankAcc;
    public:
        void setbankAcc(BankAccount &ba){
            bankAcc=&ba;
        }
        Client(string name,string address,string phoneNum);
        string getName();
        string getAddress();
        string getPhonenum();

};
Client* BankAccount::getOwner(){
    return owner;
}

#endif