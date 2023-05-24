#pragma once
#include "Action.h"
class ReturnMortgage:public Action
{
		string* ReturnedPos;
		int NumOfReturnedCities;
	public:
		ReturnMortgage(ApplicationManager* pApp);
		virtual ~ReturnMortgage();
		virtual void Execute();
		virtual void ReadActionParameters();
};

