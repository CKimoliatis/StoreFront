#ifndef USER_H
#define USER_H

#include "AllHeader.h"
#include "Items.h"
#include "Store.h"


using namespace std;

struct UserInfo
{
    char name[20];
    char password[20];
    bool active;

    UserInfo() : name(""), password(""), active(true) {}
};

class User
{
private:
    UserInfo *info;
    map<Items *, int> cart;
    double total;
public:
    User();
    User(string, string);
    ~User();
    string getName();
    string getPass();
    void setName(string);
    void setPass(string);
    void addToCart(Items *, int);
    void addToCart(string, int, Store *);
    void delItem(string, int);
    void userPrompt(Store *);
    void checkout();
    void printUser();
    void printCart();
    void verifyUser();
};

#endif /* USER_H */
