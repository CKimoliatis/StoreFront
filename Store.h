#ifndef STORE_H
#define STORE_H

#include "Items.h"
#include "AllHeader.h"
using namespace std;

class Store{
private:
    vector<Items*> vec;
public:
    Store(){}
    Store(string n, double p, int s){
        Items* item = new Items(n, p, s);
        vec.push_back(item);
    }
    ~Store() {
        this->writeBin();
        for (auto item : vec) {
            delete item;
        }
        vec.clear();
    }

    void prompt(){
        string n;
        double p;
        int s;
        cout << "Enter the name of the item:\n";
        cin.ignore();
        getline(cin, n);
        cout << "Enter the price:\n";
        cin >> p;
        cout << "Enter the amount of stock:\n";
        cin >> s;
        vec.push_back(new Items(n,p,s));
    }
    
    void addItem(Items* i){
        vec.push_back(i);
    }

    Items* findItem(string name){
        for(auto x: vec){
            if(name == x->getName()){
                return x;
            }
        }
        return new Items();
    }

    void print(){
        int i = 1;
        cout << setw(25) << "Store Front\n";
        for(auto x: vec){
            cout << "\n" << setw(20) << "Item " << i << ": \n";
            x->print();
            i++;
        }
    }
    
    bool readBin(){
        fstream file("shop.bin", ios::in | ios::binary);
        if (!file) {
            return 0;
        }
        file.seekg(0, ios::end); // move the file pointer to the end
        int size = file.tellg(); // get the size of the file
        file.seekg(0, ios::beg); // move the file pointer back to the beginning

        // read the data for each Player object and create a new Player object for
        // each one
        while (file.tellg() < size) {
            string name;
            int stock;
            double price;
            file.read(reinterpret_cast<char *>(&price), sizeof(double));
            file.read(reinterpret_cast<char *>(&stock), sizeof(int));
            getline(file, name);
            Items *item = new Items(name, price, stock);
            addItem(item);
        }
        file.close();
        return 1;
    }
    
    void writeBin() {
        fstream file("shop.bin", ios::out | ios::binary | ios::trunc);
        if (!file) {
            cerr << "error opening file" << endl;
            return;
        }
        // write the data for each Player object to the file
        for (const auto &item : vec) {
            double price = item->getPrice();
            int stock = item->getStock();
            string name = item->getName();
            file.write(reinterpret_cast<char *>(&price), sizeof(double));
            file.write(reinterpret_cast<char *>(&stock), sizeof(int));
            file << name << endl;
        }
        file.close();
    }
};


#endif /* STORE_H */

