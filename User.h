#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Items.h"

using namespace std;

class User{
private:
    string name;
    string password;
    map<Items*, int> cart1;
public:
    User(){
        name = "";
        password = "";
    }
    User(string n, string p){
        name = n;
        password = p;
    }

    void addToCart(Items* item, int n){
        cart1[item]+= n;
    }

    void delItem(string name, int n) {
        for (auto &x:cart1) {
            if (name == x.first->getName()) {
                x.second-= n;
                break;
            }
        }
    }

    void printUser(){
        int tot = 0;
        for(auto x: cart1){
            tot+= x.second;
        }
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Number of items in cart: " << tot << endl;
    }

    void printCart(){
        int i = 1;
        for(const auto x:cart1){
            if(x.second >0){
                cout << "Item " << i << ":" << endl;
            x.first->print();
            cout << "Quantity: " << x.second << endl;
            i++;
            }
            
        }
    }
};



#endif /* USER_H */

