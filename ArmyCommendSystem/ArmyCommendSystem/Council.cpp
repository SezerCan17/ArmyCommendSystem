#include "Council.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
//Read the Available Templates from file
void Council::ReadAvailableTemplates() {

    //Opening file in reading mode
    std::fstream AvailableTemplates;
    //AvailableTemplates.open("Common\\Templates\\AvailableTemplates.txt", std::ios::in);
    AvailableTemplates.open("Common\\Templates\\AvailableTemplates.txt", std::ios::in);

    if (!AvailableTemplates.is_open()) //checking whether the file is open
        std::cout << "File does not exist!" << std::endl;

    std::string line;
    int number;

    while (!AvailableTemplates.eof())
    {
        getline(AvailableTemplates, line); //Read contents line by line
        AvlTemplateNum++; //Read the # of line
        {
            std::string temp, tempWord;
            std::stringstream ss{ line };
            int firstcntr = 0;

            while (!ss.eof())
            {
                // extracting word by word from stream
                ss >> tempWord;

                //Check whether it is an integer or not
                if (std::stringstream(tempWord) >> number)
                    //If the tempWord content is a number then
                    ReqManpower.push_back((int)number);
                else
                {
                    if (firstcntr == 0)
                        temp = tempWord;
                    else
                        temp += " " + tempWord;

                    firstcntr = 1;
                }

                tempWord = "";
            }
            TemplateName.push_back(temp);
        }

    }

    AvailableTemplates.close();
}

//Display Available Template list
void Council::DisplayAvlTemplate() {

    //Print the Available Templates
    std::cout << std::left << std::setw(7) << ""
        << std::left << std::setw(20) << "Template Name"
        << std::right << std::setw(21) << "Required Manpower" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    for (size_t i{}; i < AvlTemplateNum; i++)
        std::cout << std::left << std::setw(5) << i + 1 << ':'
        << ' ' << std::left << std::setw(20) << TemplateName[i]
        << ' ' << std::right << std::setw(20) << ReqManpower[i] << std::endl;

}

//Read the list of the Assign divisions from file
void Council::ReadAssignDiv() {

    int number;
    std::string line;

    //Opening file in reading mode
    std::fstream AssignDivision;
    AssignDivision.open("Common\\Divisions\\AssignDivision.txt", std::ios::in);

    if (!AssignDivision.is_open()) //checking whether the file is open
        std::cout << "File does not exist!" << std::endl;



    while (!AssignDivision.eof())
    {
        getline(AssignDivision, line); //Read contents line by line
        NumOfAssignDiv++; //Read the # of line
        {
            std::string temp, tempWord;
            std::stringstream ss{ line };
            size_t integerCounter{ 0 };

            int firstcntr = 0;

            while (!ss.eof())
            {
                // extracting word by word from stream
                ss >> tempWord;

                //Check whether it is an integer or not
                if (std::stringstream(tempWord) >> number)
                {   //If the tempWord content is a number then
                    if (integerCounter == 0)
                        AssignDivisionNumber.push_back((int)number);
                    else if (integerCounter == 1)
                        AssignDivisionAssignedArmy.push_back((int)number);
                    else if (integerCounter == 2)
                        AssignDivisionAssignedArmyGroup.push_back((int)number);

                    integerCounter++;
                }
                else    //If tempWord is not an integer than it`s a string
                {
                    bool check{ false };

                    //Check tempWord is a Template Name or not
                    for (size_t i{}; i < AvlTemplateNum; i++)
                    {
                        size_t found = TemplateName[i].find(tempWord);

                        //If tempWord included in templateName then it is a Template Name if not it is a location
                        if (found != std::string::npos)
                            check = true;
                    }

                    if (check == false)
                        AssignDivisionLocation.push_back(tempWord);
                    else
                    {
                        if (firstcntr == 0)
                            temp = tempWord;
                        else
                            temp += " " + tempWord;
                    }
                    firstcntr = 1;
                }

                tempWord = "";
            }
            AssignDivisionName.push_back(temp);
        }

    }

    AssignDivision.close();

}

//Read the list of the Free divisions from file
void Council::ReadFreeDiv() {

    std::string line;
    int number;


    //Opening file in reading mode
    std::fstream FreeDivision;
    FreeDivision.open("Common\\Divisions\\FreeDivision.txt", std::ios::in);


    if (!FreeDivision.is_open()) //checking whether the file is open
        std::cout << "File does not exist!" << std::endl;



    while (!FreeDivision.eof())
    {
        getline(FreeDivision, line); //Read contents line by line
        NumOfFreeDiv++; //Read the # of line
        {
            std::string temp, tempWord;
            std::stringstream ss{ line };
            int firstcntr = 0;
            size_t integerCounter{ 0 };
            while (!ss.eof())
            {
                // extracting word by word from stream
                ss >> tempWord;

                //Check whether it is an integer or not
                if (std::stringstream(tempWord) >> number)
                {   //If the tempWord content is a number then
                    if (integerCounter == 0)
                        FreeDivisionNumber.push_back((int)number);
                    else if (integerCounter == 1)
                        FreeDivisionAssignedArmy.push_back((int)number);
                    else if (integerCounter == 2)
                        FreeDivisionAssignedArmyGroup.push_back((int)number);

                    integerCounter++;
                }
                else    //If tempWord is not an integer than it`s a string
                {
                    bool check{ false };

                    //Check tempWord is a Template Name or not
                    for (size_t i{}; i < AvlTemplateNum; i++)
                    {
                        size_t found = TemplateName[i].find(tempWord);

                        //If tempWord included in templateName then it is a Template Name if not it is a location
                        if (found != std::string::npos)
                            check = true;
                    }

                    if (check == false)
                        FreeDivisionLocation.push_back(tempWord);
                    else
                    {
                        if (firstcntr == 0)
                            temp = tempWord;
                        else
                            temp += " " + tempWord;
                    }
                    firstcntr = 1;
                }

                tempWord = "";
            }
            FreeDivisionName.push_back(temp);
        }

    }

    FreeDivision.close();

}

//Read the battalion list from the file
void Council::ReadBattalion() {

    int number;
    std::string line;


    //Opening file in reading mode
    std::fstream Battalions;
    Battalions.open("Common\\Division Type\\Battalions.txt", std::ios::in);

    //Checking whether the file is open or not
    if (!Battalions.is_open())
        std::cout << "File does not exist!" << std::endl;


    while (!Battalions.eof())
    {
        //Read contents line by line
        getline(Battalions, line);
        NumOfBattalions++;
        {
            std::string temp, tempWord;
            std::stringstream ss{ line };
            int firstcntr = 0;

            while (!ss.eof())
            {
                // extracting word by word from stream
                ss >> tempWord;

                //Check whether it is an integer or not
                if (std::stringstream(tempWord) >> number)
                    //If the tempWord content is a number then
                    ReqManpowerBattalions.push_back((int)number);
                else
                {
                    if (firstcntr == 0)
                        temp = tempWord;
                    else
                        temp += " " + tempWord;

                    firstcntr = 1;
                }

                tempWord = "";
            }
            BattalionsName.push_back(temp);
        }

    }

    Battalions.close();

}

//Create new Divisions
void Council::CreateDiv() {

    int TemplateNum, DivNum;

    DisplayAvlTemplate();

    std::cout << std::endl << "Choose a template # or press 0 to quit:" << ' ';
    std::cin >> TemplateNum;


    if (TemplateNum != 0)
    {
        std::cout << std::endl << "Choose the division size:" << ' ';
        std::cin >> DivNum;


        //Opening file in reading mode
        std::fstream FreeDivision;

        FreeDivision.open("Common\\Divisions\\FreeDivision.txt", std::ios::app);


        if (!FreeDivision.is_open()) //checking whether the file is open
            std::cout << "File does not exist!" << std::endl;

        NumOfDiv++;
        for (size_t i{}; i < DivNum; i++) {

            //Update the related variables
            TemplateDivName.push_back(TemplateName[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(TemplateNum) - 1]);
            DivisionNum.push_back(NumOfDiv);
            DivisionAssignArmy.push_back(0);
            DivisionAssignArmyGroup.push_back(0);
            DivisionLocation.emplace_back("Ankara");

            //Writing the new divisions to the free division file
            FreeDivision << std::endl << TemplateName[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(TemplateNum) - 1]
                << std::left << "\t" << NumOfDiv++
                << std::left << "\t" << "Ankara"
                << std::left << "\t" << 0
                << std::left << "\t" << 0;
        }
        NumOfDiv--;
        FreeDivision.close();
    }



}

//Display the division list
void Council::DisplayDiv() {
    DisplayNumOfDivType();
    //Display the division according to Assign/Unassigned
    std::cout << std::endl << std::endl;
    std::cout << std::left << std::setw(7) << ""
        << std::left << std::setw(20) << "Division Name"
        << std::right << std::setw(16) << "Division Number"
        << std::right << std::setw(21) << "Assigned/Unassigned" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    for (size_t i{}; i < NumOfDiv; i++) {
        if (DivisionAssignArmy[i] != 0)
            std::cout << std::left << std::setw(5) << i + 1 << ":"
            << ' ' << std::left << std::setw(20) << TemplateDivName[i]
            << ' ' << std::right << std::setw(15) << DivisionNum[i]
            << ' ' << std::right << std::setw(20) << "Assigned" << std::endl;
        else
            std::cout << std::left << std::setw(5) << i + 1 << ":"
            << ' ' << std::left << std::setw(20) << TemplateDivName[i]
            << ' ' << std::right << std::setw(15) << DivisionNum[i]
            << ' ' << std::right << std::setw(20) << "Unassigned" << std::endl;
    }

}

//Display the number of each division type
void Council::DisplayNumOfDivType() {

    std::vector<int> NumOfTemplate;

    //Count the numbers for each template has how many divisions
    for (size_t i{}; i < AvlTemplateNum; i++)
    {
        NumOfTemplate.push_back(0);
        for (size_t j{}; j < NumOfDiv; j++)
        {
            if (TemplateName[i] == TemplateDivName[j])
                NumOfTemplate[i]++;
        }
    }

    //Print the number of divisions for each template
    std::cout << std::endl;
    for (size_t i{}; i < AvlTemplateNum; i++)
        std::cout << "###" << " There are" << ' ' << NumOfTemplate[i] << ' ' << TemplateName[i] << std::endl;

}

//Display the Battalion list
void Council::DisplayBattalion() {

    //Print the Battalions list
    std::cout << std::left << std::setw(7) << ""
        << std::left << std::setw(20) << "Battalion Name"
        << std::right << std::setw(31) << "Required Manpower" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    for (size_t i{}; i < NumOfBattalions; i++)
        std::cout << std::left << std::setw(5) << i + 1 << ':'
        << ' ' << std::left << std::setw(30) << BattalionsName[i]
        << ' ' << std::right << std::setw(20) << ReqManpowerBattalions[i] << std::endl;
}

//Design new Template
void Council::DesignTemplate() {

    std::string NewTemplateName;
    int BattalionNum, BattalionSize, ReqManPower{ 0 }, counter{ 0 };

    std::cin.ignore();
    std::cout << std::endl << "Choose a name for template:" << ' ';
    getline(std::cin, NewTemplateName);

    std::string line;

    std::string FileName{ "Common\\Templates\\" };


    FileName += NewTemplateName;

    //Creating a new file in writing mode
    std::fstream NewTemplate;
    NewTemplate.open(FileName, std::ios::out);

    //Update the Available template/Num vector

    size_t found = NewTemplateName.find(".txt");

    //If tempWord included in templateName then it is a Template Name if not it is a location
    if (found != std::string::npos)
        NewTemplateName.erase(found, NewTemplateName.size() - 1);


    TemplateName.push_back(NewTemplateName);
    AvlTemplateNum++;

    while (true)
    {
        std::cout << std::endl;
        DisplayBattalion();

        //If we run this code first time generate a new space in vector
        if (counter == 0)
            ReqManpower.push_back(ReqManPower);

        std::cout << std::endl << "Choose a battalions # or 0 to complete the assign battalions:" << ' ';
        std::cin >> BattalionNum;

        //Prevent the unnecessary end lines in file
        if (counter != 0 && BattalionNum != 0)
            NewTemplate << std::endl;

        if (BattalionNum != 0) {

            std::cout << std::endl << "Choose the # of the battalions:" << ' ';
            std::cin >> BattalionSize;

            NewTemplate << BattalionsName[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(BattalionNum) - 1]
                << std::right << std::setw(10) << BattalionSize
                << std::right << std::setw(10) << ReqManpowerBattalions[static_cast<std::vector<int, std::allocator<int>>::size_type>(BattalionNum) - 1];

            ReqManpower[AvlTemplateNum - 1] += ReqManpowerBattalions[static_cast<std::vector<int, std::allocator<int>>::size_type>(BattalionNum) - 1] * BattalionSize;
            counter = 1;
        }
        else
            break;
    }

    //Closing the File
    NewTemplate.close();


    //Opening file in append mode
    std::fstream AvailableTemplates;

    AvailableTemplates.open("Common\\Templates\\AvailableTemplates.txt", std::ios::app);

    AvailableTemplates << std::endl << std::left << std::setw(15) << NewTemplateName
        << std::right << std::setw(10) << ReqManPower;

    //Closing the File
    AvailableTemplates.close();


}

//Update a currently used template
void Council::RedesignedTemplate() {

    int TemplateChoice, BattalionNum, Size, check;
    int number, NumOfBattalionType{ 0 };

    std::vector<std::string> BattalionName;
    std::vector<int> BattalionSize, BattalionManPower;

    std::string line;

    std::string FileName{ "Common\\Templates\\" };


    DisplayAvlTemplate();       //Print the Available Templates

    std::cout << std::endl << "Choose a template number to redesign:" << ' ';
    std::cin >> TemplateChoice;


    FileName = FileName + TemplateName[TemplateChoice - 1] + ".txt";      //Completing the file path


    //Creating a new file in writing mode
    std::fstream Template;
    Template.open(FileName, std::ios::in);

    //Checking whether the file is open or not
    if (!Template.is_open())
        std::cout << "File does not exist!" << std::endl;

    //Read The template`s battalion structure
    while (!Template.eof())
    {
        //Read contents line by line
        getline(Template, line);
        NumOfBattalionType++;
        {
            std::string temp, tempWord;
            std::stringstream ss{ line };
            int firstcntr = 0;
            size_t Counter{ 0 };

            while (!ss.eof())
            {
                // extracting word by word from stream
                ss >> tempWord;

                //Check whether it is an integer or not
                if (std::stringstream(tempWord) >> number)
                {
                    //If the tempWord content is a number then
                    if (Counter == 0)
                        BattalionSize.push_back((int)number);
                    else
                        BattalionManPower.push_back((int)number);

                    Counter++;
                }
                else
                {
                    if (firstcntr == 0)
                        temp = tempWord;
                    else
                        temp += " " + tempWord;

                    firstcntr = 1;
                }

                tempWord = "";
            }
            BattalionName.push_back(temp);
        }

    }

    Template.close();


    Template.open(FileName, std::ios::out);

    //Checking whether the file is open or not
    if (!Template.is_open())
        std::cout << "File does not exist!" << std::endl;

    while (true)
    {
        std::cout << std::endl;
        DisplayBattalion(); //Display the Battalion list

        std::cout << std::endl << std::endl << "Choose a battalions # or 0 to complete the assign battalions:" << ' ';
        std::cin >> BattalionNum;


        if (BattalionNum != 0)
        {

            std::cout << std::endl << "Choose the # of the battalions:" << ' ';
            std::cin >> Size;
            check = 0;

            for (size_t i{}; i < NumOfBattalionType; i++)
            {
                //If the battalion is used in the template update it
                if (BattalionName[i] == BattalionsName[BattalionNum - 1]) {
                    BattalionSize[i] += Size;
                    BattalionManPower[i] += Size * ReqManpowerBattalions[BattalionNum - 1];
                    ReqManpower[TemplateChoice - 1] += BattalionManPower[i];
                    check = 1;
                    break;
                }
            }

            //If the battalion is not used in the template create new one
            if (check == 0)
            {
                BattalionName.push_back(BattalionsName[BattalionNum - 1]);
                BattalionSize.push_back(Size);
                BattalionManPower.push_back(Size * ReqManpowerBattalions[BattalionNum - 1]);
                ReqManpower[TemplateChoice - 1] += Size * ReqManpowerBattalions[BattalionNum - 1];
                NumOfBattalionType++;
            }
        }
        else
            break;
    }


    std::cout << BattalionName.size() << std::endl;


    //Update the template
    for (size_t i{}; i < NumOfBattalionType; i++)
    {
        if (i != NumOfBattalionType - 1)
            Template << BattalionName[i] << std::setw(10) << std::left << "\t"
            << BattalionSize[i] << std::setw(10) << std::right
            << BattalionManPower[i] << std::setw(10) << std::right << std::endl;
        else
        {
            Template << BattalionName[i] << std::setw(10) << std::left << "\t"
                << BattalionSize[i] << std::setw(10) << std::right
                << BattalionManPower[i] << std::setw(10) << std::right;
        }
    }
    Template.close();

}

//Print the Council menu
void Council::CouncilPrintMenu() {

    std::cout << std::endl;
    std::cout << "a-) Create Divisions" << std::endl;
    std::cout << "b-) See total number of divisions" << std::endl;
    std::cout << "c-) Design division templates" << std::endl;
    std::cout << "d-) Redesign division templates" << std::endl;
    std::cout << "e-) Back to the main menu" << std::endl;

}
// Take the choice for Council menu
void Council::ChoiceOfCouncil(char& choice) {

    bool check;

    do {
        std::cout << "Choose your choice (a,b,c,d,e): " << ' ';
        std::cin >> choice;

        choice = char(tolower(choice));
        std::cout << choice << std::endl;

        if (choice >= 'a' && choice <= 'e')// Check the choice, if it is not in the required period,
            check = false;                // get new choice from the user
        else
        {
            check = true;
            std::cout << "Please choose a choice between a to e!!!" << std::endl;
        }
    } while (check);

}
//Go to the required choice according to choice
void Council::CouncilChoiceDistributor(char& choice) {
    switch (choice)
    {
    case 'a':
    {
        //Create Divisions according to available templates
        CreateDiv();
        break;
    }
    case 'b':
    {
        //Display the list of the divisions
        DisplayDiv();

        break;
    }
    case 'c':
    {
        //Create a new template, using battalions
        DesignTemplate();
        break;
    }
    case 'd':
    {
        //Redesigning an available template, using battalions
        RedesignedTemplate();
        break;
    }
    case 'e':
    {
        //Back to the main menu
        break;
    }
    default:
        std::cout << "An error occurred!!!" << std::endl;
    }

}

void Council::CouncilMenu() {
    if (NumOfRepeat != 0)    //Update!!!
        ReadFiles();        //Update!!!

    NumOfRepeat++;          //Update!!!
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

        CouncilPrintMenu(); //Print the main menu
        ChoiceOfCouncil(choice); // Take the user choice
        system("cls");
        CouncilChoiceDistributor(choice); //Go to the required choice according to choice
        std::cin.ignore();

    } while (choice != 'e');
}

//Using Read functions
Council::Council() {

    NumOfDiv = 0;
    NumOfFreeDiv = 0;
    NumOfAssignDiv = 0;
    AvlTemplateNum = 0;
    NumOfBattalions = 0;

    ReadAvailableTemplates();
    ReadBattalion();
    ReadAssignDiv();
    ReadFreeDiv();
    CombineVariable();

}

//Read the whole required txt files         //Update!!!
void Council::ReadFiles() {

    ClearVariable();
    ReadAvailableTemplates();
    ReadBattalion();
    ReadAssignDiv();
    ReadFreeDiv();
    CombineVariable();
}             //Update!!!
void Council::openConfirmFile(std::string& confimcode)
{
    std::fstream Confirm_File;
    Confirm_File.open("Common\\Confirm Code(Council).txt", std::ios::in);

    if (!Confirm_File) { std::cout << "No such a file" << std::endl; }
    else {

        while (!Confirm_File.eof())
        {
            Confirm_File >> confimcode;
        }

    }

    Confirm_File.close();

}
//Clear the variables values                //Update!!!
void Council::ClearVariable() {

    NumOfDiv = 0;
    NumOfFreeDiv = 0;
    NumOfAssignDiv = 0;
    AvlTemplateNum = 0;
    NumOfBattalions = 0;

    ReqManpower.clear();
    DivisionNum.clear();
    DivisionAssignArmy.clear();
    ReqManpowerBattalions.clear();
    DivisionAssignArmyGroup.clear();

    TemplateName.clear();
    BattalionsName.clear();
    TemplateDivName.clear();
    DivisionLocation.clear();
}

//Combine the Assign and Free Div variable to a single variable
template<typename T>
T Council::CombineFreeAssignDiv(T source1, T source2) {
    T Target;

    for (int i{}; i < source1.size(); i++)
        Target.push_back(source1[i]);

    for (int i{}; i < source2.size(); i++)
        Target.push_back(source2[i]);

    return Target;
}

void Council::CombineVariable() {

    NumOfDiv = NumOfAssignDiv + NumOfFreeDiv;

    DivisionNum = CombineFreeAssignDiv(AssignDivisionNumber, FreeDivisionNumber);
    DivisionAssignArmy = CombineFreeAssignDiv(AssignDivisionAssignedArmy, FreeDivisionAssignedArmy);
    DivisionAssignArmyGroup = CombineFreeAssignDiv(AssignDivisionAssignedArmyGroup, FreeDivisionAssignedArmyGroup);
    TemplateDivName = CombineFreeAssignDiv(AssignDivisionName, FreeDivisionName);
    DivisionLocation = CombineFreeAssignDiv(AssignDivisionLocation, FreeDivisionLocation);

}


int Council::loginSystem()
{
    /*Override function for Council*/
    if (controlMechsForCouncil > 3) { std::cout << "You've tried to enter a lot, the program will exit..." << std::endl; exit(0); }
    else if (controlMechsForCouncil >= 1 && controlMechsForCouncil <= 3) { std::cout << "OOPS try Again!!!!\a" << std::endl << std::endl; }
    /*-----------------------------------------------------*/

    std::string ConfirmCode{ "4567" };
    std::string UserCode;
    std::cout << "Enter Confirm Code for (Council) to continue: ";

    std::cin >> UserCode;
    if (ConfirmCode != UserCode) { controlMechsForCouncil++; return 0; }
    else {
        std::cout << "You're allowed to enter the system!!!!!" << std::endl;
        return 1;
    }
}