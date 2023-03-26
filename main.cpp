#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Items.h"
#include "Store.h"
#include "User.h"
using namespace std;

int main(){
    /*Store* c = new Store();
    Store* c1 = new Store();
    c->addItem(item1);
    c->addItem(item2);
    c->writeBin();
    c1->readBin();
    c1->print();*/
    Items* item1 = new Items("Apple", 23.50, 30);
    Items* item2 = new Items("Orange", 22.50, 12);
    User * user = new User("Chris", "123");
    user->addToCart(item1, 1);
    user->addToCart(item2, 2);
    user->addToCart(item2, 2);
    user->delItem("Orange", 4);
    user->printCart();
}