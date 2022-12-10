#include"BankSystem.h"
#include"BankSystem.cpp"
#include"SavingsBankAccount.h"
#include"SavingsBankAccount.cpp"
#include"Client.h"
#include"Client.cpp"
#include"BankingApplication.h"
#include"BankingApplication.cpp"
int main(){
    BankingApplication person;
    bool cn=true;
    while(cn){
        person.menu();
        person.run();
        cout<<"\nwanna continue? one or zero:  ";
        cin>>cn;
    }

}