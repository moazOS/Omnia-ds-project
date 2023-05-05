#pragma once

#include <iostream>
using namespace std;
bool flag, vaccinated, fullyVaccinated, halfVaccinated;






void Register(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_govern, string user_vaccinted, int num_of_dose);
void Login(string, string);
void Password_validation(string);
void ID_validation(string);
void DisplayMyRecord();
void edit_user_data();
void Delete_MyACC();
void vaccinationState_stat();
class Queue
{
public:
	Node* front, * back;
	Queue() {
		front = back = NULL;
	}
	void enQueue(string);
	void deQueue(string);
};
class Node {
public:
	string data;
	Node* next;
	Node(string d) {
		data = d;
		next = NULL;
	}
};
