#include<iostream>
#include<string>
#include "Users.h"
#include <vector>
#include <fstream>
#include <set>
using namespace std;



bool is_empty_file(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

//---------------------global-----------------
vector<Users> users;
set<int>USERSSID;
set<int> usersID;

int TOTALUSERS;
//--------------------------------------------





void Register(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
void Login(string, string);
void Password_validation(string);
void ID_validation(string);
void DisplayMyRecord();
void edit_user_data();
void Delete_MyACC();
void vaccinationState_stat();
void load();
void save();








int main() {
    load();
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");

    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    Register("moaz", 123, "27007447", "male", 20, "cairo", "yes", "5");
    save();
    
    /*cout << users[0].id << endl;*/
    
    cout <<TOTALUSERS << endl;
    


   /* int choice;
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
    return 0;*/
}






void Register(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose)
{
    Users temp(user_name, user_id, user_pass, user_gender, user_age, user_govern, user_vaccinted, num_of_dose);
    usersID.insert(user_id);
    TOTALUSERS++;
    users.push_back(temp);
}
void Login(string, string) {

}
void Password_validation(string) {

}
void ID_validation(string) {

}
void DisplayMyRecord() {

}
void edit_user_data() {

}
void Delete_MyACC() {

}
void vaccinationState_stat() {

}
void load()
{



    

    string fullName;
    string id;
    string password;
    string gender;;
    string governorate;
    string vaccinated;
    string num_of_dose;
    string age;


    string line;


    ifstream file("users\\USERSID.txt");
    string ids;
    if (file.fail()) {
        std::ofstream fav;
        fav.open("users\\USERSID.txt");
        fav.close();
    }
    if (!is_empty_file(file))
    {
        while (!file.eof())
        {

            getline(file, ids);
            usersID.insert(stoi(ids));
            TOTALUSERS++;
        }
        file.close();
    }







    ifstream file2("users\\Users.txt");
  
    if (file2.fail()) {
        std::ofstream fav;
        fav.open("users\\Users.txt");
        fav.close();
    }
    /*if (!is_empty_file(file2))
    {
        while (file2 >> fullName >> id >> password >> gender >> age >> governorate >> vaccinated >> num_of_dose)
        {
            Users temp(fullName, stoi(id), password, gender, stoi(age), governorate, vaccinated, num_of_dose);
            users.push_back(temp);
        }

    }*/
    if (!is_empty_file(file2))
    {
        while (!file2.eof())
        {
            getline(file2, line);

        }
    }
    file2.close();
 
    
   
    
 

}
void save()
{
    ofstream file;
    ofstream file2;
    file2.open("users\\USERSID.txt");
    file.open("users\\Users.txt");

        
    if (file.is_open() && file2.is_open()) {
         for (int i = 0; i < users.size(); i++) 
         {
            file << users[i].fullName << " " << users[i].id << " " << users[i].password << " " << users[i].gender << " " << users[i].age << " " << users[i].gender << " " << users[i].vaccinated << " " << users[i].num_of_dose << endl;
            file2 << users[i].id << endl;

         }
    }
    file.close();
    file2.close();
    
}