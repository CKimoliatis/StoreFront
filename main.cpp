#include "AllHeader.h"
#include "Items.h"
#include "Store.h"
#include "User.h"
#include "Admin.h"
using namespace std;

void addAdmin(){
    AdminInfo* a1 = new AdminInfo();
    strcpy(a1->name, "admin");
    strcpy(a1->password, "admin");
    fstream file("admin.bin", ios::binary| ios::out);
    file.write(reinterpret_cast<char*>(a1), sizeof(AdminInfo));
    file.close();
    delete a1;
}

bool checkAcc(string n, string p){
    fstream file("users.bin", ios::binary|ios:: in);
    AdminInfo* temp = new AdminInfo();
    while(file.read(reinterpret_cast<char*>(temp), sizeof(AdminInfo))){
        if(n.compare(temp->name) == 0 && p.compare(temp->password) == 0){
            file.close();
            delete temp;
            return true;
        }
    }
    file.close();
    delete temp;
    return false;
}

int main()
{
    Store* store = new Store();
    if(!store->readBin()){
        Items* item1 = new Items("Apple", 3.50, 30);
        Items* item2 = new Items("Orange", 2.50, 12);
        store->addItem(item1);
        store->addItem(item2);
        store->writeBin();
    }
    string n, p;
    cout << "Enter Username:\n";
    cin>>n;
    cout << "Enter Password:\n";
    cin>>p;
    if(checkAcc(n, p)){
        Admin* admin = new Admin(n,p);
        delete admin;
    }else{
        User* user = new User(n,p);
        user->verifyUser();
        user->userPrompt(store);
        delete user;
    }

    
    //user->printUser();
    delete store;
    
}