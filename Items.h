#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Items{
private:
    string name;
    double price;
    int stock;
public:
    Items(string n, double p, int s){
        name = n;
        price = p;
        stock = s;
    }

    void print(){
        cout << "Item name: " << name << endl;
        cout << fixed << setprecision(2) << "Price: $" << price << endl;
        cout << "In stock: " << stock << endl;
    }
    
    void setName(string n){
        name = n;
    }
    void setPrice(double p){
        price = p;
    }
    void setStock(int s){
        stock = s;
    }
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
    int getStock(){
        return stock;
    }
    
};
#endif /* ITEMS_H */

