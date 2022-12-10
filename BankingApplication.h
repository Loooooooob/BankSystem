#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H
#include"BankSystem.h"
#pragma once

class BankingApplication{
    private:
        vector<BankAccount*>v1;
        vector<Client*>v2;
    public:
        ~BankingApplication();
        int choice;
        void menu();
        void run();
};

#endif