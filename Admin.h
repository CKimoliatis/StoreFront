#ifndef ADMIN_H
#define ADMIN_H

#include "AllHeader.h"
#include "User.h"
#include "Store.h"
using namespace std;

struct AdminInfo{
    char name[20];
    char password[20];

    AdminInfo() : name(""), password("") {}
};

class Admin{
private:
    AdminInfo* info;
    vector<UserInfo*> users;
public:
    Admin(){
        info = new AdminInfo;
    };
    Admin(string n, string p){
        info = new AdminInfo;
        strcpy(info->name, n.c_str());
        strcpy(info->password, p.c_str());
        this->fillVec();
    }
    ~Admin(){
        delete info;
        for (auto x : users) {
            delete x;
        }
        users.clear();
    }
    void checkStore(Store* s){
        s->print();
    }
    void addAdmin(string n, string p){
        fstream file("admin.bin", ios::binary|ios::app|ios::out);
        AdminInfo* temp = new AdminInfo();
        strcpy(temp->name, n.c_str());
        strcpy(temp->password, p.c_str());
        file.write(reinterpret_cast<char*>(temp), sizeof(AdminInfo));
        file.close();
        delete temp;
    }
    void fillVec(){
        fstream file("users.bin", ios::binary|ios::in);
        int i = 0;
        UserInfo* temp = new UserInfo();
        while(file.read(reinterpret_cast<char*>(temp), sizeof(UserInfo))){
            users.push_back(temp);
            temp = new UserInfo();
        }
        file.close();
    }
    void printUsers(){
        for(auto x: users){
            cout << x->name << endl;
            cout << x->password << endl;
            cout << x->active << endl;
        }
    }
};

#endif /* ADMIN_H */
