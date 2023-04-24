#ifndef STORE_H
#define STORE_H

#include "Items.h"
#include "AllHeader.h"
using namespace std;

class Store{
private:
    vector<Items*> items;
public:
    Store(){}
    Store(string, double, int);
    ~Store();
    void prompt();
    void addItem(Items*);
    Items* findItem(string);
    void print();
    bool readBin();
    void writeBin();
};


#endif /* STORE_H */

