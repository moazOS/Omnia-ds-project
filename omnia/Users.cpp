#include "Users.h"
#include<iostream>
#include<string>


Users::Users(string user_name, string user_id, string user_pass, char user_gender, int user_age, string user_govern, int user_num_of_dose)
{
	this->fullName = user_name;
	this->id = user_id;
	this->password = user_pass;
	this->gender = user_gender;
	this->age = user_age;
	this->governorate = user_govern;
	this->num_of_dose = user_num_of_dose;
}

Users::Users() {
	fullName = id = password = governorate = vaccinated = "";
	age = 0;

}

Users::Users(string user_id, string user_pass)
{
	this->id = user_id;
	this->password = user_pass;
}


Users::~Users(void) {

}

