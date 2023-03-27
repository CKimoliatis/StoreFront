#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Items.h"
#include "Store.h"
#include "User.h"
using namespace std;

int main(){
    Store* c = new Store();
    Store* c1 = new Store();
    Items* item1 = new Items("Apple", 3.50, 30);
    Items* item2 = new Items("Orange", 2.50, 12);
    c->addItem(item1);
    c->addItem(item2);
    c->writeBin();
    c1->readBin();
    string name, pass;
    cout << "Enter Username:\n";
    getline(cin, name);
    cout << "Enter Password:\n";
    getline(cin, pass);

    User * user1 = new User(name, pass);
    user1->userPrompt(c1);
}