#include "BankingApplication.h"
#include "SavingsBankAccount.h"
#include "BankSystem.h"
/*---------------Start BankingApplication---------------*/ 
BankingApplication::~BankingApplication(){
    for(auto i:v1)
        delete i;

    for(auto i:v2)
        delete i;
}
void BankingApplication:: menu(){
    cout<<"Welcome to FCAI Banking Application\n";
    cout<<"1. Create a New Account\n";
    cout<<"2. List Clients and Accounts\n";
    cout<<"3. Withdraw Money\n";
    cout<<"4. Deposit Money\n";
    cout<<"Please Enter Choice =========> ";
    cin>>choice;
}
void BankingApplication:: run(){
    if(choice==1){
        string Name,Address,Phone,Type;
        double Balance,minb;
        cin.ignore();
        cout<<"Please Enter Client Name =========> ";getline(cin,Name);
        cout<<"Please Enter Client Address =======> ";getline(cin,Address);
        cout<<"Please Enter Client Phone =======> ";getline(cin,Phone);
        cout<<"What Type of Account Do You Like? (1) Basic (2) Saving � Type 1 or 2 =========> ";
            cin>>Type;
        cout<<"Please Enter the Starting Balance =========> ";
            cin>>Balance;
            Client c(Name,Address,Phone);
        if(Type=="1"){
            BankAccount b=BankAccount(Balance);
            v1.push_back(new BankAccount(b));
            cout<<"An account was created with ID "<<b.getAccount_id()<<" and Starting Balance"<<b.getBalance()<<" L.E.\n";
        }
        else if(Type=="2"){
                cout<<"Enter the minimum balance =========> ";
                cin>>minb;
                SavingsBankAccount s(Balance,minb);
                cout<<"An account was created with ID "<<s.getAccount_id()<<" and Starting Balance"<<s.getBalance()<<" L.E.\n";
                v1.push_back(new SavingsBankAccount (s));
        }
        v2.push_back(new Client(c));
        v2[v2.size()-1]->setbankAcc(*v1[v1.size()-1]);
        (v1[v1.size()-1])->setOwner(*v2[v2.size()-1]);
    }
    else if(choice==2){
        for(int i=0;i<v1.size();i++){
            cout<<"name: "<<v1[i]->getOwner()->getName()<<"\n";
            cout<<"address: "<<v1[i]->getOwner()->getAddress()<<"\n";
            cout<<"Phone Num: "<<v1[i]->getOwner()->getPhonenum()<<"\n";
            cout<<"ID: "<<v1[i]->getAccount_id()<<"\n";
            cout<<"Balance: "<<v1[i]->getBalance()<<"\n";
            cout<<"Type: "<<v1[i]->getType()<<"\n";
        }
    }
    else if(choice==3){
        string id;
        double amount;
        bool valid;
        cout<<"Enter your account id: =========> ";
        cin>>id;
        for(int i=0;i<v1.size();i++){
            if(id==v1[i]->getAccount_id()){
                cout<<"Balance: "<<v1[i]->getBalance()<<"\n";
                cout<<"Type: "<<v1[i]->getType()<<"\n";
                while(true){
                    cout<<"Enter the amount : =========> ";
                    cin>>amount;
                    valid=v1[i]->withdraw(amount);
                    if(valid){
                        cout<<"Done..your new balance is now:   "<<v1[i]->getBalance()<<"\n";
                        break;
                        }
                    else cout<<"Oops,There are not enough money...please try again\n";

                }
            break;
            }
        }

    }
    else if(choice==4){
        string id;
        double amount;
        bool valid;
        cout<<"Enter your account id: =========> ";
        cin>>id;
        for(int i=0;i<v1.size();i++){
            if(id==v1[i]->getAccount_id()){
                cout<<"Balance: "<<v1[i]->getBalance()<<"\n";
                cout<<"Type: "<<v1[i]->getType()<<"\n";
                while(true){
                    cout<<"Enter the amount : =========> ";
                    cin>>amount;
                    valid=v1[i]->deposit(amount);
                    if(valid){
                        cout<<"Done..your new balance is now:   "<<v1[i]->getBalance()<<"\n";
                        break;
                        }
                    else cout<<"Oops,you can not deposit under 100...please try again\n";

                }
            break;
            }
        }

    }
}