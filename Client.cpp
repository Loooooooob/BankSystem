#include "Client.h"

Client::Client(string name,string address,string phoneNum){
    this->name=name;
    this->address=address;
    this->phoneNum=phoneNum;
}
string Client::getName(){return name;}
string Client::getAddress(){return address;}
string Client::getPhonenum(){return phoneNum;}