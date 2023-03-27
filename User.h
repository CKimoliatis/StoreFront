#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Items.h"
#include "Store.h"

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

    void addToCart(string n, int q, Store* s){
        Items* item = s->findItem(n);
        cart1[item]+= q;
    }

    void delItem(string name, int n) {
        for (auto &x:cart1) {
            if (name == x.first->getName()) {
                x.second-= n;
                break;
            }
        }
    }

    void userPrompt(Store* store){
        int choice;
        while(1){
            cout << "\nMenu:\n";
            cout << "1. See Store Front.\n";
            cout << "2. See Cart\n";
            cout << "3. Logout\n";
            cin >> choice;
            if(choice == 1){
                cout << endl;
                while(1){
                    store->print();
                    string n;
                    int q;

                    cout << "\nWould you like to add anything to Cart?\n";
                    cout << "If not enter 0 to return to menu\n";
                    cout << "Enter quantity:\n";
                    cin >> q;
                    cout << "Enter name of item:\n";
                    cin.ignore();
                    getline(cin, n);
                    addToCart(n, q, store);

                    cout << "\nEnter 0 to return to Menu.\n";
                    cout << "Enter 1 to add more to cart.\n";
                    cout << "Enter 2 to see cart.\n";
                    int choice;
                    cin>> choice;
                    cout << endl;
                    
                    if(choice == 0){
                        break;
                    }else if(choice == 1){
                        continue;
                    }else if(choice == 2){
                        printCart();
                        cout << "\nEnter 0 to return to Menu.\n";
                        cout << "Enter 1 to add more to cart.\n";
                        int ret;
                        cin>>ret;
                        if(ret == 0)break;
                        else continue;
                    }
                }
            }else if(choice == 2){
                printCart();
                //TODO adding more prompts
            }else if(choice == 3){
                cout << "Thank you for using the store!";
                return;
            } 
        }
    }

    void printUser(){
        int tot = 0;
        for(auto x: cart1){
            tot += x.second;
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

