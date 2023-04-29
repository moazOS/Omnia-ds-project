#pragma once
#include<string>
using namespace std;
class Users
{
public:
	string full_name;
	string id;
	string password;
	string gender;
	int age;
	string country;
	string governorate;
	string vaccinated;
	string num_of_dose;
public:
	Users();
	Users(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_country, string user_govern, string user_vaccinted, string num_of_dose);
	Users(string user_id, string user_pass);
	bool Register();
	void ADDUSER();
	bool Login();
	bool Password_validation(string);
	bool ID_validation(string);
	void DisplayMyRecord();
	void edit_user_data();
	void Delete_MyACC();
	void vaccinationState_stat();
	~Users(void);

};

