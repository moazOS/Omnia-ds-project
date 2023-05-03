#pragma once

#include <iostream>
using namespace std;






void Register(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
void Login(string, string);
void Password_validation(string);
void ID_validation(string);
void DisplayMyRecord();
void edit_user_data();
void Delete_MyACC();
void vaccinationState_stat();
