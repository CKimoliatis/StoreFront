#ifndef ADMIN_H
#define ADMIN_H

#include "AllHeader.h"
#include "User.h"
#include "Store.h"
using namespace std;

class Admin{
private:
    string name;
    string password;
public:
    Admin(){};
    Admin(string n, string p){
        name = n;
        password = p;
    }
};

#endif /* ADMIN_H */
