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

public:
    User()
    {
       info = new UserInfo;
    }
    User(string n, string p)
    {
        info = new UserInfo;
        strcpy(info->name, n.c_str());
        strcpy(info->password, p.c_str());
    }
    ~User(){
        delete info;
    }
    string getName()
    {
        return info->name;
    }
    string getPass()
    {
        return info->password;
    }
    void setName(string n)
    {
        strcpy(info->name, n.c_str());
    }
    void setPass(string p)
    {
        strcpy(info->password, p.c_str());
    }

    void addToCart(Items *item, int n)
    {
        cart[item] += n;
    }

    void addToCart(string n, int q, Store *s)
    {
        Items *item = s->findItem(n);
        cart[item] += q;
    }

    void delItem(string name, int n)
    {
        for (auto &x : cart)
        {
            if (name == x.first->getName())
            {
                x.second -= n;
                break;
            }
        }
    }

    void userPrompt(Store *store)
    {
        int choice;
        while (1)
        {
            cout << "\nMenu:\n";
            cout << "1. See Store Front.\n";
            cout << "2. See Cart\n";
            cout << "3. Logout\n";
            cout << "Enter a number corresponding to the action:\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << endl;
                while (1)
                {
                    store->print();
                    string n;
                    int q;

                    cout << "\nWould you like to add anything to Cart?\n";
                    cout << "If not enter 0 to return to menu\n";
                    cout << "Enter quantity:\n";
                    cin >> q;
                    cout << "Enter name of item:\n";
                    cin.ignore();
                    getline(cin, n);
                    addToCart(n, q, store);

                    cout << "\nEnter 0 to return to Menu.\n";
                    cout << "Enter 1 to add more to cart.\n";
                    cout << "Enter 2 to see cart.\n";
                    int choice;
                    cin >> choice;
                    cout << endl;

                    if (choice == 0)
                    {
                        break;
                    }
                    else if (choice == 1)
                    {
                        continue;
                    }
                    else if (choice == 2)
                    {
                        printCart();
                        cout << "\nEnter 0 to return to Menu.\n";
                        cout << "Enter 1 to add more to cart.\n";
                        int ret;
                        cin >> ret;
                        if (ret == 0)
                            break;
                        else
                            continue;
                    }
                }
            }
            else if (choice == 2)
            {
                printCart();
                int n;
                cout << "Enter any integer to return to menu.\n";
                cin >> n;
            }
            else if (choice == 3)
            {
                cout << "Thank you for using the store!";
                return;
            }
        }
    }

    void printUser()
    {
        int tot = 0;
        for (auto x : cart)
        {
            tot += x.second;
        }
        cout << "Name: " << info->name << endl;
        cout << "Password: " << info->password << endl;
        cout << "Number of items in cart: " << tot << endl;
    }

    void printCart()
    {
        int i = 1;
        if (cart.empty())
        {
            cout << "Your cart is empty!\n";
        }
        else
        {
            cout << "\n-------Cart-------\n\n";
            for (const auto x : cart)
            {
                if (x.second > 0)
                {
                    cout << "Item " << i << ":" << endl;
                    x.first->print();
                    cout << "Quantity: " << x.second << endl
                         << endl;
                    i++;
                }
            }
        }
    }

    void verifyUser()
    {
        bool userFound = false;
        fstream file("users.bin", ios::binary | ios::in);

        // Loop through each UserInfo struct in the file
        UserInfo *temp = new UserInfo;
        while(file.read(reinterpret_cast<char*>(temp),sizeof(UserInfo))){
            if(strcmp(temp->name,info->name) == 0 && strcmp(temp->password, info->password) == 0){
                cout << "\nWelcome back " << temp->name << "!" << endl;
                userFound = true;
            }else if(strcmp(temp->name,info->name) == 0 && strcmp(temp->password, info->password) != 0){
                do{
                    cout << "Wrong Password Please Reenter Password:\n";
                    cin >> info->password;
                    userFound = true;
                }while(strcmp(temp->password, info->password) != 0);
            }
        }
        file.close();

        // If user not found, add them to the file
        if (!userFound)
        {
            file.open("users.bin", ios::binary | ios::app);
            if (!file)
            {
                cerr << "Error opening output file." << endl;
                delete temp;
                return;
            }

            file.write(reinterpret_cast<char *>(info), sizeof(UserInfo));
            cout << "User added to file." << endl;

            file.close();
        }

        delete temp;
    }
};

#endif /* USER_H */
