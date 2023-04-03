#include "AllHeader.h"
#include "Items.h"
#include "Store.h"
#include "User.h"
#include "Init.h"
using namespace std;

int main()
{
    Init* init = new Init();
    init->writeUsers();

    Init* init2 = new Init();
    init2->readUsers();

    init2->printUsers();
    init2->printStore();


    
}