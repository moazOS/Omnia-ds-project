#include "Users.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
Users::Users(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string user_num_of_dose)
{
	this->fullName = user_name;
	this->id = user_id;
	this->password = user_pass;
	this->gender = user_gender;
	this->age = user_age;
	this->governorate = user_govern;
	this->vaccinated = user_vaccinted;
	this->num_of_dose = user_num_of_dose;
}

Users::Users() {
	fullName = id = password = gender = governorate = vaccinated = "";
	age = 0;

}

Users::Users(string user_id, string user_pass)
{
	this->id = user_id;
	this->password = user_pass;
}


 void Users::Register(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose)
{
	 fstream File;
	 File.open("txts\\users.txt", ios::app);
	 if (File.is_open())
	 {
		 File << user_name + '\n';
	 }
	 File.close();

	 File.open("txts\\id.txt", ios::app);
	 if (File.is_open())
	 {

		 File << user_id + '\n';
	 }
	 File.close();

	 File.open("txts\\age.txt", ios::app);
	 if (File.is_open())
	 {

		 File << user_age + '\n';
	 }
	 File.close();

	 File.open("txts\\user_vaccinated.txt", ios::app);
	 if (File.is_open())
	 {

		 File << user_vaccinted + '\n';
	 }
	 File.close();

	 File.open("txts\\governorate.txt", ios::app);
	 if (File.is_open())
	 {

		 File << user_govern + '\n';
	 }
	 File.close();

	 File.open("txts\\pass.txt", ios::app);
	 if (File.is_open())
	 {

		 File << user_pass + '\n';
	 }
	 File.close();

	 File.open("txts\\num_of_dose.txt", ios::app);
	 if (File.is_open())
	 {

		 File << num_of_dose + '\n';
	 }
	 File.close();

	 File.open("txts\\gender.txt", ios::app);
	 if (File.is_open())
	 {
		 File << user_gender + '\n';
	 }
	 File.close();

	 Users user1( user_name,  user_id,  user_pass,  user_gender,  user_age,  user_govern,  user_vaccinted,  num_of_dose);
	 this->users1.insert(pair<string, Users>(id, user1));
 }


 bool Users::Login(string, string) {

}
 bool Users::Password_validation(string) {

}
 bool Users::ID_validation(string) {

}
 void Users::DisplayMyRecord(unordered_map<string, Users>& user){

}
 void Users::edit_user_data(unordered_map<string, Users>& user) {

}
 void Users::Delete_MyACC() {

}
 void Users::vaccinationState_stat() {

}


Users::~Users(void) {

}

