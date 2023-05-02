#pragma once
#include<string>

using namespace std;
class Users
{
    typedef std::unordered_map<string, Users> users;
    static users users1;
public:
	string fullName;
	string id;
	string password;
	string gender;;
	string governorate;
	string vaccinated;
	string num_of_dose;
	int age;
public:
	Users();
	Users(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
	Users(string user_id, string user_pass);
	void Register(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, string num_of_dose);
	bool Login(string, string);
	bool Password_validation(string);
	bool ID_validation(string);
	void DisplayMyRecord(unordered_map<string, Users>& user);
	void edit_user_data(unordered_map<string, Users>& user);
	void Delete_MyACC();
	void vaccinationState_stat();
    //getters
    string getFullname() {
        return fullName;
    }
    string getId() {
        return id;
    }
    string getPassword() {
        return password;
    }
    string getGovernate() {
        return governorate;
    }
    string getGender() {
        return gender;
    }
    int getAge() {
        return age;
    }
	//setters
    void setFullname(string s) {
        fullName = s;
    }
 
    void setId(string s) {
        id = s;
    }
    void setPassword(string s) {
        password = s;
    }
    void setGovernate(string s) {
        governorate = s;
    }
    void setGender(string s) {
        gender = s;
    }
    void setAge(int i) {
        age = i;
    }

	~Users(void);

};

