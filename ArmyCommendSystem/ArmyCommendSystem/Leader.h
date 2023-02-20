#pragma once
#include <string>
#include "Base.h"
#include <iostream>
using namespace std;
static int controlMechsForLeader = 0;

class Leader :public Base {
protected:
    long int CorePopulation;
    string ConscLaw;
    double ConscLawPercentage;
    void openConfirmFile(string& confimcode);
public:
    long int getCorePopulation();
    void getConscLaw();
    void setConscLaw(int);
    void getGenerals();
    void setGenerals();
    void getMarshals();
    void setMarshals();
    void leader_choice_distrubitor(char&);
    void choice_of_leader(char&);
    void leader_menu();
    void leader_print_menu();
    Leader();

    int loginSystem() override
    {	/*Override function for Leader*/
        if (controlMechsForLeader > 3) { cout << "You've tried to enter a lot, the program will exit..." << endl; exit(0); }
        else if (controlMechsForLeader >= 1 && controlMechsForLeader <= 3) { cout << "OOPS try Again!!!!" << endl << endl; }

        string ConfirmCode;
        string UserCode;
        openConfirmFile(ConfirmCode);
        cout << "Enter Confirm Code for (Leader) to continue: ";
        cin >> UserCode;
        if (ConfirmCode != UserCode) { controlMechsForLeader++; return 0; }
        else {
            cout << "You're allowed to enter the system!!!!!" << endl;
            return 1;
        }
    }

};