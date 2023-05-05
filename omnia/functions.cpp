#include <iostream>
#include "Users.h"
#include <fstream>
#include <vector>
#include<queue>
#include<unordered_map>
#include "functions.h"

using namespace std;
vector<Users> users;
unordered_map<string, Users >::iterator itr;
unordered_map<string, Users> userMapping;
Queue waitingList;
Queue SecDoseWaitingList;
Users user;



void Register()
{
	cout << "\tMake sure the National ID you are using aren't already registered." << endl;
	cout << "\tPlease fill in the following information to create your record:" << endl;
	cout << endl;
one:
	cout << "\tFirst name: ";
	cin >> user.fullName;
	for (int i = 0; i < user.fullName.size(); i++) {
		if (isalpha(user.fullName[i]) == 0) {
			cout << "\tInvalid, name must contain letters only." << endl;
			goto one;
			break;
		}
	}
two:
	ID_validation();
	while (user.id.size() != 13) {
		cout << "\tInvalid ID , please re-enter your ID: " << endl;
		ID_validation();
	}
	CheckRegisteredID(user.id);

	cout << endl;
	cout << "\tPlease enter your age: ";
	cin >> user.age;
	cout << endl;

	cout << "\tPlease choose gender F for female or M for male: ";
	cin >> user.gender;
	while (user.gender != 'F' && user.gender != 'M' && user.gender != 'm' && user.gender != 'f') {
		cout << "\tInvalid value, please re-enter: ";
		cin >> user.gender;

	}

	cout << endl;
	getGov();
	cout << endl;


	std::ofstream file;
	file.open("users\\"+ user.id +".txt");
	if (file.is_open()) {
		file << user.fullName << user.id << user.password << user.gender << user.age << user.governorate;
		checkVaccineStatus();
		file << user.num_of_dose<< endl;
		file.close(); 
		cout << "\tYour record is successfully saved." << endl;
	}
	//hasa el heta el ta7t dy msh lazem
	Users temp(user.fullName, user.id, user.password, user.gender, user.age, user.governorate,user.num_of_dose);
	users.push_back(temp);
}
void CheckRegisteredID(string enteredID) {
	char choice;
	for (itr = userMapping.begin(); itr != userMapping.end(); itr++) {
		if (enteredID == itr->first) {
			cout << "\tID already Registered!" << endl;
		q:
			cout << "\t Do you want to sign in ? (y/n) ";
			cin >> choice;
			switch (choice) {
			case 'y':
				system("cls");
				Login();
				break;
			case'n':
				system("cls");
			    //hena el mafrood ykon feeh fn 3shan yrga3 lel main menu
				break;
			default:
				cout << "\tInvalid choice , try again." << endl;
				goto q;
				break;
			}
			ID_validation();
			break;


		}


	}
}
void Login() {
a:
	cout << "Enter your id :" << endl;
	cin >> user.id;
b:
	cout << "Enter your password:" << endl;
	cin >> user.password;

	itr = userMapping.find(user.id);

	if (itr == userMapping.end()) {
		cout << "\n\n\n\t\t\t\t\t| USER CHECKING..... |\n\t\t\t\t\t";
		cout << "\n\tInvalid ID...\n";
		cout << "\tMake Sure You Sign Up First!\n\n";
		system("PAUSE");
		system("cls");
		//main menu fn
		goto a;
	}

	else {
		cout << "\n\n\n\t\t\t\t\t| USER CHECKING..... |\n\t\t\t\t\t";
		if (user.password == itr->second.password) {
			cout << endl;
			cout << "\n\n\tAccess Granted..\n\n";
			system("PAUSE");
			system("cls");
			UserOptions();

		}
		else {

			cout << "\n\n\tinvalid password!\n\n";
			int passchoice;
		j:
			cout << "\tDo You want to ->\n";
			cout << "\t1->try again?\n";
			cout << "\t2->go back to the sign up page?\n";
			cout << "\tenter your choice:";
			cin >> passchoice;
			switch (passchoice) {
			case 1:
				system("cls");
				goto b;
				break;
			case 2:
				system("cls");
				//return to main menu
				break;
			default:
				cout << "\tinvalid Choice.";
				goto j;
				break;
			}
			system("PAUSE");
			system("cls");
			goto b;
		}

		cout << endl;
		cout << "\n\n\tAccess Granted..\n\n";
		system("PAUSE");
		system("cls");
		UserOptions();
		}
		cout << endl;


}
void UserOptions() {
H:
//title

	int userchoice;
	cout << "\t-->> User Panel <<--\n";
	cout << "\t~choose one of the following choices~\n";
	cout << "\t1->Display Record.\n";
	cout << "\t2->Edit/Update Record.\n";
	cout << "\t3->Delete Record.\n";
	cout << "\t4->Log Out.\n";
	cout << "\tEnter your choice:";
	cin >> userchoice;

	switch (userchoice) {
	case 1:
		system("CLS");
		DisplayMyRecord();

		break;
	case 2:
		system("CLS");
		edit_user_data();

		break;
	case 3:
		system("CLS");
		Delete_MyACC();

		break;
	case 4:
		system("cls");
		//update the files and return to main menu fn
		break;
	default:
		cout << "\tInvalid choice!\n";
		BackOption();
		UserOptions();
		break;
	}

}
void BackOption() {

	system("PAUSE");
	system("cls");

}


void Password_validation() {

	bool msg = true;
	user.password = "";
	user.password_confirm = "";

	cout << "\tCreate a new password : ";
	cin >> user.password;

	cout << "\tConfirm your password : ";
	cin >> user.password_confirm;

	while (user.password.size() < 5) {
		cout << "\tPassword too short" << endl;
		msg = false;
		Password_validation();
		break;
	}
	if (msg) {

		if (user.password == user.password_confirm) {
			cout << "\n\tPassword created successfully" << endl;

		}
		else {
			cout << "\n\tPasswords don't match , please try again" << endl;
			Password_validation();
		}
	}

}
void ID_validation() {
	cout << "\tEnter National ID (13 digits ): ";
	cin >> user.id;
	if (user.id[0] != '2' && user.id[0] != '3') { //century
		cout << "\tInvaild ID" << endl;
		ID_validation();
	}
	if (user.id[1] != '0' && user.id[1] != '1' && user.id[1] != '2' && !(0 <= user.id[2] >= 9)) { //year
		cout << "\tInvaild ID" << endl;
		ID_validation();
	}
	if (user.id[3] != '0' && user.id[3] != '1' && !(0 <= user.id[4] >= 9)) { // month
		cout << "\tInvaild ID" << endl;
		ID_validation();
	}
	if (user.id[5] != '0' && user.id[5] != '1' && user.id[5] != '2' && user.id[5] != '3' && !(0 <= user.id[6] >= 9)) { //day
		cout << "\tInvaild ID" << endl;
		ID_validation();
	}
	if (user.id[7] != '0' && user.id[7] != '1' && user.id[7] != '2' && user.id[7] != '3' && user.id[7] != '8' && !(1 <= user.id[8] >= 9)) { //governorate
		cout << "\tInvaild ID" << endl;
		ID_validation();
	}

}
void displayGov() {
	cout << "\t1 ---> Cairo " << endl;
	cout << "\t2 ---> Dakahlia " << endl;
	cout << "\t3 ---> Alexandria " << endl;
	cout << "\t4 ---> Giza " << endl;
	cout << "\t5 ---> Port Said " << endl;
	cout << "\t6 ---> Other " << endl;
	cout << "\tPlease enter number of governorate you are currently living at: ";
}
void getGov() {

	displayGov();
	int choice;

	switch (choice) {
	case 1:
		user.governorate = "Cairo";
		break;
	case 2:
		user.governorate = "Dakahlia";
		break;
	case 3:
		user.governorate = "Alexandria";
		break;
	case 4:
		user.governorate = "Giza";
		break;
	case 5:
		user.governorate = "PortSaid";
		break;
	case 6:
		user.governorate = "Other";
		break;
	default:
	{
		cout << "\tInvalid value entered.\n\tPlease make sure to enter a value from the  options below." << endl;
		getGov();

	}
	}
}

void checkVaccineStatus() {
	char ans;
S:
	cout << "\tDid you get the COIVD-19 Vaccine? y/n : ";
	while (!(cin >> ans)) {
		cout << "\tInvalid Input.";
		cin.clear();
		cin.ignore(123, '\n');
		goto S;
		break;

	}

	switch (ans)
	{
	case 'y':
	case'Y':
	{
	label:
	E:
		cout << "\tHave you taken 1 or 2 doses? 1/2 : ";
		while (!(cin >> user.num_of_dose)) {
			cout << "\tInvalid Input. ";
			cin.clear();
			cin.ignore(123, '\n');
		}

		switch (user.num_of_dose) {
		case 1:
		{
			cout << "\tYou will be added on 2nd dose waiting list" << endl;
			//put them in the second dose waiting list
			SecDoseWaitingList.enQueue(user.id);
			break;
		}
		case 2:
		{
			fullyVaccinated = true;
			break;
		}
		default:
		{
			cout << "\tInvalid choice" << endl;
			goto label;
			break;
		}
		}

		break;
	}
	case 'n':
	case'N':
	{
		vaccinated = false;
		user.num_of_dose = 0;
		cout << "\tYou will be registered into our waiting list" << endl;
		//put them is the first dose waiting list
		waitingList.enQueue(user.id);
		break;
	}
	default:
		cout << "\tInvalid choice" << endl;
		checkVaccineStatus();
		break;

	}

}
void Queue::enQueue(string ) {
	Node* temp = new Node(user.id);

	if (back == NULL) {
		front = back = temp;
		return;
	}
	back->next = temp;
	back = temp;
}
void Queue::deQueue(string )
{
	
	if (front == NULL)
		return;


	Node* temp = front;
	front = front->next;

	if (front == NULL)
		back = NULL;

	delete (temp);
}

void DisplayMyRecord(){

}
void edit_user_data() {

}
void Delete_MyACC() {

}
