#pragma once

#include <iostream>
using namespace std;
bool flag, vaccinated, fullyVaccinated, halfVaccinated;






void Register();
void Login();
void Password_validation(string);
void ID_validation(string);
void DisplayMyRecord();
void edit_user_data();
void Delete_MyACC();
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
