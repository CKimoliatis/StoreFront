#ifndef INIT_H
#define INIT_H

#include "AllHeader.h"
#include "Store.h"
#include "User.h"
#include "Items.h"
using namespace std;

class Init{
private:
    vector<User*> user;
    Store * store;
public:
    Init(){
        store = new Store();
        if(!store->readBin()){
            Items* item1 = new Items("Apple", 3.50, 30);
            Items* item2 = new Items("Orange", 2.50, 12);
            store->addItem(item1);
            store->addItem(item2);
            store->writeBin();
        }
    }

    void readUsers(){
        fstream file("users.bin", ios::binary | ios::in);
        string n, p;
        if (file.is_open()) {
            while (file.peek() != EOF) {
                User* ptr = new User();
                file.read(reinterpret_cast<char*>(ptr), sizeof(User));
                user.push_back(ptr);
            }
        }
        file.close();
    }

    void writeUsers(){
        user.push_back(new User("1", "1"));
        user.push_back(new User("2", "2"));
        fstream file("users.bin", ios::binary|ios::out);
        if(file.is_open()){
            for(const auto& x: user){
                file.write(reinterpret_cast<char*>(x), sizeof(User));
            }
        }
        file.close();
    }

    void printUsers(){
        for (int i = 0; i < user.size(); i++){
            cout << "User " << i + 1 << endl;
            cout << "Username: " << user[i]->getName() << endl;
            cout << "Password: " << user[i]->getPass() << endl;
            cout << endl;
        }
    }

    void printStore(){
        store->print();
    }
};


#endif /* INIT_H */

