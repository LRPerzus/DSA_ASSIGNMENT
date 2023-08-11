#include <iostream>
#include "HashTable.h"
#include "AVLTree.h";

int main()
{
    HashTable newTable;

    Admin admin = Admin(23, "Roye@gmail.com", "passd", 23);
    Admin admin1 =Admin(1111, "oRye@gmail.com", "admin123", 2222);
    Admin admin2 = Admin(9876, "yoRe@gmail.com", "securepwd", 5432);
    Admin admin3 = Admin(5555, "eRoy@gmail.com", "pass456", 8888);

    /*cout << admin.hashValue << endl;*/



    newTable.add(admin);
    cout << "admin inserted" << endl;
    newTable.add(admin1);
    cout << "admin1 inserted" << endl;
    newTable.add(admin2);
    cout << "admin2 inserted" << endl;
    newTable.add(admin3);
    cout << "admin3 inserted" << endl;

    ItemType* searched = newTable.search(admin1.hashValue, admin1.lengthUsername,admin1.viewEmailUserName());

    string email = searched->viewEmailUserName();

    cout << "The username is:" << email << endl;


    
    

};

