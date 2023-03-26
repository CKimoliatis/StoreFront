/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Items.h
 * Author: ckimo
 *
 * Created on March 25, 2023, 6:07 PM
 */

#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
        cout << "Price: $" << price << endl;
        cout << "In stock: " << stock << endl;
    }
    void changeName(string n){
        name = n;
    }

    void changePrice(double p){
        price = p;
    }
};


#endif /* ITEMS_H */

