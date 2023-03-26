#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Items.h"
#include "Store.h"
using namespace std;

int main(){
    Store* c = new Store();
    Store* c1 = new Store();
    fstream cart("cart.bin", ios::in| ios::out| ios::binary| ios::trunc);
    if (!cart) {
        cerr << "Error: failed to open file." << endl;
        return 1;
    }
    cout << "How many products:\n";
    int n;
    cin >>n;
    for(int i = 0; i < n; i++){
        cin.ignore();
        c->prompt();
    }
    cart.write(reinterpret_cast<char*>(c), sizeof(*c));
    cart.seekg(ios::beg);
    cart.read(reinterpret_cast<char*>(c1), sizeof(*c1));
    c1->print();
    cart.close();

}