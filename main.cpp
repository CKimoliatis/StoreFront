#include "AllHeader.h"
#include "Items.h"
#include "Store.h"
#include "User.h"
using namespace std;

int main()
{
    /*Store* store = new Store();
    if(!store->readBin()){
        Items* item1 = new Items("Apple", 3.50, 30);
        Items* item2 = new Items("Orange", 2.50, 12);
        store->addItem(item1);
        store->addItem(item2);
        store->writeBin();
    }*/
    vector<User *> users(3);
    fstream file("users.bin", ios::binary | ios::out);
    users[0] = new User("Test1", "11111");
    users[1] = new User("Test2", "22222");
    users[2] = new User("Test3", "33333");

    for (int i = 0; i < users.size(); i++){
        file.write((char *)users[i], sizeof(User));
    }

    file.close();

    vector<User *> users1;
    file.open("users.bin", ios::binary | ios::in);

    // Read the User objects from the binary file
    User *user = new User("", "");
    while (file.read((char *)user, sizeof(User))){
        users1.push_back(user);
        user = new User("", "");
    }

    file.close();

    for (int i = 0; i < users1.size(); i++){
        cout << "User " << i + 1 << endl;
        cout << "Username: " << users1[i]->getName() << endl;
        cout << "Password: " << users1[i]->getPass() << endl;
        cout << endl;
    }

    /*string name, pass;
   cout << "Enter Username:\n";
   cin>>name;
   cout << "Enter Password:\n";
   cin>>pass;

   User * user1 = new User(name, pass);
   user1->userPrompt(store);*/
}