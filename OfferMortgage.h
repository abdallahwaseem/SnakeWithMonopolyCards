#pragma once

#include "Action.h"
class OfferMortgage:public Action
{
	int NumOfOfferedCities;
	string *OfferedPos;

public:
	OfferMortgage(ApplicationManager* pApp);
	virtual ~OfferMortgage();
	virtual void Execute();
	virtual void ReadActionParameters();
	string* GetOfferedPos();
};

