#include "AllHeader.h"
#include "Items.h"
#include "Store.h"
#include "User.h"
using namespace std;

void checkAcc(User* user){
    fstream file("users.bin", ios::binary|ios:: in);

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
    User* user = new User(n,p);
    user->verifyUser();
    user->userPrompt(store);
    //user->printUser();
    delete store;
    delete user;
}