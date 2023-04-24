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
    Items(string, double, int);
    void print() const;
    void setName(string);
    void setPrice(double );
    void setStock(int );
    string getName();
    double getPrice();
    int getStock();
};
#endif /* ITEMS_H */

