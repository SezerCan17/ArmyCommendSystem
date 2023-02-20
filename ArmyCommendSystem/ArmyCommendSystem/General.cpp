
#include "general.h"
#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;


/*------------------------------------------Constructor-----------------------------------------------*/
General::General()
{
    openGeneralFile();
    OpenAssignedDivisionFile();
}

void General::TotalDivision()
{ //This finds how many Divisions the Generals use.
    int counter{ 0 };
    string line;
    string str;


    /*Reading Assigned Division File*/
    open_files();
    for (int i = 0; i < GeneralAssignArmy.size(); i++)
    {
        for (int j = 0; j < AssignDivisionAssignedArmy.size(); j++)
        {
            if (GeneralAssignArmy[i] == AssignDivisionAssignedArmy[j])
            {
                counter++;
            }
        }
        TotalNODivisionUsed.push_back(counter);
        counter = 0;
    }
}


void General::ChangeArmyDivLocation(int& GeneralNum) {
    //Changes the location of the army.
    auto tempNum = 0;
    string loc;
    int DivAssArmy;
    open_files();
    cout << "Enter Location:";
    cin >> loc;

    DivAssArmy = GeneralAssignArmy[GeneralNum - 1];
    cout << "************************************************************************************************" << endl;
    for (int i = 0; i < AssignDivisionAssignedArmy.size(); i++)
        if (DivAssArmy == AssignDivisionAssignedArmy[i]) {
            AssignDivisionLocation[i] = loc;
        }
    cout << "************************************************************************************************" << endl;
    cout << endl;
    DisplayGeneralAndLocation();

}

void General::openConfirmFile(string& confimcode)
{
    fstream Confirm_File;
    Confirm_File.open("Common\\Confirm Code(General).txt", ios::in);

    if (!Confirm_File) { cout << "No such a file" << endl; }
    else {

        while (!Confirm_File.eof())
        {
            Confirm_File >> confimcode;
        }

    }

    Confirm_File.close();

}

void General::DisplayGeneralsArmy()
{
    open_files();
    int counter = 1;
    //It prints the name of the generals and their assigned armies and assigned army groups..
    cout << left << setw(34) << "Currently used Generals" << left << setw(20) << "Assign Army" << right << setw(20) << "Total Number Of Divisions Used" << endl;
    cout << "************************************************************************************************" << endl;
    for (int i = 0; i < GeneralName.size(); i++)
    {
        if (GeneralAssignArmy[i] != 0)
        {
            cout << counter << ")" << left << setw(20) << GeneralName[i] << right << setw(20) << GeneralAssignArmy[i] << right << setw(20) << TotalNODivisionUsed[i] << endl;
            counter++;
        }


    }
    cout << "*************************************************************************************************" << endl;
    cout << endl;
}

void General::DisplayGeneralsDivision(string& name)
{
    //It prints the divisions and division numbers of the general entered by the user.

    open_files();

    int temp = 0;
    int asArmy;
    int count = 1;
    cout << left << setw(10) << "General " << name << endl;
    for (int i = 0; i < GeneralName.size(); i++)
    {
        if (GeneralName[i] == name)
        {
            temp = i;
            break;
        }
    }

    asArmy = AssignDivisionAssignedArmy[temp];

    cout << left << setw(34) << "Division Name" << right << setw(20) << "Division Number" << endl;
    cout << "************************************************************************************************" << endl;

    for (int i = 0; i < AssignDivisionAssignedArmy.size(); i++)
    {
        if (AssignDivisionAssignedArmy[i] == asArmy)
        {
            cout << count << ")" << left << setw(20) << AssignDivisionName[i] << right << setw(18) << AssignDivisionNumber[i] << endl;
            count++;
        }
    }
    cout << "************************************************************************************************" << endl;
    cout << endl;


}

void General::DisplayGeneralandArmy()
{
    //The general prints his/her name and the armies assigned to them.

    open_files();
    int counter{ 1 };
    cout << left << setw(34) << "Currently Used Generals" << left << setw(20) << "Assign Army" << endl;
    cout << "************************************************************************************************" << endl;
    for (int i = 0; i < GeneralName.size(); i++)
    {
        cout << counter << ")" << left << setw(20) << GeneralName[i] << right << setw(18) << GeneralAssignArmy[i] << endl;
        counter++;

    }
    cout << "************************************************************************************************" << endl;
    cout << endl;

}

void General::DisplayGeneralAndLocation()
{
    //prints the changed locations to the file.

    ofstream writeFile;
    writeFile.open("Common\\Divisions\\AssignDivision.txt", ios::out);

    for (int i = 0; i < AssignDivisionNumber.size(); i++)
    {
        if (i != AssignDivisionNumber.size() - 1)
            writeFile << left << setw(20) << AssignDivisionName[i] << right << setw(20) << AssignDivisionNumber[i] << right << setw(20) << AssignDivisionLocation[i] << right << setw(20) << AssignDivisionAssignedArmy[i] << right << setw(20) << AssignDivisionAssignedArmyGroup[i] << endl;
        else
            writeFile << left << setw(20) << AssignDivisionName[i] << right << setw(20) << AssignDivisionNumber[i] << right << setw(20) << AssignDivisionLocation[i] << right << setw(20) << AssignDivisionAssignedArmy[i] << right << setw(20) << AssignDivisionAssignedArmyGroup[i];


    }

    open_files();

    writeFile.close();

}


void General::open_files()
{
    /*Reopening General File*/
    GeneralName.clear();
    GeneralAssignArmy.clear();
    GeneralAssignArmyGroup.clear();
    openGeneralFile();
    /*Reopening Assigned Free division*/
    AssignDivisionName.clear();
    AssignDivisionLocation.clear();
    AssignDivisionNumber.clear();
    AssignDivisionAssignedArmy.clear();
    AssignDivisionAssignedArmyGroup.clear();
    OpenAssignedDivisionFile();
}

void General::general_print_menu() {

    // Print the general menu

    cout << endl;
    cout << "a-) See generals' army divisions" << endl;
    cout << "b-) Change the location of the division" << endl;
    cout << "c-) Back to the main menu" << endl;

}

void General::choice_of_general(char& choice) {

    // Take the choice for general menu

    bool check{};

    do {
        cout << "Choose your choice (a,b,c): ";
        cin >> choice;

        choice = char(tolower(choice));
        cout << choice << endl;

        if (choice >= 'a' && choice <= 'c')// Check the choice, if it is not in the required period,
            check = false;                // get new choice from the user
        else
        {
            check = true;
            cout << "Please choose a choice between a to c!!!" << endl;
        }
    } while (check);

}


void General::general_choice_distrubitor(char& choice) {

    //Go to the required choice according to choice

    switch (choice)
    {
    case 'a':
    {
        //See generals' army divisions
        int x, temp;
        string y;
        TotalDivision();
        DisplayGeneralsArmy();
        cout << "Press 0 to see the number of generals and division type. " << endl;
        cout << "Press 1 to return to general option menu :" << endl;
        cin >> x;
        if (x == 0) {
            cout << "Enter General Name:" << endl;
            cin >> y;
            DisplayGeneralsDivision(y);
        }

        break;
    }
    case 'b':
    {
        //Change the location of the division
        int a;
        int GeneralNum{};
        DisplayGeneralandArmy();
        cout << "Press 0 to change position " << endl;
        cout << "Press 1 to return to general option menu :" << endl;
        cin >> a;
        if (a == 0)
        {
            cout << "Enter General Number:";
            cin >> GeneralNum;
            ChangeArmyDivLocation(GeneralNum);
        }

        break;
    }
    case 'c':
    {
        //Back to the main menu
        break;
    }
    default:
        cout << "An error occurred!!!" << endl;
    }

}
void General::general_menu() {

    char choice{};
    int type{ 0 };//That is for LoginSystem Function

    system("cls");
    type = loginSystem();
    while (type == 0)
    {
        system("cls");
        type = loginSystem();
    }

    do {
        general_print_menu(); //Print the main menu
        choice_of_general(choice); // Take the user choice
        system("cls");
        general_choice_distrubitor(choice); //Go to the required choice according to choice

    } while (choice != 'c');


}