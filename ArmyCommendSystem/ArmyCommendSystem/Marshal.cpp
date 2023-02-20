#include "Marshal.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
//Print the marshal menu
void Marshal::marshal_print_menu() {
    cout << endl;
    cout << "a-) Reassign divisions" << endl;
    cout << "b-) See Marshal" << endl;
    cout << "c-) Back to the main menu" << endl;

}
// Take the choice for marshal menu
void Marshal::choice_of_marshal(char& choice) {

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
//Go to the required choice according to choice
void Marshal::marshal_choice_distrubitor(char& choice) {

    switch (choice)
    {
    case 'a':
    {
        //Reassign divisions
        int marhal_num{};
        int choice{};
        getMarshals();
        cout << "Choose a Marshal number to assign division Army group: ";
        cin >> marhal_num;
        choice = MarshalSpecialMenu();
        while (choice != 3)
        {
            if (choice == 1)
            {
                AssingFreeDiv();
            }
            else if (choice == 2)
            {
                ReassignDiv();
            }
            else {
                cout << "Going back to the menu" << endl;
            }
            choice = MarshalSpecialMenu();
        }

        break;
    }
    case 'b':
    {
        //See Marshal
        seeMarshalStruce();
        break;
    }
    case 'c':
    {
        //Back to the main menu
        cout << "Going back to the menu..." << endl;
        break;
    }
    default:
        cout << "An error occurred!!!" << endl;
    }

}

void Marshal::marshal_menu() {

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
        marshal_print_menu(); //Print the main menu
        choice_of_marshal(choice); // Take the user choice
        system("cls");
        marshal_choice_distrubitor(choice); //Go to the required choice according to choice

    } while (choice != 'c');


}

int Marshal::MarshalSpecialMenu()
{
    cout << endl;
    int special_menu_choice{};
    cout << "1)Assing free divisions" << endl;
    cout << "2)Reassign division which are in army" << endl;
    cout << "3)Back to the Marshal menu" << endl;
    cout << endl;
    cout << "Choose your choice: ";
    cin >> special_menu_choice;
    return special_menu_choice;
}

/*Setting variables from the text files*/
Marshal::Marshal()
{
    OpenMarshalFile();
    OpenFreeDivisionFile();
    openGeneralFile();
    OpenAssignedDivisionFile();
}

void Marshal::getMarshals()
{
    MarshalName.clear();
    MarshalAssignedArmyGroup.clear();
    OpenMarshalFile();
    //Displaying The marshal names and their assignd army group numbers to the screen
    cout << "Marshals                   AssignedArmyGroup" << endl;
    int counter{};
    for (size_t i{}; i < MarshalName.size(); i++)
    {
        if (MarshalAssignedArmyGroup.at(i) != 0)
        {
            cout << counter + 1 << ")" << left << setw(20) << MarshalName.at(i) << right << setw(18) << MarshalAssignedArmyGroup.at(i) << endl;
            counter++;
        }
    }
}

void Marshal::AssingFreeDiv()
{
    Open_files();
    vector<string>tempGenName; // The vector to print general names that are assigned to somewhere
    vector<int>tempGenAssignedArmy;//The vector to print assigned army numbers that are assigned to somewhere
    for (size_t i{}; i < GeneralName.size(); i++)
    {
        if (GeneralAssignArmy.at(i) != 0)
        {
            tempGenName.push_back(GeneralName.at(i));
            tempGenAssignedArmy.push_back(GeneralAssignArmy.at(i));
        }
    }

    cout << "Free divisions			Location of the Divisions" << endl;
    for (size_t i{}; i < FreeDivisionName.size(); i++)
    {
        cout << i + 1 << ")" << left << setw(20) << FreeDivisionName.at(i);
        cout << right << setw(20) << FreeDivisionLocation.at(i) << endl;
    }
    cout << endl << endl;


    /*Printing out Currently used Genereals to the screen*/
    int counter{};
    cout << "Generals 		AssignedArmy" << endl;
    for (size_t i{}; i < tempGenName.size(); ++i)
    {
        cout << counter + 1 << ")" << left << setw(20) << tempGenName.at(i) << right << setw(10) << tempGenAssignedArmy.at(i) << endl;
        counter++;
    }
    /*Getting free-division number and arrmy number to assign it.*/
     //Choose a currently general number

    int general_number{};
    int freeDiv_number{};
    int assign_new_army{};
    cout << "Choose a genereal: ";
    cin >> general_number;

    for (size_t i{}; i < GeneralName.size(); i++)
    {
        if (GeneralName.at(i) == tempGenName.at(general_number - 1))
        {
            general_number = i;
            break;
        }
    }


    cout << "Choose division and Army number to assign to a genereals'army: ";
    cin >> freeDiv_number >> assign_new_army;

    //It is time to overwrite the text files and change their information
    //removing the free div first from the text file and update the freeDivFile
    fstream freeDivFile;
    freeDivFile.open("Common\\Divisions\\FreeDivision.txt", ios::out);
    if (!freeDivFile) { cout << "No such a file"; }
    else {
        for (size_t i{}; i < FreeDivisionName.size(); i++)
            if (i != static_cast<unsigned long long>(freeDiv_number) - 1)
            {
                if (i != FreeDivisionName.size() - 1)
                    freeDivFile << FreeDivisionName.at(i) << "		" << FreeDivisionNumber.at(i) << "			" << FreeDivisionLocation.at(i) << "		" << FreeDivisionAssignedArmy.at(i) << "		" << FreeDivisionAssignedArmyGroup.at(i) << endl;
                else {
                    freeDivFile << FreeDivisionName.at(i) << "		" << FreeDivisionNumber.at(i) << "			" << FreeDivisionLocation.at(i) << "		" << FreeDivisionAssignedArmy.at(i) << "		" << FreeDivisionAssignedArmyGroup.at(i);
                }
            }
    }
    /*----------------------------------------------------------------------------------------------------------------------------------------------------*/
    freeDivFile.close();
    cout << endl << endl;
    /*Updating Assigned Division text file but we need to hold assigned army information*/
   /*Adding new Divison to the Assigned Divison vectors*/

    AssignDivisionName.push_back(FreeDivisionName.at(static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(freeDiv_number) - 1));
    AssignDivisionLocation.push_back(FreeDivisionLocation.at(static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(freeDiv_number) - 1));
    AssignDivisionNumber.push_back(FreeDivisionNumber.at(static_cast<std::vector<int, std::allocator<int>>::size_type>(freeDiv_number) - 1));
    //Changing assigned army group information from the given user input

    FreeDivisionAssignedArmy.at(static_cast<std::vector<int, std::allocator<int>>::size_type>(freeDiv_number) - 1) = assign_new_army;
    AssignDivisionAssignedArmy.push_back(FreeDivisionAssignedArmy.at(static_cast<std::vector<int, std::allocator<int>>::size_type>(freeDiv_number) - 1));

    FreeDivisionAssignedArmyGroup.at(static_cast<std::vector<int, std::allocator<int>>::size_type>(freeDiv_number) - 1) = GeneralAssignArmyGroup.at(general_number);
    AssignDivisionAssignedArmyGroup.push_back(FreeDivisionAssignedArmyGroup.at(static_cast<std::vector<int, std::allocator<int>>::size_type>(freeDiv_number) - 1));
    /*Now it is time to update the file*/
    /*---------------------------------------------------------------------------------------------------------------------------------*/


    fstream AssignDiv;
    AssignDiv.open("Common\\Divisions\\AssignDivision.txt", ios::out);
    if (!AssignDiv) { cout << "No such a file"; }
    else {
        for (size_t i{}; i < AssignDivisionName.size(); i++)
        {
            if (i != AssignDivisionName.size() - 1)
                AssignDiv << AssignDivisionName.at(i) << "		" << AssignDivisionNumber.at(i) << "			" << AssignDivisionLocation.at(i) << "		" << AssignDivisionAssignedArmy.at(i) << "		" << AssignDivisionAssignedArmyGroup.at(i) << endl;
            else {
                AssignDiv << AssignDivisionName.at(i) << "		" << AssignDivisionNumber.at(i) << "			" << AssignDivisionLocation.at(i) << "		" << AssignDivisionAssignedArmy.at(i) << "		" << AssignDivisionAssignedArmyGroup.at(i);
            }
        }
    }
    AssignDiv.close();
    tempGenName.clear();
    tempGenAssignedArmy.clear();

}


void Marshal::ReassignDiv()
{
    Open_files();

    //Displaying assigned Division information from vectors to the screen
    cout << endl << endl;
    cout << left << setw(25) << "Assigned Divisions" << right << setw(25) << "Location of the divisions" << right << setw(25) << "Assing Army" << endl;
    for (size_t i{}; i < AssignDivisionName.size(); i++)
    {
        cout << i + 1 << ")" << left << setw(20) << AssignDivisionName.at(i) << right << setw(20) << AssignDivisionLocation.at(i) << right << setw(23) << AssignDivisionAssignedArmy.at(i) << endl;
    }
    //Now we need to get new parameters from the users to reassign 
    int num{};//For division number
    int reassing_num{};//Reassign it
    cout << "Choose a division and Army number to reassign division to a general's army: ";
    cin >> num >> reassing_num;

    AssignDivisionAssignedArmy.at(static_cast<std::vector<int, std::allocator<int>>::size_type>(num) - 1) = reassing_num;

    fstream ReassignDiv;
    ReassignDiv.open("Common\\Divisions\\AssignDivision.txt", ios::out);
    if (!ReassignDiv) { cout << "No such a file"; }
    else {
        for (size_t i{}; i < AssignDivisionName.size(); i++)
        {
            if (i != AssignDivisionName.size() - 1)
                ReassignDiv << left << setw(20) << AssignDivisionName.at(i) << right << setw(20) << AssignDivisionNumber.at(i) << right << setw(20) << AssignDivisionLocation.at(i) << right << setw(20) << AssignDivisionAssignedArmy.at(i) << right << setw(20) << AssignDivisionAssignedArmyGroup.at(i) << endl;
            else {
                ReassignDiv << left << setw(20) << AssignDivisionName.at(i) << right << setw(20) << AssignDivisionNumber.at(i) << right << setw(20) << AssignDivisionLocation.at(i) << right << setw(20) << AssignDivisionAssignedArmy.at(i) << right << setw(20) << AssignDivisionAssignedArmyGroup.at(i);
            }
        }
    }

    ReassignDiv.close();
}


void Marshal::seeMarshalStruce()
{
    Open_files();//Read updated files

    int counter{};
    cout << "Currently used Marshals			Assign in Army Group		Assign genereals in ArmyGroup" << endl;
    for (size_t i{}; i < MarshalName.size(); i++)
    {
        if (MarshalAssignedArmyGroup.at(i) != 0)
        {
            cout << counter + 1 << ")" << left << setw(20) << MarshalName.at(i) << right << setw(20) << MarshalAssignedArmyGroup.at(i) << right << setw(45);
            for (size_t j{}; j < GeneralAssignArmyGroup.size(); j++)
            {
                if (MarshalAssignedArmyGroup.at(i) == GeneralAssignArmyGroup.at(j))
                {
                    cout << GeneralName.at(j) << " ";
                }
            }
            cout << endl;
            counter++;
        }
    }
}


void Marshal::OpenMarshalFile()
{
    /*Reading Marshal file*/
    fstream MarshalFile;
    MarshalFile.open("Common\\Marshals\\Marshals.txt", ios::in);

    if (!MarshalFile) { cout << "No such a file" << endl; }
    else {

        string line;
        int Assarmy{};
        string name;
        while (!MarshalFile.eof())
        {
            getline(MarshalFile, line);
            for (size_t i{}; i < line.length(); i++)
            {
                if (isdigit(line.at(i)))
                {
                    Assarmy = line.at(i) - '0';
                    line.erase(i - 1, i);
                    MarshalAssignedArmyGroup.push_back(Assarmy);
                    name = line;
                    MarshalName.push_back(name);
                }
            }

        }
    }

    MarshalFile.close();
}

void Marshal::OpenFreeDivisionFile()
{
    /*Reading Free division file*/
    fstream FreeDivFile;
    FreeDivFile.open("Common\\Divisions\\FreeDivision.txt", ios::in);

    if (!FreeDivFile)
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
        while (!FreeDivFile.eof())
        {
            FreeDivFile >> Temp;
            FreeDivFile >> DivNumber;
            FreeDivFile >> Loc;
            FreeDivFile >> AssArmy;
            FreeDivFile >> AssArmyGr;
            FreeDivisionName.push_back(Temp);
            FreeDivisionLocation.push_back(Loc);
            FreeDivisionNumber.push_back(DivNumber);
            FreeDivisionAssignedArmy.push_back(AssArmy);
            FreeDivisionAssignedArmyGroup.push_back(AssArmyGr);
        }
    }
    FreeDivFile.close();
}


void Marshal::Open_files()
{

    /*Repening Free division File */
    FreeDivisionName.clear();
    FreeDivisionNumber.clear();
    FreeDivisionLocation.clear();
    FreeDivisionAssignedArmy.clear();
    FreeDivisionAssignedArmyGroup.clear();
    OpenFreeDivisionFile();
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
    /*Reopening Marshal File*/
    MarshalName.clear();
    MarshalAssignedArmyGroup.clear();
    OpenMarshalFile();


}

void Marshal::openConfirmFile(string& confimcode)
{
    fstream Confirm_File;
    Confirm_File.open("Common\\Confirm Code(Marshal).txt", ios::in);

    if (!Confirm_File) { cout << "No such a file" << endl; }
    else {

        while (!Confirm_File.eof())
        {
            Confirm_File >> confimcode;
        }

    }

    Confirm_File.close();

}
