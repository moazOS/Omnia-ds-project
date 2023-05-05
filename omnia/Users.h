#pragma once
#include<string>


using namespace std;
class Users
{
    
public:
	string fullName;
	string id;
	string password;
	string password_confirm;
	char gender;;
	string governorate;
	string vaccinated;
	int num_of_dose;
	int age;
	Users();
	Users(string user_name, string user_id, string user_pass, char user_gender, int user_age, string user_govern, int num_of_dose);
	Users(string user_id, string user_pass);

 

	~Users(void);

};

