#include <iostream>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "   SMART MESS MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Student Registration\n";
        cout << "2. Student Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
           case 1:
                 cout << "\nStudent Registration Module (Coming Soon)\n";
                 break;

            case 2:
                 cout << "\nStudent Login Module (Coming Soon)\n";
                break;

            case 3:
                 cout << "\nAdmin Login Module (Coming Soon)\n";
                break;

             case 4:
                 cout << "\nThank you for using Smart Mess Management System!\n";
                 break;

            default:
                 cout << "\nInvalid choice! Please try again.\n";
        }

    } 
    while (choice != 4);

    return 0;
}