#pragma once
#include "Base.h"
#include <iostream>
using namespace std;
static int controlMechsForGeneral = 0;

class General :
    public Base
{
protected:
    void TotalDivision();
    void ChangeArmyDivLocation(int& GeneralNum);
    vector<int> TotalNODivisionUsed;
    void openConfirmFile(string& confimcode);
public:
    void general_menu();
    void general_choice_distrubitor(char& choice);
    void general_print_menu();
    void choice_of_general(char& choice);
    void DisplayGeneralsArmy();
    void DisplayGeneralsDivision(string& name);
    void DisplayGeneralandArmy();
    void DisplayGeneralAndLocation();
    /*Constructor*/
    General();
    void open_files();

    /*Login System*/

    int loginSystem() override
    {	/*Override function for General*/
        if (controlMechsForGeneral > 3) { cout << "You've tried to enter a lot, the program will exit..." << endl; exit(0); }
        else if (controlMechsForGeneral >= 1 && controlMechsForGeneral <= 3) { cout << "OOPS try Again!!!!" << endl << endl; }
        /*-----------------------------------------------------*/

        string ConfirmCode;;
        string UserCode;
        openConfirmFile(ConfirmCode);
        cout << "Enter Confirm Code for (General) to continue: ";

        cin >> UserCode;
        if (ConfirmCode != UserCode) { controlMechsForGeneral++; return 0; }
        else {
            cout << "You're allowed to enter the system!!!!!" << endl;
            return 1;
        }
    }


};