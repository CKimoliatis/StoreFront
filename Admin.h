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
    AdminInfo* info;
    vector<UserInfo*> users;
public:
    Admin(){
        info = new AdminInfo;
    }
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

    void adminPrompt(Store* store){
        int choice;
        do{
            cout << "\nMenu\n";
            cout << "1. Print all users\n";
            cout << "2. Change user status\n";
            cout << "3. See store\n";
            cout << "4. Add Item to store\n";
            cout << "5. Change a user's password\n";
            cout << "0. Logout\n";
            cout << "Enter choice shown above:\n";
            cin>>choice;
            if(choice == 1){
                this->printUsers();
            }else if(choice == 2){
                cout << "Enter username of user to change status\n";
                string n;
                cin>>n;
                this->changeUserStatus(n);
            }else if(choice == 3){
                store->print();
            }else if(choice == 4){
                string n;
                double p;
                int s;
                cout << "Enter the name of the item:\n";
                getline(cin, n);
                cout << "Enter the price:\n";
                cin >> p;
                cout << "Enter the amount of stock:\n";
                cin >> s;
                Items* item = new Items(n, p, s);
                store->addItem(item);
                delete item;
            }else if(choice == 5){
                cout << "Enter username to change password\n";
                string n;
                cin >> n;
                this->changeUserPass(n);
            }
        }while(choice != 0);
    }

    void changeUserPass(string n){
        char p[20];
        cout << "Enter new password:\n";
        cin >> p;
        for(auto &x: users){
            if(strcmp(n.c_str(), x->name) == 0){
                strcpy(x->password, p);
                cout << x->name << "'s password changed to " << x->password;
                break;
            }
        }
    }
    void changeUserStatus(string n){
        for(auto &x: users){
            if(n.compare(x->name)){
                x->active = !x->active;
                cout << x->name << "'s status changed to " << x->active;
                break;
            }
        }
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
        delete temp;
    }

    void printUsers(){
        cout << endl;
        int maxNameLength = 0;
        int maxPasswordLength = 0;
        for(auto x: users){
            maxNameLength = max(maxNameLength, (int)strlen(x->name));
            maxPasswordLength = max(maxPasswordLength, (int)strlen(x->password));
        }
        cout << setw(maxNameLength + 10) << left << "Users"
            << setw(maxPasswordLength + 10) << left << "Password"
            << "Status" << endl;
        for(auto x: users){
            cout << setw(maxNameLength + 10) << left << x->name
                << setw(maxPasswordLength + 10) << left << x->password
                << (x->active ? "Active" : "Inactive" ) << endl;
        }
    }
};

#endif /* ADMIN_H */
