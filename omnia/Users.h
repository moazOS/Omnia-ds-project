#pragma once
#include<string>
#include <fstream>
#include<iostream>
#include <vector>
#include <set>
#include<queue>
#include <map>
#include<unordered_map>
using namespace std;
class Users
{
    public:
	string fullName;
	string id;
	string password;
	string password_confirm;
	string gender;
	string governorate;
	bool flag, vaccinated, fullyVaccinated, halfVaccinated;
	int age = 0;
	int num_of_dose=0;

	//---------------------Menus-----------------------
	void mainMenu();
	void MainMenuChoices();
	void adminMenu();
	void userMenu();
	void returnBack();
	//--------------------- user ------------------------------
	void Register();
	void ID_validation(string id);
	bool ID_validation2(string id);
	void createPass();
	void displayGovernorate();
	void GovernorateChoice();
	void gotVaccine();
	void insertUserData();
	void Login();
	bool Password_ID_validation(string id, string password);

	void displayUserData();
	void editUserData();
	void editAgain(char);
	void deleteUserData();
	//--------------------- admin ------------------------------

	void display_perc_of_gender(char kind);
	void display_perc_of_doses(int dose_num);
	void display_record(string id);
	void display_records_filterd(int num_doses, int age);
	void delete_record(string id);

	//--------------------- file retated functions ------------------------------
	Users getData(string id);
	void load();
	void save();
	void deleteData();
	

	~Users(void);

};
class Node
{
public:
	string data;
	Node* next;
	Node(string d) {
		data = d;
		next = NULL;
	}
};
class Queue
{
public:
	Node* front, * back;
	Queue() {
		front = back = NULL;
	}
	void enqueue(string);
	void dequeue(string);
};

