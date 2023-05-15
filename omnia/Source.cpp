#include<iostream>
#include<string>
#include "Users.h"
#include <vector>
#include <fstream>
#include <set>
#include<queue>
#include <map>
#include<unordered_map>
using namespace std;



bool is_empty_file(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

//---------------------global-----------------
int Myid;
vector<Users> users_vec;
unordered_map<int, Users>users;
set<int> usersID;
queue<Users>waiting_list;
float TOTALUSERS=0;
//--------------------------------------------




bool ID_validation(int id);
void Register(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
void Login(string, string);
bool Password_ID_validation(int id, string password);
void DisplayMyRecord();
void edit_user_data(string choose);
void Delete_MyACC();
void load();
void save();
void accepting_vaccinated(int number_of_user);
void get_vaccinted_user();
void mainMenu();
//--------------------- admin ------------------------------

void display_perc_of_gender(char kind);
void display_perc_of_doses(int dose_num);
void display_record(int id);
void display_records_filterd(string num_doses , int age);
void delete_record(int id);
void adminMenu();

//----------------------------------------------------------






int main() {
 
    
    Users admin;
    users_vec.push_back(admin);
    users.insert(make_pair(admin.id, admin));
    usersID.insert(admin.id);
    mainMenu();

    
    

}






void Register(string user_name, int user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose)
{
    Users temp(user_name, user_id, user_pass, user_gender, user_age, user_govern, user_vaccinted, num_of_dose);
    usersID.insert(user_id);
    TOTALUSERS++;
    users_vec.push_back(temp);
    users.insert(make_pair(user_id, temp));
    
}
void Login(string, string) {

}
bool Password_ID_validation(int id , string password)
{
    for (int i = 0; i < users_vec.size(); i++)
    {
        if (users_vec[i].id == id && users_vec[i].password == password)
        {
            return true;
        }
    }
    return false;
}
void DisplayMyRecord() {
    cout << "Name : " << users.at(Myid).fullName << "\nGender : " << users.at(Myid).gender << "\nAge : " << users.at(Myid).age << "\nGovernorate : " << users.at(Myid).governorate << "\nNum of doses : " << users.at(Myid).num_of_dose << endl;

}
void edit_user_data(string choose) {
    if (choose=="name")
    {
        cin >> users.at(Myid).fullName;
    }
    else if (choose == "id")
    {
        int id;
        do
        {
            cin >> id;
        } while (ID_validation(id) == false);
        
        users.at(Myid).id=id;
    }
    else if (choose == "gender")
    {
        cin >> users.at(Myid).gender;
    }
    else if (choose == "age")
    {
        cin >> users.at(Myid).age;
    }
    else if (choose == "govern")
    {
        cin >> users.at(Myid).gender;
    }
    else if (choose == "vaccinted")
    {
        cin >> users.at(Myid).vaccinated;
    }
    else if (choose == "num_of_dose")
    {
        cin >> users.at(Myid).num_of_dose;
    }
}
void Delete_MyACC() 
{
    users.erase(Myid);
}
void accepting_vaccinated(int number_of_user)
{
    if (number_of_user > waiting_list.size())
    {
        cout << "can't accept all these users now ";
    }
    else
    {
        for (int x = 0; x < users.size(); x++)
        {
            if (waiting_list.size() == 0 || number_of_user == 0)
            {
                break;
            }
            Users temp1 = waiting_list.front();
            if (temp1.id == users[x].id)
            {
                //cout << users[x].fullName << " done" << endl;
                users[x].vaccinated = "yes";
                waiting_list.pop();
                number_of_user--;
                continue;
            }
        }
    }
}
void get_vaccinted_user()
{
    for (int x = 0; x < users.size(); x++)
    {
        if (users[x].vaccinated == "NO" || users[x].vaccinated == "No" || users[x].vaccinated == "nO" || users[x].vaccinated == "no")
        {
            waiting_list.push(users[x]);
        }
    }

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
            users.insert(make_pair(stoi(id), temp));
            users_vec.push_back(temp);
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
            if (i == users_vec.size() - 1)
            {
                file << users_vec[i].fullName << " " << users_vec[i].id << " " << users_vec[i].password << " " << users_vec[i].gender << " " << users_vec[i].age << " " << users_vec[i].governorate << " " << users_vec[i].vaccinated << " " << users_vec[i].num_of_dose;
                file2 << users_vec[i].id;
                break;
            }
            file << users_vec[i].fullName << " " << users_vec[i].id << " " << users_vec[i].password << " " << users_vec[i].gender << " " << users_vec[i].age << " " << users_vec[i].governorate << " " << users_vec[i].vaccinated << " " << users_vec[i].num_of_dose << endl;
            file2 << users_vec[i].id << endl;

        }
    }
    file.close();
    file2.close();


    
}
bool ID_validation(int id)
{
    if (usersID.find(id) != usersID.end())
    {
        return true;
    }
    else
        return false;
}
void mainMenu()
{
    
    int choice;
    int option;
    int your_choice;
    string x;
    int id;
    string password;
    string username;
    cout << endl;
    cout << "               ***********************************************           " << endl;
    cout << "                    WELCOME TO VACCINE TRACKING SYSTEM                    " << endl;
    cout << "               ***********************************************           " << endl;
    cout << endl;
    cout << endl;
    cout << "\t1. Log in" << endl;
    cout << "\t2. Register as a new user" << endl;
    cout << "\t3. Exit Program" << endl;
    cout << "\tPlease enter number of your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        bool flag = false;
        cout << "Enter ID : ";
        cin >> id;
        cout << "Enter password : ";
        cin >> password;
        do
        {

            
            if (id == 0 && password == "admin")
            {
                system("cls");
                adminMenu();

                break;
            }
            
            if (flag)
            {
                int c;
                cout << "Do u want to Renter Id and password or go back" << endl;
                cout << "1 -> Renter" << endl;
                cout << "2 -> Go back" << endl;
                cout << "Your choice : ";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "Enter ID : ";
                    cin >> id;
                    cout << "Enter password : ";
                    cin >> password;
                    break;
                case 2:
                    system("cls");
                    mainMenu();
                    break;
                default:
                    flag = true;
                    continue;

                }


            }
            if (Password_ID_validation(id, password) == true)
            {
                break;
            }
            else
                flag = true;

        } while (Password_ID_validation(id, password) == false);

        Myid = id;
        system("cls");
        break;
    }

    case 2:
    {

       
        break;

    }


    

    }
}


//----------------------  admin -----------------------------

void display_perc_of_gender(char kind)
{
    float num_of_boys = 0;
    float num_of_girls = 0;
    if (users_vec.size() != 1)
    {
        for (int i = 0; i < users_vec.size(); i++)
        {
            if (users_vec[i].gender == "male")
            {
                num_of_boys++;

            }
            else
            {
                num_of_girls++;

            }
        }
    }
   
    bool done = true;
    do
    {
        if (kind == 'm' || kind == 'M') {

            cout << (num_of_boys / TOTALUSERS) * 100 << "%\n";
            cout << "f" << endl;
            done = false;
            break;
        }
        else if (kind == 'f' || kind == 'F') {
            cout << (num_of_girls / TOTALUSERS) * 100 << "%\n";
            done = false;
            break;
        }
        else
            cout << "Wrong Choice please choose eithe m or f\n";
        cout << "M : Male      F : Femals" << endl;
        cout << "Choose a char : ";
        cin >> kind;
    } while (done);

}
void display_perc_of_doses(int dose_num)
{
    float num_of_doses=0;
    float num_of_0 = 0;
    float num_of_1 = 0;
    float num_of_2 = 0;
    for (int i = 0; i < users_vec.size(); i++) {
        if (users_vec[i].num_of_dose == "0") {
            num_of_0++;
            num_of_doses++;
        }
        else if (users_vec[i].num_of_dose == "1") {
            num_of_1++;
            num_of_doses++;

        }
        else if (users_vec[i].num_of_dose == "2") {
            num_of_2++;
            num_of_doses++;

        }
    }
    bool done = true;
    do
    {
        if (dose_num == 0) {
            cout << (num_of_0 / num_of_doses) * 100 << "%\n";
            done = false;
            break;
        }
        else if (dose_num == 1) {
            cout << (num_of_1 / num_of_doses) * 100 << "%\n";
            done = false;
            break;

        }
        else if (dose_num == 2) {
            cout << (num_of_2 / num_of_doses) * 100 << "%\n";
            done = false;
            break;
        }
        else {
            cout << "Wrong information\n";
            cout << "Number of doses : ";
            cin >> dose_num;
        }
    } while (done);
    
}
void display_record(int id)
{


        if (users.find(id)!=users.end() ) {
            cout << "Name : " << users.at(id).fullName << "\nGender : " << users.at(id).gender << "\nAge : " << users.at(id).age << "\nGovernorate : " << users.at(id).governorate << "\nNum of doses : " << users.at(id).num_of_dose << endl;

        }
        else
        {
            cout << "user not found" << endl;
        }



}
void display_records_filterd(string num_doses, int age)
{
    bool flag = true;
    do
    {
        for (int i = 0; i < users_vec.size(); i++)
        {
            if (users_vec[i].age == age && users_vec[i].num_of_dose == num_doses) {
                cout << "Name : " << users_vec[i].fullName << "\nGender : " << users_vec[i].gender << "\nAge : " << users_vec[i].age << "\nGovernorate : " << users_vec[i].governorate << endl;
                cout << "--------------------------------------------\n";
                flag = false;
            }
        }
        if (flag)
        {
            cout << "user not found" << endl;
            cout << "Number of doses : ";
            cin >> num_doses;
            cout << "AGE : ";
            cin >> age;
        }
    } while (flag);
    
}
void delete_record(int id)
{
    users.erase(id);
    usersID.erase(usersID.find(id));

}
void adminMenu()
{
    bool done = true;
    do
    {
        int c;
        cout << "               ***********************************************           " << endl;
        cout << "                            WELCOME TO Admin page                        " << endl;
        cout << "               ***********************************************           " << endl;
        cout << "1 -> Display percentage of gender" << endl;
        cout << "2 -> Display percentage of doses" << endl;
        cout << "3 -> Display records" << endl;
        cout << "4 -> Display a record" << endl;
        cout << "5 -> Display records filterd" << endl;
        cout << "6 -> Delete a record" << endl;
        cout << "7 -> Exit" << endl;
        cout << "Choose a number : ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            char c2;
            cout << "M : Male      F : Femals" << endl;
            cout << "Choose a char : ";
            cin >> c2;
            display_perc_of_gender(c2);
            break;
        }


        case 2:
        {
            int c2;
            cout << "Number of doses : ";
            cin >> c2;
            display_perc_of_doses(c2);
            break;
        }
        case 3:
        case 4:
        {
            int c2;
            cout << "Enter ID : ";
            do
            {
                cin >> c2;
            } while (ID_validation(c2) == false);
            display_record(c2);
            break;
        }

        case 5:
        {
            string c2;
            int c3;
            cout << "Number of doses : ";
            cin >> c2;
            cout << "AGE : ";
            cin >> c3;
            display_records_filterd(c2, c3);
            break;
        }
        case 6:
        {
            int c2;
            cout << "Enter ID : ";
            do
            {

                cin >> c2;
            } while (ID_validation(c2) == false);
            delete_record(c2);
            break;
        }


        default:
            done = false;
            break;
        }
    } while (done);
    system("cls");
    mainMenu();
}
//-----------------------------------------------------------