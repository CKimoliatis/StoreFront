#include "User.h"

User::User()
{
    info = new UserInfo;
    total = 0;
}
User::User(string n, string p)
{
    info = new UserInfo;
    strcpy(info->name, n.c_str());
    strcpy(info->password, p.c_str());
    total = 0;
}
User::~User()
{
    delete info;
}
string User::getName()
{
    return info->name;
}
string User::getPass()
{
    return info->password;
}
void User::setName(string n)
{
    strcpy(info->name, n.c_str());
}
void User::setPass(string p)
{
    strcpy(info->password, p.c_str());
}
void User::addToCart(Items *item, int n)
{
    cart[item] += n;
}
void User::addToCart(string n, int q, Store *s)
{
    Items *item = s->findItem(n);
    cart[item] += q;

    total += item->getPrice() * q;
}
void User::delItem(string name, int n)
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
void User::userPrompt(Store *store)
{
    int choice;
    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. See Store Front.\n";
        cout << "2. See Cart\n";
        cout << "3. Checkout\n";
        cout << "0. Logout\n";
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
                if(q == 0){
                    break;
                }
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
            this->checkout();
            cout << "Thank you for your purchase!\n";
            return;
        }
        else if (choice == 0)
        {
            cout << "Thank you for using the store!";
            return;
        }
        else
        {
            cout << "Invalid choice. Please reenter choice.\n";
        }
    }
}
void User::checkout()
{
    for (auto &x : cart)
    {
        x.first->setStock(x.first->getStock() - x.second);
    }
}
void User::printUser()
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
void User::printCart()
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
                cout << left << setw(15) << "Item name:" << setw(20) << right << x.first->getName() << endl;
                cout << left << setw(15) << "Price:" << setw(16) << right << "$ " << fixed << setprecision(2) << x.first->getPrice() << endl;
                cout << "Quantity: " << setw(25) << right << x.second << endl
                     << endl;
                i++;
            }
        }
        cout << left << setw(15) << "Total:" << setw(16) << right << "$ " << fixed << setprecision(2) << total << endl;
    }
}
void User::verifyUser()
{
    bool userFound = false;
    fstream file("users.bin", ios::binary | ios::in);

    // Loop through each UserInfo struct in the file
    UserInfo *temp = new UserInfo;
    while (file.read(reinterpret_cast<char *>(temp), sizeof(UserInfo)))
    {
        if (strcmp(temp->name, info->name) == 0 && strcmp(temp->password, info->password) == 0)
        {
            cout << "\nWelcome back " << temp->name << "!" << endl;
            userFound = true;
            info->active = temp->active;
            break;
        }
        else if (strcmp(temp->name, info->name) == 0 && strcmp(temp->password, info->password) != 0)
        {
            do
            {
                cout << "Wrong Password Please Reenter Password:\n";
                cin >> info->password;
                userFound = true;
            } while (strcmp(temp->password, info->password) != 0);
            info->active = temp->active;
            break;
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

        UserInfo newUser; // Create a new user object for the new user
        strcpy(newUser.name, info->name);
        strcpy(newUser.password, info->password);
        newUser.active = 1;

        file.write(reinterpret_cast<char *>(&newUser), sizeof(UserInfo));
        cout << "User added to file." << endl;

        file.close();
    }

    delete temp;
}