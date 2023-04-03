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
    }
    ~Admin(){
        delete info;
        for (auto x : users) {
            delete x;
        }
        users.clear();
    }
};

#endif /* ADMIN_H */
