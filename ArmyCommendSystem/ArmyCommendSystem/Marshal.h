#pragma once
#include "Base.h"
#include <vector>
#include <iostream>
using namespace std;
static int controlMechs = 0;


class Marshal :public Base
{
public:
	//Basic Marshal's methods and other functions
	void marshal_print_menu();
	void choice_of_marshal(char& choice);
	void marshal_choice_distrubitor(char& choice);
	void marshal_menu();
	/*Default Constructor*/

	Marshal();
protected:

	//This a function that determines whether you will assing or reassign your divisions by giving you a decision!!!!!

	int MarshalSpecialMenu();
	/*Special methods*/
	void getMarshals();
	void AssingFreeDiv();
	void ReassignDiv();
	void seeMarshalStruce();

	void OpenMarshalFile();
	void OpenFreeDivisionFile();
	/*This function's purpose to clear all vectors and reopening the files again*/
	void Open_files();


	void openConfirmFile(string& confimcode);


	int loginSystem() override
	{	/*Override function for Marshal*/

		if (controlMechs > 3) { cout << "You've tried to enter a lot, the program will exit..." << endl; exit(0); }
		else if (controlMechs >= 1 && controlMechs <= 3) { cout << "OOPS try Again!!!!" << endl << endl; }
		/*-----------------------------------------------------*/

		string ConfirmCode;
		string UserCode;

		openConfirmFile(ConfirmCode);

		cout << "Enter Confirm Code for (Marshal) to continue: ";

		cin >> UserCode;
		if (ConfirmCode != UserCode) { controlMechs++; return 0; }
		else {
			cout << "You're allowed to enter the system!!!!!" << endl;
			return 1;
		}
	}
};