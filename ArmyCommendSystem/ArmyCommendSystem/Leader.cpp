//
// Created by dogan on 13.12.2022.
//
#include<iostream>
#include "Leader.h"
#include <fstream>
#include <cctype>
#include <iomanip>
#include <vector>


using namespace std;

//Print the leader menu
void Leader::leader_print_menu() {

    cout << endl;
    cout << "a-) See Eligible Core Population" << endl;
    cout << "b-) See Conccription Law" << endl;
    cout << "c-) General Options" << endl;
    cout << "d-) Marshal Options" << endl;
    cout << "e-) Back to main menu" << endl;

}
// Take the choice for leader menu
void Leader::choice_of_leader(char& choice) {

    bool check;

    do {
        cout << "Choose your choice (a,b,c,d,e): ";
        cin >> choice;

        choice = char(tolower(choice));
        cout << choice << endl;

        if (choice >= 'a' && choice <= 'e')// Check the choice, if it is not in the required period,
            check = false;                // get new choice from the user
        else
        {
            check = true;
            cout << "Please choose a choice between a to e!!!" << endl;
        }
    } while (check);

}
//Go to the required choice according to choice
void Leader::leader_choice_distrubitor(char& choice) {

    switch (choice)
    {
    case 'a':
    {
        cout << endl << "Core Population:" << endl << endl;
        cout << getCorePopulation() << endl;
        break;
    }
    case 'b':
    {
        //See Conccription Law
        int number;
        getConscLaw();
        cout << endl << "Choose one the choice to change the current conscription law(1.2...)";
        cin >> number;
        setConscLaw(number);
        break;
    }
    case 'c':
    {
        int num;

        do {
            cout << endl << "1-See currently used Generals and its location" << endl << "2-Change the Generals" << endl << "3-Back to the Leader menu" << endl << endl << "Choose your choice(1,2,3)" << endl;
            cin >> num;
            if (num == 1) {
                getGenerals();
            }
            else if (num == 2) {
                setGenerals();
            }
        } while (num != 3);

        break;
    }
    case 'd':
    {
        int num;

        do {
            cout << endl << "1-See currently used Marshals and its location" << endl << "2-Change the Marshals" << endl << "3-Back to the Leader menu" << endl << endl << "Choose your choice(1,2,3)" << endl;
            cin >> num;
            if (num == 1) {
                getMarshals();
            }
            else if (num == 2) {
                setMarshals();
            }
        } while (num != 3);

        break;
    }
    case 'e':
        //Back to main menu
        break;
    default:
        cout << "An error occurred!!!" << endl;
    }

}

void Leader::leader_menu() {

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
        leader_print_menu(); //Print the main menu
        choice_of_leader(choice); // Take the user choice
        system("cls");
        leader_choice_distrubitor(choice); //Go to the required choice according to choice

    } while (choice != 'e');


}
Leader::Leader() {
    ConscLaw = "Disarmed Nation";
    ConscLawPercentage = 0.01;
    CorePopulation = 0;
}
void Leader::openConfirmFile(string& confimcode)
{
    fstream Confirm_File;
    Confirm_File.open("Common\\Confirm Code(Leader).txt", ios::in);

    if (!Confirm_File) { cout << "No such a file" << endl; }
    else {

        while (!Confirm_File.eof())
        {
            Confirm_File >> confimcode;
        }

    }

    Confirm_File.close();

}
long int Leader::getCorePopulation() {
    ifstream readFile("Common\\Recruitable Population.txt");;
    if (!readFile) {
        cout << "Fail";
        exit(1);
    }
    readFile >> CorePopulation;
    readFile.close();

    return CorePopulation;
}

void Leader::getConscLaw() {
    string str;
    ifstream readFile("Common\\Conscription Laws.txt");
    if (!readFile) {
        cout << "fail";
        exit(1);
    }
    cout << "Currentlaw" << " " << ConscLaw << " Usable core population" << " " << CorePopulation * ConscLawPercentage << endl;
    while (!readFile.eof())
    {
        getline(readFile, str);
        cout << str << endl;
    }

}
void Leader::setConscLaw(int number) {
    int j = 0;
    string str;
    vector<string> vect;
    ifstream readFile("Common\\Conscription Laws.txt");
    if (!readFile) {
        cout << "fail";
        exit(1);
    }
    while (!readFile.eof())
    {
        getline(readFile, str);
        vect.push_back(str);
        j++;
    }
    double found;
    vector <double>percent;
    vector<string> str2;
    for (int i = 0; i < j; i++) {
        stringstream ss;
        ss << vect[i];
        string temp;
        string tempword;
        int firstcntr = 0;
        while (!ss.eof()) {
            ss >> tempword;
            if (stringstream(tempword) >> found)
                percent.push_back((double)found);
            else {
                if (firstcntr == 0) {
                    temp = tempword;
                }
                else {
                    temp += " " + tempword;
                }
                firstcntr = 1;
            }
            tempword = "";
        }
        str2.push_back(temp);
    }
    ConscLaw = str2[number - 1];
    ConscLawPercentage = percent[number - 1];
}

void Leader::getGenerals() {
    int j = 0;
    string str;
    vector<string> vect;
    ifstream readFile("Common\\Generals\\Generals.txt");
    if (!readFile) {
        cout << "fail";
        exit(1);
    }
    while (!readFile.eof())
    {
        getline(readFile, str);
        vect.push_back(str);
        j++;
    }

    double found;
    int num = 0;
    int num2 = 0;
    int k = 0;
    int k2 = 0;
    vector <int>keepgen;
    vector<int>keepgensecond;
    vector<int>assignednum;
    vector<int>assignedsecondnum;
    vector<int>nrofarmy;
    vector<double> assignedOnlyNum;
    vector<double> assignedOnlysecondNum;
    vector<string> str2;
    for (int i = 0; i < j; i++) {
        stringstream ss;
        ss << vect[i];
        string temp;
        string tempword;
        int firstcntr = 0;
        int secondcntr = 0;
        while (!ss.eof()) {
            ss >> tempword;
            if (stringstream(tempword) >> found) {
                if (secondcntr == 0) {
                    if ((double)found == 0) {
                        keepgen.push_back(i);
                        num++;
                    }
                    else if ((double)found != 0) {
                        assignedOnlyNum.push_back(i);
                        k++;
                    }
                    assignednum.push_back((double)found);
                }
                else {
                    if ((double)found == 0) {
                        keepgensecond.push_back(i);
                        num2++;
                    }
                    else if ((double)found != 0) {
                        assignedOnlysecondNum.push_back(i);
                        k2++;
                    }
                    assignedsecondnum.push_back((double)found);
                }
                secondcntr = 1;
            }

            else {
                if (firstcntr == 0) {
                    temp = tempword;
                }
                else {
                    temp += " " + tempword;
                }
                firstcntr = 1;
            }
            tempword = "";
        }
        str2.push_back(temp);
    }
    for (int i = 0; i < k; i++) {
        cout << left << setw(22) << str2[assignedOnlyNum[i]] << " " << left << setw(22) << assignednum[assignedOnlyNum[i]] << left << setw(22) << assignednum[assignedOnlysecondNum[i]] << endl;
    }
}
void Leader::setGenerals() {
    int j = 0;
    string str;
    vector<string> vect;
    ifstream readFile("Common\\Generals\\Generals.txt");
    if (!readFile) {
        cout << "fail";
        exit(1);
    }
    while (!readFile.eof())
    {
        getline(readFile, str);
        vect.push_back(str);
        j++;
    }

    double found;
    int num = 0;
    int num2 = 0;
    int k = 0;
    int k2 = 0;
    vector <int>keepgen;
    vector<int>keepgensecond;
    vector<int>assignednum;
    vector<int>assignedsecondnum;
    vector<int>nrofarmy;
    vector<double> assignedOnlyNum;
    vector<double> assignedOnlysecondNum;
    vector<string> str2;
    for (int i = 0; i < j; i++) {
        stringstream ss;
        ss << vect[i];
        string temp;
        string tempword;
        int firstcntr = 0;
        int secondcntr = 0;
        while (!ss.eof()) {
            ss >> tempword;
            if (stringstream(tempword) >> found) {
                if (secondcntr == 0) {
                    if ((double)found == 0) {
                        keepgen.push_back(i);
                        num++;
                    }
                    else if ((double)found != 0) {
                        assignedOnlyNum.push_back(i);
                        k++;
                    }
                    assignednum.push_back((double)found);
                }
                else {
                    if ((double)found == 0) {
                        keepgensecond.push_back(i);
                        num2++;
                    }
                    else if ((double)found != 0) {
                        assignedOnlysecondNum.push_back(i);
                        k2++;
                    }
                    assignedsecondnum.push_back((double)found);
                }
                secondcntr = 1;
            }

            else {
                if (firstcntr == 0) {
                    temp = tempword;
                }
                else {
                    temp += " " + tempword;
                }
                firstcntr = 1;
            }
            tempword = "";
        }
        str2.push_back(temp);
    }
    cout << "Avaliable Generals to assign" << endl;
    for (int i = 0; i < num; i++) {
        cout << i + 1 << "-" << str2[keepgen[i]] << endl;
    }

    cout << "choose general number" << endl;
    int n;
    cin >> n;
    cout << "Current Generals" << endl;
    cout << left << setw(22) << "General" << left << setw(22) << left << setw(22) << "Assigned Army" << left << setw(22) << "Assigned Army Group\t" << endl;
    for (int i = 0; i < k; i++) {
        cout << left << setw(22) << str2[assignedOnlyNum[i]] << " " << left << setw(22) << assignednum[assignedOnlyNum[i]] << left << setw(22) << assignednum[assignedOnlysecondNum[i]] << endl;
    }
    cout << "choose current general number" << endl;
    int m;
    cin >> m;

    int GeneralAssignAr;
    GeneralAssignAr = assignednum[assignedOnlyNum[m - 1]];
    GeneralAssignArmy.push_back(GeneralAssignAr);
    int NrOfAr;
    NrOfAr = assignednum[assignedOnlysecondNum[m - 1]];
    GeneralAssignArmyGroup.push_back(NrOfAr);
    ofstream writeFile("Common\\Generals\\Generals.txt");
    for (int i{ 0 }; i < j; i++) {
        if (keepgen[n - 1] != i) {
            if (assignedOnlyNum[m - 1] != i) {
                if (i == j - 1) {
                    writeFile << str2[i] << "\t" << assignednum[i] << "\t" << assignednum[i];
                }
                else {
                    writeFile << str2[i] << "\t" << assignednum[i] << "\t" << assignednum[i] << endl;
                }
            }
            else {
                if (i == j - 1) {
                    writeFile << str2[i] << "\t" << 0 << "\t" << 0;
                }
                else {
                    writeFile << str2[i] << "\t" << 0 << "\t" << 0 << endl;
                }
            }


        }
        else {
            if (i == j - 1) {
                writeFile << str2[i] << "\t" << GeneralAssignAr << "\t" << NrOfAr;
            }
            else {
                writeFile << str2[i] << "\t" << GeneralAssignAr << "\t" << NrOfAr << endl;
            }

        }

    }

}
void Leader::getMarshals() {
    int j = 0;
    string str;
    vector<string> vect;
    ifstream readFile("Common\\Marshals\\Marshals.txt");
    if (!readFile) {
        cout << "fail";
        exit(1);
    }
    while (!readFile.eof())
    {
        getline(readFile, str);
        vect.push_back(str);
        j++;
    }

    int found;
    int num = 0;
    int k = 0;
    vector<double> assignedOnlyNum;
    vector<int>assignednum;
    vector<string> str2;
    vector <int>keepmarsh;
    for (int i = 0; i < j; i++) {
        stringstream ss;
        ss << vect[i];
        string temp;
        string tempword;
        int firstcntr = 0;
        while (!ss.eof()) {
            ss >> tempword;
            if (stringstream(tempword) >> found) {
                if (found == 0) {
                    keepmarsh.push_back(i);
                    num++;
                }
                else if ((double)found != 0) {
                    assignedOnlyNum.push_back(i);
                    k++;
                }
                assignednum.push_back(found);
            }

            else {
                if (firstcntr == 0) {
                    temp = tempword;
                }
                else {
                    temp += " " + tempword;
                }
                firstcntr = 1;
            }
            tempword = "";
        }
        str2.push_back(temp);
    }
    for (int i = 0; i < k; i++) {
        cout << left << setw(22) << str2[assignedOnlyNum[i]] << " " << left << setw(22) << assignednum[assignedOnlyNum[i]] << endl;
    }
}
void Leader::setMarshals() {
    int j = 0;
    string str;
    vector<string> vect;
    ifstream readFile("Common\\Marshals\\Marshals.txt");
    if (!readFile) {
        cout << "fail";
        exit(1);
    }
    while (!readFile.eof())
    {
        getline(readFile, str);
        vect.push_back(str);
        j++;
    }

    double found;
    int num = 0;
    int k = 0;
    vector<double> assignedOnlyNum;

    vector <int>keepmarsh;
    vector<int>assignednum;
    vector<string> str2;
    for (int i = 0; i < j; i++) {
        stringstream ss;
        ss << vect[i];
        string temp;
        string tempword;
        int firstcntr = 0;
        while (!ss.eof()) {
            ss >> tempword;
            if (stringstream(tempword) >> found) {
                if ((double)found == 0) {
                    keepmarsh.push_back(i);
                    num++;
                }
                else if ((double)found != 0) {
                    assignedOnlyNum.push_back(i);
                    k++;
                }
                assignednum.push_back((double)found);
            }

            else {
                if (firstcntr == 0) {
                    temp = tempword;
                }
                else {
                    temp += " " + tempword;
                }
                firstcntr = 1;
            }
            tempword = "";
        }
        str2.push_back(temp);
    }

    cout << "Avaliable Marshals to assign" << endl;
    for (int i = 0; i < num; i++) {
        cout << i + 1 << "-" << str2[keepmarsh[i]] << endl;
    }
    cout << "choose marshals number" << endl;
    int n;
    cin >> n;
    cout << "Current Marshals" << endl;
    cout << left << setw(22) << "Marshals" << left << setw(22) << left << setw(22) << "Marshals Army Group" << endl;
    for (int i = 0; i < k; i++) {
        cout << left << setw(22) << str2[assignedOnlyNum[i]] << " " << left << setw(22) << assignednum[assignedOnlyNum[i]] << endl;
    }
    cout << "choose marshal general number" << endl;
    int m;
    cin >> m;
    int AssignedArmyGro;
    AssignedArmyGro = assignednum[assignedOnlyNum[m - 1]];
    MarshalAssignedArmyGroup.push_back(AssignedArmyGro);
    ofstream writeFile("Common\\Marshals\\Marshals.txt");
    for (int i{ 0 }; i < j; i++) {
        if (keepmarsh[n - 1] != i) {
            if (assignedOnlyNum[m - 1] != i) {
                if (i == j - 1) {
                    writeFile << str2[i] << "\t" << assignednum[i];
                }
                else {
                    writeFile << str2[i] << "\t" << assignednum[i] << endl;
                }
            }
            else {
                if (i == j - 1) {
                    writeFile << str2[i] << "\t" << 0;
                }
                else {
                    writeFile << str2[i] << "\t" << 0 << endl;
                }
            }

        }
        else {
            if (i == j - 1) {
                writeFile << str2[i] << "\t" << AssignedArmyGro;
            }
            else {
                writeFile << str2[i] << "\t" << AssignedArmyGro << endl;
            }

        }
    }
}