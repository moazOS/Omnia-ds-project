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
set<int> usersID;

float TOTALUSERS=0;
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

//--------------------- admin ------------------------------

void display_perc_of_gender(char kind);
void display_perc_of_doses(int dose_num);
void display_record(int id);
void display_records_filterd(string num_doses , int age);
void delete_record(int id);


//----------------------------------------------------------






int main() {
 
    Register("moaz", 1, "27007447", "male", 19, "cairo", "yes", "1");
    Register("maryam", 4, "142003", "girl", 20, "cairo", "yes", "3");
    Register("omnia", 6, "27007576", "girl", 20, "cairo", "yes", "2");
    Register("nada", 2, "27007511", "girl", 18, "cairo", "yes", "3");
    Register("saleh", 5, "27007555", "male", 19, "sudan", "yes", "3");
    Register("youssef", 9, "27007787", "male", 20, "cairo", "no", "0");
    Register("malak", 8, "27007333", "girl", 19, "cairo", "no", "0");
    Register("kiro", 7, "27007444", "male", 21, "cairo", "yes", "2");
    Register("menna", 3, "27007123", "girl", 21, "cairo", "no", "0");
    display_perc_of_gender('m');
    display_perc_of_gender('f');
    cout << "------------------------\n";

     display_perc_of_doses(0);
     display_perc_of_doses(1);
     display_perc_of_doses(2);
     cout << "------------------------\n";

     display_record(4);
     cout << "------------------------\n";
     display_records_filterd("2",20);
     cout << "------------------------\n";
     delete_record(5);
     display_record(5);

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
    if (!is_empty_file(file2))
    {
        while (file2 >> fullName >> id >> password >> gender >> age >> governorate >> vaccinated >> num_of_dose)
        {
            Users temp(fullName, stoi(id), password, gender, stoi(age), governorate, vaccinated, num_of_dose);
            users.push_back(temp);
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
            if (i == users.size() - 1)
            {
                file << users[i].fullName << " " << users[i].id << " " << users[i].password << " " << users[i].gender << " " << users[i].age << " " << users[i].governorate << " " << users[i].vaccinated << " " << users[i].num_of_dose;
                file2 << users[i].id;
                break;
            }
            file << users[i].fullName << " " << users[i].id << " " << users[i].password << " " << users[i].gender << " " << users[i].age << " " << users[i].governorate << " " << users[i].vaccinated << " " << users[i].num_of_dose << endl;
            file2 << users[i].id << endl;

        }
    }
    file.close();
    file2.close();


    
}


//----------------------  admin -----------------------------

void display_perc_of_gender(char kind)
{
    float num_of_boys = 0;
    float num_of_girls = 0;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].gender == "male")
        {
             num_of_boys++;
           
        }
        else
        {
            num_of_girls++;

        }
    }
    if (kind == 'm' || kind == 'M') {
        
        cout << (num_of_boys / TOTALUSERS) * 100<< "%\n";
    }
    else if (kind == 'f' || kind == 'F') {
        cout << (num_of_girls / TOTALUSERS) * 100 << "%\n";
    }
    else
        cout << "Wrong Choice please choose eithe m or f\n";

}
void display_perc_of_doses(int dose_num)
{
    float num_of_doses=0;
    float num_of_0 = 0;
    float num_of_1 = 0;
    float num_of_2 = 0;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].num_of_dose == "0") {
            num_of_0++;
            num_of_doses++;
        }
        else if (users[i].num_of_dose == "1") {
            num_of_1++;
            num_of_doses++;

        }
        else if (users[i].num_of_dose == "2") {
            num_of_2++;
            num_of_doses++;

        }
    }
    if (dose_num == 0) {
        cout << (num_of_0 / num_of_doses) * 100 << "%\n";
    }
    else if (dose_num == 1) {
        cout << (num_of_1 / num_of_doses) * 100 << "%\n";
    }
    else if (dose_num == 2) {
        cout << (num_of_2 / num_of_doses) * 100 << "%\n";
    }
    else {
        cout << "Wrong information\n";
    }
}
void display_record(int id)
{
    bool flag = true;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].id == id) {
            cout << "Name : " << users[i].fullName << "\nGender : " << users[i].gender << "\nAge : " << users[i].age << "\nGovernorate : " << users[i].governorate << "\nNum of doses : " << users[i].num_of_dose << endl;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "user not found"<<endl;
    }

}
void display_records_filterd(string num_doses, int age)
{
    bool flag = true;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].age == age && users[i].num_of_dose==num_doses) {
            cout << "Name : " << users[i].fullName << "\nGender : " << users[i].gender << "\nAge : " << users[i].age << "\nGovernorate : " << users[i].governorate << endl;
            cout << "--------------------------------------------\n";
            flag = false;
        }
    }
    if (flag)
    {
        cout << "user not found" << endl;
    }
}
void delete_record(int id)
{
    bool flag = true;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].id == id) {
            users.erase(users.begin() + i);
            TOTALUSERS--;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "user not found" << endl;
    }
}

//-----------------------------------------------------------