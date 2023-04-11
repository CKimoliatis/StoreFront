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
    void swapActiveUser(string n){
        for(auto x: users){
            if(strcmp(x->name, n.c_str()) == 0){
                x->active = !x->active;
                break;
            }
        }
    }

    void writeVec(){
        fstream file("users.bin", ios::binary|ios::out|ios::trunc);
        for(int i = 0; i < users.size(); i++){
            file.write(reinterpret_cast<char*>(users[i]), sizeof(UserInfo));
        }
        file.close();
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
            cout << "6. Create and admin account\n";
            cout << "0. Logout\n";
            cout << "Enter choice shown above:\n";
            cin>>choice;
            if(choice == 1){
                this->printUsers();
            }else if(choice == 2){
                this->changeUserStatus();
            }else if(choice == 3){
                store->print();
            }else if(choice == 4){
                store->prompt();
            }else if(choice == 5){
                this->changeUserPass();
            }else if(choice == 6){
                string n, p;
                cout << "Enter username of new admin account:\n";
                cin>>n;
                cout << "Enter password of new admin account:\n";
                cin>>p;
                this->addAdmin(n,p);
                cout << "New admin account created!\n";
            }else{
                cout << "Choice invalid. Please reenter choice.\n";
            }
        }while(choice != 0);
        this->writeVec();
    }

    void changeUserPass(){
        cout << "Enter username to change password\n";
        string n;
        cin >> n;
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

    void changeUserStatus(){
        cout << "Enter username of user to change status\n";
        string n;
        cin>>n;
        for(auto &x: users){
            if(strcmp(n.c_str(), x->name) == 0){
                x->active = !x->active;
                cout << x->name << "'s status changed to " << (x->active?"Active":"Inactive") << endl;
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
