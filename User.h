#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Items.h"

using namespace std;

class User{
private:
    string name;
    string password;
    vector<Items*> cart;
public:
    User(){
        name = "";
        password = "";
    }
    User(string n, string p){
        name = n;
        password = p;
    }

    void addToCart(Items* item){
        cart.push_back(item);
    }

    void delItem(string name) {
        vector<Items *>::iterator it;
        it = cart.begin();
        for (int i = 0; i < p.size(); i++) {
        if (name == cart[i]->getName()) {
            cart.erase(it);
            break;
        }
        it++;
    }
}

    void printUser(){
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Number of items in cart: " << cart.size() << endl;
    }

    void printCart(){
        int i = 1;
        for(const auto x:cart){
            cout << "Item " << i << ":" << endl;
            x->print(); 
            i++;
        }
    }
};



#endif /* USER_H */

