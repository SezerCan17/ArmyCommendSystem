#pragma once
#include "Council.h"
#include "General.h"
#include "Leader.h"
#include "Marshal.h"
class Country :public virtual Leader, public virtual Marshal, public virtual General, public virtual Council
{
private:
	string CountryName;

public:
	Country();
	string get_CountryName() { return CountryName; }
};
