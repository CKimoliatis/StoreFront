/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Store.h
 * Author: ckimo
 *
 * Created on March 25, 2023, 6:41 PM
 */

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
    void prompt(){
        string n;
        double p;
        int s;
        cout << "Enter name: " << endl;
        getline(cin, n);
        cout << "Enter price: " << endl;
        cin >> p;
        cout << "Enter stock: " << endl;
        cin >> s;
        vec.push_back(new Items(n,p,s));
    }

    void print(){
        int i = 1;
        for(auto x: vec){
            cout << "Item " << i << ": \n";
            x->print();
            i++;
        }
    }
};


#endif /* STORE_H */

