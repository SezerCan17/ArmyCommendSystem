#pragma once
#include <vector>
#include <string>
#include<sstream>
#include <fstream>

class Base
{
protected:

	std::vector<std::string>MarshalName;
	std::vector<std::string>GeneralName;

	std::vector<std::string>AssignDivisionLocation;              //change AsLocation
	std::vector<std::string>AssignDivisionName;          //change AsDivisionName

	std::vector<std::string>FreeDivisionLocation;                //Added!!! by Batuhan
	std::vector<std::string>FreeDivisionName;            //Added!!! by Batuhan

	std::vector<int>GeneralAssignArmy;
	std::vector<int>GeneralAssignArmyGroup;              //change NrOfArmy to GeneralAssignArmyGroup
	std::vector<int>MarshalAssignedArmyGroup;            //change AssingedArmyGroup


	std::vector<int>AssignDivisionNumber;               //change AsDivisionNumber
	std::vector<int>AssignDivisionAssignedArmy;         //AssignDivsionAssignedArmy
	std::vector<int>AssignDivisionAssignedArmyGroup;    //change AsDivisionAssignedArmyGroup

	std::vector<int>FreeDivisionNumber;                 //Added!!! by Batuhan
	std::vector<int>FreeDivisionAssignedArmy;           //Added!!! by Batuhan
	std::vector<int>FreeDivisionAssignedArmyGroup;      //Added!!! by Batuhan

	void openGeneralFile();
	void OpenAssignedDivisionFile();

	virtual int loginSystem() = 0;

public:
	//Constructor

};