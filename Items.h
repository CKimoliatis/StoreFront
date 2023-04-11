#ifndef ITEMS_H
#define ITEMS_H

#include "AllHeader.h"
using namespace std;

class Items{
private:
    string name;
    double price;
    int stock;
public:
    Items() = default;
    Items(string n, double p, int s){
        name = n;
        price = p;
        stock = s;
    }

    void print() const {
        cout << left << setw(15) << "Item name:" << setw(20) << right << name << endl;
        cout << left << setw(15) << "Price:" << setw(16) << right << "$ " << fixed << setprecision(2) << price << endl;
        cout << left << setw(15) << "In stock:" << setw(20) << right << stock << endl;
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

