#include<string>
#include<iostream>
#include"Users.h"
#include"functions.h"
using namespace std;
int main() {
    
    int choice;
    int option;
    int your_choice;
    string x;
    string id;
    string password;
    string username;
    cout << endl;
    cout << "               ***********************************************           " << endl;
    cout << "                    WELCOME TO VACCINE TRACKING SYSTEM                    " << endl;
    cout << "               ***********************************************           " << endl;
    cout << endl;
    cout << "\t\t 1.User        \t\t\t2.Admin \n\t\t\t\t\     3. Exit" << endl;
    cout << endl;
    cout << " Please enter your choice:-" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        do {
            cout << "Please enter your choice: \n 1.Don't have an account ? (SignUp)\n  2.Display your record\n  3.Edit your record\n   4.Delete your record" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
            {
               


                break;
            }
            case 2:
            {
                cout << "Enter your id \n";
                cin >> id;
                cout << "Enter your password \n";
                cin >> password;
                string user_id ;
                cout << "                    WELCOME USER                 " << endl;
                cout << "Enter your choice: (1-Display your record 2-Edit your record  3-Delete your record)" << endl;
                cin >> your_choice;
                switch (your_choice)
                {
                case 1:
                {
                    
                    break;
                }
                case 2:
                {
                    
                    break;
                }
                case 3:
                {
                    
                    break;

                }
                }
                break;
            }
            }
            cout << "Do you want to continue ? \n only enter y  " << endl;
            cin >> x;

        } while (x == "y" || x == "Y");

        break;
    }

    case 2:
    {

        do {

            cout << "----------------LOGIN AS AN ADMIN------------------- " << endl;

            cout << "enter your username \n";
            cin >> username;
            cout << "enter your password \n";
            cin >> password;
           
            cout << "Enter your choice:\n 1-Display one user only \n 2-Display all users \n  3-Delete one user only \n  4-Delete all users \n 5-View users filtered by doses \n 6-View records ordered by their age \n 7-View the waiting list \n 8- View % of first dose people \n 9-View % of both dose people \n 10-View % of males and females in the sytsem" << endl;
            cin >> your_choice;
            switch (your_choice)
            {
            case 1:
            {

                cout << "Enter User's id" << endl;
                cin >> id;
               
                break;
            }
            case 2:
            {
                
                break;
            }
            case 3:
            {
                cout << "Enter User's id" << endl;
                cin >> id;
                
                break;

            }
            case 4: {
                
                break;
            }
            case 5: {

                break;
            }
            case 6: {

                break;
            }
            case 7: {

                break;
            }
            case 8: {

                break;
            }
            case 9: {

                break;
            }
            case 10: {

                break;
            }
            }
            cout << "Do you want to continue ?" << endl;
            cin >> x;
        } while (x == "y" || x == "Y");
        break;

    }


    case 3:
    {
        cout << "               ***********************************************           " << endl;
        cout << "                      THANKS FOR USING OUR APPLICATION                  " << endl;
        cout << "                              HAVE A NICE DAY !             " << endl;
        cout << "               ***********************************************           " << endl;
        exit(0);
        break;

    }

    }
    return 0;
}
//this is a test
