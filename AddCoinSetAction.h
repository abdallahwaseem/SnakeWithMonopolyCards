#pragma once
#include"Action.h"

class AddCoinSetAction :public Action
{
	CellPosition pos;
	int amount;
	bool checkDrawing; // Validation check for drawing
public:
	AddCoinSetAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~AddCoinSetAction();

};