#ifndef ADMIN_H
#define ADMIN_H

#include "AllHeader.h"
#include "User.h"
#include "Store.h"
#include "Items.h"
using namespace std;

struct AdminInfo{
    char name[20];
    char password[20];

    AdminInfo() : name(""), password("") {}
};

class Admin{
private:
    AdminInfo *info;
    vector<UserInfo *> users;

public:
    Admin();
    Admin(string, string);
    ~Admin();
    void swapActiveUser(string);
    void writeVec();
    void checkStore(Store *s);
    void addAdmin(string, string);
    void adminPrompt(Store *);
    void changeUserPass();
    void changeUserStatus();
    void fillVec();
    void printUsers();
};

#endif /* ADMIN_H */
