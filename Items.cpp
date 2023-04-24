#include "Items.h"

Items::Items(string n, double p, int s) {
    name = n;
    price = p;
    stock = s;
}

void Items::print() const {
    cout << left << setw(15) << "Item name:" << setw(20) << right << name << endl;
    cout << left << setw(15) << "Price:" << setw(16) << right << "$ " << fixed << setprecision(2) << price << endl;
    cout << left << setw(15) << "In stock:" << setw(20) << right << stock << endl;
}

void Items::setName(string n) {
    name = n;
}

void Items::setPrice(double p) {
    price = p;
}

void Items::setStock(int s) {
    stock = s;
}

string Items::getName() {
    return name;
}

double Items::getPrice() {
    return price;
}

int Items::getStock() {
    return stock;
}