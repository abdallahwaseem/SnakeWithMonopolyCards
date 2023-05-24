#pragma once
#include "Action.h"
class SellCity :public Action
{
	int NumberOfSoldCities;
	string* SoldPos;
public:
	SellCity(ApplicationManager* pApp);
	virtual ~SellCity();
	virtual void Execute();
	virtual void ReadActionParameters();
};

