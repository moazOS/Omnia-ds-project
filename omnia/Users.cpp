#include "Users.h"
#include<iostream>
#include<string>
Users::Users(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_country, string user_govern, string user_vaccinted, string user_num_of_dose)
{
	this->full_name = user_name;
	this->id = user_id;
	this->password = user_pass;
	this->gender = user_gender;
	this->age = user_age;
	this->country = user_country;
	this->governorate = user_govern;
	this->vaccinated = user_vaccinted;
	this->num_of_dose = user_num_of_dose;
}

Users::Users() {}

Users::Users(string user_id, string user_pass)
{
	this->id = user_id;
	this->password = user_pass;
}


 bool Users::Register() 
{
}

 void  Users::ADDUSER() {

}
 bool Users::Login() {

}
 bool Users::Password_validation(string) {

}
 bool Users::ID_validation(string) {

}
 void Users::DisplayMyRecord() {

}
 void Users::edit_user_data() {

}
 void Users::Delete_MyACC() {

}
 void Users::vaccinationState_stat() {

}


Users::~Users(void) {

}

