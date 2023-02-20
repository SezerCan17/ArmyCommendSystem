#include "Base.h"
#include <fstream>
#include<iostream>
using namespace std;
void Base::openGeneralFile()
{
    fstream general_file;
    general_file.open("Common\\Generals\\Generals.txt");

    if (!general_file) { cout << "No such a file" << endl; }
    else {
        string genName;
        int assingArmy{};
        int assingArmyGroup{};
        while (!general_file.eof())
        {
            general_file >> genName;
            general_file >> assingArmy;
            general_file >> assingArmyGroup;
            GeneralName.push_back(genName);
            GeneralAssignArmy.push_back(assingArmy);
            GeneralAssignArmyGroup.push_back(assingArmyGroup);
        }

    }

    general_file.close();

}

void Base::OpenAssignedDivisionFile()
{

    /*Reading Assigned Division File*/
    fstream AssDivFile;
    AssDivFile.open("Common\\Divisions\\AssignDivision.txt", ios::in);

    if (!AssDivFile)
    {
        cout << "No such a file" << endl;
    }
    else {
        string line;
        string Temp;//Template
        int DivNumber{};
        string Loc;
        int AssArmy{};
        int AssArmyGr{};
        while (!AssDivFile.eof())
        {
            AssDivFile >> Temp;
            AssDivFile >> DivNumber;
            AssDivFile >> Loc;
            AssDivFile >> AssArmy;
            AssDivFile >> AssArmyGr;
            AssignDivisionName.push_back(Temp);
            AssignDivisionLocation.push_back(Loc);
            AssignDivisionNumber.push_back(DivNumber);
            AssignDivisionAssignedArmy.push_back(AssArmy);
            AssignDivisionAssignedArmyGroup.push_back(AssArmyGr);
        }
    }
    AssDivFile.close();
}