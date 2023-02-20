#include <vector>
#include <string>
#include "Base.h"
#include <iostream>

static int controlMechsForCouncil = 0;

class Council : public Base {
protected:

    int NumOfDiv;
    int NumOfFreeDiv;
    int NumOfAssignDiv;
    int AvlTemplateNum;
    int NumOfBattalions;                        //Hold the # how many Battalions is available to use

    std::vector<int> ReqManpower;               //Required Manpower for creating a div from Available Template
    std::vector<int> DivisionNum;               //A division number EX: Armor div 5
    std::vector<int> DivisionAssignArmy;        //For each division print the division`s Assign Army
    std::vector<int> ReqManpowerBattalions;     //For each battalion display required manpower
    std::vector<int> DivisionAssignArmyGroup;   //For each division print the division`s Assign Army

    std::vector<std::string> TemplateName;      //Hold the available template names
    std::vector<std::string> BattalionsName;    //Hold the  battalion names
    std::vector<std::string> TemplateDivName;   //Hold a division name
    std::vector<std::string> DivisionLocation;  //Hold a division location

    void ReadFreeDiv();                         //Read the list of the Free divisions from the file
    void ReadBattalion();                       //Read Battalions from the file
    void ReadAssignDiv();                       //Read the list of the Assign divisions from the file
    void ReadAvailableTemplates();              //Read Available Templates from a file and assign them to related variables
    void ReadFiles();                           //Read the whole required txt files

    template<class T>                           //Combine the Assign and Free Div variable to a single variable
    T CombineFreeAssignDiv(T source1, T source2);

    void openConfirmFile(std::string& confimcode);

public:
    int NumOfRepeat;  //Update!!!        //Count the number how many times the Council class

    void DisplayDiv();                          //Display the Division list
    void DisplayBattalion();                    //Display the Battalion list
    void DisplayAvlTemplate();                  //Display the Available Template list
    void DisplayNumOfDivType();                 //Display the number of each division type


    void ClearVariable();    //Update!!!        //Clear the variables values
    void CreateDiv();                           //Create Divisions according to available templates
    void DesignTemplate();                      //Create a new template
    void RedesignedTemplate();                  //Update a currently used template

    void CouncilMenu();
    void CouncilChoiceDistributor(char& choice);//Takes the user choice and called required func


    void CouncilPrintMenu();
    void ChoiceOfCouncil(char& choice);

    void CombineVariable();

    Council();


    int loginSystem() override;





};