#include <iostream>
#include "Users.h"
#include <fstream>
#include <vector>
#include "functions.h"

using namespace std;
vector<Users> users;



void Register(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose)
{
	std::ofstream file;
	file.open("users\\"+ user_id +".txt");
	if (file.is_open()) {
		file << user_name << user_id << user_pass << user_gender << user_age << user_govern << user_vaccinted << num_of_dose;
		file.close(); 
	}
	Users temp(user_name, user_id, user_pass, user_gender, user_age, user_govern, user_vaccinted, num_of_dose);
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