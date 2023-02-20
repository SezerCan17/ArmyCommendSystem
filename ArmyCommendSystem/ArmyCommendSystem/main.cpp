#include <iostream>
#include "Country.h"
#include <conio.h>
using namespace std;


void print_menu()
{
    cout << "1-Leader" << endl;
    cout << "2-General" << endl;
    cout << "3-Marshal" << endl;
    cout << "4-Council" << endl;
    cout << "5-Exit" << endl;
}
// Take the choice for the main menu
void get_choice(unsigned int& choice) {

    bool check{};

    do {
        cout << endl << "Choose your choice(1,2,3,4,5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)// Check the choice, if it is not in the required period,
            check = false;            // get new choice from the user
        else
        {
            check = true;
            cout << "Please choose a choice between 1 to 5!!!" << endl;
        }

    } while (check);

}
//Go to the required choice according to choice
void choice_distrubitor(unsigned int& choice, Country& country) {

    switch (choice)
    {
    case 1:
    {
        country.leader_menu();
        system("cls");
        break;
    }
    case 2:
    {
        country.general_menu();
        system("cls");
        break;
    }
    case 3:
    {
        country.marshal_menu();
        system("cls");
        break;
    }
    case 4:
    {
        country.CouncilMenu();
        system("cls");
        break;
    }
    case 5:
        exit(0);
    default:
    {
        cout << "An error occurred!!!" << endl;
    }
    }

}

int main() {

    Country country;

    unsigned int choice{};
    do {
        print_menu(); //Print the main menu
        get_choice(choice); // Take the user choice
        choice_distrubitor(choice, country); //Go to the required choice according to choice

    } while (choice != 5);

    return 0;
}