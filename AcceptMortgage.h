#pragma once
#include "Action.h"
#include "OfferMortgage.h"
class OfferMortgage;
class AcceptMortgage : public Action
{
	int NumberOfAcceptedCities;
	string* AcceptedPos;
public:
	AcceptMortgage(ApplicationManager* pApp);
	virtual ~AcceptMortgage();
	virtual void Execute();
	virtual void ReadActionParameters();
};
